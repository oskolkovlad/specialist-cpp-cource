#include "IoOperations.h"

/* ��:

* 1.1. ������������ ��������� Date � Time � (�������������) ������� Set, Print � Read ��� ���������, ������ � ������ � ���������� �������� ���� � �������.
������������� ����������� ��� ��������� ������� �������� �������� ������ �� ���������.
������������� � �������� Set ������������ ����������� ���� � ������� ������ ���������� ��������.
������������� �� ������.
*/

bool IsYearLeap(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int GetDayUpperBound(int month, int year)
{
    int value;

    switch (month)
    {
        case 2:
            value = IsYearLeap(year) ? 29 : 28;
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            value = 30;
            break;

        default:
            value = 31;
            break;
    }

    return value;
}

void Set(Date& item, int day, int month, int year)
{
    // ��������� �������, ��� ��� �� ��. �� ���������������, ��� ��� ���� ����� ���������� ��� ������.

    // �����������, ��� ���������� �������� �������� �� 1 �� 2500.
    //if (year >= 1 && year <= 2500)
        item.Year = year;

    //if (month >= 1 && month <= 12)
        item.Month = month;

    //if (day >= 1 && day <= GetDayUpperBound(month, year))
        item.Day = day;
}

void Set(Time& item, int hour, int minute, int second = 0)
{
    // ��������� �������, ��� ��� �� ��. �� ���������������, ��� ��� ���� ����� ���������� ��� ������.

    //if (hour >= 0 && hour <= 23)
        item.Hour = hour;

    //if (minute >= 0 && minute <= 59)
        item.Minute = minute;

    //if (second >= 0 && second <= 59)
        item.Second = second;
}

int ReadValue(const char* entityName, int lowerBound, int upperBound)
{
    int value;
    bool condition = true;

    do
    {
        cout << "������� " << entityName << " (�� " << lowerBound << " �� " << upperBound << "): ";
        cin >> value;

        if (value >= lowerBound && value <= upperBound)
        {
            condition = false;
        }
        else
        {
            cout << "������� ������������ ��������! ";
        }

    } while (condition);

    return value;
}

void Read(Date& item)
{
    int year = ReadValue("���", 1, 2500); // �����������, ��� ���������� �������� �������� �� 1 �� 2500.
    int month = ReadValue("�����", 1, 12);
    int day = ReadValue("����", 1, GetDayUpperBound(month, year));

    Set(item, day, month, year);

    cout << endl;
}

void Read(Time& item)
{
    int hour = ReadValue("���", 0, 23);
    int minute = ReadValue("������", 0, 59);
    //int second = ReadValue("�������", 0, 59);

    Set(item, hour, minute/*, second*/);

    cout << endl;
}

void Print(const Date& item, bool withEndl)
{
    cout << format("{:02}.{:02}.{:04}", item.Day, item.Month, item.Year);

    if (withEndl)
    {
        cout << endl << endl;
    }
}

void Print(const Time& item, bool withEndl)
{
    cout << format("{:02}:{:02}:{:02}", item.Hour, item.Minute, item.Second);

    if (withEndl)
    {
        cout << endl << endl;
    }
}
