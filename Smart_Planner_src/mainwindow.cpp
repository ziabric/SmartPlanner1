#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTime>
#include <QDebug>
#include <QTimer>
#include <QTimeEdit>
#include <QMessageBox>
#include <QStandardItemModel>
#include "newwindow.h"
#include "data.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    tmr = new QTimer();
    tmr->setInterval(15000);
    connect(tmr, SIGNAL(timeout()), this, SLOT(updateTime()));
    tmr->start();

    setWindowIcon(QIcon("icon.png"));
    ui->setupUi(this);
    ui->timer->setDateTime(QDateTime::currentDateTime());
    ui->title->setText(QTime::currentTime().toString());



}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_create_clicked()
{
        vectordata.push(ui->title->text(), ui->source->toPlainText(), ui->timer->time());
        ui->comboBox->clear();
        ui->comboBox->addItems(vectordata.getvectortitle());
        ui->title->setText("");
        ui->source->setText("");
        ui->timer->setTime(QTime::currentTime());
}
void MainWindow::on_delete_2_clicked()
{
    if (!vectordata.IsEmpty())
    {
        vectordata.pop(ui->comboBox->currentIndex());
        ui->comboBox->clear();
        ui->comboBox->addItems(vectordata.getvectortitle());
        ui->title->setText("");
        ui->source->setText("");
        ui->timer->setTime(QTime::currentTime());
    }
}
void MainWindow::on_open_clicked()
{
    if (!vectordata.IsEmpty())
    {
        std::ptrdiff_t index = ui->comboBox->currentIndex();
        ui->title->setText(vectordata.rtitle(index));
        ui->source->setText(vectordata.rsource(index));
        ui->timer->setTime(vectordata.rdate(index));
    }
}
void MainWindow::updateTime()
{
    if(!vectordata.IsEmpty()) for(QTime item : vectordata.getvectordate()) if(item <= QTime::currentTime())
         {
            //QMessageBox::warning(this, vectortitle[i] , vectorsourse[i]);
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setText("Warning!");
            msgBox.exec();
         }
}
void MainWindow::on_saveAs_clicked()
{
    newwindow* sWindow = new newwindow;
    sWindow->setWindowTitle("Save as");
    sWindow->strTitle = ui->title->text();
    sWindow->strSource = ui->source->toPlainText();
    sWindow->show();


}

