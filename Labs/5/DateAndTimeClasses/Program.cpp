#include <cstdlib>
#include "Date.h"
#include "Time.h"

using std::boolalpha;

// В рамках данного проекта реализована лабораторная работа по модулю 3.

inline void CheckDate()
{
    Date* datePointer1 = new Date;
    Date* datePointer2 = new Date(31, 3, 2025);

    Date date1 = *datePointer1;
    Date date2 = *datePointer2;

    date1.Print(false);
    cout << "; ";
    date2.Print(false);
    cout << endl << endl;

    cout << boolalpha;

    date1.Print(false);
    cout << " == ";
    date2.Print(false);
    cout << " = ";
    cout << (date1 == date2) << endl;

    date1.Print(false);
    cout << " != ";
    date2.Print(false);
    cout << " = ";
    cout << (date1 != date2) << endl;

    date1.Print(false);
    cout << " > ";
    date2.Print(false);
    cout << " = ";
    cout << (date1 > date2) << endl;

    date1.Print(false);
    cout << " >= ";
    date2.Print(false);
    cout << " = ";
    cout << (date1 >= date2) << endl;

    date1.Print(false);
    cout << " < ";
    date2.Print(false);
    cout << " = ";
    cout << (date1 < date2) << endl;

    date1.Print(false);
    cout << " <= ";
    date2.Print(false);
    cout << " = ";
    cout << (date1 <= date2) << endl << endl << endl << endl;

    delete datePointer1;
    delete datePointer2;
}

inline void CheckTime()
{
    Time* timePointer1 = new Time;
    Time* timePointer2 = new Time(10, 0);

    Time time1 = *timePointer1;
    Time time2 = *timePointer2;

    time1.Print(false);
    cout << "; ";
    time2.Print(false);
    cout << endl << endl;

    cout << boolalpha;

    time1.Print(false);
    cout << " == ";
    time2.Print(false);
    cout << " = ";
    cout << (time1 == time2) << endl;

    time1.Print(false);
    cout << " != ";
    time2.Print(false);
    cout << " = ";
    cout << (time1 != time2) << endl;

    time1.Print(false);
    cout << " > ";
    time2.Print(false);
    cout << " = ";
    cout << (time1 > time2) << endl;

    time1.Print(false);
    cout << " >= ";
    time2.Print(false);
    cout << " = ";
    cout << (time1 >= time2) << endl;

    time1.Print(false);
    cout << " < ";
    time2.Print(false);
    cout << " = ";
    cout << (time1 < time2) << endl;

    time1.Print(false);
    cout << " <= ";
    time2.Print(false);
    cout << " = ";
    cout << (time1 <= time2) << endl << endl << endl << endl;

    delete timePointer1;
    delete timePointer2;
}

int main()
{
    system("chcp 1251 > nul");

    CheckDate();
    CheckTime();
}
