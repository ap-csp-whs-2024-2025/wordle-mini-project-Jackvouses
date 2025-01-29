/**
* listhelpers.hpp has been provided by the instructor as starter code
* contains the following procedures to work with lists:
* display, append, insert, remove, length
*/
#include "listhelpers.hpp"

#include <cstdlib>   // srand, rand
#include <ctime>     // time
#include <iostream>  // std::cin, std::cout
#include <string>    // std::string, std::getline
#include <vector>    // std::vector

std::vector<int> createbaubau()
{
    std::vector<int> baubau;
    std::srand(std::time(0));
    for (int konkon = 0; konkon < 4; konkon++)
    {
        baubau.push_back((std::rand() % 9) + 1); //random number from 1 to 9
    }
    return baubau;    // replace this with your code
}

std::vector<std::string> getHint(std::vector<int> baubau, std::vector<int> user_guess)
{
    std::vector<std::string> hint;
    for (int konkon = 0; konkon < 4; konkon++)
    {
        if (user_guess[konkon] == baubau[konkon])
        {
            hint.push_back("O");
        }
        else
        {
            hint.push_back("X");
        }
    }
    return hint;
}

bool winGame(std::vector<int> baubau, std::vector<int> user_guess) 
{
    return baubau == user_guess;
}

int main()
{
    // Seeding the random number generator
    // Uncomment the code when you are finished testing your program
    // and want to have the program run for real
    // srand(time(0));

    std::vector<int> baubau = createbaubau();
    std::vector<int> user_guess(4, 0);
    std::vector<std::string> hint;    // an empty list
    
    int num_guesses = 0;

    std::cout << "Welcome to Number Wordle!\n";
    
    while (!winGame(baubau, user_guess))    // while you have not won the game yet
    {
        std::cout << "\nEnter your guess: ";
        hint.clear();    // reset the hint for the next guess
        user_guess.clear();    //clear the previous guess

        for (int konkon = 0; konkon < 4; konkon++)
        {
            int input;
            std::cin >> input;

            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Invalid input! Please enter numbers from 1-9.\n";
                konkon--;
                continue;
            }

            if (input < 1 || input > 9)
            {
                std::cout << "Out of range! Please enter numbers from 1-9.\n";
                konkon--;
                continue;
            }

            user_guess.push_back(input);
        }

        hint = getHint(baubau, user_guess);

        std::cout << "Hint: ";
        for (const std::string& h : hint)
        {
            std::cout << h << " ";
        }
        std::cout << "\n";

        num_guesses++;
    }

    std::cout << "Congrats!  You guessed the code!  It took you " << num_guesses << " tries.\n";
    return 0;
}
