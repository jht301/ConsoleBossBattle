#pragma once

#include<iostream>
#include <thread>

using int32 = int;
using FText = std::string;
enum class Bosses {
	Dragon,
	Ogre,
	Cyclops,
	Error
};
enum class PlayerMoves {
	Attack,
	PowerUp,
	DefenseUp,
	Heal,
	None,
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

	PlayerMoves ConvertPlayerMove(int32 selection);
	PlayerMoves GetSelectedMove();
	void SetPlayerMove(PlayerMoves validMove);

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
	PlayerMoves selectedMove = PlayerMoves::None;

	FText currentBossName;
	Bosses currentBoss;

};