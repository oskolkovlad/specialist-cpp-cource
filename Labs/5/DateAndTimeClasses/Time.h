#pragma once

#include <iostream>
#include <format>
#include "IoOperations.h"

using std::cin;
using std::cout;
using std::endl;
using std::format;

class Time
{
private:
    int Hour;
    int Minute;
    int Second;

    int CompareTo(const Time& item) const;

public:
    Time();
    Time(int hour, int minute) : Time(hour, minute, 0) { }
    //Time(int hour, int minute, int second = 0) : Hour(hour), Minute(minute), Second(second) { } - или можно так.
    Time(int hour, int minute, int second) : Hour(hour), Minute(minute), Second(second) { }

    inline int GetHour() const { return Hour; }
    inline int GetMinute() const { return Minute; }
    inline int GetSecond() const { return Second; }

    void Set(int hour, int minute, int second = 0);
    void Read();
    void Print(bool withEndl = true) const;

    inline bool Equal(const Time& item) const { return CompareTo(item) == 0; }
    inline bool Less(const Time& item) const { return CompareTo(item) == -1; }
    inline bool Greater(const Time& item) const { return CompareTo(item) == 1; }

    friend int CompareTimes(const void* item1, const void* item2);
};

bool operator ==(const Time& item1, const Time& item2);
bool operator !=(const Time& item1, const Time& item2);
bool operator >(const Time& item1, const Time& item2);
bool operator >=(const Time& item1, const Time& item2);
bool operator <(const Time& item1, const Time& item2);
bool operator <=(const Time& item1, const Time& item2);


int CompareTimes(const void* item1, const void* item2);