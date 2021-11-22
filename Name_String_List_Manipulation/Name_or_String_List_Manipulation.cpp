/*****************************************************************************************
    Name/String List/Array Manipulation
        - Demonstrates removing, adding, editing elements from array of string/names

    November 22, 2021

    Rosgen D. Hizer
    @Rokhai
*****************************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    const int arrayLength = 10;
    vector<string> names[arrayLength];
    string inputName, tempName;
    int choice;

    // 1st option/menu 
    menu_1:
        cout << "\n ===Name List Manipulation===" << endl;
        cout << "Menu: " << endl;
        cout << "1. Use Pre-set Names" << endl;
        cout << "2. Manually input a name" << endl;   
        cout << "\n0. Exit" << endl;
        cout << "\nChoose a number: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                names->push_back("Rokhai");
                names->push_back("Lawrence");
                names->push_back("Shelia");                
            break;

            case 2:
                cout << "\nInput a name: " << endl;
                for (int i = 0; i < 3; i++)
                {
                    cout << i << ". name: ";
                    cin >> inputName;
                    names->push_back(inputName);
                }
            break;

            case 0:
                cout << "Thank YOU!" << endl;
                exit(1);
            break;

            default:
                cout << "** Invalid input! **" << endl;
                goto menu_1;
            break;

        }
    // 2nd menu/option
    while (true)
    {
        cout << "\n\nMenu: " << endl;
        cout << "1. Show all name" << endl;
        cout << "2. Show all name (Sort as Ascending)" << endl;
        cout << "3. Show all name (Sort as Descending)" << endl;
        cout << "4. Add Item" << endl;
        cout << "5. Rename Item" << endl;
        cout << "6. Remove Item" << endl;
        cout << "\n0. Exit" << endl;
        cout << "\nChoose a number: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                system("cls");
                cout << "\n-- List of Names --" << endl;
                for (int i = 0; i < names->size(); i++)
                {
                    cout << i << ". " << names->at(i) << endl;
                }
            break;

            case 2:
                system("cls");
                cout << "\n-- List of Names Sort as Ascending --" << endl;
                for (int i = 0; i < names->size(); i++)
                {
                    for (int j = 0; j < names->size(); j++)
                    {
                        if (names->at(i) < names->at(j))
                        {
                            tempName = names->at(i);
                            names->at(i) = names->at(j);
                            names->at(j) = tempName;
                        }
                    }
                }
                for (int i = 0; i < names->size(); i++)
                {
                    cout << i << ". " << names->at(i) << endl;
                }
            break;

            case 3:
                system("cls");
                cout << "\n-- List of Names Sort as Descending --" << endl;
                for (int i = 0; i < names->size(); i++)
                {
                    for (int j = 0; j < names->size(); j++)
                    {
                        if (names->at(i) > names->at(j))
                        {
                            tempName = names->at(i);
                            names->at(i) = names->at(j);
                            names->at(j) = tempName;
                        }
                    }
                }
                for (int i = 0; i < names->size(); i++)
                {
                    cout << i << ". " << names->at(i) << endl;
                }
            break;

            case 4:
                system("cls");
                cout << "\n-- Add Item --" << endl;
                if (!(names->size() > arrayLength))
                {
                    cout << "\nEnter name: ";
                    cin >> inputName;
                    names->push_back(inputName);
                } else {
                    cout << "** Max List! **" << endl;
                }
            break;

            case 5:
                system("cls");
                cout << "\n-- Renames Item --" << endl;
                for (int i = 0; i < names->size(); i++)
                {
                    cout << i << ". " << names->at(i) << endl;
                }
                input_rename:
                    cout << "\nWhich name do you want to rename\n" 
                            << "Choose a number: ";
                    cin >> choice;
                    cout << "\nEnter name: ";
                    cin >> inputName; 
                    if (inputName != " ")
                        names->at(choice) = inputName;
                    else 
                        goto input_rename;
            break;

            case 6:
                system("cls");
                cout << "\n-- Remove Item --" << endl;
                for (int i = 0; i < names->size(); i++)
                {
                    cout << i << ". " << names->at(i) << endl;
                }
                input_remove:
                    cout << "\nWhich name do you want to remove\n" 
                            << "Choose a number: ";
                    cin >> choice;
                    if (choice >= 0 && choice <= names->size())
                        if (choice == 0)
                            names->erase(names->begin() + 0);
                        else
                            names->erase(names->begin() + choice);
                    else 
                        goto input_remove;
            break;

            case 0:
                cout << "Thank YOU!" << endl;
                exit(1);
            break;

            default:
                cout << "\n** Invalid input!" << endl;
            break;
        }

    }

    return 0;
}