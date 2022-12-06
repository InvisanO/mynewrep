#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString name = QFileDialog::getOpenFileName();
    QFile file(name);
    if(!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0, "about", file.errorString());
    QTextStream in(&file);
    ui->textBrowser->setText(in.readAll());
}









