/****************************************
    Number Sorting without Loop Statements
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

    start:

    static int lengthOfArray = 10;
    int randomNumbers[lengthOfArray];
    int iChoose;
    int tempNumber;
    int i = 0, j = 0;

    char yesOrNo;

    start_loop_1:
        randomNumbers[i] = (rand() % 100 + 1);
            if (i != lengthOfArray-1) { i++; goto start_loop_1;}

    i = 0; // resets the value of i into 0

    cout << "\nRandom Generated  Number List:" << endl;
    start_loop_2:
        cout << randomNumbers[i] << ", ";
             if (i != lengthOfArray-1) { i++; goto start_loop_2;}

    start_loop_menu:
        cout << "\nMenu: " << endl;
        cout << "1. Sort (Ascending)" << endl;
        cout << "2. Sort (Descending)" << endl;
        cout << "\n0. Quit" << endl;

        cout << "\nChoose number in menu: ";
        cin >> iChoose;

        switch (iChoose)
        {

            case 1:
                main_ascending_loop:
                    i = 0; // resets the value
                    start_loop_ascending:
                        j = i+1;
                        start_loop_ascending_inner:
                            if (j < lengthOfArray && randomNumbers[i] > randomNumbers[j])
                            {
                                tempNumber = randomNumbers[i];
                                randomNumbers[i] = randomNumbers[j];
                                randomNumbers[j] = tempNumber;
                                j++;
                                goto start_loop_ascending_inner;

                            } else if (j < lengthOfArray && randomNumbers[i] < randomNumbers[j]) {
                               j++;
                               goto start_loop_ascending_inner;
                            }

                        if (i < lengthOfArray)
                        {
                            i++;
                            goto start_loop_ascending;
                        }

                i = 0;

                cout << "Sorted Ascending: " << endl;
                start_loop_display_ascending:
                   
                    if (i != lengthOfArray)
                    {
                        cout << randomNumbers[i] << ", ";
                        i++;
                        goto start_loop_display_ascending;
                    }
            break;

            case 2:
                main_descending_loop:
                    i = 0; // resets the value
                    start_loop_descending:
                        j = i+1;
                        start_loop_descending_inner:
                            if (j < lengthOfArray && randomNumbers[i] < randomNumbers[j])
                            {
                                tempNumber = randomNumbers[i];
                                randomNumbers[i] = randomNumbers[j];
                                randomNumbers[j] = tempNumber;
                                j++;
                                goto start_loop_descending_inner;

                            } else if (j < lengthOfArray && randomNumbers[i] > randomNumbers[j]) {
                               j++;
                               goto start_loop_descending_inner;
                            }

                        if (i < lengthOfArray)
                        {
                            i++;
                            goto start_loop_descending;
                        }

                i = 0;

                cout << "Sorted Descending: " << endl;
                start_loop_display_descending:
                   
                    if (i != lengthOfArray)
                    {
                        cout << randomNumbers[i] << ", ";
                        i++;
                        goto start_loop_display_descending;
                    }
            break;

            case 0:
                cout << "Thank You!!" << endl;
                exit(1);
            break;

            default:
                cout << "Invalid input!!" << endl;
                goto start_loop_menu;
            break;
        }

    yesNoAgain:
        cout << "\nWant to try again (y/n): ";
        cin >> yesOrNo;

        if (isalpha(yesOrNo) && tolower(yesOrNo) == 'y')
        {
            system("cls");
            goto start;
        } else if (isalpha(yesOrNo) && tolower(yesOrNo) == 'n') {
            system("cls");
            cout << "Thank YOU!" << endl;
            exit(1);
        } else {
            system("cls");
            cout << "Invalid input!" << endl;
            goto yesNoAgain;
        }

    return 0;
}