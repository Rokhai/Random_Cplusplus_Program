/*************************************************************
    Number Guessing Game Functional Approach

    November 24, 2021

    Rosgen D. Hizer
    @Rokhai
*************************************************************/


#include <iostream>
#include <cstdlib>
#include <ctime>

// tryAgain function that checks if player want to try again
bool tryAgain(void)
{
    char yesNo;
    
    while (true)
    {
        std::cout << "\nWant to try again? (y/n):";
        std::cin >> yesNo;

        if (tolower(yesNo) == 'y')
        {
            return true;
        } else if (tolower(yesNo) == 'n') {
            return false;
        } else {
            std::cout << "\n*** Invalid Input!! ***" << std::endl;
        }

    }
    
}


// menu function that display all choice in menu
int menu()
{    
    int choice;

    while (!(choice >= 0 && choice <= 3))
    {
        std::cout << "\n\t*** Welcome to Modified Guessing Game ***" << std::endl;
        std::cout << "\n\nMenu:\n" << std::endl;
        std::cout << "1\t Easy (You have 3 life, you need to guess number between 1 and 10)" << std::endl;
        std::cout << "2\t Medium (You have 5 life, you need to guess number between 1 and 50)" << std::endl;
        std::cout << "3\t Hard (You have 7 life, you need to guess number between 1 and 100)" << std::endl;
        std::cout << "\n0\tExit" << std::endl;
        std::cout << "\nChoose --->: ";
        std::cin >> choice;
    }

    return choice;
}

// isHighOrLow checks if the input guess needs to be higher or lower
void isHighOrLow(int inputGuess, int randomNumber)
{

    if (inputGuess > randomNumber)
    {
        std::cout << "\n------------------------\n";
        std::cout << "\tLower!!pls.\n";
        std::cout << "------------------------\n";
    } else {
        std::cout << "\n------------------------\n";
        std::cout << "\tHigher!!pls.\n";
        std::cout << "------------------------\n";
    }

}

// inputGuess a function where user guess the random number
int inputGuess(int maxRangeNumber)
{
    int inputGuess = 0;

    while (true)
    {
        std::cout << "\n\nEnter number between 1 and " << maxRangeNumber << "): ";
        std::cin >> inputGuess;

        if (!(inputGuess >= 0 &&  inputGuess <= maxRangeNumber))
        {
            std::cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n";
            std::cout << "(Invalid input!) Just enter number between 1 and " << maxRangeNumber << "." << std::endl;
            std::cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
        } else {
            return inputGuess;
        }
    }

}

// isCorrect checks if the inputGuess correct or wrong
bool isCorrect(int inputGuess, int randomNumber)
{
    if (inputGuess == randomNumber)
    {
        return true;
    } else {
        isHighOrLow(inputGuess, randomNumber);
        return false;
    }
}

// start function where game mechanics work
void start()
{
    

    int numberOfWin = 0;
    int numberOfLose = 0;
    int numberOfTries = 5;
    int maxRangeNumber = 100;
    int randomNumber;
   
    while (true)
    {
        switch (menu())
        {
            case 1:
                randomNumber = (rand() % 10) + 1;
                numberOfTries = 3;
                maxRangeNumber = 10;
                system("cls");
            break;
        
            case 2:
                randomNumber = (rand() % 50) + 1;
                numberOfTries = 5;
                maxRangeNumber = 50;
                system("cls");
            break;

            case 3:
                randomNumber = (rand() % 100) + 1;
                numberOfTries = 7;
                maxRangeNumber = 100;
                system("cls");
            break;

            case 0:
                std::cout << "\nGoodbye!!, Thanks for Playing. <3<3" << std::endl;
                exit(1);
            break;

            default:
                std::cout << "\n*** Invalid Input ***" << std::endl;
                std::cout << "\t- just choose number in the menu" << std::endl;
            break;
        }


        while (numberOfTries > 0)
        {
            // Dashboard
            std::cout << "\n\t*** Welcome to Guessing Game ***" << std::endl;
            std::cout << "=========================================\n";
            std::cout << "\tNumber of Tries: " << numberOfTries << std::endl;
            std::cout << "\tNumber of Win: " << numberOfWin << std::endl;
            std::cout << "\tNumber of Lose: " << numberOfLose << std::endl;
            std::cout << "=========================================\n";

            if (isCorrect(inputGuess(maxRangeNumber), randomNumber))
            {
                std::cout << "###################################################################################################\n\n";
                std::cout << "\tYou got the correct number: \'" <<  randomNumber << "\' with the remaining number of tries: " << numberOfTries << std::endl;
                std::cout << "\n###################################################################################################\n";
                numberOfWin++;
                break;
            } else {
                // if player didn't got the correct randomNumber yet there's remaining numberOfTries
                numberOfTries--;
            }
        }

        if (numberOfTries == 0)
        {
        std::cout << "############################################################\n\n";
        std::cout << "\tBetter luck next time, the correct number is: \'" << randomNumber << "\'" << std::endl;
        std::cout << "\n############################################################\n";
        numberOfLose++;
        }
        if (tryAgain()) 
        {
            system("cls");
        } else {
            exit(1);
        }
    }
}


int main()
{
    srand(time(0));
    // game start
    start();

    return 0;
}