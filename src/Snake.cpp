#include "Snake.h"

#include <cstdio>

#include "Game.h"
void Snake::Move() {
	Coord& prev_head = body[head];
	head++;
	if (head > sizeof(body)) head = 0;
	Coord& current_head = body[head];
	if (game->GetCell(current_head.x, current_head.y)) {
		Stop();
		return;
	}
	game->SetCell(current_head.x, current_head.y, 1);
	game->SetCell(body[tale].x, body[tale].y, 0);
	tale++;
	if (head > sizeof(body)) tale = 0;
	game->SetCell(body[tale].x, body[tale].y, 1);
	if (dx) body[head].x = prev_head.x + dx;
	if (dy) body[head].y = prev_head.y + dy;
}
void Snake::Stop() {
	// this function is called when snake is dead
	this->alive = 0;
	for (int i = this->length, j = this->tale; i > -1 && j != head; i--, j++) {
		printf("\033[%d;%dH%c", body[j].x, body[j].y, body_shape);
		this->game->SetCell(body[j].x, body[j].y, 0);
	}
	// printf("\033[%d;%dH%c", body[head].x, body[head].y, head_shape);
}
void Snake::Draw() {
	for (int i = this->length, j = this->tale; i > 0 && j != head; i--, j++) {
		printf("\033[%d;%dH%c", body[j].x, body[j].y, body_shape);
	}
	printf("\033[%d;%dH%c", body[head].x, body[head].y, head_shape);
}
void Snake::SetName(char* new_name) {
	int i = 0;
	while (new_name[i] != '\0' && i < sizeof(this->name)) {
		this->name[i] = new_name[i];
	}
}
