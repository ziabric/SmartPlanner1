//! @file mainwindow/mainwindow.h
//! @authors Курбет Н.А.
//! @note Ответственный: Полевой Д.В.
//! @brief Класс главного окна, содержит функции для управления программой
//! @todo

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma once

#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include "newwindow.h"
#include "data.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    //! @brief Конструктор класса для главного окна
    //! @param[i] parent - указатель на родительский класс
    MainWindow(QWidget *parent = nullptr);

    //! @brief Деструктор экземпляра класса
    ~MainWindow();

private slots:

    //! @brief Проверка оповещений
    void updateTime();

    //! @brief Обработка нажатия на кнопку "Create"
    void on_create_clicked();

    //! @brief Обработка нажатия на кнопку "Delete"
    void on_delete_2_clicked();

    //! @brief Обработка нажатия на кнопку "Open"
    void on_open_clicked();

    //! @brief Обработка нажатия на кнопку "Save as"
    void on_saveAs_clicked();

private:
    Ui::MainWindow *ui; //!< Указатель на графический интерфейс
    QTimer *tmr; //!< Указатель на тааймер
    Data vectordata; //!< Хранение заметок
};
#endif // MAINWINDOW_H
