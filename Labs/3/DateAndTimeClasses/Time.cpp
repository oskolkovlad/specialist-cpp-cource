#include "Time.h"

Time::Time()
{
    time_t raw_time;
    time(&raw_time);

    tm localtime;
    localtime_s(&localtime, &raw_time);

    Set(localtime.tm_hour, localtime.tm_min, localtime.tm_sec);
}


int Time::CompareTo(const Time& item) const {
    if (this->Hour == item.Hour)
    {
        if (this->Minute == item.Minute)
        {
            if (this->Second == item.Second)
            {
                return 0;
            }

            return this->Second > item.Second ? 1 : -1;
        }

        return this->Minute > item.Minute ? 1 : -1;
    }

    return this->Hour > item.Hour ? 1 : -1;
}


void Time::Set(int hour, int minute, int second)
{
    if (hour >= 0 && hour <= 23)
        Hour = hour;

    if (minute >= 0 && minute <= 59)
        Minute = minute;

    if (second >= 0 && second <= 59)
        Second = second;
}

void Time::Read()
{
    int hour = ReadValue("час", 0, 23);
    int minute = ReadValue("минуты", 0, 59);
    //int second = ReadValue("секунды", 0, 59);

    Set(hour, minute/*, second*/);

    cout << endl;
}

void Time::Print(bool withEndl) const
{
    //  лючевое слово "this", можно опустить, но используем его, чтобы отработать материал.

    cout << format("{:02}:{:02}:{:02}", this->Hour, this->Minute, this->Second);

    if (withEndl)
    {
        cout << endl << endl;
    }
}

int CompareTimes(const void* item1, const void* item2)
{
    return static_cast<const Time*>(item1)->CompareTo(*static_cast<const Time*>(item2));
}
