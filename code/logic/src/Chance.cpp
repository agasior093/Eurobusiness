#include "../include/Chance.h"

logic::Chance::Chance(ChanceType type) 
	: Field(false), m_type(type) 
{	
	
}

void logic::Chance::activate(logic::Player& player) {
	
}

void logic::Chance::reveal(logic::Player& player) {
	if (m_type == ChanceType::RED) {
		RedChanceDeck::getDeck().getTopCard()(player, m_mainMessage);		
	}

	else {
		BlueChanceDeck::getDeck().getTopCard()(player, m_mainMessage);
	}
	m_charge = player.getCurrentPayment();
}

void logic::Chance::pay(logic::Player& player) {
	float calculatedCharge = m_charge;
	if (player.pay()) {
		m_charge = 0;		;
		m_gameStatusMessage = "You payed " + toStringWithPrecision(calculatedCharge) + "$";
	}
}

void logic::Chance::reset() {
	m_mainMessage = "";
	m_gameStatusMessage = "";
}




