#include "../include/PropertyManager.h"

bool logic::PropertyManager::buyProperty(logic::Player& player, logic::Field* property) {
	if (property->getOwner() == nullptr && (property->getPrice() <= player.getCash())) {
		property->setOwner(player);
		player.addProperty(property);
		player.substractCash(property->getPrice());
		return true;
	}
	else {
		return false;
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
