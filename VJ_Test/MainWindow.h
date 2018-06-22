#pragma once

#include <QtWidgets/QMainWindow>
#include <opencv2/opencv.hpp>
#include "ui_MainWindow.h"
using namespace cv;
class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	~MainWindow();
	QImage MainWindow::convertOpenCVMatToQtQImage(Mat mat);

private slots:
	void btnLoadImage();
	void FaceDetection();
	void HumanDetection();
	void VehicleFrontDetection();
	void VehicleSideDetection();
	void VehicleRearDetection();
private:
	Ui::MainWindowClass ui;
};