#include "../include/PropertyManager.h"
#include <iostream>

std::string logic::PropertyManager::buyProperty(logic::Player& player, logic::Field* property) {
	if (property->getOwner() == nullptr && (property->getPrice() <= player.getCash())) {
		property->setOwner(player);
		player.addProperty(property);
		player.substractCash(property->getPrice());
		
		return "You bought " + property->getName() + " for " + toStringWithPrecision(property->getPrice()) + "$";
	}
	else {
		
		return "You can't afford that.";
	}
}

bool logic::PropertyManager::buyHouse(logic::Player&, logic::Field*){
	return true;
}

bool logic::PropertyManager::sellHouse(logic::Player&, logic::Field*){
	return true;
}

bool logic::PropertyManager::buyHotel(logic::Player&, logic::Field*){
	return true;
}

bool logic::PropertyManager::sellHotel(logic::Player&, logic::Field*) {
	return true;
}

bool logic::PropertyManager::mortgageProperty(logic::Player&, logic::Field*){
	return true;
}

bool logic::PropertyManager::liftMortgage(logic::Player&, logic::Field*){
	return true;
}