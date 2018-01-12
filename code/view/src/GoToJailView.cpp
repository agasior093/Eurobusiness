#include "../include/GoToJailView.h"

void view::GoToJail::activate(std::map<std::string, view::Button*> buttons, logic::Player& player) {
	if (m_rollCounter == 0) {
		buttons.at("Jail roll")->enable();
	}
	else {
		buttons.at("Jail roll")->disable();
	}
	
	if (player.getOutOfJailCards() > 0) {
		buttons.at("Jail card")->enable();
	}	
}

void view::GoToJail::reset() {
	m_rollCounter = 0;
}

void view::GoToJail::roll() {
	m_rollCounter++;	
 }