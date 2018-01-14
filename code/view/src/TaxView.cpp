#include "../include/TaxView.h"

void view::Tax::activate(std::map<std::string, view::Button*> buttons, logic::Player& player, logic::Field*) {
	if (player.getCurrentPayment() > 0 && (player.getCash() >= player.getCurrentPayment())) {
		buttons["Pay"]->enable();
	}
	else {
		buttons["Pay"]->disable();
	}
	
}

void view::Tax::reset(std::map<std::string, view::Button*> buttons) {

}
