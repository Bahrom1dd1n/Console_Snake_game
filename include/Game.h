#ifndef __GAME__
#define __GAME__

#include <cstdint>

#include "Bot.h"
#include "Player.h"
#include "Snake.h"
class Tank;
class Game {
   private:
	uint32_t bit_map[50][2] = {0};
	Snake* snakes[8];
	Player* players[8];
	Bot* bots[8];
	uint8_t window_width = 0;
	uint8_t window_height = 0;
	uint8_t frame_delay = 200;
	bool running = false;
	void HandleEvents();
	void Update();

	friend class Snake;
	friend class Bot;

   public:
	Game(int width, int height);
	inline void SetFrameRate(unsigned int FPS) { this->frame_delay = 1000 / FPS; }
	uint8_t GetCell(uint8_t x, uint8_t y);	// return wheter that positoin is free or not
	void SetCell(uint8_t x, uint8_t y, uint8_t status);
	void AddPlayer(Player* player);
	void Redraw();
	void Start();
	void Stop();
	void OnKeyDown(short key);
	void OnKeyUp(short key);
	~Game();
};

#endif	// !__GAME__
