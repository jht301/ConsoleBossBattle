#include "FBossBattle.h"

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
	std::cout 
		<< "Boss: " << currentBossName << "\n"
		<< "Health: " << bossHealth << std::endl
		<< "\n"
		<< "Player: " << playerName <<"\n"
		<< "Health: " << playerHealth << " Attack: " << playerAttack << " Defense: " << playerDefense << std::endl;
}

void FBossBattle::SetPlayerName(FText name)
{
	playerName = name;
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

