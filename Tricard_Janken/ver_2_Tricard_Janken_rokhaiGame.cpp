#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string.h>
#include <windows.h>
#include <conio.h>

using namespace std;

// COLOR   
void color (int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Goto X ,Y Coordinate with the Console Cursor
void gotoxy(int x, int y)
{
    COORD coordinate;
    coordinate.X = x;
    coordinate.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}

class Player
{
    public:
        // Properties
        string name = "Player";
        int money = 0;
        int bet = 0;
        vector <string> hand[3];
        string uiCard[3][2] = {{"Rock", "[R] Rock"}, {"Paper", "[P] Paper"}, {"Scissor", "[S] Scissor  "}};
       
        // Set player name
        void setName()
        {
            system("cls");

            // Horizontal Border
            for (int i = 10; i <= 50; i++)
            {
                gotoxy(i, 3);
                cout << '=';
                gotoxy(i,9);
                cout << '=';

                if (i >= 20 && i <= 40)
                {
                    gotoxy(i, 7);
                    cout << '-';
                }
            }
            // Vertical Border
            for (int i = 3; i <= 9; i++)
            {
                gotoxy(10, i);
                cout << '|';
                gotoxy(50, i);
                cout << '|';
            }
            // Credit
            gotoxy(22, 8);
            cout << "(C) Rokhai Games";
            // Name Input
            gotoxy(13, 5);
            cout << "Enter name: "; cin >> name;

            for (int i = 0; i < name.size(); i++)
            {
                if (name[i] == ' ') name[i] = '_';
            }
        }
        // Set player bet
        void setBet()
        {
            int errInput = 0;
            inputBetAgain:
                errInput++;
                system("cls");

                // Horizontal Border
                for (int i = 10; i <= 50; i++)
                {
                    gotoxy(i, 3);
                    cout << '=';
                    gotoxy(i,9);
                    cout << '=';

                    if (i >= 20 && i <= 40)
                    {
                        gotoxy(i, 7);
                        cout << '-';
                    }
                }
                // Vertical Border
                for (int i = 3; i <= 9; i++)
                {
                    gotoxy(10, i);
                    cout << '|';
                    gotoxy(50, i);
                    cout << '|';
                }
                // Credit
                gotoxy(22, 8);
                cout << "(C) Rokhai Games";
                // Player Money Info
                gotoxy(13, 5);
                cout << "Your Money: $ " << money;

                // Input Bet
                gotoxy( 13, 6);
                if (money > 2) {cout << "Enter bet: "; cin >> bet; cin.ignore();}
                else bet = money;
                
                if (errInput == 3) bet = money; // 3rd time of invalid input whole money will be bet
                if (!(bet >= 2 && bet <= money) || (money - bet) == 1 || bet == 1) goto inputBetAgain;
        }

        // Handcard Sorter
        void handSort()
        {
            string sTemp;
            // Bubble Sort
            for (int i = 0; i < hand->size(); i++)
            {
                for (int j = 0; j < hand->size(); j++)
                {
                    if (hand->at(i) > hand->at(j))
                    {
                        sTemp = hand->at(i);
                        hand->at(i) = hand->at(j);
                        hand->at(j) = sTemp;
                    }
                }
            }
        }

        // Player Controller
        int controller()
        {
            int Set[] = {7, 7, 7};
            int counter = 0;
            char key;
            for (int i = 0;;)
            {

                gotoxy(29, 28);
                color(Set[0]);
                for (int i = 0; i < 3; i++)
                {
                    if (hand->at(0) == uiCard[i][0])
                        cout << uiCard[i][1];  
                } 

                gotoxy(41, 28);
                color(Set[1]);
                for (int i = 0; i < 3; i++)
                {
                    if (hand->at(1) == uiCard[i][0])
                        cout << uiCard[i][1];  
                } 

                gotoxy(53, 28);
                color(Set[2]);
                for (int i = 0; i < 3; i++)
                {
                    if (hand->at(2) == uiCard[i][0])
                        cout << uiCard[i][1];  
                } 

                int handSize = 0;

                for (int i = 0; i < 3; i++) if (!(hand->at(i) == "")) ++handSize;
                
                key = _getch();

                if (tolower(key) == 'a' && (counter >= 1 && counter <= handSize-1)) counter--; // Left
                if (tolower(key) == 'd' && (counter >=0 && counter <= handSize-2)) counter++; // Right
                if (tolower(key) == '\r') break; // return == enter

                for (int i = 0; i < 3; i++) Set[i] = 7; // it will default all item into white color

                Set[counter] = 9; // it will set the selected item into light blue color which is 9

            }
            color(7);

            return counter;
        }

        Player(){} // Constructor
        ~Player(){} // Destructor
};     

class Computer
{
    public:
        // Properties
        string name = "Computer";
        int money = 0;
        int bet = 0;
        vector <string> hand[3];

        // Get Computer Bet
        void setBet(int playerBet)
        {
            while (true)
            {
                bet = (playerBet / 2) / ((rand() % 5) + 1);
                if (bet < 0 && bet > money) bet = money;
                if (bet > 0) break;  
            }
        }

        // Handcard Sorter
        void handSort()
        {
            string sTemp;

            for (int i = 0; i < hand->size(); i++)
            {
                for (int j = 0; j < hand->size(); j++)
                {
                    if (hand->at(i) > hand->at(j))
                    {
                        sTemp = hand->at(i);
                        hand->at(i) = hand->at(j);
                        hand->at(j) = sTemp;
                    }
                }
            }
        }

        // Computer Controller
        int controller()
        {
            int choice = 0;

            for (int i = 0; i < 3; i++) if (hand->at(i) != "") ++choice;

            choice = (rand() % choice);

            return choice;
        }

        Computer(){} // Constructor
        ~Computer(){} // Destructor
};

class Game
{
    public:
        // Properties
        string card[3]= {"Rock", "Paper", "Scissor"};
        int round = 0;
        vector <string> DECK[10];

        // Object Instance
        Player player = Player();
        Computer computer = Computer();

        // Game Guidelines
        void instructionDisplay()
        {
            /*
            1. There will be money at stake when the round starts. As the round starts there will be money at stake. 
            2. There'll be 10 cards on the deck, and a brand new set of card on the deck to the following round
            3. Then, it will be distributed 1 each after another, until there's only 3 cards on hand
            4. Players will choose 1 from the 3 cards at hand to play, then the to game is concluded. 
            5. If the result is a DRAW, players will play from the remaining cards on hand. 
            6. When the game concludes all bets will be given to the winner. 
            7. In this case MONEY is your LIFE.
            */
            string warning = "-- Please read the GUIDELINES carefully! --";
            string rules[7] = {
            "1. There will be money at stake when the round starts. As the round starts there will be money at stake.",
            "2. There'll be 10 cards on the deck, and a brand new set of card on the deck to the following round.",
            "3. Then, it will be distributed 1 each after another, until there's only 3 cards on hand.",
            "4. Players will choose 1 from the 3 cards at hand to play, then the game is concluded.",
            "5. If the result is a DRAW, players will play from the remaining cards on hand.",
            "6. When the game concludes all bets will be given to the winner.",
            "7. In this case MONEY is your LIFE."
            };

            gotoxy(25,2);
            cout << "+----- TriCard : Rock, Paper and Scissor Game -----+" << endl;

            // Horizontal Border
            for (int i = 1; i <= 110; i++)
            {
                gotoxy(i, 3);
                cout << '#';

                gotoxy(i, 20);
                cout << '#';
            }
            // char by char Display
            for (int i = 0; i < warning.size(); i++)
            {
                gotoxy(i + 3, 5);
                cout << warning.at(i);
                Sleep(50);
            }
            for (int i = 0; i < 7; i++)
            {
                gotoxy(2, 7 + i);
                cout << rules[i];
                Sleep(1500);
            }
            // Title
            gotoxy(3, 16);
            cout << "** TriCard (Rock, Paper, and Scissor) Game **";
            // Credit
            gotoxy(3, 17);
            cout << "-- (C) Rokhai Games --";

            gotoxy(3, 19);
            system("pause");
        }

        // Just A Loading Display
        void loadingDisplay()
        {
            system("cls");
            
            // Horizontal Line Bar
            for (int i = 5; i < 45; i++)
            {
                // Top Border
                gotoxy(i, 5);
                cout << "-";

                // Dots
                gotoxy(i, 6);
                cout << ".";

                // Bottom Border
                gotoxy(i, 7);
                cout << "-";
            }

            // Corner & Side
            gotoxy(4, 5); // upper left corner
            cout << "+";
            gotoxy(45, 5); // upper right corner
            cout << "+";
            gotoxy(4, 7); // lower left corner
            cout << "+";
            gotoxy(45, 7); // lower right corner
            cout << "+";
            gotoxy(4, 6); // left vertical bar
            cout << "|";
            gotoxy(45,6); // right vertical bar
            cout << "|"; 
            gotoxy(15,7);
            cout << "\n\t\t   LOADING..."; 
            cout << "\n";

            // Loading Scheme
            for (int i = 6; i < 44; i++)
            {
                gotoxy(i, 6);
                color(2);
                cout << "#";
                Sleep(150);
                // color(7);
            }

            gotoxy(6, 10);
            color(7);
            system("pause");
        }

        // Reverse String
        void reverse(string str)
        {
            for (int i=str.length() - 1; i >= 0; i--)
                cout << str[i]; 
        }

        // Create Deck
        void createDeck()
        {
            for (int i = 0; i < 10; i++)
            {
                DECK->push_back(card[rand() % 3]);
            }
        }

        // Distribute Card
        void setHandCard()
        {
            for (int i = 0; i < 3; i++)
            {
                player.hand->push_back(DECK->back());
                DECK->pop_back();
                computer.hand->push_back(DECK->back());
                DECK->pop_back();
            }
        }

        // Game Condition
        int whoWin(string player, string computer)
        {
            if (player != computer)
            {
                if (player == "Rock" && computer == "Scissor")
                    return 1;
                else if (player == "Rock" && computer == "Paper")
                    return 0;
                else if (player == "Scissor" && computer == "Paper")
                    return 1;
                else if (player == "Scissor" && computer == "Rock")
                    return 0;
                else if (player == "Paper" && computer == "Rock")
                    return 1;
                else if (player == "Paper" && computer == "Scissor")
                    return 0;
            }     
            return 2;
        }

        void gameUI()
        {
            //Title
            gotoxy(26, 4);
            cout << "** TriCard (Rock, Paper, and Scissor) Game **";

            // Horizontal Border
            for (int i = 1; i <= 55; i++)
            {
                gotoxy(20 + i, 5);
                cout << "#";

                gotoxy(20 + i, 25);
                cout << "#";
            }
        
            // Vertical Border
            for (int i = 1; i <= 20; i++)
            {
                gotoxy(21, 5 + i);
                cout << "#";

                gotoxy(75, 5 + i);
                cout << "#";
            }

            gotoxy(80, 8);
            cout << "- STAKE STATS -";
            gotoxy(80, 10);
            cout << "Computer BET: " << computer.bet;
            gotoxy(80, 12);
            cout << player.name << " BET: " << player.bet;
            gotoxy(78, 14);
            cout << " _ _ _ _ _ _ _ _ _ _ ";
            gotoxy(80, 16);
            cout << "Total BET: " << player.bet + computer.bet;

            // Instruction Controller
            gotoxy(23, 26);
            cout << "Press A \"<-\" and D \"->\" to choose, then press Enter";
        
            // Game Round
            gotoxy(23, 15);
            cout << '+';
            gotoxy(73, 15);
            cout << '+';
            
            gotoxy(45, 15);
            cout << "Round " << round + 1 << " ";

            for (int i = 1; i <= 20; i++ )
            {
                gotoxy(23 + i, 15);
                cout << '-';

                gotoxy(73 - i, 15);
                cout << '-';

            }

            // Computer Info
            gotoxy(57, 12);
            cout << "> " << computer.name << " <";
            gotoxy(58, 13);
            cout << "$ " << computer.money;
            // Player Info
            gotoxy(27, 17);
            cout << "> " << player.name << " <";
            gotoxy(28, 18);
            cout << "$ " << player.money;
        }

        bool start()
        {
            bool isGameOn = true, isPlayerWon = false;
            while (isGameOn)
            {
                int returnResult;
                bool isRound = true;

                createDeck();
                setHandCard();

                system("cls");
                player.setBet();
                computer.setBet(player.bet);
                
                for (int i = 0; i < 3 && isRound; i++)
                {
                    string CARD[3][6] = {
                    {"   _______",
                    "---'   ____)",
                    "      (_____)",
                    "      (_____)",
                    "      (____)",
                    "---.__(___)"},

                    {"    _______",
                    "---'    ____)____",
                    "           ______)",
                    "          _______)",
                    "         _______)",
                    "---.__________)"},

                    {"   _______",
                    "---'   ____)____",
                    "          ______)",
                    "       __________)",
                    "      (____)",
                    "---.__(___)"}
                    };

                    system("cls");
                    gameUI();

                    // Input Play Card
                    int inputPlayerPlayCard = player.controller();
                    int inputComputerPlayCard = computer.controller();
                    string playerInputCard = player.hand->at(inputPlayerPlayCard);
                    string computerInputCard = computer.hand->at(inputComputerPlayCard);

                    player.hand->at(inputPlayerPlayCard) = "";
                    computer.hand->at(inputComputerPlayCard) = "";
                    player.handSort();
                    computer.handSort();

                    // Animation Anticipation
                    for (int i = 0; i < (rand() % 5 + 4); i++)
                    {
                        for (int j = 0; j < 3; j++)
                        {   
                            // Display Card
                            for (int k = 0; k < 6; k++)
                            {
                                gotoxy(25, 7 + k);
                                cout << CARD[j][k];
                            }

                            Sleep(500 - (50 * i));

                            // Clearing Tracks
                            for (int l = 0; l < 6; l++)
                            {
                                for (int m = 0; m < 20; m++)
                                {
                                    gotoxy(25 + m, 7 + l);
                                    cout << " ";
                                }
                            }
                        }
                    }

                    // Computer  Game Showdown
                    for (int i = 0; i < 6; i++)
                    {
                        gotoxy(25, 7 + i);
                        if (computerInputCard == "Rock") cout << CARD[0][i];
                        else if (computerInputCard == "Paper") cout << CARD[1][i];
                        else if (computerInputCard == "Scissor") cout << CARD[2][i];
                    }

                    int inputCard = 0;

                    // Player Game Showdown
                    if (playerInputCard == "Rock") inputCard = 0;
                    else if (playerInputCard == "Paper") inputCard = 1;
                    else if (playerInputCard == "Scissor") inputCard = 2;

                    // Reverse ASCII Art 
                    for (int i = 0; i < 6; i++)
                    {
                        for (int j = 0; j < CARD[inputCard][i].size(); j++)
                        {
                            if (CARD[inputCard][i][j]== '(')
                                CARD[inputCard][i][j] = ')';
                            else if (CARD[inputCard][i][j]== ')')
                                CARD[inputCard][i][j] = '(';
                        }
                    }

                    // Displays Player Card
                    for (int i = 0; i < 6; i++)
                    {
                        gotoxy(72 - CARD[inputCard][5 - i].size(), 23 - i);
                        reverse(CARD[inputCard][5 - i]);
                    }

                    int result = whoWin(playerInputCard, computerInputCard);
                    
                    switch (result)
                    {
                        case 0:
                            gotoxy(27, 21);
                            color(6);
                            cout << "You LOSE!";

                            gotoxy(55, 10);
                            color(3);
                            cout << "Computer WIN!";

                            color(7);
                            isRound = false;
                            returnResult = 0;
                        break;

                        case 1:
                            gotoxy(27, 21);
                            color(3);
                            cout << "You WIN!";

                            gotoxy(55, 10);
                            color(6);
                            cout << "Computer LOSE!";
                            
                            color(7);
                            isRound = false;
                            returnResult = 1;
                        break;

                        case 2:
                            gotoxy(27, 21);
                            color(4);
                            cout << "Its DRAW!";

                            gotoxy(55, 10);
                            color(4);
                            cout << "Its DRAW!";

                            color(7);
                            returnResult = 2;
                        break;
                    }
                    gotoxy(23, 30);
                    system("pause");
                }
                round++;

                // Resetting Hand and Deck
                player.hand->clear();
                computer.hand->clear();
                DECK->clear();

                // Bet Distribution
                if (returnResult == 0)
                {
                    computer.money += player.bet;
                    player.money -= player.bet;
                } else if (returnResult == 1) {
                    player.money += computer.bet;
                    computer.money -= computer.bet;
                }
                if (!(player.money > 0) || !(computer.bet > 0)) 
                {
                    if (computer.money <= 0 ) isPlayerWon = true;
                    isGameOn = false;
                }
            }
            return isPlayerWon;
        }
        Game() // Constructor
        {
            instructionDisplay();
            player.setName();
            loadingDisplay();
            player.money = 100;
            computer.money = 100;
        }
        ~Game(){} // Destructor
};

int main()
{
    srand(time(NULL));
    system("cls");

    Game game = Game();
    bool playerWon = game.start();

    system("cls");
    cout << "\n\n\n";
    cout << "\t\t\t\t     .-\"\"\"\"\"\"-." << endl;
    cout << "\t\t\t\t   .'          '." << endl;
    cout << "\t\t\t\t  /   O    -=-   \\" << endl;
    cout << "\t\t\t\t :                :" << endl;
    cout << "\t\t\t\t |                | " << endl;
    cout << "\t\t\t\t : ',          ,' :" << endl;
    cout << "\t\t\t\t  \\  '-......-'  /" << endl;
    cout << "\t\t\t\t   '.          .'" << endl;
    cout << "\t\t\t\tjgs  '-......-'" << endl << endl;
    if (playerWon == false) cout << "\t\t\t-- Better luck next time!! --" << endl;
    else cout << "\t\t\t-- Woah! congrats! - nice play!! --" << endl;
    cout << "\n\t\t\t \" Heh!...Thanks for playing!! \"" << endl << "\n\n";
    system("pause");

    return 0;
}

/*******************************************
    July 09, 2022
    Github: @Rokhai
********************************************/
