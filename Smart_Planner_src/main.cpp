#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
        MainWindow w;
        w.setWindowTitle("Smart Planner");
        w.setWindowIcon(QIcon("icon.png"));
        w.show();
        return a.exec();
}
