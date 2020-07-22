#include "FBossBattle.h"

using namespace std::this_thread;
FBossBattle::FBossBattle() {
	ResetGame();
}

void FBossBattle::ResetGame()
{
	//pick a boss
	currentBoss = BossSelector();
	currentBossName = GetBossName();
	//reset player values
	playerHealth = 20;
	playerAttack = 1;
	playerDefense = 1;

}

void FBossBattle::PrintIntro() {
	
}

void FBossBattle::PrintInfo() {
	const int32 textDelay = 1000000;
	std::cout
		<< "Boss: " << currentBossName << "\n"
		<< "Health: " << bossHealth << std::endl
		<< "\n"
		<< "Player: " << playerName << "\n"
		<< "Health: " << playerHealth << " Attack: " << playerAttack << " Defense: " << playerDefense << std::endl << std::endl;
	std::this_thread::sleep_for(std::chrono::microseconds(textDelay));
	std::cout
		<< "Choose Your Move:" << std::endl
		<< "1. Attack          2. Power Boost" << std::endl
		<< "3. Defense Boost   4. Heal" << std::endl <<std::endl;

}

void FBossBattle::SetPlayerName(FText name)
{
	playerName = name;
}

PlayerMoves FBossBattle::ConvertPlayerMove(int32 selection)
{
	switch (selection)
	{
	case 1:
		return PlayerMoves::Attack;
	case 2:
		return PlayerMoves::PowerUp;
	case 3:
		return PlayerMoves::DefenseUp;
	case 4:
		return PlayerMoves::Heal;
	case 0:
		return PlayerMoves::Error;
	default:
		break;
	}
	return PlayerMoves::None;
}

PlayerMoves FBossBattle::GetSelectedMove()
{
	return selectedMove;
}

void FBossBattle::SetPlayerMove(PlayerMoves validMove)
{
	selectedMove = validMove;
}

FText FBossBattle::GetBossName() {
	switch (currentBoss)
	{
	case Bosses::Cyclops:
		return "Cyclops";
		break;
	case Bosses::Dragon:
		return "Dragon";
		break;
	case Bosses::Ogre:
		return "Ogre";
		break;
	default:
		break;
	}
	return "";
}

Bosses FBossBattle::BossSelector() {
	int ind = std::rand() % 3; //TODO fix the random number bug
	switch (ind) {
	case 0:
		bossHealth = 30;
		bossAttack = 5;
		bossDefense = 1;
		return Bosses::Dragon;
	case 1:
		bossHealth = 20;
		bossAttack = 3;
		bossDefense = 2;
		return Bosses::Cyclops;
	case 2:
		bossHealth = 25;
		bossAttack = 2;
		bossDefense = 4;
		return Bosses::Ogre;
	default:
		break;
	}
	return Bosses::Error;
}

