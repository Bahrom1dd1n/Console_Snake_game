#include "Game.h"

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keyboard.h>

#include <chrono>
#include <cstdint>
#include <thread>
uint8_t Game::GetCell(uint8_t x, uint8_t y) {
	// return wheter that positoin is free or not
	return (bit_map[y][x << 5]) & (1 << (x - 32));
}

void Game::SetCell(uint8_t x, uint8_t y, uint8_t status) {
	if (status)
		bit_map[y][x << 5] |= (1 << (x - 32));
	else
		bit_map[y][x << 5] &= ~(1 << (x - 32));
}
void Game::OnKeyDown(short key) {
	for (int i = 0; i < num_players; i++) {
		if (players[i]->Handle(key)) break;
	};
}
void Game::OnKeyUp(short key) {
	for (int i = 0; i < num_players; i++) {
		if (players[i]->Handle(key)) break;
	};
}
void Game::HandleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_KEYDOWN:
				OnKeyDown(event.key.keysym.scancode);
				break;
			case SDL_KEYUP:
				OnKeyUp(event.key.keysym.scancode);
				break;
		};
	};
}
void Game::Start() {
	this->running = true;
	while (running) {
		HandleEvents();
		for (int i = 0; i < num_players; i++) {
			players[i]->Move();
		};
		// giving some delay
		std::this_thread::sleep_for(std::chrono::milliseconds(frame_delay));
	}
}

void Game::AddPlayer(Player* player) {
	if (num_players >= sizeof(this->players)) return;
	players[num_players++] = player;
}

void Game::AddBot(Bot* bot) {
	if (num_bots >= sizeof(this->bots)) return;
	bots[num_bots++] = bot;
}
