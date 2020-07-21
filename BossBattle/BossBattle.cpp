// BossBattle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "FBossBattle.h"

using FText = std::string;
using int32 = int;
bool runGame = true;
FBossBattle BossBat;

void RunIntro();
void PlayGame();

int main()
{
    //Introduction
    RunIntro();
    
    PlayGame();
    //Battle 
    //End game
    //Reset?

}



void PlayGame() {
    do {
        //print stats
        BossBat.PrintInfo();
        
        //attack
        //defend 
        //check for win conditions
        
        runGame = false;

    } while (runGame);
}

void RunIntro() {
    std::cout
        << "//////////////////////////////////////////////////////\n"
        << "///////////   Welcome to Boss Battle!  ///////////////\n"
        << "//////////////////////////////////////////////////////\n\n"

        << "Press the number of the attack you wish to use.\n"
        << "Good Luck.\n\n";

    std::cout << "What's your name? ";

    FText name = "";

    std::getline(std::cin, name);
    BossBat.SetPlayerName(name);

    std::cout << "\n\n";
}

