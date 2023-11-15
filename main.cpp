#include <iostream>
#include <fstream>
#include<string>

using namespace std;

bool isDevider(string ch)
{
    return (ch == "." || ch == "!" || ch == "?" || ch == "\"");
}

bool isDeviderExt(string ch)
{
    return (ch == "." || ch == "!" || ch == "?" || ch == "\"" || ch == " " || ch == "\t" || ch == "\n");
}

bool check(string a) // проверка на наличие кавычек в строке
{
    if (a.find('<<') != string::npos)
    {
        return 0;
    }
    else return 1;
}

void readFile()
{
    setlocale(LC_ALL, "Russian");

    ifstream fin; // создаем объект класса ifstream
    string filename = "text.txt"; // объ€вл€ем название файла

    fin.open(filename); // открываем файл
    if (!fin.is_open()) // если файл не открылс€, значит вызываем исключение, что файл не найден
    {
        throw "»сключение: файл " + filename + " не найден";
    }

    string str[100];
    string c;
    char ch;
    int count = 0;

    while (!fin.eof()) // пока файл не пуст
    {
        fin.get(ch); // получаем строку (предложение до знака "." или "?" или "!")
        c = ch;

        if (!isDeviderExt(c)) // пока строка не равна конце предложени€ (то есть точки и т.д)
        {
            while (!fin.eof()) // пока файл не пуст
            {
                str[count] += c; // добавл€ем предложение
                fin.get(ch);
                c = ch;
                if (isDevider(c)) // если это конец предложени€
                {
                    if (check(str[count])) // проверка на зап€тую
                    {
                        cout << "" << endl;
                    }
                    else {
                        cout << str[count] << endl; // выводим предложени€ в кавычках
                    }

                    count++;
                    break;
                }
            }
        }
    }
    fin.close();
}


int main()
{
    readFile();
}