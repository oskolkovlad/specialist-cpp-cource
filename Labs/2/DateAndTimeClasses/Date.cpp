#include "Date.h"

/* ТЗ:

* 2.1. Разработайте класс Date и (перегруженные) функции Set, Print и Read для установки, печати и чтения с клавиатуры значений даты.
Предусмотрите в функциях Set присваивание компонентам даты только допустимых значений.
Протестируйте их работу.
*/

bool Date::IsYearLeap(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int Date::GetDayUpperBound(int month, int year)
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

int Date::CompareTo(const Date& item) const {
    if (this->Year == item.Year)
    {
        if (this->Month == item.Month)
        {
            if (this->Day == item.Day)
            {
                return 0;
            }
            
            return this->Day > item.Day ? 1 : -1;
        }

        return this->Month > item.Month ? 1 : -1;
    }

    return this->Year > item.Year ? 1 : -1;
}


void Date::Set(int day, int month, int year)
{
    // Предположим, что допустимый диапазон значений от 1 до 2500.
    if (year >= 1 && year <= 2500)
        Year = year;

    if (month >= 1 && month <= 12)
        Month = month;

    if (day >= 1 && day <= GetDayUpperBound(month, year))
        Day = day;
}

void Date::Read()
{
    int year = ReadValue("год", 1, 2500); // Предположим, что допустимый диапазон значений от 1 до 2500.
    int month = ReadValue("месяц", 1, 12);
    int day = ReadValue("день", 1, GetDayUpperBound(month, year));

    Set(day, month, year);

    cout << endl;
}

void Date::Print(bool withEndl) const
{
    // Ключевое слово "this", можно опустить, но используем его, чтобы отработать материал.

    cout << format("{:02}.{:02}.{:04}", this->Day, this->Month, this->Year);

    if (withEndl)
    {
        cout << endl << endl;
    }
}

int CompareDates(const void* item1, const void* item2)
{
    return static_cast<const Date*>(item1)->CompareTo(*static_cast<const Date*>(item2));
}
