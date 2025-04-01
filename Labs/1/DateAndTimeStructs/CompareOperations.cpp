#include "CompareOperations.h"

/* ��:

* 1.2. � ���������� � ������ 1.1 ������������ (�������������) ������� Equal, Less � Grater ��� ���������� ��������� ������, ������� � ������� �������� ���� � �������.
������������� �� ������.
*/

bool Equal(const Date& item1, const Date& item2)
{
	return item1.Year == item2.Year && item1.Month == item2.Month && item1.Day == item2.Day;
}

bool Equal(const Time& item1, const Time& item2)
{
	return item1.Hour == item2.Hour && item1.Minute == item2.Minute && item1.Second == item2.Second;
}

bool Less(const Date& item1, const Date& item2)
{
	if (item1.Year != item2.Year)
		return item1.Year < item2.Year;

	if (item1.Month != item2.Month)
		return item1.Month < item2.Month;

	return item1.Day < item2.Day;
}

bool Less(const Time& item1, const Time& item2)
{
	if (item1.Hour != item2.Hour)
		return item1.Hour < item2.Hour;

	if (item1.Minute != item2.Minute)
		return item1.Minute < item2.Minute;

	return item1.Second < item2.Second;
}

bool Grater(const Date& item1, const Date& item2)
{
	return Less(item2, item1);
}

bool Grater(const Time& item1, const Time& item2)
{
	return Less(item2, item1);
}
