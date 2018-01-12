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
	else {
		buttons.at("Jail card")->disable();
	}
}

void view::GoToJail::reset(std::map<std::string, view::Button*> buttons) {
	m_rollCounter = 0;
	buttons.at("Jail roll")->disable();
	buttons.at("Jail card")->disable();
}

void view::GoToJail::roll() {
	m_rollCounter++;	
 }