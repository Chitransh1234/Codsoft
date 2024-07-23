#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void playGuessingGame()
{
    srand(time(0));

    int randomNumber = rand() % 100 + 1;
    int userGuess = 0;
    int numberOfGuesses = 0;

    cout << "Welcome to the Guessing Game!" << endl;
    cout << "I have generated a random number between 1 and 100." << endl;
    cout << "Can you guess what it is?" << endl;

    while (userGuess != randomNumber)
    {
        cout << "Enter your guess: ";
        cin >> userGuess;
        numberOfGuesses++;

        if (userGuess < randomNumber)
        {
            cout << "Too low! Try again." << endl;
        }
        else if (userGuess > randomNumber)
        {
            cout << "Too high! Try again." << endl;
        }
        else
        {
            cout << "Congratulations! You guessed the correct number in " << numberOfGuesses << " attempts." << endl;
        }
    }
}

int main()
{
    char playAgain;
    do
    {
        playGuessingGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!" << endl;
    return 0;
}
