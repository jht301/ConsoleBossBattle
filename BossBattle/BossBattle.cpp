// BossBattle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "FBossBattle.h"

using FText = std::string;
using int32 = int;
bool bossAlive = true;
bool playerAlive = true;
FBossBattle BossBat;

void RunIntro();
void FightBoss();
void DoTheMove();
PlayerMoves PickValidMove();

int main()
{
    //Introduction
    RunIntro();
    
    FightBoss();
    //Battle 
    //End game
    //Reset?

}



void FightBoss() {
    do {
        //print stats
        BossBat.PrintInfo();
        PickValidMove(); //Validates selection and returns the player's move

        DoTheMove();
        //check for win conditions
        if (BossBat.GetBossHealth <= 0) {
            bossAlive = false;
            std::cout << BossBat.GetPlayerName() << " WINS!!\n";
        }
        else {
            //boss attack

            //is player alive
        }

    } while (bossAlive && playerAlive);
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

PlayerMoves PickValidMove() {
    int32 moveNumber;
    std::cin >> moveNumber; //have the player choose the number
    PlayerMoves selectedMove = BossBat.ConvertPlayerMove(moveNumber);
    if (selectedMove == PlayerMoves::Error) {
        std::cout << "Please choose a number from 1-4\n";
        std::cin.clear();
        std::cin.ignore();
        PickValidMove();
    }
    else {
        BossBat.SetPlayerMove(selectedMove);

        return selectedMove;
    }
}

void DoTheMove() {
    switch (BossBat.GetPlayerMove())
    {
    case PlayerMoves::Attack:
        BossBat.Attack();
        break;
    case PlayerMoves::PowerUp:
        BossBat.PowerUp();
        break;
    case PlayerMoves::DefenseUp:
        BossBat.DefenseUp();
        break;
    case PlayerMoves::Heal:
        BossBat.Heal();
        break;
    default:
        break;
    }
}
