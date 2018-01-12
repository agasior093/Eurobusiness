#include "../include/GoToJailView.h"

void view::GoToJail::activate(std::map<std::string, view::Button*> buttons, logic::Player& player) {
	buttons.at("Jail roll")->enable();
	if (player.getOutOfJailCards() > 0) {
		buttons.at("Jail card")->enable();
	}	
}

void view::GoToJail::roll(bool argument) {
	if (argument == true) {

	}
 }