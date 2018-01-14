#include "../include/Tax.h"

void logic::Tax::activate(logic::Player& player) {
	player.createPayment(static_cast<float>(m_charge), nullptr);	
}

void logic::Tax::pay(logic::Player& player) {
	if (player.pay()) {
		m_charge = 0;
		m_mainMessage = m_name + "\n\nThank you for payment.";
		m_gameStatusMessage = "You payed " + toStringWithPrecision(m_defaultCharge) + "$ for taxes";
	} 	
}

void logic::Tax::reset() {
	m_charge = m_defaultCharge;
}