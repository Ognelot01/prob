#pragma once
#ifndef TASKS_H
#define TASKS_H
#include <QVariant>
#include <QRandomGenerator>
#include <QtMath>
/*!
 * \brief Класс заданий
*/

/*!
 * \brief Функция, генерирующее задание на тему построения системы представителей двудольного графа
 * \return Структуру задания, содержащую поля text и answer
 */
QVariantMap Task1();
/*!
 * \brief Функция, генерирующее задание на тему проверки двудольного графа
 * \return Структуру задания, содержащую поля text и answer
 */
QVariantMap Task2();
/*!
 * \brief Функция, генерирующее задание на тему построения гамильтонова графа
 * \return Структуру задания, содержащую поля text и answer
 */
QVariantMap Task3();

#endif // TASKS_H
