#include "IoOperations.h"

int ReadValue(const char* entityName, int lowerBound, int upperBound)
{
    int value;
    bool condition = true;

    do
    {
        cout << "¬ведите " << entityName << " (от " << lowerBound << " до " << upperBound << "): ";
        cin >> value;

        if (value >= lowerBound && value <= upperBound)
        {
            condition = false;
        }
        else
        {
            cout << "¬ведено некорректное значение! ";
        }

    } while (condition);

    return value;
}
