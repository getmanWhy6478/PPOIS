#pragma once
#ifndef DICT_H
#define DICT_H

#include <string>
#include <fstream>
using namespace std;
/**
  @mainpage ������������ ������ Dict - �����-������� ������� �� �������� ������
 
  @section intro_sec ��������
  ����� Dict ��������� �����-������� ������� � �������������� ��������� ������ ������.
  ��� ����������� ��������� ������ ��� �������� � ������ ��� ����-��������, ��� �������
  �������� ���������� �����, � ���������� - �� ������� ��������.
 
  @section features_sec �������� �����������
  - ���������� ����� ���� � ��������� (�������� +=)
  - �������� ���� �� ������� (�������� -=)
  - ����� � ������ ��������� (�������� [])
  - ������� ���������� ���� � �������
  - �������� ������� �� �����
  - ��������� ��� C-����� (char), ��� � std::string
 
  @section usage_sec ������ �������������
  @code
  Dict dict;
  dict += std::make_pair("apple", "������");
  dict += std::make_pair("car", "������");
 
  cout << dict["apple"] << endl; // �������: ������
  dict["car"] = "����������";    // ������ ��������
 
  dict -= "apple";               // �������� �����
  cout << dict.size() << endl;   // �������: 1
  @endcode
 
  @section structure_sec ��������� ������
  ����� ���������� ���������� ����� Node ��� ������������� ����� ��������� ������.
  ������ ���� ��������:
  - ���������� ����� (����)
  - ������� ������� (��������)
  - ��������� �� ������ � ������� ��������
 
  @section file_format_sec ������ ����� �������
  ������� ����� ��������� �� ������ � �������:
  @code
  apple=������
  car:������
  book    �����
  @endcode
  �������������� �����������: '=', ':' � ���������.
  @see file:///C:/Users/user/source/repos/%D0%9F%D0%9F%D0%9E%D0%98%D0%A1%201/%D0%9F%D0%9F%D0%9E%D0%98%D0%A1%201/html/class_vector.html
 */

/**
  @class Dict
  @brief �����, ����������� �����-������� ������� �� ������ ��������� ������ ������.
 
  ����� ������������� ���������������� ��� �������� � ���������� ��������,
  ��� ���������� ����� �������� �������, � ������� - ����������.
  ���������� �� ������ ��������� ������ ������ ��� ������������ ���������� ��������.
 */
class Dict {
private:
    /**
      @class Node
      @brief ���������� �����, �������������� ���� ��������� ������.
     
      ������ ���� �������� ���������� �����, ��� ������� ������� � ��������� �� ������ � ������� ��������.
     */
    class Node {
    private:
        string english;
        string russian; 
        Node* left;
        Node* right; 

    public:
        /**
          @brief ����������� ����.
          @param eng ���������� �����.
          @param rus ������� �������.
         */
        Node(const string& eng, const string& rus);

        /**
          @brief �������� ���������� �����.
          @return ����������� ������ �� ���������� �����.
         */
        const string& get_english();

        /**
          @brief �������� ������� ������� (����������� ������).
          @return ����������� ������ �� ������� �������.
         */
        const string& get_russian() const;

        /**
          @brief �������� ������� ������� (������������� ������).
          @return ������ �� ������� �������.
         */
        string& get_russian();

        /**
          @brief �������� ������ �������.
          @return ��������� �� ������ �������.
         */
        Node* get_left() const;

        /**
          @brief �������� ������� �������.
          @return ��������� �� ������� �������.
         */
        Node* get_right() const;

        /**
          @brief ���������� ������ �������.
          @param node ��������� �� ����� ����� ����.
         */
        void set_left(Node* node);

        /**
          @brief ���������� ������� �������.
          @param node ��������� �� ����� ������ ����.
         */
        void set_right(Node* node);

        /**
          @brief ���������� ������� �������.
          @param rus ����� ������� �������.
         */
        void set_russian(const string& rus);
    };

    Node* root;
    int count;

    // ��������������� ������ ��� ������ � �������
    Node* add_node(Node* node, const string& english, const string& russian);
    Node* remove_node(Node* node, const string& english);
    Node* direct_remove_node(Node* node, const std::string& english);
    Node* find_min(Node* node) const;
    Node* find_node(Node* node, const string& english) const;
    void clear_tree(Node* node);
    Node* copy_tree(Node* node) const;

public:
    /**
      @brief ����������� �� ���������.
      ������� ������ �������.
     */
    Dict();

    /**
      @brief ����������� �����������.
      @param other ������� ��� �����������.
     */
    Dict(const Dict& other);

    /**
      @brief ����������.
      ����������� ��� ������, ������� �������.
     */
    ~Dict();

    /**
      @brief �������� ������������.
      @param other ������� ��� �����������.
      @return ������ �� ������� ������.
     */
    Dict& operator=(const Dict& other);

    /**
      @brief ���������� ����� � ������� (��� C-�����).
      @param pair ���� ����: ���������� � �������.
      @return ������ �� ������� ������.
     */
    Dict& operator+=(const pair<char*, char*>& pair);

    /**
      @brief ���������� ����� � ������� (��� std::string).
      @param pair ���� ����: ���������� � �������.
      @return ������ �� ������� ������.
     */
    Dict& operator+=(const pair<string, string>& pair);

    /**
      @brief �������� ����� �� ������� (��� C-�����).
      @param english ���������� ����� ��� ��������.
      @return ������ �� ������� ������.
     */
    Dict& operator-=(const char* english);

    /**
      @brief �������� ����� �� ������� (��� std::string).
      @param english ���������� ����� ��� ��������.
      @return ������ �� ������� ������.
     */
    Dict& operator-=(const string& english);

    /**
      @brief ����� � ������ �������� (������������� ������ ��� C-�����).
      @param english ���������� ����� ��� ������.
      @return ������ �� ������� �������.
      @throw std::runtime_error ���� ����� �� �������.
     */
    string& operator[](const char* english);

    /**
      @brief ����� � ������ �������� (������������� ������ ��� std::string).
      @param english ���������� ����� ��� ������.
      @return ������ �� ������� �������.
      @throw std::runtime_error ���� ����� �� �������.
     */
    string& operator[](const string& english);
    /**
      @brief �������� ���������� ���� � �������.
      @return ���������� ���� � �������.
     */
    int size() const;

    /**
      @brief �������� ������� �� �����.
      @param filename ��� ����� ��� ��������.
      @throw std::runtime_error ���� ���� �� ����� ���� ������.
     
      ������ �����: ������ ������ �������� ���� "����������_�����=�������_�������".
      �������������� �����������: '=', ':' � ���������.
     */
    void load_from_file(const string& filename);

    /**
      @brief ������� �������.
      ������� ��� ����� �� �������.
     */
    void clear();

    /**
      @brief �������� ������� ����� � ������� (��� std::string).
      @param english ���������� ����� ��� ��������.
      @return true ���� ����� �������, ����� false.
     */
    bool contains(const string& english) const;
    /**
      @brief �������� ������� ����� � ������� (��� C-�����).
      @param english ���������� ����� ��� ��������.
      @return true ���� ����� �������, ����� false.
     */
    bool contains(const char* english) const;
};

#endif
