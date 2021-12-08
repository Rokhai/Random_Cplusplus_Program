/******************************
    Tic-Tac-Toe OOP in C++

    December 08, 2021

    Rosgen D. Hizer
    @Rokhai
******************************/

#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>


void gotoxy(int x, int y)
{
    COORD coordinate;
    coordinate.X = x;
    coordinate.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}

using namespace std;

class TicTacToe
{

    private:
        char board[8];
        char cWhoWon = ' ';
        int iCurrentPlayer = 1;
        int currentRound = 1;
        int inputChoice;
        int comChoice = 0;
        int player1Score = 0 , player2Score = 0;
        string player1 , player2;

        bool isPvP = false, isPvC = false;
        bool isGameOn = true, isPlaying = true;
    public:

        // Just A Loading Display
        void loadingDsiplay()
        {
            for (int i = 5; i < 45; i++)
            {
                gotoxy(i, 5);
                cout << "-";
                gotoxy(i, 7);
                cout << "-";
            }
            gotoxy(5, 6);
            cout << "|";
            gotoxy(44,6);
            cout << "|";
            gotoxy(15,7);
            cout << "\n\t\t   LOADING...";
            cout << "\n";
            for (int i = 6; i < 44; i++)
            {
                gotoxy(i, 6);
                cout << "#";
                Sleep(150);
            }
        }
        // Ask to play again
        bool playAgain()
        {
            while (true)
            {
                char yesOrNo;
                cout << "\nWant to play again? (y/n): ";
                cin >> yesOrNo;

                if (tolower(yesOrNo) == 'y')
                {
                    return true;
                } else if (tolower(yesOrNo) == 'n') {
                    return false;
                } else {
                    cout << "\n[***Invalid Input***]" << endl;
                }
            }
        }

        // Create New Playable Board
        void newBoard()
        {
            for (int i = 0; i < 9; i++)
                board[i] = ' ';
        }

        // Displays the Game Instruction
        void displayInstruct()
        {
            system("cls");
            cout << "\t---> Welcome To TicTacToe Game <---" << endl;
            cout << "The number correspond to the board position as illustrated: \n\n"
                    << "\t\t1 | 2 | 3\n"
                    << "\t\t---------\n"
                    << "\t\t4 | 5 | 6\n"
                    << "\t\t---------\n"
                    << "\t\t7 | 8 | 9" << endl;
            cout << "\t[*** Prepare Yourself ***]\n" << endl;
            cout << "\n- Player 1 will Turn as O"
                 << "\n- Player 2 will Turn as X" << endl;
            system("pause");
        }

        // Display the Current State of the Board
        void displayBoard()
        {
            cout << "\n";
            cout << "\t" << board[0] << " | " << board[1] << " | " << board[2] << endl;
            cout << "\t---------" << endl;
            cout << "\t" << board[3] << " | " << board[4] << " | " << board[5] << endl;
            cout << "\t---------" << endl;
            cout << "\t" << board[6] << " | " << board[7] << " | " << board[8] << endl;
            
            cout << "\nRound " << currentRound << " Score Board" << endl;
            cout << "+ - - - - - - - - - - - - - - --+- - - - - - - - +" << endl;
            cout << "| Player 1: " << player1 << "\t\t| Score: " << player1Score << "\t |" << endl
                 << "| Player 2: " << player2 << "\t\t| Score: " << player2Score << "\t |" << endl
                 << "+ - - - - - - - - - - - - - - --+- - - - - - - - +" << endl;
        }
        // Checks if Selected Sqaure is Available
        bool verifySelection(int selectSquare, int player)
        {
            if (board[selectSquare-1] == ' ' && player == 1)
            {
                board[selectSquare-1] = 'O';
                return true;
            } else  if (board[selectSquare-1] == ' ' && player == 2) {
                board[selectSquare-1] = 'X';
                return true;
            }

            return false;
        }
        
        // Check Whose Probale to Win, Lose or Tie
        char checkWinner()
        {
            int totalInput = 0;

            // HORIZONTAL CHECK
            if (board[0] == 'O' && board[1] == 'O' && board[2] == 'O')
                return 'O';
            else if (board[3] == 'O' && board[4] == 'O' && board[5] == 'O')
                return 'O';
            else if (board[6] == 'O' && board[7] == 'O' && board[8] == 'O')
                return 'O';
            // HORIZONTAL CHECK

            // VERTICAL CHECK
            else if (board[0] == 'O' && board[3] == 'O' && board[6] == 'O')
                return 'O';
            else if (board[1] == 'O' && board[4] == 'O' && board[7] == 'O')
                return 'O';
            else if (board[2] == 'O' && board[5] == 'O' && board[8] == 'O')
                return 'O';
            // VERTICAL CHECK

            // DIAGONAL CHECK
            else if (board[0] == 'O' && board[4] == 'O' && board[8] == 'O')
                return 'O';
            else if (board[2] == 'O' && board[4] == 'O' && board[6] == 'O')
                return 'O';
            // DIAGONAL CHECK


            // HORIZONTAL CHECK
            if (board[0] == 'X' && board[1] == 'X' && board[2] == 'X')
                return 'X';
            else if (board[3] == 'X' && board[4] == 'X' && board[5] == 'X')
                return 'X';
            else if (board[6] == 'X' && board[7] == 'X' && board[8] == 'X')
                return 'X';
            // HORIZONTAL CHECK

            // VERTICAL CHECK
            else if (board[0] == 'X' && board[3] == 'X' && board[6] == 'X')
                return 'X';
            else if (board[1] == 'X' && board[4] == 'X' && board[7] == 'X')
                return 'X';
            else if (board[2] == 'X' && board[5] == 'X' && board[8] == 'X')
                return 'X';
            // VERTICAL CHECK

            // DIAGONAL CHECK
            else if (board[0] == 'X' && board[4] == 'X' && board[8] == 'X')
                return 'X';
            else if (board[2] == 'X' && board[4] == 'X' && board[6] == 'X')
                return 'X';
            // DIAGONAL CHECK

            else {
                for (int i = 0; i < 9; i++)
                {
                    if (board[i] != ' ')
                    {
                        totalInput++;
                    }
                }

                if (totalInput == 9)
                    return 'T';
            }
        
            return ' ';
        }

        // Player 1 Controller
        int playerOneController()
        {
            int selectSquare;
            cout << "\nPlayer 1: " << player1 << " O Turns" << endl;
            cout << "Enter an available number position (1-9): ";
            
            while (!(cin >> selectSquare))
            {
                cout << "\n[**Invalid Input**]" << endl
                        << "Enter an available number position (1-9): ";

                cin.clear();
                cin.ignore();
            }

            return selectSquare;
        }

        // Player 2 Controller
        int playerTwoController()
        {
            int selectSquare;

            cout << "\nPlayer 2: " << player2 << " X Turns" << endl;
            cout << "Enter an available number position (1-9): ";
            
            while (!(cin >> selectSquare))
            {
                cout << "\n[**Invalid Input**]" << endl
                        << "Enter an available number position (1-9): ";

                cin.clear();
                cin.ignore();
            }

            return selectSquare;   
        }
        // Computer Controller
        int computerController( int selectSquare)
        {   
            int bestMoves[9] = {5, 1, 3, 7, 9, 2, 4, 6, 8};

            selectSquare = bestMoves[selectSquare];

            return selectSquare;

        }
        // Player VS Player Mode
        void playerToPlayer()
        {
            system("cls");
            cout << "\n == Player VS Player ==" << endl;
            cin.clear();
            cin.ignore();
            // Player 1
            do
            {
                cout << "\nEnter player 1 name (atleast 4 character out of 10): ";
                getline(cin, player1);
            } while (!(player1.length() <= 10 && player1.length() >= 4));
            // Player 2
            do
            {
                cout << "\nEnter player 2 name (atleast 4 character out of 10): ";
                getline(cin, player2);
            } while (!(player2.length() <= 10 && player2.length() >= 4));

            isPvP = true;
        }
        // Player VS Computer Mode
        void playerToComputer(int i)
        {
            string randomName[5] = {"Levi", "Raiden", "Rika", "Rokhai", "Jace"};
            cin.clear();
            cin.ignore();
            system("cls");
            cout << "\n == Player VS Computer ==" << endl;
            // Player 1
            do
            {
                cout << "Enter player 1 name (10 character): ";
                getline(cin, player1);
            } while (!(player1.length() <= 10 && player1.length() >= 4));
            // Computer
            player2 = randomName[i];

            isPvC = true;   
        }

        void play()
        {
            while (isGameOn)
            {
                while (isPlaying)
                {
                    displayBoard();

                    if (isPvP)
                    {
                        if (iCurrentPlayer == 1)
                        {
                            if (verifySelection(playerOneController(), iCurrentPlayer))
                                iCurrentPlayer = 2;
                            else 
                                iCurrentPlayer = 1;
                        } else if (iCurrentPlayer == 2) {
                            if (verifySelection(playerTwoController(), iCurrentPlayer))
                                iCurrentPlayer = 1;
                            else 
                                iCurrentPlayer = 2;
                        }

                    } else if (isPvC) {
                        if (iCurrentPlayer == 1)
                        {
                            if (verifySelection(playerOneController(), iCurrentPlayer))
                                iCurrentPlayer = 2;
                            else 
                                iCurrentPlayer = 1;
                        } else if (iCurrentPlayer == 2) {
                            if (verifySelection(computerController(comChoice), iCurrentPlayer))
                                iCurrentPlayer = 1;
                            else 
                                iCurrentPlayer = 2;
                            comChoice++;
                        }

                    } else {
                        system("cls");
                        cout << "[**Something Wrong**]" << endl;
                        exit(1);
                    }

                    if (checkWinner() == 'O')
                    {
                        system("cls");
                        displayBoard();
                        cout << "\n[***Player O \'" << player1 << "\' Wins!!***]" << endl;
                        player1Score++;
                        isPlaying = false;
                    } else if (checkWinner() == 'X') {
                        system("cls");
                        displayBoard();
                        cout << "\n[***Player X \'" << player2 << "\' Wins!!***]" << endl;
                        player2Score++;
                        isPlaying = false;
                    } else  if (checkWinner() == 'T') {
                        system("cls");
                        displayBoard();
                        cout << "\n[***It's A Draw!!***]" << endl;
                        isPlaying = false;
                    }
                    
                }

                if (playAgain())
                {
                    system("cls");
                    newBoard();
                    iCurrentPlayer = 1;
                    currentRound++;
                    isPlaying = true;
                } else {
                    cout << "\nThank YOU! for Playing!!" << endl;
                    isGameOn = false;
                    exit(1);
                }
            }
        }

        // Main Menu
        int menu()
        {
            cout << "\nOptions:" << endl;
            cout << "1. Player vs Player" << endl;
            cout << "2. Player vs Computer" << endl;
            cout << "\n0. Quit" << endl;
            cout << "\nChoose (0-2): ";
            while (!(cin >> inputChoice))
            {
                cin.clear();
                cin.ignore();
                cout << "\n[*** Out of Bound Choice!! ***]" << endl
                    << "Choose (0-2): ";
            }
            return inputChoice;
        }

        TicTacToe()
        {
            system("cls");
            loadingDsiplay();
            cout << "\nCreated New TicTacToe Board" << endl;
            displayInstruct();
            newBoard();
            
        }


};

int main()
{
    srand(time(0));

    TicTacToe ticTacToeObject = TicTacToe();

    while (true)
    {
        switch (ticTacToeObject.menu())
        {
            case 1:
                ticTacToeObject.playerToPlayer();
                ticTacToeObject.play();
            break;

            case 2:
                ticTacToeObject.playerToComputer(rand() % 5);
                ticTacToeObject.play();
            break;

            case 0:
                cout << "Thank YOU!" << endl;
            break;

            default:
                cout << "\n[*** Invalid Input ***]" << endl;
            break;
        }
    }
}