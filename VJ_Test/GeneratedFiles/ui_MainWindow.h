/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QLabel *label_image;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(1122, 915);
        MainWindowClass->setStyleSheet(QStringLiteral("background:white"));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(80, 70, 93, 28));
        pushButton->setStyleSheet(QLatin1String("background:black;\n"
"color:white"));
        label_image = new QLabel(centralWidget);
        label_image->setObjectName(QStringLiteral("label_image"));
        label_image->setGeometry(QRect(80, 100, 971, 741));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(190, 70, 111, 28));
        pushButton_2->setStyleSheet(QLatin1String("background:black;\n"
"color:white"));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(310, 70, 131, 28));
        pushButton_3->setStyleSheet(QLatin1String("background:black;\n"
"color:white"));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(450, 70, 131, 28));
        pushButton_4->setStyleSheet(QLatin1String("background:black;\n"
"color:white"));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(590, 70, 131, 28));
        pushButton_5->setStyleSheet(QLatin1String("background:black;\n"
"color:white"));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(730, 70, 131, 28));
        pushButton_6->setStyleSheet(QLatin1String("background:black;\n"
"color:white"));
        MainWindowClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        retranslateUi(MainWindowClass);
        QObject::connect(pushButton, SIGNAL(clicked()), MainWindowClass, SLOT(btnLoadImage()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), MainWindowClass, SLOT(FaceDetection()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), MainWindowClass, SLOT(HumanDetection()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), MainWindowClass, SLOT(VehicleFrontDetection()));
        QObject::connect(pushButton_5, SIGNAL(clicked()), MainWindowClass, SLOT(VehicleSideDetection()));
        QObject::connect(pushButton_6, SIGNAL(clicked()), MainWindowClass, SLOT(VehicleRearDetection()));

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindowClass", "LoadImage", Q_NULLPTR));
        label_image->setText(QString());
        pushButton_2->setText(QApplication::translate("MainWindowClass", "FaceDetection", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindowClass", "HumanDetection", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindowClass", "VehicleFront", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindowClass", "VehicleSide", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWindowClass", "VehicleRear", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
