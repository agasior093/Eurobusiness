#include "../include/PropertyView.h"

void view::Property::activate(std::map < std::string, view::Button*> buttons, logic::Player& player, logic::Field* property) {
	if (property->getOwner() == nullptr) {
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
}

void view::Property::reset(std::map<std::string, view::Button*> buttons) {

}