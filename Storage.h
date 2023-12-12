#ifndef STORAGE_H
#define STORAGE_H

#include <iostream>
#include <string>
#include "Train.h"

using namespace std;

class Store
{
private:
    Train **array; // массив для хранения значений
    int countElement; // кол-ва элементов

public:
    Store(); // конструктор по умолчанию
    Store(int size); // конструктор с параметром
    Store(const Store &s); // конструктор копирования
    ~Store(); // деструктор

    void SortedArray(); // сортировка после ввода
    void FindTrain(); // поиск по номеру поезда
    void ExtractField(); // извлечь значения объекта
    void GetFiel(); // получить поля
    void Set(); // вставить значение объекта
    void Change(); // изменить значение
    void Delete(); // удалить значние
};

#endif
