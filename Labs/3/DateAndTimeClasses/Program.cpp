#include <cstdlib>
#include "Date.h"
#include "Time.h"

// В рамках данного проекта реализована лабораторная работа по модулю 3.

inline void CheckDate()
{
    Date* datePointer1 = new Date;
    Date* datePointer2 = new Date(1, 4, 2025);

    datePointer1->Print(false);
    cout << endl;
    datePointer2->Print(false);

    cout << endl << endl;

    delete datePointer1;
    delete datePointer2;
}

inline void CheckTime()
{
    Time* timePointer1 = new Time;
    Time* timePointer2 = new Time(20, 30, 57);

    timePointer1->Print(false);
    cout << endl;
    timePointer2->Print(false);

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
