#include "Player.h"

void Player::SetName(char* new_name) {
	int i = 0;
	while (new_name[i] != '\0' && i < sizeof(this->name)) {
		this->name[i] = new_name[i];
	}
}
