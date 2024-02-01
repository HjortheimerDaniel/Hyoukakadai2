#include "Player.h"

Player::Player(Quad pos, Vector2 speed) {

	player_.pos = pos;
	player_.hitbox = {};
	player_.speed = speed;
	player_.handle = Novice::LoadTexture("./Sprites/player.png");
	for (int i = 0; i < 3; i++) {
		player_.heartHandle[i] = Novice::LoadTexture("./Sprites/heartbig.png");
	}
	player_.isDead = false;
	player_.animation = 0;
	player_.frames = 0;
	player_.size = {58, 68};
	player_.isDamaged = false;
	player_.damagedTimer = 0;
	player_.HP = 3;
	player_.color = WHITE;

}

void Player::Initialize(Quad pos, Vector2 speed) {

	player_.pos = pos;
	player_.hitbox = {};
	player_.speed = speed;
	player_.isDead = false;
	player_.isDamaged = false;
	player_.damagedTimer = 0;
	player_.HP = 3;
	player_.color = WHITE;

	InitializeBullet();

}

void Player::Movement(char* keys, char* preKeys) {

	player_.speed.x = 0;
	player_.speed.y = 0;

	if (keys[DIK_D] && preKeys[DIK_D] && player_.pos.UL.x <= 1140 && !keys[DIK_A] &&
	    !preKeys[DIK_A]) {
		player_.speed.x = +5;
	}

	if (keys[DIK_A] && preKeys[DIK_A] && player_.pos.UL.x >= 0 && !keys[DIK_D] && !preKeys[DIK_D]) {
		player_.speed.x = -5;
	}

	if (keys[DIK_S] && preKeys[DIK_S]) {
		player_.speed.y = +5;
	}

	if (keys[DIK_W] && preKeys[DIK_W]) {
		player_.speed.y = -5;
	}

	float normalizeSpeed =
	    sqrtf(player_.speed.x * player_.speed.x + player_.speed.y * player_.speed.y);
	if (normalizeSpeed != 0.0f) {
		player_.speed.x /= normalizeSpeed;
		player_.speed.y /= normalizeSpeed;
	}

	player_.pos.UL.x += player_.speed.x * 5;
	player_.pos.UR.x += player_.speed.x * 5;
	player_.pos.LL.x += player_.speed.x * 5;
	player_.pos.LR.x += player_.speed.x * 5;
	player_.pos.UL.y += player_.speed.y * 5;
	player_.pos.UR.y += player_.speed.y * 5;
	player_.pos.LL.y += player_.speed.y * 5;
	player_.pos.LR.y += player_.speed.y * 5;

}

void Player::HitBox() {

	player_.hitbox.UL.x = player_.pos.UL.x  + 30;
	player_.hitbox.UL.y = player_.pos.UL.y  + 30;
	player_.hitbox.UR.x = player_.pos.UR.x  - 40;
	player_.hitbox.UR.y = player_.pos.UR.y  + 30;
	player_.hitbox.LL.x = player_.pos.LL.x  + 30;
	player_.hitbox.LL.y = player_.pos.LL.y  - 30;
	player_.hitbox.LR.x = player_.pos.LR.x  - 40;
	player_.hitbox.LR.y = player_.pos.LR.y  - 30;
}

void Player::PlayerDamaged() {

	if (player_.isDamaged) {
		player_.damagedTimer++;
		player_.color = RED;
	} else {
		player_.color = WHITE;
	}

	if (player_.damagedTimer == 1) {
		player_.HP--;
	}

	if (player_.damagedTimer >= 60) {
		player_.damagedTimer = 0;
	}

	if (player_.HP <= 0) {
		player_.isDead = true;
	}

}
void Player::Shoot(char* keys, char* preKeys) {

	for (int i = 0; i < 10; i++) {

		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE] && !bullet.isShot[i]) {
			bullet.isShot[i] = true;
			bullet.pos[i].x = (player_.pos.UL.x + player_.pos.UR.x) /2;
			bullet.pos[i].y = player_.pos.UL.y - 30;
			break;
		}
	}

}

void Player::Update(char* keys, char* preKeys) {

	Movement(keys, preKeys);
	UpdateBullet();
	Shoot(keys, preKeys);
	PlayerDamaged();
	HitBox();
}

void Player::DrawHeart() {

	if (player_.HP >= 3) {
		Novice::DrawSprite(20, 400, player_.heartHandle[0], 1, 1, 0.0f, WHITE);
	}
	if (player_.HP >= 2) {
		Novice::DrawSprite(20, 500, player_.heartHandle[1], 1, 1, 0.0f, WHITE);
	}
	if (player_.HP >= 1) {
		Novice::DrawSprite(20, 600, player_.heartHandle[2], 1, 1, 0.0f, WHITE);
	}

}

void Player::Draw() {
	DrawBullet();
	Novice::DrawSprite((int)player_.pos.UL.x, (int)player_.pos.UL.y, player_.handle, 1, 1, 0.0f, player_.color);

}
