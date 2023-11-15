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

bool check(string a) // �������� �� ������� ������� � ������
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

    ifstream fin; // ������� ������ ������ ifstream
    string filename = "text.txt"; // ��������� �������� �����

    fin.open(filename); // ��������� ����
    if (!fin.is_open()) // ���� ���� �� ��������, ������ �������� ����������, ��� ���� �� ������
    {
        throw "����������: ���� " + filename + " �� ������";
    }

    string str[100];
    string c;
    char ch;
    int count = 0;

    while (!fin.eof()) // ���� ���� �� ����
    {
        fin.get(ch); // �������� ������ (����������� �� ����� "." ��� "?" ��� "!")
        c = ch;

        if (!isDeviderExt(c)) // ���� ������ �� ����� ����� ����������� (�� ���� ����� � �.�)
        {
            while (!fin.eof()) // ���� ���� �� ����
            {
                str[count] += c; // ��������� �����������
                fin.get(ch);
                c = ch;
                if (isDevider(c)) // ���� ��� ����� �����������
                {
                    if (check(str[count])) // �������� �� �������
                    {
                        cout << "" << endl;
                    }
                    else {
                        cout << str[count] << endl; // ������� ����������� � ��������
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