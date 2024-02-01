#include "Game.h"

void Game::Initialize() {

	stage->Initialize();

	game = Title;
	titleHandle_ = Novice::LoadTexture("./Sprites/title.png");
	clearHandle_ = Novice::LoadTexture("./Sprites/clear.png");
	overHandle_ = Novice::LoadTexture("./Sprites/gameover.png");

}

void Game::Update(char* keys, char* preKeys) {

	switch (game) {
	case Title:

		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
			game = Ingame;
			break;
		}

		break;
	case Ingame:
		stage->Update(keys, preKeys);

		if (stage->GetGameOver()) {
			game = GameOver;
			stage->Initialize();
			break;
		}

		if (stage->GetGameClear()) {
			game = GameClear;
			stage->Initialize();
			break;
		}
		
		break;
	case GameOver:

		if (keys[DIK_R] && !preKeys[DIK_R]) {
			game = Title;
			stage->Initialize();
			break;
		}

		break;
	case GameClear:

		if (keys[DIK_R] && !preKeys[DIK_R]) {
			game = Title;
			stage->Initialize();
			break;
		}

		break;
	default:
		break;
	}

}

void Game::Draw() {

	if (game == Title) {
		Novice::DrawSprite(0, 0, titleHandle_, 1, 1, 0.0f, WHITE);
	}

	if (game == Ingame) {
		stage->Draw();
	}

	if (game == GameOver) {
		Novice::DrawSprite(0, 0, overHandle_, 1, 1, 0.0f, WHITE);
	}

	if (game == GameClear) {
		Novice::DrawSprite(0, 0, clearHandle_, 1, 1, 0.0f, WHITE);
	}
}
