#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main() {
    srand(time(0));
    int numberToGuess = rand() % 100 + 1;
    int tries = 0;
    cout << "welcometo the number guessing game. " << endl;
    cout << "please guess a number between 1 and 100." << endl;
    while (true) {
        int userGuess;
        cout << "Take a guess: ";
        cin >> userGuess;
        if (userGuess < 1 || userGuess > 100) {
            cout << "Please enter a number between 1 and 100." << endl;
            continue;
        }
        tries++;
        if (userGuess == numberToGuess) {
            cout << "Congratulations! You've guessed the number in " << tries << " tries." << endl;
            break;
        } else if (userGuess < numberToGuess) {
            cout << "you have guess lesser no.than actual no.! Try again." << endl;
        } else {
            cout << "you have guess larger no.than actual no.! Try again." << endl;
        }
    }
    return 0;
}
