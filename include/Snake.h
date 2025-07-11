#ifndef __SNAKE_H__
#define __SNAKE_H__

#include <cstdint>

#include "Coord.h"
class Game;
class Snake {
   private:
   protected:
	Coord body[32];
	Coord prev_tale = {0, 0};  // coordinate of previous tale postion (need fro drawing)
	Game* game = 0;			   // Game that snake is running
	uint8_t length = 5;
	uint8_t head = 4;  // index of the head
	uint8_t tale = 0;  // index of the tale
	uint8_t head_shape = '@';
	uint8_t body_shape = '*';
	uint8_t alive = 1;	// if snake hit soemthing than its not alive

	int8_t dx = 0;
	int8_t dy = 0;
	inline void SetDirection(char dx, char dy) {
		this->dx = dx;
		this->dy = dy;
	}
	void Stop();
	friend class Player;
	friend class Bot;

   public:
	Snake();
	Snake(short x, short y, char head_shape, char body_shape);
	void Move();	// moves the snake by dx , dy
	void Draw();	// draws only changed parts of the snake  (in every frame)
	void Redraw();	// redraws entire body of the snake
	~Snake();
};

#endif	// !__SNAKE_H__
