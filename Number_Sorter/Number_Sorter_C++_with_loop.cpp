/****************************************
    Number Sorting with Loop Statements
    November 15, 2021

    Rosgen D. Hizer

    @Rokhai
****************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));

    const int arrayLength = 10;
    int numberList[arrayLength];
    int tempNumber;
    int iChoose = 1;

    cout << "\nRandom Number Generated List: " << endl;
    for (int i = 0; i < arrayLength; i++)
    {
        numberList[i] = (rand() % 100) + 1;  
        cout << numberList[i] << ", ";
    }

    while (iChoose != 0)
    {
        cout << "\n\nMenu: " << endl;
        cout << "1. Sort (Ascending)" << endl;
        cout << "2. Sort (Descending)" << endl;
        cout << "\n0. Quit" << endl;

        cout << "\nChoose: ";
        cin >> iChoose;

        switch (iChoose)
        {
            case 1:
                for(int i = 0; i < arrayLength; i++)
                {
                    for (int j = i+1; j < arrayLength; j++)
                    {
                        if (numberList[i] > numberList[j])
                        {
                            tempNumber = numberList[i];
                            numberList[i] = numberList[j];
                            numberList[j] = tempNumber;
                        }
                    }
                }
                cout << "Ascending Sorted Number: " << endl;
                for (int i = 0; i < arrayLength; i++)
                {
                    cout << numberList[i] << ", ";
                }

                
            break;

            case 2:
                for(int i = 0; i < arrayLength; i++)
                {
                    for (int j = i+1; j < arrayLength; j++)
                    {
                        if (numberList[i] < numberList[j])
                        {
                            tempNumber = numberList[i];
                            numberList[i] = numberList[j];
                            numberList[j] = tempNumber;
                        }
                    }
                }
                cout << "Descending Sorted Number: " << endl;
                for (int i = 0; i < arrayLength; i++)
                {
                    cout << numberList[i] << ", ";
                }
            break;

            case 0:
                cout << "\nThank you!" << endl;
                exit(1);
            break;

            default:
                cout << "\nInvalid input!" << endl;
            break;

        }
    }


    return 0;
}