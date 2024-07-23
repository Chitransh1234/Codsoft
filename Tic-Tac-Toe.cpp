#include <iostream>
using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE];
char currentPlayer;

void initializeBoard()
{
    int count = 1;
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            board[i][j] = '0' + count++;
        }
    }
}

void displayBoard()
{
    cout << "Current Board:" << endl;
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            cout << board[i][j];
            if (j < SIZE - 1)
                cout << " | ";
        }
        cout << endl;
        if (i < SIZE - 1)
            cout << "--|---|--" << endl;
    }
}

bool isValidMove(int move)
{
    int row = (move - 1) / SIZE;
    int col = (move - 1) % SIZE;
    return (move >= 1 && move <= 9 && board[row][col] != 'X' && board[row][col] != 'O');
}

void makeMove(int move)
{
    int row = (move - 1) / SIZE;
    int col = (move - 1) % SIZE;
    board[row][col] = currentPlayer;
}

bool checkWin()
{
    for (int i = 0; i < SIZE; ++i)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
    }
    for (int i = 0; i < SIZE; ++i)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;
    return false;
}

bool checkDraw()
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }
    return true;
}

void switchPlayer()
{
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void playGame()
{
    initializeBoard();
    currentPlayer = 'X';
    bool gameOngoing = true;

    while (gameOngoing)
    {
        displayBoard();
        int move;
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        if (isValidMove(move))
        {
            makeMove(move);
            if (checkWin())
            {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameOngoing = false;
            }
            else if (checkDraw())
            {
                displayBoard();
                cout << "The game is a draw!" << endl;
                gameOngoing = false;
            }
            else
            {
                switchPlayer();
            }
        }
        else
        {
            cout << "Invalid move. Try again." << endl;
        }
    }
}

int main()
{
    char playAgain;
    do
    {
        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!" << endl;
    return 0;
}
