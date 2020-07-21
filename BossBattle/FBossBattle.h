#pragma once

#include<iostream>


using int32 = int;
using FText = std::string;
enum class Bosses {
	Dragon,
	Ogre,
	Cyclops,
	Error
};

class FBossBattle {
public:
	FBossBattle();
	//resets game
	void ResetGame();
	void PrintIntro();
	void PrintInfo();
	void SetPlayerName(FText name);
	FText GetBossName();
	Bosses BossSelector();
	

private:
	//player stats
	int32 playerHealth = 20;
	int32 playerAttack = 1;
	int32 playerDefense = 1;

	//boss stats
	int32 bossHealth = 20;
	int32 bossAttack = 1;
	int32 bossDefense = 1;

	FText playerName;

	FText currentBossName;
	Bosses currentBoss;

};