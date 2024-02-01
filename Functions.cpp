#include "Functions.h"

bool CheckCollision(Vector2 pos1, Vector2 pos2, Vector2 size1, Vector2 size2) {
	if (pos1.x < pos2.x + size2.x && pos2.x < pos1.x + size1.x && pos1.y < pos2.y + size2.y &&
	    pos2.y < pos1.y + size1.y) {
		return true;
	}
	return false;
}