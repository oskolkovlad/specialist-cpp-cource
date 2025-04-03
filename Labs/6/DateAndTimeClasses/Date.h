#pragma once

#include <iostream>
#include <format>
#include "IoOperations.h"

using std::cin;
using std::cout;
using std::endl;
using std::format;
using std::ostream;
using std::istream;

class Date
{
private:
    int Day;
    int Month;
    int Year;

    bool IsYearLeap(int year);
    int GetDayUpperBound(int month, int year);
    int CompareTo(const Date& item) const;

public:
    Date();
    Date(int day, int month, int year) : Day(day), Month(month), Year(year) { }

    inline int GetDay() const { return Day; }
    inline int GetMonth() const { return Month; }
    inline int GetYear() const { return Year; }

    void Set(int day, int month, int year);
    void Read();
    void Print(bool withEndl = true) const;

    inline bool Equal(const Date& item) const { return CompareTo(item) == 0; }
    inline bool Less(const Date& item) const { return CompareTo(item) == -1; }
    inline bool Greater(const Date& item) const { return CompareTo(item) == 1; }

    bool operator ==(const Date& item);
    bool operator !=(const Date& item);
    bool operator >(const Date& item);
    bool operator >=(const Date& item);
    bool operator <(const Date& item);
    bool operator <=(const Date& item);

    friend int CompareDates(const void* item1, const void* item2);
};

ostream& operator <<(ostream& stream, const Date& item);
istream& operator >>(istream& stream, Date& item);

int CompareDates(const void* item1, const void* item2);
