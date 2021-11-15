/*
=====================================
    Number Guessing Game
    October 30, 2021

    Rosgen D. Hizer

    @Rokhai
=====================================
*/ 

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function that checks if player want to try again
bool tryAgain(void)
{
    char yesOrNo;
    labelAskAgain:
    cout << "\nWant to roll again? (y/n): ";
    cin >> yesOrNo;
    yesOrNo = tolower(yesOrNo);
    if(yesOrNo == 'y')
    {
        return true;
    } else if (yesOrNo == 'n') {
        cout << "\nThank You for playing!" << endl;
        return false;
    } else {
        cout << "** Invalid input! **" << endl;
        goto labelAskAgain;
    }
}

int main()
{

    srand(time(0));

    int numberOfWin = 0;
    int numberOfLose = 0;
    
    labelStart: // label for restarting game
        system("cls");
        int randomNumber = (rand() % 100) + 1;
        int inputResponse = 0;
        int numberOfTries = 5;
        int maxRangeNumber = 100;

        int iChoose;
        
        /*
            Modified Number Guessing Game
                As is the instruction or feature display
            
            Uncomment this code of block below.
        */
        // cout << "\n\t*** Welcome to Modified Guessing Game ***" << endl;
        // cout << "\n\nMenu:\n" << endl;
        // cout << "1\t Easy (You have 3 life, you need to guess number between 1 and 10)" << endl;
        // cout << "2\t Medium (You have 5 life, you need to guess number between 1 and 50)" << endl;
        // cout << "3\t Hard (You have 7 life, you need to guess number between 1 and 100)" << endl;
        // cout << "\n0\tExit" << endl;
        // cout << "\nChoose --->: ";
        // cin >> iChoose;

        // switch (iChoose)
        // {
        //     case 1:
        //         randomNumber = (rand() % 10) + 1;
        //         numberOfTries = 3;
        //         maxRangeNumber = 10;
        //         system("cls");
        //     break;
        //     case 2:
        //         randomNumber = (rand() % 50) + 1;
        //         numberOfTries = 5;
        //         maxRangeNumber = 50;
        //         system("cls");
        //     break;
        //     case 3:
        //         randomNumber = (rand() % 100) + 1;
        //         numberOfTries = 7;
        //         maxRangeNumber = 100;
        //         system("cls");
        //     break;
        //     case 0:
        //         cout << "\nGoodbye!, Thanks for Playing. <3<3" << endl;
        //         exit(1);
        //     break;

        //     default:
        //         cout << "There's no such choice in menu!" << endl;
        //         goto labelStart;
        //     break;
        // }

        labelInputAgain: // label for input a response again
        
            /*
            ======================================================================================================================================
            - Outer if checks if there's remaining tries(numberOfTries > 0 ), then it prompt to input a response(or guess)
                - then it check if the inputResponse is valid and not equal to randomNumber,
                    - then it checks if it needs to be higher or lower, and displays the corresponding response guide
                - otherwise it will finish the program, if the inputResponse is equal to randomNumber and displays the congratulatory dialogue
                    - then ask again if the player want to play again.

            - Otherwise it will finish the program if there's no remaining tries, and it will displays the correct answer
                - then ask again if the player want to play again.
            ======================================================================================================================================
            */

            if (numberOfTries > 0)
            {
                cout << "\n\t*** Welcome to Guessing Game ***" << endl;
                cout << "=========================================\n";
                cout << "\tNumber of Tries: " << numberOfTries << endl;
                cout << "\tNumber of Win: " << numberOfWin << endl;
                cout << "\tNumber of Lose: " << numberOfLose << endl;
                cout << "=========================================\n";
                cout << "\n\nEnter number (between 1 and " << maxRangeNumber << " ): ";
                cin >> inputResponse;

                if (inputResponse != randomNumber)
                {
                        // Checks if the response is valid
                        if (inputResponse > 0 && inputResponse <= maxRangeNumber)
                        {
                            cout << "------------------------\n";
                            (inputResponse > randomNumber) ? cout << "\tLower.!! pls.\n" : cout << "\tHigher.!! pls.\n";
                            cout << "------------------------\n";
                            numberOfTries--;
                           
                        } else {
                            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n";
                            cout << "(Invalid input!) Just enter number between 1 and " << maxRangeNumber << "." << endl;
                            cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
                        }
                        goto labelInputAgain;

                } else {
                    /*
                        if player got the correct answer, it prints congratulatory message, 
                            then add 1 point for win,
                            last ask the player to play again
                    */
                    cout << "###################################################################################################\n\n";
                    cout << "\tYou got the correct number: \'" <<  randomNumber << "\' with the remaining number of tries: " << numberOfTries << endl;
                    cout << "\n###################################################################################################\n";
                    numberOfWin++;
                        if (tryAgain())
                            goto labelStart;
                        else 
                            exit(1);
                } 

            } else {
                /*
                    if player doesn't get the correct answer, it prints couraging message, 
                        then add 1 point for lose,
                        last ask the player to play again
                */
                cout << "############################################################\n\n";
                cout << "\tBetter luck next time, the correct number is: \'" << randomNumber << "\'" << endl;
                cout << "\n############################################################\n";
                numberOfLose++;
                if (tryAgain())
                    goto labelStart;
                else 
                    exit(1);
            } 
    return 0;
}
