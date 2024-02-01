#pragma once
#include "Stage.h"
class Game {

	public:

		enum GGame {Title, Ingame, GameOver, GameClear};

		void Initialize();

		void Update(char* keys, char* preKeys);

		void Draw();


	private:
	    Stage* stage = new Stage();
	    GGame game;
	    int titleHandle_;
	    int clearHandle_;
	    int overHandle_;
};
