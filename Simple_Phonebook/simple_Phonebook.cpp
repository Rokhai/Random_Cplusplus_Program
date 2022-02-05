/*
    Simple Phonebook

    Showcasing (CRUD) i guess, using array as container
    with basic UI/UX feels

    February 05, 2022

    Rosgen D. Hizer
    @Rokhai
*/


// Return Func in Rename Adding contact
// Change postion in remove and rename contact.

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>

using namespace std;

void color (int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x, int y)
{
    COORD coordinate;
    coordinate.X = x;
    coordinate.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}

namespace phonebook
{
    vector<string> name[10];
    vector<string> number[10];

} // namespace phonebook

void defaultContactsSample()
{   
    phonebook::name->push_back("Rokhai");
    phonebook::number->push_back("123-4567-8901");
    phonebook::name->push_back("Xai");
    phonebook::number->push_back("123-4567-8901");
}


void contactList()
{
    system("cls");
    gotoxy(60,5);
    cout << "Contact List:" << endl;

    gotoxy(55, 7);
    cout << "\t- Name -";
    for (int i = 0; i < (phonebook::name->size()); i++)
    {   gotoxy(55, 9+i);
        cout << i+1 << ".  " << phonebook::name->at(i);
    }

    gotoxy(75, 7);
    cout << "\t- Phone Number -";
    for (int i = 0; i < (phonebook::number->size()); i++)
    {
        gotoxy(80, 9+i);
        cout << phonebook::number->at(i);
    }
}

// A-Z Sort
void atoz()
{
    string tempName, tempNumber;

    for (int i = 0; i < (phonebook::name->size()); i++)
    {
        for (int j = 0; j < (phonebook::name->size()); j++)
        {
            if (phonebook::name->at(i) < phonebook::name->at(j))
            {
                tempName = phonebook::name->at(i);
                tempNumber = phonebook::number->at(i);

                phonebook::name->at(i) = phonebook::name->at(j);
                phonebook::number->at(i) = phonebook::number->at(j);

                phonebook::name->at(j) = tempName;
                phonebook::number->at(j) = tempNumber;
            }
        }
    }
}

// Z-A Sort
void ztoa()
{
    string tempName, tempNumber;
    for (int i = 0; i < (phonebook::name->size()); i++)
    {
        for (int j = 0; j < (phonebook::name->size()); j++)
        {
            if (phonebook::name->at(i) > phonebook::name->at(j))
            {
                tempName = phonebook::name->at(i);
                tempNumber = phonebook::number->at(i);

                phonebook::name->at(i) = phonebook::name->at(j);
                phonebook::number->at(i) = phonebook::number->at(j);

                phonebook::name->at(j) = tempName;
                phonebook::number->at(j) = tempNumber;
            }
        }
    }
}

// Contact Sort Menu Interface
void contactSort()
{
    string tempName, tempNumber;
    char key;
    for (int i = 0;;)
    {
        contactList();

        gotoxy(55, 3);
        cout << "> Press number key to choose in option <";
    
        gotoxy(55,5);
        cout << "Sort Contact List: " << endl;

        gotoxy(85,5);
        cout << "[1] A-Z";

        gotoxy(95,5);
        cout << "[2] Z-A";

        gotoxy(105,5);
        cout << "[0] Return";

        key = _getch();

        // A-Z Sort
        if (key == '1')
        {
            atoz();
        }
        // Z-A Sort
        if (key == '2')
        {
            ztoa();
        }
        // Return to menu
        if (key == '0') break;    
    }
}

//check the string if there's or not alpha-numeric characters
bool isWhiteSpace(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (!(isspace(s[i])))
            return false;
    }

    return true;
}

void addContact()
{
    system("cls");
    string s = " ";

    // border-frame
    for (int i = 45; i <= 85; i++)
    {
        gotoxy(i, 3);
        cout << '*';
        gotoxy(i, 10);
        cout << '*';
    }
    // border-frame

    if (phonebook::name->size() < 10)
    {
        gotoxy(60,5);
        cout << "New Contact";

        do
        {
            gotoxy(55, 7);
            cout << "Enter name: ";
            getline(cin, s);
        } while (isWhiteSpace(s));
        
        phonebook::name->push_back(s);

        do
        {
            gotoxy(55, 8);
            cout << "Enter number: ";
            getline(cin, s);
        } while (isWhiteSpace(s));
        
        phonebook::number->push_back(s);

    } else {
        gotoxy(52, 6);
        cout << "[** Insufficient Space **]";
    }

    cin.clear();
}

void renameContact()
{
    int choice;
    string s;

    do
    {
        contactList();
        // border-frame
        for (int i = 55; i <= 102; i++)
        {
            gotoxy(i, 20);
            cout << "*";
            gotoxy(i, 27);
            cout << "*";
        }
        // border-frame
        gotoxy(53, 3);
        cout << "> Enter the number of contact you want to rename <";

        gotoxy(63, 22);
        cout << "Enter number between (1 - " << phonebook::name->size() << "): ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore();        
        }
    } while (!(choice >= 1 && choice <= phonebook::name->size()));
    
    do
    {
        gotoxy(63, 24);
        cout << "Enter new name: ";
        getline(cin, s);
    } while (isWhiteSpace(s));
    
    phonebook::name->at(choice-1).assign(s);

    do
    {
        gotoxy(63, 25);
        cout << "Enter new number: ";
        getline(cin, s);
    } while (isWhiteSpace(s));
    
    phonebook::number->at(choice-1).assign(s);

}

void removeContact()
{
    string tempName, tempNumber;
    int choice;

    do
    {
        contactList();
        // border-frame
        for (int i = 55; i <= 102; i++)
        {
            gotoxy(i, 20);
            cout << "*";
            gotoxy(i, 27);
            cout << "*";
        }
        // border-frame
        gotoxy(55, 3);
        cout << "> Enter the number of contact you want to remove <";

        gotoxy(63, 22);
        cout << "Enter number between (1 - " << phonebook::name->size() << "): ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore();       
        }

    } while (!(choice >= 0 && choice <= phonebook::name->size()));

    phonebook::name->at(choice-1).erase();
    phonebook::number->at(choice-1).erase();

    ztoa();

    phonebook::name->pop_back();
    phonebook::number->pop_back();

    atoz();
}

void border(bool _to_animate)
{
    color(7);
    if (_to_animate)
    {
        gotoxy(3, 3);
        cout << "+"; // upper left corner

        for (int i = 4; i <= 35; i++)
        {
            gotoxy(i, 3);
            color(7);
            cout << "-";
            Sleep(20);
        }

        gotoxy(36, 3);
        cout << "+"; // upper right corner

        for (int i = 4; i <= 13; i++)
        {
            gotoxy(36, i);
            cout << "|";
            Sleep(20);
        }

        gotoxy(36, 14);
        cout << "+"; // lower right corner

        for (int i = 35; i >= 3; i--)
        {
            gotoxy(i, 14);
            cout << "-";
            Sleep(20);
        }

        gotoxy(3, 14);
        cout << "+"; // lower left corner

        for (int i = 13; i >=4; i--)
        {
            gotoxy(3, i);
            cout << "|";
            Sleep(20);
        }

    } else {
        gotoxy(3, 3);
        cout << "+"; // upper left corner

        for (int i = 4; i <= 35; i++)
        {
            gotoxy(i, 3);
            color(7);
            cout << "-";
        }

        gotoxy(36, 3);
        cout << "+"; // upper right corner

        for (int i = 4; i <= 13; i++)
        {
            gotoxy(36, i);
            cout << "|";
        }

        gotoxy(36, 14);
        cout << "+"; // lower right corner

        for (int i = 35; i >= 3; i--)
        {
            gotoxy(i, 14);
            cout << "-";
        }

        gotoxy(3, 14);
        cout << "+"; // lower left corner

        for (int i = 13; i >=4; i--)
        {
            gotoxy(3, i);
            cout << "|";
        }
    }
}

int menu()
{
    
    int Set[] = {7, 7, 7, 7, 7, 7}; // Default Color White
    static int counter = 1;
    static bool _to_animateFrame = false;
    char key;

    border(_to_animateFrame);
    _to_animateFrame = false;

    for (int i = 0;;)
    {

        // Instruction
        gotoxy(1, 1);
        color(7);
        cout << "> Press \'W\' and \'S\' key to choose, Press enter to confirm <";

        gotoxy(10, 5);
        cout << "Contacts: " << phonebook::name->size() << "/" << 10;

        gotoxy(10, 7);
        color(Set[0]);
        cout << "1. List All Contacts";

        gotoxy(10, 8);
        color(Set[1]);
        cout << "2. Sort";

        gotoxy(10, 9);
        color(Set[2]);
        cout << "3. Add Contact";

        gotoxy(10, 10);
        color(Set[3]);
        cout << "4. Rename Contact";

        gotoxy(10, 11);
        color(Set[4]);
        cout << "5. Remove Contact";

        gotoxy(10, 12);
        color(Set[5]);
        cout << "6. Exit";

        
        key = _getch();

        if (key == 'w' && (counter >= 2 && counter <= 6)) counter--; // Up
        if (key == 's' && (counter >=1 && counter <= 5)) counter++; // Down
        if (key == '\r') break; // return == enter

        for (int i = 0; i < 6; i++) Set[i] = 7; // it will default all item into white color

        Set[counter-1] = 9; // it will set the selected item into light blue color which is 9

    }

    return counter;
}


int main()
{
    
    defaultContactsSample();
    system("cls");
    //border();
    while (true)
    {
        switch(menu())
        {
            case 1:
                contactList();
            break;

            case 2:
                contactSort();
            break;

            case 3:
                addContact();
            break;
            
            case 4:
                renameContact();
            break;
            
            case 5:
                removeContact();
            break;

            case 6:
                exit(1);
            break;
        }
    }

    return 0;
}