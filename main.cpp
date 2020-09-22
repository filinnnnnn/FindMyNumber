//
//  main.cpp
//  FindMyNumber
//
//  Created by user on 19.09.2020.
//  Copyright © 2020 user. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

enum statusTypes
{
    ST_IDLE,
    ST_SMALLER,
    ST_BIGGER,
    ST_CORRECT
};

void startPlayLikeFinder()
{
    srand(static_cast<unsigned int>(time(0)));
    int secretNumber = rand() % 100 + 1;
    int tries = 0;
    int guessNumber;
    do
    {
        std::cout << "\nEnter a guess: ";
        std::cin >> guessNumber;
        ++tries;

        if (guessNumber > secretNumber)
        {
            std::cout << "Too high!!!\n\n";
        }
        else if (guessNumber < secretNumber)
        {
            std::cout << "Too low!!!\n\n";
        }
        else
        {
            std::cout << "\nThat it! You got it in " << tries << " tries!" << std::endl;
        }
    } while (guessNumber != secretNumber);
}

void startPlayLikeNigma ()
{
    int secretNumber, guessNumber, choise, tries, smallerNumber, biggerNumber, state = ST_IDLE;
    int min = 1;
    int max = 101;
    
    std::cout << "\nEnter your Secret Number: ";
    std::cin >> secretNumber;
    
    srand(static_cast<unsigned int>(time(0)));
    guessNumber = rand() % 100 + 1;
    
    do
    {
        ++tries;
        
        std::cout << "\nI'll try to find it...";
        std::cout << "\nMy guess... " << guessNumber;
        std::cout << "\nAnd that's my " << tries << " try!\n\n";
        std::cout << "\t\t-1- Too high!\n";
        std::cout << "\t\t-2- Too low!\n";
        std::cout << "\t\t-3- That's my number!\n";
        std::cin >> choise;

        switch (choise)
        {
            case 1:
                state = ST_SMALLER;
                max = guessNumber;
                smallerNumber = rand() % (max - min) + min;
                if (guessNumber == smallerNumber) smallerNumber++;
                guessNumber = smallerNumber;
                break;
                
            case 2:
                state = ST_BIGGER;
                min = guessNumber;
                biggerNumber = rand() % (max - min) + min;
                if (guessNumber == biggerNumber) biggerNumber++;
                guessNumber = biggerNumber;
                break;
                
            case 3:
                state = ST_CORRECT;
                std::cout << "\nYou're Secret Number was " << secretNumber;
                std::cout << "\nI have found it by " << tries << " tries.";
                std::cout << "\nSee U Soon!";
            break;
        }
    } while (state != ST_CORRECT);
};

int main(int argc, const char * argv[])
{
    std::cout << "\t\tWelcome to Find My Number!\n\n";
    std::cout << "\t\tChoose yopur side:\n ";
    std::cout << "\t\t-1- Finder...\n";
    std::cout << "\t\t-2- Nigma...\n";
    unsigned int side;
    std::cin >> side;
    
    switch (side)
    {
        case 1:
            startPlayLikeFinder();
            break;
            
        case 2:
            startPlayLikeNigma();
            break;
    }
    return 0;
}


