/* 
Author: Hesham Salama - heshamsalama.com | hes8519@thi.de
THI-AVE: Programming2 - Assignment0
Name: Guess The Number
*/

#include <iostream>

int main()
{
    srand((unsigned) time(NULL)); // initialize a random number generator
    
    int number = 0; // Random Number To be Guessed.
    int x = 0; // Current Number
    bool found = false; // state of the number being found or not.
    bool stopped = false; // premature end of the game
    
    int number_of_tries = 0;
    
    std::cout << "Guess-The-Number (v0.1.0)" << std::endl;
    
    number = (rand() % 1000) + 1;
    
    while(!found && !stopped) {
        std::cout << "Enter a number between 1 and 1000 (Enter 0 to quit):\t";
        std::cin >> x;

        if (x == 0) {
            stopped = true;
        }
        else if (x < number) {
            std::cout << "Your guess is too small!\n\n";
        }
        else if (x > number) {
            std::cout << "Your guess is too large!\n\n";
        }
        else {
            found = true;
        }

        number_of_tries++;
    } // End While
    
    if (found) {
        std::cout << "Congratulations! You guessed the number." << std::endl;
        std::cout << "The number is:\t:" << number << std::endl;
        std::cout << "Number of tries:\t" << number_of_tries << std::endl;
    }
    else {
        std::cout << "Uh-oh! You didn\'t guess the number. Better luck next time." << std::endl;
    }

    return 0;
} // End Main
