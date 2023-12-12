#include <iostream>
#include <string.h>
#include "Train.h"

using namespace std;

// конструктор по умолчанию
Train::Train()
{
    this->destination = "None";
    this->train_number = "None";
    this->departure_time = "None";

    cout << "Вызван конструктор по умолчанию класса Train" << endl;
}

// конструктор с параметром
Train::Train(string destination, string train_number, string departure_time)
{
    this->destination = destination;
    this->train_number = train_number;
    this->departure_time = departure_time;

    cout << "Вызван конструктор с параметром класса Train" << endl;
}

// конструктор копирования
Train::Train(const Train &t)
{
    this->destination = t.destination;
    this->train_number = t.train_number;
    this->departure_time = t.departure_time;

    cout << "Вызван конструктор копирования класса Train" << endl;
}

// деструктор
Train::~Train()
{
    cout << "Вызван деструктор класса Train" << endl;
}

// метод извлечения полей
void Train::Extract()
{
    cout << *this;
}

// метод получения полей
void Train::Get()
{
    // обнуляем поток ввода
    string buf;
    getline(cin, buf);

    string choice; // переменная выбора поля
    cout << "\nЧто хотите получить?\n" <<
                "1 - Пункт назначения\n" <<
                "2 - Номер поезда\n" <<
                "3 - Время отправления\n" <<
                "4 - Все поля" << endl;
    cout << "Выбор: ";
    cin >> choice; // ввод

    // обработка исключительных ситуаций
    try
    {
        for (int id = 0; id < choice.size(); id ++)
        {
            if (choice[id] >= 'A' && choice[id] <= 'Z') throw "Error";
        }
    }
    catch(const char*mssg)
    {
        cout << "Неверный ввод" << endl;
    }

    if (choice == "1") cout << "Пункт назначения: " << this->destination << endl;
    else if (choice == "2") cout << "Номер поезда: " << this->train_number << endl;
    else if (choice == "3") cout << "Время отправления: " << this->departure_time << endl;
    else if (choice == "4") cout << "Пункт назначения: " << this->destination << " | Номер поезда: " << this->train_number << " | Время отправления: " << this->departure_time << endl;
    else
    {
        cout << "Ошибка выбора" << endl;
        exit(0);
    }
}

// метод получения информации о поезде
void Train::GetInformatio()
{
    cout << "Пункт назначения: " << this->destination << " | Номер поезда: " << this->train_number << " | Время отправления: " << this->departure_time << endl;
}

// метод получения поля времени (для сортировки)
string Train::GetTime()
{
    return this->departure_time;
}

// метод получения пункта назначения
string Train::GetDestination()
{
    return this->destination;
}

// метод получения номера поезда
string Train::GetTrainNumber()
{
    return this->train_number;
}

// метод установки значения
void Train::Set()
{
    // обнуляем поток ввода
    string buf;
    getline(cin, buf);

    cin >> *this;
}

void Train::Change()
{
    // обнуляем поток ввода
    string buf;
    getline(cin, buf);

    string choice;
    cout << "\nЧто хотите изменить?\n" <<
                "1 - Пункт назначения\n" <<
                "2 - Номер поезда\n" <<
                "3 - Время отправления" << endl;
    cout << "Выбор: ";
    cin >> choice;

    // обработка исключительных ситуаций
    try
    {
        for (int id = 0; id < choice.size(); id ++)
        {
            if (choice[id] >= 'A' && choice[id] <= 'Z') throw "Error";
        }
    }
    catch(const char*mssg)
    {
        cout << "Неверный ввод" << endl;
    }

    if (choice == "1")
    {
        getline(cin, choice);

        cout << "Пункт назначения: ";
        getline(cin, this->destination);
    }

    else if (choice == "2")
    {
        getline(cin, choice);

        cout << "Номер поезда: ";
        getline(cin, this->train_number);
    }

    else if (choice == "3")
    {
        getline(cin, choice);

        cout << "Время отправления: ";
        getline(cin, this->departure_time);
    }

    else
    {
        cout << "Ошибка выбора" << endl;
        exit(0);
    }
}

// перегрузка оператора вывода
std::ostream &operator<< (std::ostream &stream, Train &t) // перегрузка оператора извлеченния
{
    stream << "\nВсе поля класса:" << endl;
    stream << t.destination << endl;
    stream << t.train_number << endl;
    stream << t.departure_time << endl;

    return stream;
}

// перегрузка оператора ввода
std::istream &operator>> (std::istream &stream, Train &t) // перегрузка оператора вставки
{
    string buf;

    cout << "\nВставка значений:" << endl;
    cout << "Пункт назначения: ";
    getline(stream, buf);
    t.destination = buf;

    cout << "Номер поезда: ";
    getline(stream, buf);
    t.train_number = buf;

    cout << "Время отпрвления: ";
    getline(stream, buf);
    t.departure_time = buf;

    return stream;
}
