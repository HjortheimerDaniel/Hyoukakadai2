#pragma once
#define MAXENEMIES 2

struct Vector2 {
	float x, y;
};

struct Quad {
	Vector2 UL, UR, LL, LR;
};

struct EnemyStruct {
	Quad pos;
	Quad hitbox;
	Vector2 speed, size;
	int handle, animation, frames, MAXAnimation, MAXFrames;
	bool isDead, isDamaged;
	int damagedTimer;
	float theta;
	float amplitude;
	int HP;
	int color;
	int respawnTimer;
	int died;
	bool isDestroyed;
};

struct PlayerStruct {
	Quad pos;
	Quad hitbox;
	Vector2 speed, size;
	int handle, animation, frames, damagedTimer;
	bool isDead, isDamaged;
	int HP;
	int heartHandle[3];
	int color;
};

struct BulletStruct {
	Vector2 pos[10];
	int radius;
	bool isShot[10];
	int speed[10];
	int handle;
	int CD;
};

struct BossBulletStruct {
	Vector2 pos[4];
	int radius;
	bool isShot[4];
	int speed[4];
	int handle;
	int CD;
};