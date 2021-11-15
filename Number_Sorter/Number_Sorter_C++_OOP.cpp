/*********************************************
    Number Sorting with Loop Statements OOP
    November 15, 2021

    Rosgen D. Hizer

    @Rokhai
***********************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

class numberSorter
{
    public:
        int numberList[10];
        int arrayLength = 10;
        int tempNumber = 0;
        int choose = 1;
        int i = 0, j = 0;
        bool isChoosing = true;

        numberSorter()
        {
            while (this->isChoosing)
            {
                system("clear");
                std::cout << "\n\nMenu: " << std::endl;
                std::cout << "1. Random Generated Number" << std::endl;
                std::cout << "2. Manual Input of Number" << std::endl;
                std::cout << "0. Exit" << std::endl;
                std::cout << "\nChoose (0-2): ";
                std::cin >> this->choose;

                switch (this->choose)
                {
                    case 1:
                        for (this->i = 0; this->i < this->arrayLength; this->i++)
                        {
                            this->numberList[this->i] = (rand() % 100 + 1);
                        }
                        isChoosing = false;
                    break;

                    case 2:
                        for (int i = 0; i < arrayLength; i++)
                        {
                            std::cout << i << ". Enter number: ";
                            std::cin >> this->numberList[i];
                        }
                        isChoosing = false;
                    break;

                    default:
                        std::cout << "Invalid input" << std::endl;
                    break;
                }
            }
        }

        void ascending()
        {
            for (this->i = 0; this->i < this->arrayLength; this->i++)
            {
                for (this->j = 0; this->j < this->arrayLength; this->j++)
                {
                    if (this->numberList[i] < this->numberList[j])
                    {
                        this->tempNumber = this->numberList[this->i];
                        this->numberList[this->i] = this->numberList[this->j];
                        this->numberList[this->j] = this->tempNumber;
                    }
                }
            }
            std::cout << "\nSorter Number (Ascending): " << std::endl;
            for (int i = 0; i < this->arrayLength; i++)
            {
                std::cout << this->numberList[i] << ", ";
            }
        }

        void descending()
        {
            for (this->i = 0; this->i < this->arrayLength; this->i++)
            {
                for (this->j = 0; this->j < this->arrayLength; this->j++)
                {
                    if (this->numberList[i] > this->numberList[j])
                    {
                        this->tempNumber = this->numberList[this->i];
                        this->numberList[this->i] = this->numberList[this->j];
                        this->numberList[this->j] = this->tempNumber;
                    }
                }
            }

            std::cout << "\nSorter Number (Descending): " << std::endl;
            for (int i = 0; i < this->arrayLength; i++)
            {
                std::cout << this->numberList[i] << ", ";
            }
        }

        void menu()
        {
            std::cout << "\nRandom Number Generated List: " << std::endl;
            for (int i = 0; i < this->arrayLength; i++)
            {
                std::cout << this->numberList[i] <<", ";
            }
            while (this->choose != 0)
            {
                std::cout << "\n\nMenu: " << std::endl;
                std::cout << "1. Sort (Ascending)" << std::endl;
                std::cout << "2. Sort (Descending)" << std::endl;
                std::cout << "\n0. Quit" << std::endl;

                std::cout << "\nChoose: ";
                std::cin >> this->choose;

                switch (this->choose)
                {
                    case 1:
                        this->ascending();
                    break;

                    case 2:
                        this->descending();
                    break;

                    case 0:
                        std::cout << "\nThank YOU!" << std::endl;
                    break;

                    default:
                        std::cout << "Invalid input!" << std::endl;
                    break;
                }
            }
        }

};

int main()
{
    srand(time(0));

    numberSorter object = numberSorter();
    object.menu();


    return 0;
}