#include "../include/Property.h"
#include <iostream>

void logic::Property::setOwner(logic::Player& player) {
	m_owner = &player;
}

void logic::Property::setUnderMortgage() {
	m_underMortgage = true;
}

void logic::Property::liftMortgage() {
	m_underMortgage = false;
}

