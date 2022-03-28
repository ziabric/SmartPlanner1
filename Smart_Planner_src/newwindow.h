//! @file newwindow/newwindow.h
//! @authors Курбет Н.А.
//! @note Ответственный: Полевой Д.В.
//! @brief Класс окна, сохраняющего файл заметки
//! @todo

#ifndef NEWWINDOW_H
#define NEWWINDOW_H
#pragma once

#include <QWidget>
#include <QString>
namespace Ui {class newwindow;}

class newwindow : public QWidget
{
    Q_OBJECT

public:

    //! @brief Конструтор для окна сохранения
    explicit newwindow(QWidget *parent = nullptr);

    //! @brief Деструктор экземпляра класса
    ~newwindow();

public:


    QString strTitle; //!< Название заметки
    QString strSource; //!< Текст заметки

private slots:

    //! @brief Обработка нажатия кнопки "Save"
    void on_pushButton_clicked();


private:
    Ui::newwindow *ui; //!< Указатель на графический интерфейс

};

#endif // NEWWINDOW_H
