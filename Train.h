#ifndef TRAIN_H
#define TRAIN_H

#include <iostream>
#include <string.h>
using namespace std;

class Train
{
private:
    string destination; // пункт назначение
    string train_number; // номер поезда
    string departure_time; // время отправления

public:
    Train(); // конструктор по умолчанию
    Train(string destination, string train_number, string departure_time); // конструктор с параметром
    Train(const Train &t); // конструктор копирования
    ~Train(); // деструктор

    void Extract(); // метод извлечения значения
    void Get(); // метод получения полей
    void GetInformatio(); // метод получения информации о конкретном поезде
    string GetTime(); // метод получения поля времени для упорядочивания
    string GetDestination(); // метод получения пункта назначения
    string GetTrainNumber(); // метод получения номера поезда
    void Set(); // метод установки значения
    void Change(); // метод редактирования значений

    friend ostream &operator<< (ostream &stream, Train &t); // перегрузка оператора извлеченния
    friend istream &operator>> (istream &stream, Train &t); // перегрузка оператора вставки
};

#endif
