#include "Date.h"

Date::Date()
{
    time_t raw_time;
    time(&raw_time);

    tm localtime;
    localtime_s(&localtime, &raw_time);

    Set(localtime.tm_mday, localtime.tm_mon + 1, localtime.tm_year + 1900);
}


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


bool Date::operator ==(const Date& item)
{
    return Equal(item);
}

bool Date::operator !=(const Date& item)
{
    return !Equal(item);
}

bool Date::operator >(const Date& item)
{
    return Greater(item);
}

bool Date::operator >=(const Date& item)
{
    int result = CompareTo(item);
    return result == 1 || result == 0;
}

bool Date::operator <(const Date& item)
{
    return Less(item);
}

bool Date::operator <=(const Date& item)
{
    int result = CompareTo(item);
    return result == -1 || result == 0;
}


ostream& operator <<(ostream& stream, const Date& item)
{
    // Ключевое слово "this", можно опустить, но используем его, чтобы отработать материал.

    stream << format("{:02}.{:02}.{:04}", item.GetDay(), item.GetMonth(), item.GetYear());
    return stream;
}

istream& operator >>(istream& stream, Date& item)
{
    int day;
    int month;
    int year;
    char ch;

    stream >> day >> ch >> month >> ch >> year;
    item.Set(day, month, year);

    return stream;
}


int CompareDates(const void* item1, const void* item2)
{
    return static_cast<const Date*>(item1)->CompareTo(*static_cast<const Date*>(item2));
}
