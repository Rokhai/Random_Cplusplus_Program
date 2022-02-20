/*
    Reading and Writing Program
    - Demonstrates fstreams header onto text file
    - CRUD approach

    February 20, 2022
    Rosgen D. Hizer
    @Rokhai
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    int index = 0;
    int choose = 5;
    char buffer[50];

    char yesOrNo;
    string fileName;
    string name;
    string score;

    vector <string> nameList;
    vector <string> scoreList;

    fstream textFile;
    ofstream newTextFile;
    string line;
    
    ostringstream outputTextStream{};

    while (choose != 0)
    {
        cout << "\n========= Menu =========" << endl;
        cout << "\n1.\tCreate Score Data File";
        cout << "\n2.\tRead Score Data File";
        cout << "\n3.\tUpdate Score Data File";
        cout << "\n4.\tDelete Score Data File" << endl;

        cout << "\n0.\tExit" << endl;
        
        cout << "\n--> choose(0-4): ";
        cin >> choose;

        switch (choose)
        {
            case 1: // READ
                system("clear");
                
                cout << "\nEnter name of the file: ";
                cin >> fileName;

                textFile.open(fileName + ".txt");
                if(!textFile.is_open())
                {
                    cout << "\n[** file doesn\'t exist **]" << endl;

                    cout << "\n--> Want to create as new file? [Y] YES [N] NO: ";
                    cin >> yesOrNo;

                    if (tolower(yesOrNo) == 'y')
                    {
                        newTextFile.open(fileName + ".txt");

                        newTextFile << left <<"NAME" << ',' << "SCORE" << endl;
                        newTextFile << left <<"Rokhai" << ',' << "100" << endl;
                
                        newTextFile.close();
                    }
                } else {
                    cout << "\n[ File already exist: " << fileName + ".txt ]" << endl; 
                }

                textFile.close();
            break;

            case 2: // CREATE
                system("clear");

                cout << "\nEnter name of the file: ";
                cin >> fileName;

                textFile.open(fileName + ".txt", ios::in);

                if(!textFile.is_open())
                {
                    cout << "\n[** Error opening -- file doesn\'t exist **]" << endl;
                } else {
                    cout << "\nFile exist [\'Open Sucessfully\']: " << fileName + ".txt" << endl;

                    cout << "\n------ File Stream ------" << endl;
                    while(!textFile.eof())
                    {
                        textFile.getline(buffer, 49);
                        cout << buffer << endl;
                    }
                }

                textFile.close();
                
            break;

            case 3: // UPDATE
                system("clear");

                cout << "\nEnter name of the file: ";
                cin >> fileName;

                textFile.open(fileName + ".txt");

                if(!textFile.is_open())
                {
                    cout << "\n[** Error opening -- file doesn\'t exist **]" << endl;
                } else {
                    cout << "\nFile exist [\'Open Sucessfully\']: " << fileName + ".txt" << endl;
                    
                    while(!textFile.eof())
                    {
                        getline(textFile, line, ',');
                        nameList.push_back(line);

                        getline(textFile, line, '\n');
                        scoreList.push_back(line);
                        
                    }

                    // removes the last empty element
                    nameList.pop_back();
                    scoreList.pop_back();

                    cout << "Name\tSCORE" << endl;

                    for (int i = 1; i < scoreList.size(); i++)
                    {
                       cout << i << ". " << nameList.at(i) << "\t" << scoreList.at(i) << endl;
                    }

                    while (choose != 0)
                    {
                        cout << "\nMenu: " << endl;
                        cout << "1. Add New Data" << endl;
                        cout << "2. Update Existing Data" << endl;

                        cout << "0. Exit" << endl;

                        cout << "Choose (0-2): ";
                        cin >> choose;

                        switch (choose)
                        {
                            case 1:
                                cout << "\n** Enter the details needed **" << endl;
                                cout << "\n->Enter name: ";
                                cin >> name;

                                cout << "\n->Enter score: ";
                                cin >> score;

                                nameList.push_back(name);
                                scoreList.push_back(score);
                            break;

                            case 2:
                                system("clear");
                                input_index_again_update:
                                    
                                    // List all again
                                    cout << "Name\t   SCORE" << endl;

                                    for (int i = 1; i < scoreList.size(); i++)
                                    {
                                    cout << i << ". " << nameList.at(i) << "\t" << scoreList.at(i) << endl;
                                    }
                                    // bug in here
                                    cout << "\n** Enter the number you want to update **" << endl;
                                    cout << "->: ";
                                    cin >> index;

                                    if (index <= 0 || (index > nameList.size()-1))
                                    {
                                        system("clear");
                                        cout << "-> Number: "<< index << " doesn't exist!" << endl;
                                        goto input_index_again_update;
                                    } else {
                                        cout << "\n->Enter name: ";
                                        cin >> name;

                                        cout << "\n->Enter score: ";
                                        cin >> score;
                                        
                                        nameList.at(index) = name;
                                        scoreList.at(index) = score;
                                    }
                            break;

                            case 0:
                                cout << "Thank you!" << endl;
                            break;

                            default:
                                system("clear");
                                cout << "[\'-- Input Error!!\']" << endl;
                            break;
                        }
                    }
                }
               
                if (textFile.is_open())
                {
                    textFile.close();

                    textFile.open(fileName + ".txt", ios::out);

                    for (int i = 0; i < scoreList.size(); i++)
                    {
                        textFile << nameList.at(i) << "," << scoreList.at(i) << endl;
                    }

                    cout << "Saving...";
                }
                
                textFile.close();
                nameList.clear();
                scoreList.clear();

                choose = 5; // return to original value
                
            break;

            case 4: // DELETE
                system("clear");

                cout << "\nEnter name of the file: ";
                cin >> fileName;

                textFile.open(fileName + ".txt");

                if(!textFile.is_open())
                {
                    cout << "\n[** Error opening -- file doesn\'t exist **]" << endl;
                } else {
                    cout << "\nFile exist [\'Open Sucessfully\']: " << fileName + ".txt" << endl;
                    
                    while(!textFile.eof())
                    {
                        getline(textFile, line, ',');
                        nameList.push_back(line);

                        getline(textFile, line, '\n');
                        scoreList.push_back(line);
                        
                    }

                    // removes the last empty element
                    nameList.pop_back();
                    scoreList.pop_back();

                    cout << "Name\tSCORE" << endl;

                    for (int i = 1; i < scoreList.size(); i++)
                    {
                       cout << i << ". " << nameList.at(i) << "\t" << scoreList.at(i) << endl;
                    }

                    while (choose != 0)
                    {
                        cout << "\nMenu: " << endl;
                        cout << "1. Overwrite For New Data" << endl;
                        cout << "2. Delete Existing Data" << endl;

                        cout << "0. Exit" << endl;

                        cout << "Choose (0-2): ";
                        cin >> choose;

                        switch (choose)
                        {
                            case 1:
                                cout << "\nAre you sure to reset this file? (y/n): " << endl;
                                cin >> yesOrNo;

                                if (tolower(yesOrNo) == 'y')
                                {
                                    cout << "\n[** Overwriting... **]" << endl;

                                    nameList.clear();
                                    scoreList.clear();
                                    nameList.push_back("NAME");
                                    scoreList.push_back("GRADE");

                                    cout << "[** Overwrte Successfully **]" << endl;
                                } 
                            break;

                            case 2:
                                system("clear");
                                input_index_again_delete:
                                    
                                    // List all again
                                    cout << "Name\t   SCORE" << endl;

                                    for (int i = 1; i < scoreList.size(); i++)
                                    {
                                    cout << i << ". " << nameList.at(i) << "\t" << scoreList.at(i) << endl;
                                    }
                                    // bug in here
                                    cout << "\n** Enter the number you want to delete **" << endl;
                                    cout << "->: ";
                                    cin >> index;

                                    if (index <= 0 || (index > nameList.size()-1))
                                    {
                                        system("clear");
                                        cout << "-> Number: "<< index << " doesn't exist!" << endl;
                                        goto input_index_again_delete;
                                    } else {
                                        cout << "[** Deleting... **]" << endl;

                                        nameList.erase(nameList.begin() + index);
                                        scoreList.erase(scoreList.begin() + index);

                                        cout << "\n[** Delete Successfully **]" << endl;
                                    }
                            break;

                            case 0:
                                cout << "Thank you!" << endl;
                            break;

                            default:
                                system("clear");
                                cout << "[\'-- Input Error!!\']" << endl;
                            break;
                        }
                    }
                }
               
                if (textFile.is_open())
                {
                    textFile.close();

                    textFile.open(fileName + ".txt", ios::out);

                    for (int i = 0; i < scoreList.size(); i++)
                    {
                        textFile << nameList.at(i) << "," << scoreList.at(i) << endl;
                    }

                    cout << "Saving...";
                }
                

                textFile.close();
                nameList.clear();
                scoreList.clear();

                choose = 5; // return to original value
                
            break;

            case 0: // EXIT PROGRAM
                cout << "\n[\'** Thank YOU! **\']" << endl;
                textFile.close();
                return 0;
            break;

            default:
                system("clear");
                cout << "[\'-- Input Error!!\']" << endl;
            break;
        }
    }
}
