#pragma once
#include "Struct.h"
#include "Novice.h"
#include "Bullet.h"
#define _USE_MATH_DEFINES_
#include <math.h>
class Player : public Bullet {

	public: 

		Player(Quad pos, Vector2 speed);

		~Player(){};

		void Initialize(Quad pos, Vector2 speed);

		void Movement(char* keys, char* preKeys);

		void SetPos(Quad pos) { player_.pos = pos; };

		Quad GetPos() { return player_.hitbox; };

		Vector2* GetBulletPos() { return bullet.pos; };

		Vector2 GetSize() { return player_.size; };

		void SetIsDamaged(bool damaged) {player_.isDamaged = damaged; };

		int GetPlayerHP() { return player_.HP; };

		void HitBox();

		bool GetIsDamaged() { return player_.isDamaged; };

		void PlayerDamaged();

		bool GetIsDead() { return player_.isDead; };

		void Shoot(char* keys, char* preKeys);

		void Update(char* keys, char* preKeys);

		void DrawHeart();

		void Draw();


	private:

		PlayerStruct player_;

};
