#pragma once
#ifndef DICT_H
#define DICT_H

#include <string>
#include <fstream>
using namespace std;
/**
  @mainpage Документация класса Dict - Англо-русский словарь на бинарном дереве
 
  @section intro_sec Введение
  Класс Dict реализует англо-русский словарь с использованием бинарного дерева поиска.
  Это эффективная структура данных для хранения и поиска пар ключ-значение, где ключами
  являются английские слова, а значениями - их русские переводы.
 
  @section features_sec Основные возможности
  - Добавление новых слов и переводов (оператор +=)
  - Удаление слов из словаря (оператор -=)
  - Поиск и замена переводов (оператор [])
  - Подсчет количества слов в словаре
  - Загрузка словаря из файла
  - Поддержка как C-строк (char), так и std::string
 
  @section usage_sec Пример использования
  @code
  Dict dictionary;
  dictionary += std::make_pair("apple", "яблоко");
  dictionary += std::make_pair("car", "машина");
 
  cout << dictionary["apple"] << endl; // Выведет: яблоко
  dictionary["car"] = "автомобиль";    // Замена перевода
 
  dictionary -= "apple";               // Удаление слова
  cout << dictionary.size() << endl;   // Выведет: 1
  @endcode
 
  @section structure_sec Структура класса
  Класс использует внутренний класс Node для представления узлов бинарного дерева.
  Каждый узел содержит:
  - Английское слово (ключ)
  - Русский перевод (значение)
  - Указатели на левого и правого потомков
 
  @section file_format_sec Формат файла словаря
  Словарь можно загружать из файлов в формате:
  @code
  apple=яблоко
  car:машина
  book    книга
  @endcode
  Поддерживаются разделители: '=', ':' и табуляция.
  @see file:///C:/Users/user/source/repos/%D0%9F%D0%9F%D0%9E%D0%98%D0%A1%201/%D0%9F%D0%9F%D0%9E%D0%98%D0%A1%201/html/class_vector.html
 */

/**
  @class Dict
  @brief Класс, реализующий англо-русский словарь на основе бинарного дерева поиска.
 
  Класс предоставляет функциональность для хранения и управления словарем,
  где английские слова являются ключами, а русские - значениями.
  Реализован на основе бинарного дерева поиска для эффективного выполнения операций.
 */
class Dict {
private:
    /**
      @class Node
      @brief Внутренний класс, представляющий узел бинарного дерева.
     
      Каждый узел содержит английское слово, его русский перевод и указатели на левого и правого потомков.
     */
    class Node {
    private:
        string english;
        string russian; 
        Node* left;
        Node* right; 

    public:
        /**
          @brief Конструктор узла.
          @param eng Английское слово.
          @param rus Русский перевод.
         */
        Node(const string& eng, const string& rus);

        /**
          @brief Получить английское слово.
          @return Константная ссылка на английское слово.
         */
        const string& get_english();

        /**
          @brief Получить русский перевод (константная версия).
          @return Константная ссылка на русский перевод.
         */
        const string& get_russian() const;

        /**
          @brief Получить русский перевод (неконстантная версия).
          @return Ссылка на русский перевод.
         */
        string& get_russian();

        /**
          @brief Получить левого потомка.
          @return Указатель на левого потомка.
         */
        Node* get_left() const;

        /**
          @brief Получить правого потомка.
          @return Указатель на правого потомка.
         */
        Node* get_right() const;

        /**
          @brief Установить левого потомка.
          @param node Указатель на новый левый узел.
         */
        void set_left(Node* node);

        /**
          @brief Установить правого потомка.
          @param node Указатель на новый правый узел.
         */
        void set_right(Node* node);

        /**
          @brief Установить русский перевод.
          @param rus Новый русский перевод.
         */
        void set_russian(const string& rus);
    };

    Node* root;
    int count;

    // Вспомогательные методы для работы с деревом
    Node* add_node(Node* node, const string& english, const string& russian);
    Node* remove_node(Node* node, const string& english);
    Node* direct_remove_node(Node* node, const std::string& english);
    Node* find_min(Node* node) const;
    Node* find_node(Node* node, const string& english) const;
    void clear_tree(Node* node);
    Node* copy_tree(Node* node) const;

public:
    /**
      @brief Конструктор по умолчанию.
      Создает пустой словарь.
     */
    Dict();

    /**
      @brief Конструктор копирования.
      @param other Словарь для копирования.
     */
    Dict(const Dict& other);

    /**
      @brief Деструктор.
      Освобождает всю память, занятую деревом.
     */
    ~Dict();

    /**
      @brief Оператор присваивания.
      @param other Словарь для копирования.
      @return Ссылка на текущий объект.
     */
    Dict& operator=(const Dict& other);

    /**
      @brief Добавление слова в словарь (для C-строк).
      @param pair Пара слов: английское и русское.
      @return Ссылка на текущий объект.
     */
    Dict& operator+=(const pair<char*, char*>& pair);

    /**
      @brief Добавление слова в словарь (для std::string).
      @param pair Пара слов: английское и русское.
      @return Ссылка на текущий объект.
     */
    Dict& operator+=(const pair<string, string>& pair);

    /**
      @brief Удаление слова из словаря (для C-строк).
      @param english Английское слово для удаления.
      @return Ссылка на текущий объект.
     */
    Dict& operator-=(const char* english);

    /**
      @brief Удаление слова из словаря (для std::string).
      @param english Английское слово для удаления.
      @return Ссылка на текущий объект.
     */
    Dict& operator-=(const string& english);

    /**
      @brief Поиск и замена перевода (неконстантная версия для C-строк).
      @param english Английское слово для поиска.
      @return Ссылка на русский перевод.
      @throw std::runtime_error Если слово не найдено.
     */
    string& operator[](const char* english);

    /**
      @brief Поиск и замена перевода (неконстантная версия для std::string).
      @param english Английское слово для поиска.
      @return Ссылка на русский перевод.
      @throw std::runtime_error Если слово не найдено.
     */
    string& operator[](const string& english);

    /**
      @brief Получить количество слов в словаре.
      @return Количество слов в словаре.
     */
    int size() const;

    /**
      @brief Загрузка словаря из файла.
      @param filename Имя файла для загрузки.
      @throw std::runtime_error Если файл не может быть открыт.
     
      Формат файла: каждая строка содержит пару "английское_слово=русский_перевод".
      Поддерживаются разделители: '=', ':' и табуляция.
     */
    void load_from_file(const string& filename);

    /**
      @brief Очистка словаря.
      Удаляет все слова из словаря.
     */
    void clear();

    /**
      @brief Проверка наличия слова в словаре (для std::string).
      @param english Английское слово для проверки.
      @return true если слово найдено, иначе false.
     */
    bool contains(const string& english) const;

    /**
      @brief Проверка наличия слова в словаре (для C-строк).
      @param english Английское слово для проверки.
      @return true если слово найдено, иначе false.
     */
    bool contains(const char* english) const;
};

#endif