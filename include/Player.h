#ifndef __PLAYER__
#define __PLAYER__
#include "Snake.h"
class Player {
	uint8_t name[16] = "Player";
	Snake snake;
	// cpntrol keys
	uint8_t up = 0, down = 0, left = 0, right = 0;

   public:
	uint8_t Handle(char key) {
		if (key == up) {
			this->snake.SetDirection(0, -1);
			return true;
		}
		if (key == down) {
			this->snake.SetDirection(0, 1);
			return true;
		}
		if (key == left) {
			this->snake.SetDirection(-1, 0);
			return true;
		}
		if (key == right) {
			this->snake.SetDirection(1, 0);
			return true;
		}
		return false;
	}
	inline void Move() {
		this->snake.Move();
		this->snake.Draw();
	}
	inline uint8_t* getname() { return this->name; };
	void SetName(char* name);
};
#endif	//!__PLAYER__
