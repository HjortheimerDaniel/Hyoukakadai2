#pragma once
#include "Struct.h"
#include "Novice.h"
#define _USE_MATH_DEFINES
#include <math.h>
class Enemy {

	protected:

		EnemyStruct enemy_;
	    BossBulletStruct enemyBullet_;
		//Quad pos_;
		//Vector2 speed_;
	    //int handle_, animation_, frames_;
	    //bool dead_;


	public:

	    virtual void Initialize(Quad pos, Vector2 speed, int HP);

		virtual void Update();

		virtual Quad GetPos() { return enemy_.pos; };

	    virtual void SetPos(Quad pos) { enemy_.pos = pos; };

		virtual void SetIsDamaged(bool damaged) { enemy_.isDamaged = damaged; };

		virtual void Damaged(int& HP, bool& damaged, int& timer, bool& dead, int& color, int& died);

		virtual void Respawn(bool& isDestroyed, int& respawnTimer, int& HP, int& died);

		virtual Vector2* GetBossBulletPos() { return enemyBullet_.pos; };

		virtual bool GetIsDestroyed() { return enemy_.isDestroyed; };

		virtual bool GetIsDead() { return enemy_.isDead; };

		virtual void SetBulletX(float x, int index) { enemyBullet_.pos[index].x = x; };

	    virtual void SetBulletY(float y, int index) { enemyBullet_.pos[index].y = y; };

	    virtual void SetIsShot(bool shot, int index) { enemyBullet_.isShot[index] = shot; };

		virtual Vector2 GetSize() { return enemy_.size; };

	    virtual Vector2 GetSpeed() { return enemy_.speed; };

	    virtual void SetSpeed(Vector2 speed) { enemy_.speed = speed; };

		virtual int GetHP() { return enemy_.HP; };

		void Animation(int& animation, int& frames, int& MAXFrames, int& MAXAnimation);

	    virtual ~Enemy();

	    virtual void Draw();

};
