/**@file Vector.h
@brief ������������ ���� ������ Vector ��� ������ � ��������� � 3D ������������*/
#pragma once
#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <fstream>
#include <cmath>
/**
@mainpage ������������ ������ Vector - ������ � ��������� ������������

@section intro_sec ��������
����� Vector ��������� ������, �������� � 3D. ��� ��� ������� ���������� ��������� 3 ���������� ������ � �����.

@section features_sec �������� �����������
��������� ��������� ������ �������;
- ���������� ����� �������;
- �������� ���� �������� (��������� +, +=);
- ��������� ���� �������� (��������� -, -=);
- ������������ ���� �������� (��������� *, *=);
- ������������ ������� �� ����� (��������� *, *=);
- ������� ���� �������� (�������� /, /=);
- ����������� �������� ����� ����� ��������� (�������� ^);
- ��������� ��� ��������� ���� �������� (��������� >, >=, <, <=);

@section usage_sec ������ �������������
@code
    Vector a = Vector(1, 2, 3, 4, 5, 6);
    Vector b = Vector(1, 2, 3, 4, 5, 6);
    b += a * 3; 
    cout << b << endl;// �������: Start: (1, 2, 3), End: (13, 14, 15)
    cout << a + b << endl; // �������: Start: (1, 2, 3), End: (16, 17, 18)
@endcode

@section structure_sec ��������� ������
����� ���������� ���������� ����� Node ��� ������������� ����� ��������� ������.
������ ���� �������� :
- ���������� ������ �� ��� x, y, z;
- ���������� ����� �� ��� x, y, z;
@see file:///C:/Users/user/source/repos/%D0%9F%D0%9F%D0%9E%D0%98%D0%A1%201/Dictionary/Dictionary/html/index.html
*/
/**
@class Vector
@brief ����� ��� ������������� � ������ � ��������� � ���������� ������������

����� ������������ ������, �������� ������������ ��������� � �������� �����,
� ������������� ��������� �������� ��� ������ � ���������.*/
class Vector {
private:
    double x_start, y_start, z_start;
    double x_end, y_end, z_end;

public:

    /**
    @brief ����������� �� ���������

    ������� ������� ������ � ������� � ������ � ����� (0, 0, 0)*/

    Vector();

    /**
    @brief ����������������� �����������
    @param start_x ���������� X ��������� �����
    @param start_y ���������� Y ��������� �����
    @param start_z ���������� Z ��������� �����
    @param end_x ���������� X �������� �����
    @param end_y ���������� Y �������� �����
    @param end_z ���������� Z �������� �����*/

    Vector(double start_x, double start_y, double start_z,
        double end_x, double end_y, double end_z);

    /**
    @brief ����������� �����������
    @param second_vector ������ ��� �����������*/
    Vector(const Vector& second_vector);
    /**
    @brief �������� ���������� ��������� ����� �������
    @param &x ������ ��� ���������� ���������� X
    @param &y ������ ��� ���������� ���������� Y
    @param &z ������ ��� ���������� ���������� Z
    @return ���������� ������ �������*/

    void get_start_point(double& x, double& y, double& z) const;
    /**
    @brief �������� ���������� �������� ����� �������
    @param &x ������ ��� ���������� ���������� X
    @param &y ������ ��� ���������� ���������� Y
    @param &z ������ ��� ���������� ���������� Z
    @return ���������� ����� �������*/


    void get_end_point(double& x, double& y, double& z) const;

    /**
    @brief ��������� ����� �������
    @return ����� �������*/

    double length() const;

    /**
    @brief �������� �������� ��������
    @param second_vector ������ ��� ��������
    @return ����� ������ - ��������� ��������*/

    Vector operator+(const Vector& second_vector) const;

    /**
    @brief �������� �������� � �������������
    @param second_vector ������ ��� ��������
    @return ������ �� ���������� ������� ������*/

    Vector& operator+=(const Vector& second_vector);

    /**
    @brief �������� ��������� ��������
    @param second_vector ������ ��� ���������
    @return ����� ������ - ��������� ���������*/
    Vector operator-(const Vector& second_vector) const;

    /**
     @brief �������� ��������� � �������������
     @param second_vector ������ ��� ���������
     @return ������ �� ���������� ������� ������
     */
    Vector& operator-=(const Vector& second_vector);

    /**
     @brief ��������� ������������ ��������
     @param second_vector ������ ������
     @return ��������� ���������� ������������
     */
    double operator*(const Vector& second_vector) const;

    /**
     @brief ��������� ������������ ��������
     @param second_vector ������ ������
     @return ����� ������ - ��������� ���������� ������������
     */
    Vector operator%(const Vector& second_vector) const;

    /**
     @brief �������� ��������� ������� �� �����
     @param num ��������� ���������
     @return ����� ������ - ��������� ���������
    */
    Vector operator*(double num) const;
    /**
     @brief �������� ��������� �� ����� � �������������
     @param num ��������� ���������
     @return ������ �� ���������� ������� ������
     */
    Vector& operator*=(double num);

    /**
     @brief �������� ������� ������� �� �����
     @param num ��������� ��������
     @return ����� ������ - ��������� �������
     @throw std::runtime_error ���� num ����� 0
     */
    Vector operator/(double num) const;

    /**
     @brief �������� ������� �� ����� � �������������
     @param num ��������� ��������
     @return ������ �� ���������� ������� ������
     @throw std::runtime_error ���� num ����� 0
     */
    Vector& operator/=(double num);

    /**
     @brief ���������� �������� ���� ����� ���������
     @param second_vector ������ ������
     @return ������� ���� ����� ���������
     @throw std::runtime_error ���� ����� ������ �� �������� ����� 0
     */
    double operator^(const Vector& second_vector) const;

    /**
     @brief �������� �������� �� ��������� ��������
     @param second_vector ������ ������
     @return true ���� ������� ���������, ����� false
     */
    bool operator==(const Vector& second_vector) const;
    /**
     @brief �������� �������� �� ����������� ��������
     @param second_vector ������ ������
     @return true ���� ������� ��������, ����� false
     */
    bool operator!=(const Vector& second_vector) const;

    /**
     @brief �������� ��������� "������" (�� ����� �������)
     @param second_vector ������ ������
     @return true ���� ������� ������ �������, ����� false
     */
    bool operator>(const Vector& second_vector) const;

    /**
     @brief �������� ��������� "������ ��� �����" (�� ����� �������)
     @param second_vector ������ ������
     @return true ���� ������� ������ ������� ��� �����, ����� false
     */
    bool operator>=(const Vector& second_vector) const;

    /**
     @brief �������� ��������� "������" (�� ����� �������)
     @param second_vector ������ ������
     @return true ���� ������� ������ ������, ����� false
     */
    bool operator<(const Vector& second_vector) const;

    /**
     @brief �������� ��������� "������ ��� �����" (�� ����� �������)
     @param second_vector ������ ������
     @return true ���� ������� ������ ������ ��� �����, ����� false
     */
    bool operator<=(const Vector& second_vector) const;

    /**
     @brief �������� ������������
     @param second_vector ������ ��� �����������
     @return ������ �� ������� ������
     */
    Vector& operator=(const Vector& second_vector);

    /**
     @brief ������������� ������� ��� ������ ������� � �����
     @param os ����� ������
     @param vec ������ ��� ������
     @return ����� ������
    */
    friend std::ostream& operator<<(std::ostream& os, const Vector& vec);
    /**
     @brief ������������� ������� ��� ����� ������� �� ������
     @param is ����� �����
     @param vec ������ ��� ����������
     @return ����� �����
     */
    friend std::istream& operator>>(std::istream& is, Vector& vec);
};
#endif
