#include "../include/GoToJail.h"
#include <iostream>

void logic::GoToJail::activate(logic::Player& player) {
	if (player.getTurnsLeftInJail() == 0) {		
		player.lockInJail();
	}	
}