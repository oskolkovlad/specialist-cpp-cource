#include <cstdlib>
#include <fstream>
#include "Date.h"
#include "Time.h"

using std::boolalpha;
using std::ofstream;
using std::ifstream;
using std::ios;

// В рамках данного проекта реализована лабораторная работа по модулю 6.

inline void CheckDate()
{
    Date* datePointer1 = new Date;
    Date* datePointer2 = new Date(31, 3, 2025);

    Date date1 = *datePointer1;
    Date date2 = *datePointer2;

    cout << date1 << "; " << date2 << endl;
    cin >> date1;
    cout << date1 << "; " << date2 << endl;

    Date dates[2] = { date1, date2 };

    int datesLength = sizeof(dates) / sizeof(Date);
    qsort(dates, datesLength, sizeof(Date), CompareDates);

    ofstream outStream ("Dates.txt");

    for (int index = 0; index < datesLength; index++)
    {
        outStream << dates[index];

        if (index != datesLength - 1)
        {
            outStream << endl;
        }
    }

    outStream.close();

    ifstream inStream("Dates.txt", ios::in);

    while (!inStream.eof())
    {
        Date item;

        inStream >> item;
        cout << item << endl;
    }

    inStream.close();

    cout << endl << endl << endl;

    delete datePointer1;
    delete datePointer2;
}

inline void CheckTime()
{
    Time* timePointer1 = new Time;
    Time* timePointer2 = new Time(10, 0);

    Time time1 = *timePointer1;
    Time time2 = *timePointer2;

    cout << time1 << "; " << time2 << endl;
    cin >> time1;
    cout << time1 << "; " << time2 << endl;

    Time times[2] = { time1, time2 };

    int timesLength = sizeof(times) / sizeof(Time);
    qsort(times, timesLength, sizeof(Time), CompareTimes);

    ofstream outStream("Times.txt");

    for (int index = 0; index < timesLength; index++)
    {
        outStream << times[index];

        if (index != timesLength - 1)
        {
            outStream << endl;
        }
    }

    outStream.close();

    ifstream inStream("Times.txt", ios::in);

    while (!inStream.eof())
    {
        Time item;

        inStream >> item;
        cout << item << endl;
    }

    inStream.close();

    cout << endl << endl << endl;

    delete timePointer1;
    delete timePointer2;
}

int main()
{
    system("chcp 1251 > nul");

    CheckDate();
    CheckTime();
}
