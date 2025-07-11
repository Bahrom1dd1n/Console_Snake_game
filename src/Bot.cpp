#include "Bot.h"

#include <cstdint>
#include <cstdlib>

#include "Game.h"
#include "Snake.h"
void Bot::FindPath() {
	/*Coord ways[3] = {{int8_t(-(!snake.dx)), int8_t(-(!snake.dy)}, {!snake.dx, !snake.dy},
	{-snake.dx, -snake.dy}}; Coord sh = ways[0];	 // shortest direction short i = 0; if
	(map[head.x + ways[0].x][head.y + ways[0].y] != '.') sh = ways[++i]; short dbx = bread.x -
	head.x, dby = bread.y - head.y; for (; i < 3; i++) { short wx = head.x + ways[i].x, wy =
	head.y + ways[i].y; if (map[wx][wy] == '.' && abs(dbx - ways[i].x) + abs(dby - ways[i].y) <
	abs(dbx - sh.x) + abs(dby - sh.y)) sh = ways[i];
	}
	snake.dx = sh.x;
	snake.dy = sh.y;*/
	Coord& head_pos = snake.body[snake.head];
	Coord& food = this->snake.game->food_pos;
	uint16_t short_dist = UINT16_MAX;

	int8_t dx = -snake.dx;
	int8_t dy = -snake.dy;
	Game& game = *snake.game;
	uint16_t distance = (head_pos.x + 1 - food.x) * (head_pos.x + 1 - food.x) +
						(head_pos.y - food.y) * (head_pos.y - food.y);
	if (game.GetCell(head_pos.x + 1, head_pos.y) == 0 && distance < short_dist) {
		dx = 1;
		dy = 0;
		short_dist = distance;
	}
	distance = (head_pos.x - 1 - food.x) * (head_pos.x - 1 - food.x) +
			   (head_pos.y - food.y) * (head_pos.y - food.y);
	if (game.GetCell(head_pos.x - 1, head_pos.y) == 0 && distance < short_dist) {
		dx = -1;
		dy = 0;
		short_dist = distance;
	}
	distance = (head_pos.x - food.x) * (head_pos.x - food.x) +
			   (head_pos.y + 1 - food.y) * (head_pos.y + 1 - food.y);
	if (game.GetCell(head_pos.x, head_pos.y + 1) == 0 && distance < short_dist) {
		dx = 0;
		dy = 1;
		short_dist = distance;
	}
	distance = (head_pos.x - food.x) * (head_pos.x - food.x) +
			   (head_pos.y - 1 - food.y) * (head_pos.y - 1 - food.y);
	if (game.GetCell(head_pos.x, head_pos.y - 1) == 0 && distance < short_dist) {
		dx = 0;
		dy = -1;
		short_dist = distance;
	}
	snake.dx = dx;
	snake.dy = dy;
}
void Bot::FindFood() {
	Game& game = *snake.game;
	short sx = snake.game->food_pos.x - snake.body[snake.head].x;

	short sy = snake.game->food_pos.y - snake.body[snake.head].y;
	if (abs(sx) > abs(sy)) {
		snake.dx = sx > 0 ? 1 : -1;
		snake.dy = 0;
	} else {
		snake.dy = sy > 0 ? 1 : -1;
		snake.dx = 0;
	}
	if (map[head.x + snake.dx][head.y + snake.dy] != '.') this->findway();
}
