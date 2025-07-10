#ifndef __SNAKE_H__
#define __SNAKE_H__

#include <cstdint>
#include <string>

#include "Coord.h"
class Game;
class Snake {
   private:
   protected:
	Coord body[32];
	Game* game = 0;	 // Game that snake is running
	uint8_t name[16] = "Player";
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

   public:
	Snake();
	Snake(short x, short y, char head_shape, char body_shape);
	inline uint8_t* getname() { return this->name; };
	void SetName(char* name);
	void Move();
	void Draw();
	~Snake();
};

#endif	// !__SNAKE_H__
