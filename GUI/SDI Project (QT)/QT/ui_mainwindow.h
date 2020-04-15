/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "GraphicsView.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_4;
    QWidget *verticalWidget;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *ImageLabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *ImageFolderButton;
    QPushButton *LoadImage;
    QPushButton *SortButton;
    QListWidget *ImageList;
    QSpacerItem *horizontalSpacer;
    QFrame *line;
    QVBoxLayout *verticalLayout_5;
    QLabel *ClassesLabel;
    QPushButton *ClassOpenButton;
    QListWidget *ClassList;
    QSpacerItem *horizontalSpacer_2;
    QFrame *line_2;
    QVBoxLayout *verticalLayout_6;
    QLabel *OutputLabel;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    GraphicsView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(741, 654);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_4 = new QHBoxLayout(centralwidget);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalWidget = new QWidget(centralwidget);
        verticalWidget->setObjectName(QString::fromUtf8("verticalWidget"));
        verticalWidget->setMinimumSize(QSize(255, 0));
        verticalWidget->setMaximumSize(QSize(250, 16777215));
        verticalLayout = new QVBoxLayout(verticalWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, 1, -1);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        ImageLabel = new QLabel(verticalWidget);
        ImageLabel->setObjectName(QString::fromUtf8("ImageLabel"));
        ImageLabel->setLayoutDirection(Qt::LeftToRight);
        ImageLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(ImageLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        ImageFolderButton = new QPushButton(verticalWidget);
        ImageFolderButton->setObjectName(QString::fromUtf8("ImageFolderButton"));

        horizontalLayout->addWidget(ImageFolderButton);

        LoadImage = new QPushButton(verticalWidget);
        LoadImage->setObjectName(QString::fromUtf8("LoadImage"));

        horizontalLayout->addWidget(LoadImage);


        verticalLayout_3->addLayout(horizontalLayout);

        SortButton = new QPushButton(verticalWidget);
        SortButton->setObjectName(QString::fromUtf8("SortButton"));

        verticalLayout_3->addWidget(SortButton);

        ImageList = new QListWidget(verticalWidget);
        ImageList->setObjectName(QString::fromUtf8("ImageList"));

        verticalLayout_3->addWidget(ImageList);


        verticalLayout->addLayout(verticalLayout_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        line = new QFrame(verticalWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        ClassesLabel = new QLabel(verticalWidget);
        ClassesLabel->setObjectName(QString::fromUtf8("ClassesLabel"));
        ClassesLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(ClassesLabel);

        ClassOpenButton = new QPushButton(verticalWidget);
        ClassOpenButton->setObjectName(QString::fromUtf8("ClassOpenButton"));

        verticalLayout_5->addWidget(ClassOpenButton);

        ClassList = new QListWidget(verticalWidget);
        ClassList->setObjectName(QString::fromUtf8("ClassList"));

        verticalLayout_5->addWidget(ClassList);


        verticalLayout->addLayout(verticalLayout_5);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        line_2 = new QFrame(verticalWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        OutputLabel = new QLabel(verticalWidget);
        OutputLabel->setObjectName(QString::fromUtf8("OutputLabel"));
        OutputLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(OutputLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_4 = new QPushButton(verticalWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        horizontalLayout_2->addWidget(pushButton_4);

        pushButton_2 = new QPushButton(verticalWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(verticalWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_2->addWidget(pushButton_3);


        verticalLayout_6->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(verticalLayout_6);


        horizontalLayout_4->addWidget(verticalWidget);

        graphicsView = new GraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        horizontalLayout_4->addWidget(graphicsView);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 741, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        ImageLabel->setText(QCoreApplication::translate("MainWindow", "Images", nullptr));
        ImageFolderButton->setText(QCoreApplication::translate("MainWindow", "Open Image Folder", nullptr));
        LoadImage->setText(QCoreApplication::translate("MainWindow", "Load Image", nullptr));
        SortButton->setText(QCoreApplication::translate("MainWindow", "Sort", nullptr));
        ClassesLabel->setText(QCoreApplication::translate("MainWindow", "Classes", nullptr));
        ClassOpenButton->setText(QCoreApplication::translate("MainWindow", "Open Text File", nullptr));
        OutputLabel->setText(QCoreApplication::translate("MainWindow", "Output", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Save COCO", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Save YOLO", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Save VOC", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
