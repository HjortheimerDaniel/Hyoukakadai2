#include "Stage.h"

Stage::Stage() {

    enemy[0] = new Mob1(
	    {
	        {100, 200},
            {228, 200},
            {100, 328},
            {228, 328}
    },
	    {4.0f, 4.0f}, 7);

    player = new Player(
	    {
	        {500, 400},
            {628, 400},
            {500, 528},
            {628, 528}
    },
	    {4.0f, 4.0f});

	 enemy[1] = new Mob2(
	    {
	        {500, 50},
            {628, 50},
            {500, 178},
            {628, 178}
    },
	    {4.0f, 4.0f}, 7);


    playerDamageCooldown_ = 0;
	playerIFrames = false;
	gameOver = false;
	gameClear = false;
}

void Stage::Initialize() {

	player->Initialize(
	    {
	        {500, 400},
            {628, 400},
            {500, 528},
            {628, 528}
    },
	    {4.0f, 4.0f});

	enemy[0]->Initialize(
	    {
	        {100, 200},
            {228, 200},
            {100, 328},
            {228, 328}
    },
	    {4.0f, 4.0f}, 7);

	enemy[1]->Initialize(
	    {
	        {500, 50 },
            {628, 50 },
            {500, 178},
            {628, 178}
    },
	    {4.0f, 4.0f}, 7);

	/*enemy[0]->SetPos({
	    {100, 200},
        {228, 200},
        {100, 328},
        {228, 328}
    });

	enemy[1]->SetPos({
	    {700, 50},
        {828, 50},
        {700, 178},
        {828, 178}
    });

    player->SetPos({
	    {500, 400},
        {628, 400},
        {500, 528},
        {628, 528}
    });*/

    playerDamageCooldown_ = 0; 
    playerIFrames = false;
	gameOver = false;
	gameClear = false;
}

void Stage::Update(char* keys, char* preKeys) {
	for (int i = 0; i < MAXENEMIES; i++) {

		enemy[i]->Update();
	}
		player->Update(keys, preKeys);
		Restart(keys, preKeys);
		CollisionPlayerEnemy();
		CollisionBulletEnemy();
		CollisionEnemyBulletPlayer();
		GameOver();
	    GameClear();

}

void Stage::CollisionPlayerEnemy() {
	    for (int i = 0; i < MAXENEMIES; i++) {
			if (CheckCollision(
		        player->GetPos().UL, {enemy[i]->GetPos().UL.x, enemy[i]->GetPos().UL.y},
		        player->GetSize(), {enemy[i]->GetSize().x, enemy[i]->GetSize().y}) &&
		    playerDamageCooldown_ == 0 && !enemy[i]->GetIsDestroyed()) {
			player->SetIsDamaged(true);
			}
			if (player->GetIsDamaged()) {
			playerIFrames = true;
			}
	    }

        if (playerIFrames) {
		        playerDamageCooldown_++;
        }

        if (playerDamageCooldown_ >= 60) {
		        playerIFrames = false;
		        playerDamageCooldown_ = 0;
		        player->SetIsDamaged(false);
        }

}

void Stage::CollisionBulletEnemy() {

    for (int i = 0; i < 10; i++) {
		for (int j = 0; j < MAXENEMIES; j++) {

			if (CheckCollision(
			        player->GetBulletPos()[i], {enemy[j]->GetPos().UL.x, enemy[j]->GetPos().UL.y},
			        {10, 10}, {enemy[j]->GetSize().x, enemy[j]->GetSize().y}) &&
			    !enemy[j]->GetIsDestroyed()) {
				enemy[j]->SetIsDamaged(true);
				player->SetBulletY(-40, i);
			}
		        }
	    }

}

void Stage::CollisionEnemyBulletPlayer() {

     for (int i = 0; i < 4; i++) {
		        for (int j = 0; j < MAXENEMIES; j++) {

			if (CheckCollision(
			        enemy[j]->GetBossBulletPos()[i], {player->GetPos().UL.x, player->GetPos().UL.y},
			        {64, 64}, {player->GetSize().x, player->GetSize().y})) {
				player->SetIsDamaged(true);
				enemy[j]->SetBulletY(1500, i);
			}
		        }
	    }

}

void Stage::GameOver() {

	if (player->GetIsDead()) {
		gameOver = true;
	} else {
		gameOver = false;
	}
}

void Stage::GameClear() {

	
		if (enemy[0]->GetIsDead() && enemy[1]->GetIsDead()) {
			gameClear = true;
		}
	
}

void Stage::Draw() {
	  player->DrawHeart();
	for (int i = 0; i < MAXENEMIES; i++) {
		enemy[i]->Draw();

	}
	player->Draw();

}

void Stage::Restart(char* keys, char* preKeys) {

    if (keys[DIK_R] && !preKeys[DIK_R]) {
		enemy[0]->Initialize(
		    {
		        {100, 200},
                {228, 200},
                {100, 328},
                {228, 328}
        },
		    {4.0f, 4.0f}, 7);

		 enemy[1]->Initialize(
		    {
		        {700, 50 },
                {828, 50 },
                {700, 178},
                {828, 178}
        },
		    {4.0f, 4.0f}, 7);

           player->Initialize(
		    {
		        {500, 400},
                {628, 400},
                {500, 528},
                {628, 528}
        },
		    {4.0f, 4.0f});
    }

 

}


