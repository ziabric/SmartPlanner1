#include "newwindow.h"
#include "ui_newwindow.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QFileInfo>
#include <QMessageBox>
#include <QDebug>
newwindow::newwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newwindow)
{
    ui->setupUi(this);
}

newwindow::~newwindow()
{
    delete ui;
}


void newwindow::on_pushButton_clicked()
{
    QString pathFile = ui->path->text();
    QFile file(pathFile + strTitle + ".txt");
    if (file.open(QIODevice::WriteOnly))
    {

        QTextStream out(&file);
        QFileInfo(file).fileName() = strTitle;
        out<<strSource;
    }
    else
    {
        QMessageBox::warning(this,"ERROR","File error");
    }
    file.close();
    this->close();
}
