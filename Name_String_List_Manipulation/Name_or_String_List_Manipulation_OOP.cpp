/*************************************************************
    Name/String List/Array Manipulation OOP
        - Demonstrates removing, adding, editing elements 
            from array of string/names in OOP approach

    November 22, 2021

    Rosgen D. Hizer
    @Rokhai
*************************************************************/

#include <iostream>
#include <vector>

using std::string;

class Operator
{
    private:
        std::vector<string> names[10];
        string inputName, tempName;
        int sizeOfNamesList;
        int choice;
        int i = 0, j = 0;
        char yesNo;
        bool isChoosing = true;
    public:
        Operator() 
        {
            op_menu_1:
                std::cout << "\n ===Name List Manipulation===" << std::endl;
                std::cout << "Menu: " << std::endl;
                std::cout << "1. Use Pre-set List of Names" << std::endl;
                std::cout << "2. Manually Input Name" << std::endl;
                std::cout << "\n0. Exit" << std::endl;
                std::cout << "\nChoose a number: ";
                std::cin >> this->choice;

                switch (this->choice)
                {
                    case 1:
                        names->push_back("Rokhai");
                        names->push_back("Lawrence");
                        names->push_back("Shelia");
                    break;
                    
                    case 2:
                        op_menu_case_2:
                            std::cout << "\nEnter name: ";
                            std::cin >> this->inputName;
                            names->push_back(inputName);
                            op_menu_case_2_err:
                                std::cout << "\nWant to enter again? (y/n): ";
                                std::cin >> this->yesNo;

                                if (toupper(this->yesNo) == 'Y')
                                {
                                    system("cls");
                                    std::cout << "*** Input Again! ***" << std::endl;
                                    goto op_menu_case_2;
                                } else if (toupper(this->yesNo) == 'N') {
                                    std::cout << "DONE!!" << std::endl;
                                    break;
                                } else {
                                    std::cout << "*** Invalid Input ***" << std::endl;
                                    goto op_menu_case_2_err;
                                }
                    break;

                    case 0:
                        std::cout << "Thank YOU!" << std::endl;
                        exit(1);
                    break;

                    default:
                        system("cls");
                        std::cout << "*** Invalid Input! ***" << std::endl;
                        goto op_menu_1;
                    break;
                }
        }

        void showAllName()
        {
            system("cls");
            std::cout << "-- List of Name --" << std::endl;
            for ( this->i = 0; this->i < this->names->size(); this->i++)
            {
                std::cout << this->i << ". " << this->names->at(this->i) << std::endl;
            }
        }

        void showAllNameAscending()
        {
            system("cls");
            std::cout << "-- List of Name Sort as Ascending--" << std::endl;
            for ( this->i = 0; this->i < this->names->size(); this->i++)
            {
                for ( this->j = 0; this->j < this->names->size(); this->j++)
                {
                    if (this->names->at(this->i) < this->names->at(this->j))
                    {
                        this->tempName = this->names->at(this->i);
                        this->names->at(this->i) = this->names->at(this->j);
                        this->names->at(this->j) = this->tempName;
                    }
                }
            }
            
            this->showAllName();
        }

        void showAllNameDescending()
        {
            system("cls");
            std::cout << "-- List of Name Sort as Descending--" << std::endl;

            for ( this->i = 0; this->i < this->names->size(); this->i++)
            {
                for ( this->j = 0; this-> j < this->names->size(); this->j++)
                {
                    if (this->names->at(this->i) > this->names->at(this->j))
                    {
                        this->tempName = this->names->at(this->i);
                        this->names->at(this->i) = this->names->at(this->j);
                        this->names->at(this->j) = this->tempName;
                    }
                }
            }
            
            showAllName();
        }

        void addItem()
        {
            system("cls");
            std::cout << "\n-- Add Item" << std::endl;
            std::cout << "\nEnter name: ";
            std::cin >> this->inputName;
            this->names->push_back(inputName);
        }

        void renameItem()
        {
            system("cls");
            std::cout << "-- Renames Item --" << std::endl;

            this->showAllName();

            input_index_name:
                std::cout << "\nWhich name do you to rename\n"
                    << "Choose a number: ";
                std::cin >> this->choice;
                
                if (this->choice <= this->names->size() && this->choice >= 0)
                {
                    input_rename:
                        std::cout << "Enter name: ";
                        std::cin >> this->inputName;
                        if (this->inputName != " ")
                        {
                            names->at(choice) = this->inputName;
                        } else {
                            system("cls");
                            std::cout << "[*** Empty Name ***]" << std::endl;
                        }
                    
                } else {
                    system("cls");
                    std::cout << "*** Invalid Input ***" << std::endl;
                    goto input_index_name;
                }

        }

        void removeItem()
        {
            system("cls");
            std::cout << "\n-- Remove Item --" << std::endl;

            this->showAllName();

            input_remove:
                std::cout << "\nWhich name do you want to remove\n" 
                    << "Choose a number: ";
                std::cin >> this->choice;
                if (this->choice >= 0 && this->choice <= this->names->size())
                {
                    this->names->erase(names->begin() + this->choice);
                } else {
                    system("cls");
                    std::cout << "*** Invalid Input! ***" << std::endl;
                    goto input_remove; 
                }
        }

        void start()
        {
           while (true)
           {
                std::cout << "\n\nMenu: " << std::endl;
                std::cout << "1. Show all name" << std::endl;
                std::cout << "2. Show all name (Sort as Ascending)" << std::endl;
                std::cout << "3. Show all name (Sort as Descending)" << std::endl;
                std::cout << "4. Add Item" << std::endl;
                std::cout << "5. Rename Item" << std::endl;
                std::cout << "6. Remove Item" << std::endl;
                std::cout << "\n0. Exit" << std::endl;
                std::cout << "\nChoose a number: ";
                std::cin >> this->choice;

                switch (this->choice)
                {
                    case 1:
                        this->showAllName();
                    break;

                    case 2:
                        this->showAllNameAscending();
                    break;

                    case 3:
                        this->showAllNameDescending();
                    break;

                    case 4:
                        this->addItem();
                    break;

                    case 5:
                        this->renameItem();
                    break;

                    case 6:
                        this->removeItem();
                    break;

                    case 0:
                        std::cout << "Thank YOU!" << std::endl;
                        exit(1);
                    break;

                    default:
                        std::cout << "*** Invalid Input! ***" << std::endl;
                    break;
                }

           }
            
        }

};

int main()
{
    Operator operator_object = Operator();
    operator_object.start();

    return 0;
}