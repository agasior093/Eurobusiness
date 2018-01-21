#include "../include/Chance.h"

logic::Chance::Chance(ChanceType type) 
	: Field(false), m_type(type) 
{	
	
}

void logic::Chance::activate(logic::Player& player) {
	if (m_type == ChanceType::RED) {
		RedChanceDeck::getDeck().getTopCard()();
	}

	else {
		BlueChanceDeck::getDeck().getTopCard()();
	}
}

void logic::Chance::reveal() {	
	
}



void logic::Chance::moveForward(logic::Player& player) {

}

void logic::Chance::moveBackwards(logic::Player& player) {

}

void logic::Chance::calculateCharge() {

}



