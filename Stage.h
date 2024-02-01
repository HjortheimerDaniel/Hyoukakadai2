#pragma once
#include "Mob1.h"
#include "Mob2.h"
#include "Struct.h"
#include "Player.h"
#include "Functions.h"


class Stage {

	public:

	Stage();

	bool GetGameOver() { return gameOver; };

	bool GetGameClear() { return gameClear; };

	void Initialize();

	void Update(char* keys, char* preKeys);

	void CollisionPlayerEnemy();

	void CollisionBulletEnemy();

	void CollisionEnemyBulletPlayer();

	void GameOver();

	void GameClear();

	void Draw();

	void Restart(char* keys, char* preKeys);

	private:

		Enemy* enemy[MAXENEMIES];
	    Player* player;
	    int playerDamageCooldown_;
	    bool playerIFrames;
	    bool gameOver;
	    bool gameClear;
	   



};
