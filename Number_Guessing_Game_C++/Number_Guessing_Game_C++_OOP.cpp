/***************************
  Number Guessing Game OOP
  November 14, 2021
  @author Rokhai
****************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

using std::string;

class NumberGuessingGame
{
    private:
        string name;
        char yesOrNo;
        int choose;
        int numberOfWin = 0;
        int numberOfLose = 0;
        int randomNumber = 0;
        int inputGuessNumber;
        int numberOfTries = 5;
        int maxRangeNumber = 100;

    public:
        NumberGuessingGame(string name)
        {
            this->name = name;
        }

        bool tryAgain()
        {
            tryAgain:
                std::cout << "\nWant to try again (y/n): ";
                std::cin >> this->yesOrNo;

                if (tolower(this->yesOrNo) == 'y')
                {
                    return true;
                } else if (tolower(this->yesOrNo) == 'n') {
                    return false;
                } else {
                    std::cout << "Invalid input!" << std::endl;
                    goto tryAgain;
                }
        }

        void dashboard()
        {
            std::cout << "\n\t*** Welcome to Guessing Game " << this->name << " ***" << std::endl;
            std::cout << "=========================================\n";
            std::cout << "\tNumber of Tries: " << numberOfTries << std::endl;
            std::cout << "\tNumber of Win: " << numberOfWin << std::endl;
            std::cout << "\tNumber of Lose: " << numberOfLose << std::endl;
            std::cout << "=========================================\n";
        }

        void menu()
        {
            main_menu:
                std::cout << "\n\t*** Welcome to Modified Guessing Game ***" << std::endl;
                std::cout << "\n\nMenu:\n" << std::endl;
                std::cout << "1\t Easy (You have 3 life, you need to guess number between 1 and 10)" << std::endl;
                std::cout << "2\t Medium (You have 5 life, you need to guess number between 1 and 50)" << std::endl;
                std::cout << "3\t Hard (You have 7 life, you need to guess number between 1 and 100)" << std::endl;
                std::cout << "\n0\tExit" << std::endl;
                std::cout << "\nChoose --->: ";
                std::cin >> this->choose;

                switch (this->choose)
                {
                    case 1:
                        this->randomNumber = (rand() % 10) + 1;
                        this->numberOfTries = 3;
                        this->maxRangeNumber = 10;
                        system("cls");
                    break;
                    case 2:
                        this->randomNumber = (rand() % 50) + 1;
                        this->numberOfTries = 5;
                        this->maxRangeNumber = 50;
                        system("cls");
                    break;
                    case 3:
                        this->randomNumber = (rand() % 100) + 1;
                        this->numberOfTries = 7;
                        this->maxRangeNumber = 100;
                        system("cls");
                    break;
                    case 0:
                        std::cout << "\nGoodbye!, Thanks for Playing. <3<3" << std::endl;
                        exit(1);
                    break;

                    default:
                        std::cout << "There's no such choice in menu!" << std::endl;
                        goto main_menu;
                    break;
                }
        }

        void play()
        {
            main_game:
                this->menu();

                main_guess_game:
                    if (this->numberOfTries > 0)
                    {
                        

                            /*****************************************************************************************************************
                            - Outer if checks if there's remaining tries(numberOfTries > 0 ), then it prompt to input a response(or guess)
                                - then it check if the inputResponse is valid and not equal to randomNumber,
                                    - then it checks if it needs to be higher or lower, and displays the corresponding response guide
                                - otherwise it will finish the program, if the inputResponse is equal to randomNumber and displays 
                                the congratulatory dialogue
                                    - then ask again if the player want to play again.

                            - Otherwise it will finish the program if there's no remaining tries, and it will displays the correct answer
                                - then ask again if the player want to play again.
                            ******************************************************************************************************************/

                            this->dashboard();

                            std::cout << "\n\nEnter number between (1 and " << this->maxRangeNumber << " ): ";
                            std::cin >> this->inputGuessNumber;

                            
                            if (this->inputGuessNumber != this->randomNumber)
                            {
                                // Checks if the response is valid
                                if (this->inputGuessNumber > 0 && this->inputGuessNumber <= this->maxRangeNumber)
                                {
                                    std::cout << "------------------------" << std::endl;
                                    // hints if needs to be higher or lower (ternary)
                                    (this->inputGuessNumber > this->randomNumber) ? std::cout << "\tLower!!_pls!\n" : std::cout << "Higher!!_pls.\n";
                                    std::cout << "------------------------" << std::endl;
                                    // reduce the available try(s)
                                    this->numberOfTries--;
                                } else {
                                    std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
                                    std::cout << "(Invalid input!) Just enter number between 1 and " << this->maxRangeNumber << "." << std::endl;
                                    std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
                                }
                                goto main_guess_game;

                            } else {
                                /***********************************************************************
                                    if player got the correct answer, it prints congratulatory message, 
                                        then add 1 point for win,
                                        last ask the player to play again
                                ***********************************************************************/
                                std::cout << "###################################################################################################" << std::endl;
                                std::cout << "\tYou got the correct number: \'" <<  this->randomNumber << "\' with the remaining number of tries: " << this->numberOfTries << std::endl;
                                std::cout << "###################################################################################################" << std::endl;
                                this->numberOfWin++;
                            }
                    } else {
                        /***********************************************************************
                             if player doesn't get the correct answer, it prints couraging message, 
                                then add 1 point for lose,
                                last ask the player to play again
                        ***********************************************************************/
                        std::cout << "############################################################" << std::endl;
                        std::cout << "\tBetter luck next time, the correct number is: \'" << this->randomNumber << "\'" << std::endl;
                        std::cout << "############################################################\n" << std::endl;
                        this->numberOfLose++;           
                    }

            if (this->tryAgain())
            {
                system("clear");
                std::cout << "\nGame Restarted!" << std::endl;
                goto main_game;
            } else {
                std::cout << "Thank YOU! for playing." << std::endl;
                exit(1);
            }

        }
};

int main()
{

    srand(time(0));

    string name;

    // prompts player name
    inputName:
        std::cout << "Enter your name: ";
        std::getline(std::cin, name);
        
        // checks if user inputs name
        if (name != " ")
        {
            // initialize game object
            NumberGuessingGame game = NumberGuessingGame(name);
            game.play();
        } else {
            std::cout << "Empty Name!" << std::endl;
            goto inputName;
        }

    return 0;
}
