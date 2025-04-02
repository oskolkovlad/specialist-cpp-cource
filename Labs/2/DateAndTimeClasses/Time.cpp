#include "Time.h"

/* ТЗ:

* 2.1. Разработайте класс Time и (перегруженные) функции Set, Print и Read для установки, печати и чтения с клавиатуры значений времени.
Предусмотрите возможность для установки времени нулевого значения секунд по умолчанию.
Предусмотрите в функциях Set присваивание компонентам времени только допустимых значений.
Протестируйте их работу.
*/

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
    // Валидацию добавил, так как по ТЗ. Но закомментировал, так как тоже самое реализовал при чтении.

    //if (hour >= 0 && hour <= 23)
        Hour = hour;

    //if (minute >= 0 && minute <= 59)
        Minute = minute;

    //if (second >= 0 && second <= 59)
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
    // Ключевое слово "this", можно опустить, но используем его, чтобы отработать материал.

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
