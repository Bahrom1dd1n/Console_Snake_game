#ifndef __PLAYER__
#define __PLAYER__
#include "Snake.h"
class Player {
	// cpntrol keys
	short up = 0, down = 0, left = 0, right = 0;
	Snake* snake = 0;

   public:
	bool Handle(char key) {
		if (key == up) {
			this->snake->SetDirection(0, -1);
			return true;
		}
		if (key == down) {
			this->snake->SetDirection(0, 1);
			return true;
		}
		if (key == left) {
			this->snake->SetDirection(-1, 0);
			return true;
		}
		if (key == right) {
			this->snake->SetDirection(1, 0);
			return true;
		}
		return false;
	}
};
#endif	//!__PLAYER__
