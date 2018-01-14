#include "../include/JailVisitor.h"
#include <iostream>

void logic::JailVisitor::activate(logic::Player& player) {
	if (player.getTurnsLeftInJail() == 0) {
		m_mainMessage = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nYou are just visiting.";
	}
	else {
		m_mainMessage = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nYou have " + std::to_string(player.getTurnsLeftInJail()) + " turns left in jail.";
	}
}