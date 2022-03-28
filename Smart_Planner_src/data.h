//! @file Data/data.h
//! @authors Курбет Н.А.
//! @note Ответственный: Полевой Д.В.
//! @brief Класс для хранения и манипуляции заметками
//! @todo

#ifndef DATA_H
#define DATA_H
#pragma once

#include <QStringList>
#include <vector>
#include <QTime>
#include <QString>

class Data
{
private:
    QStringList vectortitle; //!< Назавание заметки
    QStringList vectorsource; //!< Текст заметки
    std::vector<QTime> vectordate; //!< Время оповещения
public:
    Data() = default;
    ~Data() = default;

    //! @brief Проверка на наличие заметок
    bool IsEmpty();

    //! @brief Получение названя заметки по ее индексу
    //! @param[in] index - индекс названия заметки
    QString rtitle(std::ptrdiff_t index);

    //! @brief Получение текста заметки по ее индексу
    //! @param[in] index - индекс текста заметки
    QString rsource(std::ptrdiff_t index);

    //! @brief Получение времени оповещения по ее индексу
    //! @param[in] index - индекс времени оповещения
    QTime rdate(std::ptrdiff_t index);

    //! @brief Добавление заметки в список
    //! @param[in] title - Название заметки
    //! @param[in] source - Текст заметки
    //! @param[in] date - Время оповещения
    void push(QString title, QString source, QTime date);

    //! @brief Удаление заметки из списка
    //! @param[in] index - Индекс заметки
    void pop(std::ptrdiff_t index);

    //! @brief Получение списка оповещений
    std::vector<QTime> getvectordate();

    //! @brief Получение списка названий заметок
    QStringList getvectortitle();
};

#endif // DATA_H
