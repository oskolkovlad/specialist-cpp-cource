#include <cstdlib>
#include "Date.h"
#include "Time.h"

// В рамках данного проекта реализована лабораторная работа по модулю 2.

inline void CheckDate()
{
    Date* datePointer1 = new Date;
    datePointer1->Read();
    datePointer1->Print();

    Date* datePointer2 = new Date;
    datePointer2->Read();
    datePointer2->Print();

    Date date1 = *datePointer1;
    Date date2 = *datePointer2;

    if (date1.Equal(date2))
    {
        date1.Print(false);
        cout << " равна ";
        date2.Print(false);
        cout << endl << endl;
    }

    if (date1.Less(date2))
    {
        date1.Print(false);
        cout << " меньше, чем ";
        date2.Print(false);
        cout << endl << endl;
    }

    if (date1.Greater(date2))
    {
        date1.Print(false);
        cout << " больше, чем ";
        date2.Print(false);
        cout << endl << endl;
    }

    Date dates[2] = { date1, date2 };
    qsort(dates, 2, sizeof(Date), CompareDates);

    cout << "Отсортированный массив: ";

    for (int index = 0; index < 2; index++)
    {
        dates[index].Print(false);
        cout << "; ";
    }

    cout << endl << endl;

    delete datePointer1;
    delete datePointer2;
}

inline void CheckTime()
{
    Time* timePointer1 = new Time;
    timePointer1->Read();
    timePointer1->Print();

    Time* timePointer2 = new Time;
    timePointer2->Read();
    timePointer2->Print();

    Time time1 = *timePointer1;
    Time time2 = *timePointer2;

    if (time1.Equal(time2))
    {
        time1.Print(false);
        cout << " равна ";
        time2.Print(false);
        cout << endl << endl;
    }

    if (time1.Less(time2))
    {
        time1.Print(false);
        cout << " меньше, чем ";
        time2.Print(false);
        cout << endl << endl;
    }

    if (time1.Greater(time2))
    {
        time1.Print(false);
        cout << " больше, чем ";
        time2.Print(false);
        cout << endl << endl;
    }

    Time times[2] = { time1, time2 };
    qsort(times, 2, sizeof(Time), CompareTimes);

    cout << "Отсортированный массив: ";

    for (int index = 0; index < 2; index++)
    {
        times[index].Print(false);
        cout << "; ";
    }

    cout << endl << endl;

    delete timePointer1;
    delete timePointer2;
}

int main()
{
    system("chcp 1251 > nul");

    CheckDate();
    CheckTime();
}
