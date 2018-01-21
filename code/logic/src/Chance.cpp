#include "../include/Chance.h"

logic::Chance::Chance(ChanceType type) 
	: Field(false), m_type(type) 
{	
	
}

void logic::Chance::activate(logic::Player& player) {
	
}

void logic::Chance::reveal() {	
	//reveals card on top of deck
	//(this->*m_redChances[m_redChances.size() - 1])();	
}



void logic::Chance::moveForward(logic::Player& player) {

}

void logic::Chance::moveBackwards(logic::Player& player) {

}

void logic::Chance::calculateCharge() {

}



