#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_5_clicked()
{

}

void MainWindow::on_pushButton_6_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Open a file", "C://");
    QFile file(file_name);
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this,"title","file not open");
    }

    QTextStream in (&file);
    QString text = in.readAll();
    ui->plainTextEdit->setPlainText(text);
    file.close();
}

void MainWindow::on_pushButton_7_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Open a file", "C://");
    QFile file(file_name);
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this,"title","file not open");
    }

    QTextStream out (&file);
    QString text = ui->plainTextEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
}
