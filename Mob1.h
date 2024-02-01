#pragma once
#include "Enemy.h"

class Mob1 : public Enemy{

	public:

	void Initialize(Quad pos, Vector2 speed, int HP) override;

	Mob1(Quad pos, Vector2 speed, int HP);

	~Mob1() override;

	void Movement();

	void Shoot();

	void Update() override;

	void EnemyDead();

	void DrawBullet();

	void Draw() override;

	

};
