#include <iostream>
#include <fstream>
#include <string>
#include "TextScan.h"

using namespace std;

void TextScaner()
{
    fstream file; // создаем поток ввода
    file.open("Text.txt"); // открытие файла

    if (!file.is_open()) // если файл не открылся
    {
        cout << "Ошибка открытия файла!" << endl;
        exit(0);
    }

    else
    {
        string countWord; // переменная хранит в себе кол-во слов
        cout << "Введите кол-во слов в предложении: ";
        cin >> countWord;

        try
        {
            // проверка на то, что число введено корректно
            for (int id = 0; id < countWord.size(); id++)
            {
                if (!isdigit(countWord[id])) throw "Errors";
            }
        }
        catch(const char*mssg)
        {
            cout << "Неверный ввод!" << endl;
        }

        string line; // строка, в которую будут считываться значения из файла

        while (!file.eof()) // пока не конец файла
        {
            string bufLine;
            getline(file, bufLine); // считываем строку
            line += bufLine + '\n';
        }

        int wordInSuggestion = 0; // для хранения слов в предложении
        string Suggestion; // хранение предложения
        string word; // хранит слово

        for (int id = 0; id < line.size(); id++)
        {
            // если конец предложения
            if (line[id] == '!' || line[id] == '?' || line[id] == '.' || line[id] == '\0')
            {
                if (!word.empty()) wordInSuggestion++;

                // вывод предложения
                if (wordInSuggestion == stoi(countWord))
                {
                    cout << Suggestion << endl;
                }

                wordInSuggestion = 0;
                Suggestion = "";
                word = "";
            }

            else
            {
                if ((line[id] == ' ' || line[id] == ',' || line[id] == ':' || line[id] == ';' || line[id] == '"' || line[id] == '\'' || line[id] == '\n') && !word.empty())
                {
                    // увеличиваем кол-во слов
                    wordInSuggestion++;
                    word = "";
                }
                else
                {
                    // собираем словов
                    if (line[id] != ' ' && line[id] != ',' && line[id] != ':' && line[id] != ';' && line[id] != '"' && line[id] != '\'' && line[id] != '\n') word += line[id];
                }

                if (line[id] == '\n') Suggestion += ' ';
                else Suggestion += line[id]; // собираем предложение
            }
        }
    }

    file.close(); // закрываем файл
}
