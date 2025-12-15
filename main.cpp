#include <iostream>
#include <windows.h>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
  

    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);


    // 1. Введення та ініціалізація даних

    const int SIZE = 14;
    double A[SIZE];

    srand(time(0));

    for (int i = 0; i < SIZE; i++)
    {
        A[i] = -20 + rand() % 41;
    }

    cout << "Початковий масив: [ ";
    for (int i = 0; i < SIZE; i++)
    {
        cout << A[i] << (i < SIZE - 1 ? ", " : "");
    }
    cout << " ]" << endl;

    
    // 2. Аналітична обробка масиву

    double sumNeg = 0, sumPos = 0;
    int countNeg = 0, countPos = 0;

    for (int i = 0; i < SIZE; i++)
    {
        if (A[i] < 0)
        {
            sumNeg += A[i];
            countNeg++;
        }
        else if (A[i] > 0)
        {
            sumPos += A[i];
            countPos++;
        }
    }

    double mean_negative = (countNeg > 0) ? sumNeg / countNeg : 1;
    double mean_positive = (countPos > 0) ? sumPos / countPos : 0;

    
    // 3. Логічна обробка масиву

    bool allNeg = true, allPos = true;

    for (int i = 0; i < SIZE; i++)
    {
        if (A[i] >= 0)
            allNeg = false;
        if (A[i] <= 0)
            allPos = false;
    }

    if (allNeg)
    {
        for (int i = 0; i < SIZE; i++)
            A[i] = 0;
    }
    else if (allPos)
    {
        for (int i = 0; i < SIZE; i++)
            A[i] = 1;
    }
    else
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (i % 2 == 0 && A[i] < 0)
                A[i] = mean_negative;
            else if (i % 2 == 1)
                A[i] = mean_positive;
        }
    }

    
    // 4. Виведення результатів та перевірка
    
    cout << "Перетворений масив: [ ";
    for (int i = 0; i < SIZE; i++)
    {
        cout << A[i] << (i < SIZE - 1 ? ", " : "");
    }
    cout << " ]" << endl;

    cout << "mean_negative = " << mean_negative << endl;
    cout << "mean_positive = " << mean_positive << endl;

    return 0;
}
