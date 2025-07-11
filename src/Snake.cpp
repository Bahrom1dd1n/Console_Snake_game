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
	prev_tale = body[tale];
	game->SetCell(prev_tale.x, prev_tale.y, 0);
	game->SetCell(current_head.x, current_head.y, 1);

	tale++;
	if (head > sizeof(body)) tale = 0;
	game->SetCell(body[tale].x, body[tale].y, 1);
	if (dx) current_head.x = prev_head.x + dx;
	if (dy) current_head.y = prev_head.y + dy;
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
	printf("\033[%d;%dH%c", body[tale].x, body[tale].y, ' ');  // clearing previous tale postion
	printf("\033[%d;%dH%c", body[head].x, body[head].y, head_shape);

	Coord& neck = body[head ? head - 1 : length - 1];
	printf("\033[%d;%dH%c", neck.x, neck.y, body_shape);  // drawing neck
}
void Snake::Redraw() {
	for (int i = this->length, j = this->tale; i > 0 && j != head; i--, j++) {
		printf("\033[%d;%dH%c", body[j].x, body[j].y, body_shape);
	}
	printf("\033[%d;%dH%c", body[head].x, body[head].y, head_shape);
}
