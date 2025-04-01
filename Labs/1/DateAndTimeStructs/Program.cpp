#include <cstdlib>
#include "IoOperations.h"
#include "CompareOperations.h"

// ¬ рамках данного проекта реализовано две задачи: 1.1 и 1.2.

inline void CheckDate()
{
    Date date1 = { 0, 0, 0 };
    Read(date1);
    Print(date1);

    Date date2 = { 0, 0, 0 };
    Read(date2);
    Print(date2);

    if (Equal(date1, date2))
    {
        Print(date1, false);
        cout << " равна ";
        Print(date2, false);
        cout << endl << endl;
    }

    if (Less(date1, date2))
    {
        Print(date1, false);
        cout << " меньше, чем ";
        Print(date2, false);
        cout << endl << endl;
    }

    if (Grater(date1, date2))
    {
        Print(date1, false);
        cout << " больше, чем ";
        Print(date2, false);
        cout << endl << endl;
    }
}

inline void CheckTime()
{
    Time time1 = { 0, 0, 0 };
    Read(time1);
    Print(time1);

    Time time2 = { 0, 0, 0 };
    Read(time2);
    Print(time2);

    if (Equal(time1, time2))
    {
        Print(time1, false);
        cout << " равно ";
        Print(time2, false);
        cout << endl << endl;
    }

    if (Less(time1, time2))
    {
        Print(time1, false);
        cout << " меньше, чем ";
        Print(time2, false);
        cout << endl << endl;
    }

    if (Grater(time1, time2))
    {
        Print(time1, false);
        cout << " больше, чем ";
        Print(time2, false);
        cout << endl << endl;
    }
}

int main()
{
    system("chcp 1251 > nul");

    CheckDate();
    CheckTime();
}
