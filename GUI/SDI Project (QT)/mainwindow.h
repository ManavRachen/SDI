#pragma once

#include "pch.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

	/// Add items from text file to class list
    void on_ClassOpenButton_clicked();

    /// Change Class Name
    void on_ClassList_itemClicked();


	/// Select pictures folder and loads items to picture list 
    void on_ImageFolderButton_clicked();

	/// Load selected image to canvas
    void on_LoadImage_clicked();

	/// Sort the picture list in ascending or descending order
	void on_SortButton_clicked();




private:
    Ui::MainWindow *ui;


};
