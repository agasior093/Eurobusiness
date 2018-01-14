#include "../include/IndustryView.h"

void view::Industry::activate(std::map < std::string, view::Button*> buttons, logic::Player& player, logic::Field* industry) {
	if (industry->getOwner() == nullptr) {
		buttons["Buy"]->enable();
	}
	else {
		buttons["Buy"]->disable();
	}

	if (player.getCurrentPayment() > 0) {
		buttons["Pay"]->enable();
	}
	else {
		buttons["Pay"]->disable();
	}
	

	if (m_hasRolled == false && ((industry->getOwner() != nullptr) 
		&& (industry->getOwner()->getName() != player.getName()))) {
		buttons["Jail roll"]->enable();
		buttons["End turn"]->disable();
	}
	else {
		buttons["Jail roll"]->disable();
	}
}

void view::Industry::roll () {
	m_hasRolled = true;			
}

void view::Industry::reset(std::map<std::string, view::Button*> buttons) {
	m_hasRolled = false;
	buttons["Jail roll"]->disable();
	buttons["Buy"]->disable();
	buttons["Pay"]->disable();
}
