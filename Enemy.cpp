#include "Enemy.h"


void Enemy::Initialize(Quad pos, Vector2 speed, int HP) {

	pos = {};
	speed = {};
	enemy_.hitbox = {};
	HP = {};

}

void Enemy::Update() {}

void Enemy::Damaged(int& HP, bool& damaged, int& timer, bool& dead, int& color, int& died) {

	if (damaged) {
		timer++;
	}

	if (timer == 1) {
		HP--;
		color = RED;
	}

	if (timer >= 2) {
		timer = 0;
		damaged = false;
		color = WHITE;
	}

	if (HP <= 0 && died >= 1) {
		dead = true;
	}

}

void Enemy::Respawn(bool& isDestroyed, int& respawnTimer, int& HP, int& died) {

	if (HP <= 0) {
		isDestroyed = true;
	}

	if (isDestroyed) {
  		respawnTimer++;
	}

	if (respawnTimer == 200) {
		HP = 7;
		died++;
		respawnTimer = 0;
		isDestroyed = false;
		
	}

}


void Enemy::Animation(int& animation, int& frames, int& MAXFrames, int& MAXAnimation) {

	frames++;

	if (frames >= MAXFrames) {
		animation++;
		frames = 0;
	}

	if (animation >= MAXAnimation) {
		animation = 0;
	}

}



Enemy::~Enemy() {}

void Enemy::Draw() {}
