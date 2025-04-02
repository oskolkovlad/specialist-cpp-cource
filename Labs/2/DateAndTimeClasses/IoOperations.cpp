#include "IoOperations.h"

int ReadValue(const char* entityName, int lowerBound, int upperBound)
{
    int value;
    bool condition = true;

    do
    {
        cout << "������� " << entityName << " (�� " << lowerBound << " �� " << upperBound << "): ";
        cin >> value;

        if (value >= lowerBound && value <= upperBound)
        {
            condition = false;
        }
        else
        {
            cout << "������� ������������ ��������! ";
        }

    } while (condition);

    return value;
}
