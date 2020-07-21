#include "FBossBattle.h"

FBossBattle::FBossBattle() {
	ResetGame();
}

void FBossBattle::ResetGame()
{
	//pick a boss
	currentBoss = BossSelector();
	//reset player values
	playerHealth = 20;
	playerAttack = 1;
	playerDefense = 1;

}

void FBossBattle::PrintIntro() {
	std::cout
		<< "//////////////////////////////////////////////////////\n"
		<< "///////////   Welcome to Boss Battle!  ///////////////\n"
		<< "//////////////////////////////////////////////////////\n\n"

		<< "Press the number of the attack you wish to use.\n"
		<< "Good Luck.\n\n";
}

void FBossBattle::PrintInfo() {
	std::cout 
		<< "Boss: " << currentBossName << "\n"
		<< "Health: " << bossHealth << std::endl
		<< "\n"
		<< "Player: \n"
		<< "Health: " << playerHealth << " Attack: " << playerAttack << " Defense: " << playerDefense << std::endl;
}

FText FBossBattle::GetBossName() {
	switch (currentBoss)
	{
	case Bosses::Cyclops:
		currentBossName = "Cyclops";
		break;
	case Bosses::Dragon:
		currentBossName = "Dragon";
		break;
	case Bosses::Ogre:
		currentBossName = "Ogre";
		break;
	default:
		break;
	}

}

Bosses FBossBattle::BossSelector() {
	int ind = std::rand() % 3;
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

