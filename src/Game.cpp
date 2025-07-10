#include "Game.h"

#include <cstdint>

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
void Game::Start() {
	this->running = true;
	while (running) {
	}
}
