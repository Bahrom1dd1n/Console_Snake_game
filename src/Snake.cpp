#include "Snake.h"

#include <cstdio>
void Snake::Move() {
	Coord& prev_head = body[head];
	head++;
	if (head > sizeof(body)) head = 0;
	Coord& current_head = body[head];
	if (bit_map[current_head.y][current_head.x << 32] & 1) tale++;
	if (head > sizeof(body)) tale = 0;
	if (dx) body[head].x = prev_head.x + dx;
	if (dy) body[head].y = prev_head.y + dy;
}
void Snake::Stop() {}
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
