/******************************************************************

    Simple Tic-Tac-Toe in C++
        - demonstrates use of Function, Return Types and
            partially it's paradigm

    December 05, 2021

    Rosgen D. Hizer 
    @Rokhai
******************************************************************/

#include <iostream>

using namespace std;

/***********************
    GLOBAL VARIABLES
************************/
int playerO_score = 0;
int playerX_score = 0;
char board[8];
char cWhoWon = ' ';
int iCurrentPlayer = 1;

// Ask if the PLayer Want to Play Again
bool tryAgain()
{
    while (true)
    {
        char yesOrNo;
        cout << "\nWant to try again? (y/n): ";
        cin >> yesOrNo;

        if (tolower(yesOrNo) == 'y')
        {
            return true;
        } else if (tolower(yesOrNo) == 'n') {
            return false;
        } else {
            cout << "Invalid Input!!" << endl;
        }
    }
}

// Player O Controller
int player_O()
{
    int iSquareNum;
    cout << "\nPlayer O Turn" << endl;
    cout << "Enter an available sqaure number (1-9): ";
    
    while (!(cin >> iSquareNum))
    {
        cout << "[**Invalid Input**]" << endl
            << "Enter an available sqaure number (1-9): ";

            cin.clear();
            cin.ignore();
    }

    return iSquareNum;
    
}

int player_X()
{
    int iSquareNum;
    cout << "\nPlayer X Turn" << endl;
    cout << "Enter an available sqaure number (1-9): ";

    while (!(cin >> iSquareNum))
    {
        cout << "[**Invalid Input**]" << endl
            << "Enter an available sqaure number (1-9): ";

            cin.clear();
            cin.ignore();
    }
    return iSquareNum;
}
// Create New Playable Board
void newBoard()
{
    for (int i = 0; i < 9; i++)
        board[i] = ' ';
}

// Display Game Instruction
void displayInstruct()
{
    cout << "\t\tWelcome To Tic-Tac-Toe Game\n"
            << "You will make your move known by entering a number, 1-9.\n"
            << "The number correspond to the board position as illustrated: \n\n"
            << "\t\t1 | 2 | 3\n"
            << "\t\t---------\n"
            << "\t\t4 | 5 | 6\n"
            << "\t\t---------\n"
            << "\t\t7 | 8 | 9" << endl;
    cout << "\t[*** Prepare Yourself ***]\n" << endl;
}

// Diplay State of the Board
void displayBoard()
{
    cout << "\n";
    cout << "\t" << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << "\t---------" << endl;
    cout << "\t" << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "\t---------" << endl;
    cout << "\t" << board[6] << " | " << board[7] << " | " << board[8] << endl;
    
    cout << "\nScore Board" << endl;
    cout << "- - - - - - - - - - - - - " << endl;
    cout << "Player O Score: " << playerO_score << endl
         << "Player X Score: " << playerX_score << endl
         << "- - - - - - - - - - - - - " << endl;
}

// Checks if Selection is Valid
bool verifySelection(int selecSquare, int player)
{
    if (board[selecSquare-1] == ' ' && player == 1)
    {
        board[selecSquare-1] = 'O';
        return true;
    } else if (board[selecSquare-1] == ' ' && player == 2) {
        board[selecSquare-1] = 'X';
        return true;
    }
    return false;
}

// Check Who is Probable to Win
char checkForWin()
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

int main()
{
    bool is_playing = true;
    bool is_game_on = true;

    while (is_game_on)
    {
        newBoard();
        displayInstruct();

        while (is_playing)
        {
            displayBoard();

            if (iCurrentPlayer == 1)
            {
                if (verifySelection(player_O(), iCurrentPlayer))
                    iCurrentPlayer = 2;
                else
                    iCurrentPlayer = 1;
            } else if (iCurrentPlayer == 2) {
                if (verifySelection(player_X(), iCurrentPlayer))
                    iCurrentPlayer = 1;
                else 
                    iCurrentPlayer = 2;
            }

            if (checkForWin() == 'O')
            {
                displayBoard();
                cout << "\n[***Player O Wins!!***]" << endl;
                playerO_score++;
                is_playing = false;
            } else if (checkForWin() == 'X') {
                displayBoard();
                cout << "\n[***Player X Wins!!***]" << endl;
                playerX_score++;
                is_playing = false;
            } else if (checkForWin() == 'T') {
                displayBoard();
                cout << "\n[***It's A Draw!!***]" << endl;
                is_playing = false;
            }
        }

        if (tryAgain())
        {
            system("cls");
            newBoard();
            iCurrentPlayer = 1;
            is_playing = true;
        } else {
            cout << "\nThank YOU! for Playing!!" << endl;
            is_game_on = false;
            exit(1);
        }
    }
}