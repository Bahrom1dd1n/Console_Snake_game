#ifndef __SNAKE_BOT__
#define __SNAKE_BOT__
#include <cstdlib>

#include "Snake.h"

class Bot {
   private:
	Snake snake;

   public:
	inline void Move() {
		this->snake.Move();
		this->snake.Draw();
	}
	void FindPath();
	void FindFood();
};
#endif	//!__SNAKE_BOT__
