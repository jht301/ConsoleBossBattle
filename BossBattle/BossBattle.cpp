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
PlayerMoves GetValidMove();

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
        PlayerMoves thisMove = GetValidMove(); //Validates selection and returns the player's move

        std::cout << "Selected: ";

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

PlayerMoves GetValidMove() {
    int32 moveNumber;
    std::cin >> moveNumber; //have the player choose the number
    PlayerMoves selectedMove = BossBat.ConvertPlayerMove(moveNumber);
    if (selectedMove == PlayerMoves::Error) {
        std::cout << "Please choose a number from 1-4\n";
        std::cin.clear();
        std::cin.ignore();
        GetValidMove();
    }
    else {
        return selectedMove;
    }
}

