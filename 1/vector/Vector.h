/**@file Vector.h
@brief Заголовочный файл класса Vector для работы с векторами в 3D пространстве*/
#pragma once
#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <fstream>
#include <cmath>
/**
@mainpage Документация класса Vector - Вектор в трёхмерном пространстве

@section intro_sec Введение
Класс Vector реализует вектор, заданный в 3D. Для его задания необходимо обозначит 3 координаты начала и конца.

@section features_sec Основные возможности
получение координат концов вектора;
- вычисление длины вектора;
- сложение двух векторов (операторы +, +=);
- вычитание двух векторов (операторы -, -=);
- произведение двух векторов (операторы *, *=);
- произведение вектора на число (операторы *, *=);
- деление двух векторов (оператор /, /=);
- определение косинуса между двумя векторами (оператор ^);
- операторы для сравнения двух векторов (операторы >, >=, <, <=);

@section usage_sec Пример использования
@code
    Vector a = Vector(1, 2, 3, 4, 5, 6);
    Vector b = Vector(1, 2, 3, 4, 5, 6);
    b += a * 3; 
    cout << b << endl;// Выведет: Start: (1, 2, 3), End: (13, 14, 15)
    cout << a + b << endl; // Выведет: Start: (1, 2, 3), End: (16, 17, 18)
@endcode

@section structure_sec Структура класса
Класс использует внутренний класс Node для представления узлов бинарного дерева.
Каждый узел содержит :
- Координаты начала по оси x, y, z;
- Координаты конца по оси x, y, z;
@see file:///C:/Users/user/source/repos/%D0%9F%D0%9F%D0%9E%D0%98%D0%A1%201/Dictionary/Dictionary/html/index.html
*/
/**
@class Vector
@brief Класс для представления и работы с векторами в трехмерном пространстве

Класс представляет вектор, заданный координатами начальной и конечной точек,
и предоставляет различные операции для работы с векторами.*/
class Vector {
private:
    double x_start, y_start, z_start;
    double x_end, y_end, z_end;

public:

    /**
    @brief Конструктор по умолчанию

    Создает нулевой вектор с началом и концом в точке (0, 0, 0)*/

    Vector();

    /**
    @brief Параметризованный конструктор
    @param start_x Координата X начальной точки
    @param start_y Координата Y начальной точки
    @param start_z Координата Z начальной точки
    @param end_x Координата X конечной точки
    @param end_y Координата Y конечной точки
    @param end_z Координата Z конечной точки*/

    Vector(double start_x, double start_y, double start_z,
        double end_x, double end_y, double end_z);

    /**
    @brief Конструктор копирования
    @param second_vector Вектор для копирования*/
    Vector(const Vector& second_vector);
    /**
    @brief Получить координаты начальной точки вектора
    @param &x Ссылка для сохранения координаты X
    @param &y Ссылка для сохранения координаты Y
    @param &z Ссылка для сохранения координаты Z
    @return Координаты начала вектора*/

    void get_start_point(double& x, double& y, double& z) const;
    /**
    @brief Получить координаты конечной точки вектора
    @param &x Ссылка для сохранения координаты X
    @param &y Ссылка для сохранения координаты Y
    @param &z Ссылка для сохранения координаты Z
    @return Координаты конца вектора*/


    void get_end_point(double& x, double& y, double& z) const;

    /**
    @brief Вычислить длину вектора
    @return Длина вектора*/

    double length() const;

    /**
    @brief Оператор сложения векторов
    @param second_vector Вектор для сложения
    @return Новый вектор - результат сложения*/

    Vector operator+(const Vector& second_vector) const;

    /**
    @brief Оператор сложения с присваиванием
    @param second_vector Вектор для сложения
    @return Ссылка на измененный текущий вектор*/

    Vector& operator+=(const Vector& second_vector);

    /**
    @brief Оператор вычитания векторов
    @param second_vector Вектор для вычитания
    @return Новый вектор - результат вычитания*/
    Vector operator-(const Vector& second_vector) const;

    /**
     @brief Оператор вычитания с присваиванием
     @param second_vector Вектор для вычитания
     @return Ссылка на измененный текущий вектор
     */
    Vector& operator-=(const Vector& second_vector);

    /**
     @brief Скалярное произведение векторов
     @param second_vector Второй вектор
     @return Результат скалярного произведения
     */
    double operator*(const Vector& second_vector) const;

    /**
     @brief Векторное произведение векторов
     @param second_vector Второй вектор
     @return Новый вектор - результат векторного произведения
     */
    Vector operator%(const Vector& second_vector) const;

    /**
     @brief Оператор умножения вектора на число
     @param num Скалярный множитель
     @return Новый вектор - результат умножения
    */
    Vector operator*(double num) const;
    /**
     @brief Оператор умножения на число с присваиванием
     @param num Скалярный множитель
     @return Ссылка на измененный текущий вектор
     */
    Vector& operator*=(double num);

    /**
     @brief Оператор деления вектора на число
     @param num Скалярный делитель
     @return Новый вектор - результат деления
     @throw std::runtime_error Если num равен 0
     */
    Vector operator/(double num) const;

    /**
     @brief Оператор деления на число с присваиванием
     @param num Скалярный делитель
     @return Ссылка на измененный текущий вектор
     @throw std::runtime_error Если num равен 0
     */
    Vector& operator/=(double num);

    /**
     @brief Вычисление косинуса угла между векторами
     @param second_vector Второй вектор
     @return Косинус угла между векторами
     @throw std::runtime_error Если длина одного из векторов равна 0
     */
    double operator^(const Vector& second_vector) const;

    /**
     @brief Оператор проверки на равенство векторов
     @param second_vector Второй вектор
     @return true если векторы идентичны, иначе false
     */
    bool operator==(const Vector& second_vector) const;
    /**
     @brief Оператор проверки на неравенство векторов
     @param second_vector Второй вектор
     @return true если векторы различны, иначе false
     */
    bool operator!=(const Vector& second_vector) const;

    /**
     @brief Оператор сравнения "больше" (по длине вектора)
     @param second_vector Второй вектор
     @return true если текущий вектор длиннее, иначе false
     */
    bool operator>(const Vector& second_vector) const;

    /**
     @brief Оператор сравнения "больше или равно" (по длине вектора)
     @param second_vector Второй вектор
     @return true если текущий вектор длиннее или равен, иначе false
     */
    bool operator>=(const Vector& second_vector) const;

    /**
     @brief Оператор сравнения "меньше" (по длине вектора)
     @param second_vector Второй вектор
     @return true если текущий вектор короче, иначе false
     */
    bool operator<(const Vector& second_vector) const;

    /**
     @brief Оператор сравнения "меньше или равно" (по длине вектора)
     @param second_vector Второй вектор
     @return true если текущий вектор короче или равен, иначе false
     */
    bool operator<=(const Vector& second_vector) const;

    /**
     @brief Оператор присваивания
     @param second_vector Вектор для копирования
     @return Ссылка на текущий вектор
     */
    Vector& operator=(const Vector& second_vector);

    /**
     @brief Дружественная функция для вывода вектора в поток
     @param os Поток вывода
     @param vec Вектор для вывода
     @return Поток вывода
    */
    friend std::ostream& operator<<(std::ostream& os, const Vector& vec);
    /**
     @brief Дружественная функция для ввода вектора из потока
     @param is Поток ввода
     @param vec Вектор для заполнения
     @return Поток ввода
     */
    friend std::istream& operator>>(std::istream& is, Vector& vec);
};
#endif
