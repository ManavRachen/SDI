#include "pch.h"

QString folder;
SDI::LinkedList<QString> images;
QString className;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
	ui->setupUi(this);

}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_ClassOpenButton_clicked()
{
	ui->ClassList->clear();
    ui->graphicsView->current = nullptr;

	QString fileName = QFileDialog::getOpenFileName(this, "Open a file");
	QFile file(fileName);

	if (!file.open(QFile::ReadOnly | QFile::Text))
	{
		QMessageBox::warning(this, "title", "file not open");
	}

	QTextStream in(&file);
	while (!in.atEnd()) {
		ui->ClassList->addItem(in.readLine());
	}

	file.close();
}

void MainWindow::on_ClassList_itemClicked(){

    ui->graphicsView->current = ui->ClassList->currentItem()->text();
    qDebug() << "Change Box Name to " << ui->graphicsView->current;

}

void MainWindow::on_ImageFolderButton_clicked()
{
	ui->ImageList->clear();
    ui->graphicsView->openImage("");
    ui->graphicsView->containsImage = false;
    ui->SaveBtn->fileName = "";

	QString folderName = QFileDialog::getExistingDirectory();

	if (folderName == "") {
		QMessageBox::warning(this, "title", "No folder selected");
        ui->SaveBtn->folderName = "";

		return;
	}

	folder = folderName + "/";
    ui->SaveBtn->folderName = folder;

	QDir directory(folderName);

	foreach(QString string, directory.entryList()) {
		if (string.endsWith(".jpg") || string.endsWith(".png")) {
			ui->ImageList->addItem(string);
			
			images.append(string);
		}

	}

}

void MainWindow::on_LoadImage_clicked()
{
	if (ui->ImageList->currentItem()) {

		QString file = folder + ui->ImageList->currentItem()->text();
		ui->graphicsView->openImage(file);
        ui->graphicsView->containsImage = true;
        ui->SaveBtn->fileName = ui->ImageList->currentItem()->text();

        QPixmap q(file);
        ui->SaveBtn->width = q.width();
        ui->SaveBtn->height = q.height();

	}

}

void MainWindow::on_SortButton_clicked()
{
	if (ui->ImageList->count()) {	//Check if there are any items to sort

		int size = ui->ImageList->count();
		SDI::LinkedList<QString> list;

		for (int i = 0; i < size; i++) {			//Append all items to linked list
			list.append(ui->ImageList->item(i)->text());
		}

		bool order = list.front().data < list.back().data;

		list.sort(!order);		//Sort list

		ui->ImageList->clear();

		for (int i = 0; i < size; i++){		//Re-add items back to widget
			ui->ImageList->addItem(list.front().data);
			list.popFront();
		}


	}
	else {
		QMessageBox::warning(this, "title", "No Items to sort");
	}

}
