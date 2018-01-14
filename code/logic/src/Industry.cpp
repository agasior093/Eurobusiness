#include "../include/Industry.h"


void logic::Industry::updateMessage() {
	std::string ownerInfo;
	if (m_owner == nullptr) {
		ownerInfo = "\nOwner: none";
	}
	else {
		ownerInfo = "\nOwner: " + m_owner->getName();
	}

	m_mainMessage = m_name + "\n\n" +
		"Purchase price : " + toStringWithPrecision(m_price) + "$\n\n" +
		"Base charge is 100$ and its\nmultiplied by number rolled by\nplayer that stays here.\n" +
		"If both industries are owned\nby same player this\nnumber is doubled\n\n\n\n\n" +
		ownerInfo;
}

void logic::Industry::calculateCharge() {
	m_charge = m_rollResult * m_baseFee;
}

void logic::Industry::activate(logic::Player& player) {
	if (m_hasPayed == false && ((this->getOwner() != nullptr)
		&& (this->getOwner()->getName() != player.getName()))) {
		m_gameStatusMessage = "You are staying in " + this->getName() +
			",which belongs\nto player " + this->getOwner()->getName() +
			". Roll the dice to see how\nmuch you owe him.";
		if (m_rollResult > 0) {			
			calculateCharge();			
			player.createPayment(m_charge, this->getOwner());
			m_gameStatusMessage = "You are staying in " + this->getName() +
				",which belongs\nto player " + this->getOwner()->getName() +
				". You owe him " + toStringWithPrecision(m_charge) + "$.";
		}
	}
}

void logic::Industry::checkRollResult(int firstRoll, int secondRoll, logic::Player& player) {
	m_rollResult = firstRoll;	
	activate(player);
}

void logic::Industry::reset() {
	m_rollResult = 0;
}