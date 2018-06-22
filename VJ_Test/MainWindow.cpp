#include "MainWindow.h"
#include <QtCore/qdebug.h>
#include <qslider.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <qfiledialog.h>
#include <iostream>
using namespace cv;
using namespace std;
Mat img, src, dst;
double ticks = cvGetTickFrequency()*10e6;
int64 t0;
int v1 = 90, v2 = 35, v3 = 15, v4 = 25, v5 = 225;

string filename = "../people_on_the_road.bmp";
string face_detector = "../face_cascade.xml";
string human_detector = "../human_cascade.xml";
string vehicle_front_detector = "../vehicle_front_cascade.xml";
string vehicle_side_detector = "../vehicle_side_cascade.xml";
string vehicle_rear_detector = "../vehicle_rear_cascade.xml";

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}
MainWindow::~MainWindow() {}
QImage MainWindow::convertOpenCVMatToQtQImage(Mat mat) {
	if (mat.channels() == 1) {
		return QImage((uchar*)mat.data, (int)mat.cols, (int)mat.rows, (int)mat.step, QImage::Format_Indexed8);
	}
	else if (mat.channels() == 3) {
		cv::cvtColor(mat, mat, CV_BGR2RGB);
		return QImage((uchar*)mat.data, (int)mat.cols, (int)mat.rows, (int)mat.step, QImage::Format_RGB888);
	}
	else {
		qDebug() << "in convertOpenCVMatToQtQImage, image was not 1 channel or 3 channel, should never get here";
	}
	return QImage();
}
void MainWindow::btnLoadImage() {
	img = imread(filename, 1);
	src = img.clone();
	QImage qimgOutput = convertOpenCVMatToQtQImage(img);
	ui.label_image->setPixmap(QPixmap::fromImage(qimgOutput));
}


bool R1(int R, int G, int B) {
	bool e1 = (R>v1) && (G>v2) && (B>v3) && ((max(R, max(G, B)) - min(R, min(G, B)))>15) && (abs(R - G)>15) && (R>G) && (R>B);
	bool e2 = (R>220) && (G>210) && (B>170) && (abs(R - G) <= 15) && (R>B) && (G>B);
	return (e1 || e2);
}
bool R2(float Y, float Cr, float Cb) {
	bool e3 = Cr <= 1.5862*Cb + 20;
	bool e4 = Cr >= 0.3448*Cb + 76.2069;
	bool e5 = Cr >= -4.5652*Cb + 234.5652;
	bool e6 = Cr <= -1.15*Cb + 301.75;
	bool e7 = Cr <= -2.2857*Cb + 432.85;
	return e3 && e4 && e5 && e6 && e7;
}
bool R3(float H, float S, float V) {
	return (H<v4) || (H>v5);
}
void GetSkin() {
	dst = src.clone();

	Vec3b cwhite = Vec3b::all(255);
	Vec3b cblack = Vec3b::all(0);

	Mat src_ycrcb, src_hsv;
	cvtColor(src, src_ycrcb, CV_BGR2YCrCb);
	src.convertTo(src_hsv, CV_32FC3);
	cvtColor(src_hsv, src_hsv, CV_BGR2HSV);
	// Now scale the values between [0,255]:
	normalize(src_hsv, src_hsv, 0.0, 255.0, NORM_MINMAX, CV_32FC3);

	for (int i = 0; i < src.rows; i++) {
		for (int j = 0; j < src.cols; j++) {

			Vec3b pix_bgr = src.ptr<Vec3b>(i)[j];
			int B = pix_bgr.val[0];
			int G = pix_bgr.val[1];
			int R = pix_bgr.val[2];
			// apply rgb rule
			bool a = R1(R, G, B);

			Vec3b pix_ycrcb = src_ycrcb.ptr<Vec3b>(i)[j];
			int Y = pix_ycrcb.val[0];
			int Cr = pix_ycrcb.val[1];
			int Cb = pix_ycrcb.val[2];
			// apply ycrcb rule
			bool b = R2(Y, Cr, Cb);

			Vec3f pix_hsv = src_hsv.ptr<Vec3f>(i)[j];
			float H = pix_hsv.val[0];
			float S = pix_hsv.val[1];
			float V = pix_hsv.val[2];
			// apply hsv rule
			bool c = R3(H, S, V);

			if (!(a&&b&&c))
				dst.ptr<Vec3b>(i)[j] = cblack;
		}
	}
	src = dst.clone();
}
Mat preprocessing(Mat image)
{
	Mat gray;
	cvtColor(image, gray, CV_BGR2GRAY);						// 명암도 영상변환
	GaussianBlur(gray, gray, Size(3, 3), 1.0, BORDER_DEFAULT);	// Gaussian Blur
	equalizeHist(gray, gray);								// 히스토그램 평활화

	//GaussianBlur(gray, gray, Size(3, 3), 1.0, BORDER_DEFAULT);	// Gaussian Blur

	return gray;
}
void MainWindow::FaceDetection() {
	CascadeClassifier face_cascade;
	face_cascade.load(face_detector);
	Mat image = src.clone();	// 원본 이미지 clone
	GetSkin();	// Skin Detection
	vector<Rect> faces;
	face_cascade.detectMultiScale(src, faces, 1.05, 2, 0, Size(10, 13));	// 얼굴 검출xml
	if (faces.size() > 0)	// 얼굴 사각형 검출되면
	{
		for (size_t i = 0; i < faces.size(); i++)
			rectangle(image, faces[i], Scalar(0, 0, 255), 2);	// 얼굴 검출 사각형 그리기

		// 결과 출력
		QImage qimgOutput = convertOpenCVMatToQtQImage(image);
		ui.label_image->setPixmap(QPixmap::fromImage(qimgOutput));
	}
}
void MainWindow::HumanDetection() {
	CascadeClassifier human_cascade;
	human_cascade.load(human_detector);
	Mat image = src.clone();
	cvtColor(image, src, CV_BGR2GRAY);						// 명암도 영상변환
	equalizeHist(src, src);								// 히스토그램 평활화
	vector<Rect> humans;
	human_cascade.detectMultiScale(src, humans, 1.05, 2, 0, Size(14, 42));	// 사람 검출xml
	if (humans.size() > 0)	// 사람 사각형 검출되면
	{
		for (size_t i = 0; i < humans.size(); i++)
			rectangle(image, humans[i], Scalar(0, 0, 255), 2);	// 사람 검출 사각형 그리기

																// 결과 출력
		QImage qimgOutput = convertOpenCVMatToQtQImage(image);
		ui.label_image->setPixmap(QPixmap::fromImage(qimgOutput));
	}
}
void MainWindow::VehicleFrontDetection() {
	CascadeClassifier vehicle_cascade;
	vehicle_cascade.load(vehicle_front_detector);
	Mat image = src.clone();
	Mat gray = preprocessing(image);
	vector<Rect> vehicles;
	vehicle_cascade.detectMultiScale(gray, vehicles, 1.05, 2, 0, Size(5, 5));	// 자동차 검출xml
	if (vehicles.size() > 0)	// 자동차 사각형 검출되면
	{
		for (size_t i = 0; i < vehicles.size(); i++)
			rectangle(image, vehicles[i], Scalar(0, 0, 255), 2);	// 자동차 검출 사각형 그리기

																// 결과 출력
		QImage qimgOutput = convertOpenCVMatToQtQImage(image);
		ui.label_image->setPixmap(QPixmap::fromImage(qimgOutput));
	}
}
void MainWindow::VehicleSideDetection() {
	CascadeClassifier vehicle_cascade;
	vehicle_cascade.load(vehicle_side_detector);
	Mat image = src.clone();
	vector<Rect> vehicles;
	vehicle_cascade.detectMultiScale(src, vehicles, 1.05, 2, 0, Size(5, 5));	// 자동차 검출xml
	if (vehicles.size() > 0)	// 자동차 사각형 검출되면
	{
		for (size_t i = 0; i < vehicles.size(); i++)
			rectangle(image, vehicles[i], Scalar(0, 0, 255), 2);	// 자동차 검출 사각형 그리기

																	// 결과 출력
		QImage qimgOutput = convertOpenCVMatToQtQImage(image);
		ui.label_image->setPixmap(QPixmap::fromImage(qimgOutput));
	}
}
void MainWindow::VehicleRearDetection() {
	CascadeClassifier vehicle_cascade;
	vehicle_cascade.load(vehicle_rear_detector);
	Mat image = src.clone();
	// gray gaussian
	Mat gray;
	cvtColor(image, gray, CV_BGR2GRAY);						// 명암도 영상변환
	GaussianBlur(gray, gray, Size(3, 3), 1.0, BORDER_DEFAULT);	// Gaussian Blur
	vector<Rect> vehicles;
	vehicle_cascade.detectMultiScale(gray, vehicles, 1.05, 2, 0, Size(5, 5));	// 자동차 검출xml
	if (vehicles.size() > 0)	// 자동차 검출되면
	{
		for (size_t i = 0; i < vehicles.size(); i++)
			rectangle(image, vehicles[i], Scalar(0, 0, 255), 2);	// 자동차 검출 사각형 그리기

																	// 결과 출력
		QImage qimgOutput = convertOpenCVMatToQtQImage(image);
		ui.label_image->setPixmap(QPixmap::fromImage(qimgOutput));
	}
}