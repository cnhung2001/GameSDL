#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int generateRandomNumber(){
    return rand() % 100 + 1;
}

int getPlayerNumber(){
    int guess;
    cout << "Enter your guess (1..100)";
    cin >> guess;
    return guess;
}

void printAnswer(int guess, int secretNumber){
    if (guess < secretNumber) cout << "Too small" << endl;
    else if (guess > secretNumber) cout << "Too big" << endl;
    else cout << "Correct. You win" << endl;

}
void playGuessIt(){
    int guessCount = 0;
    int secretNumber = generateRandomNumber();
    int guess;

    do{
        guess = getPlayerNumber();
        guessCount++;
        printAnswer(guess, secretNumber);
        cout << "This is the " <<  guessCount << "th guess" << endl;
        cout << "Score: " << 100 - guessCount << endl;
    } while (guess != secretNumber);
}

int main()
{
    srand(time(0));
    char isContinued;
    do {
        playGuessIt();
        cout << "Do you want play again Guess It(y/n)" << endl;
        cin >> isContinued;
    } while (isContinued == 'y' || isContinued == 'Y');
    return 0;
}
