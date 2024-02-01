#pragma once
#include "Enemy.h"
class Mob2 : public Enemy {

	public:

	void Initialize(Quad pos, Vector2 speed, int HP) override;

	Mob2(Quad pos, Vector2 speed, int HP);

	~Mob2() override;

	void Movement();

	void Shoot();

	void Update() override;

	void DrawBullet();

	void EnemyDead();

	void Draw() override;



};
