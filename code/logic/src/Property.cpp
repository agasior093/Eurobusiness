#include "../include/Property.h"

void logic::Property::activate(logic::Player& player) {
	if (m_hasPayed == false && ((this->getOwner() != nullptr) 
		&& (this->getOwner()->getName() != player.getName()) )) {
		calculateCharge();
		player.createPayment(m_charge, this->getOwner());
		m_gameStatusMessage = "You are staying in " + this->getName() + ",which belongs\nto player " +
			this->getOwner()->getName() + ". You owe him " + toStringWithPrecision(m_charge) + "$.";
		updateMessage();
	} 	
	else {		
		updateMessage();
	}
}

void logic::Property::buy(logic::Player& player) {
	if (this->getOwner() == nullptr && (this->getPrice() <= player.getCash())) {
		this->setOwner(player);
		player.addProperty(this);
		player.substractCash(this->getPrice());

		m_gameStatusMessage = "You bought " + this->getName() + " for " + toStringWithPrecision(this->getPrice()) + "$";
		updateMessage();
	}
}

void logic::Property::pay(logic::Player& player) {
	if (player.pay()) {		
		m_hasPayed = true;
		float tempCharge = m_charge;
		m_charge = 0;
		m_gameStatusMessage =  "You payed " + toStringWithPrecision(tempCharge) + "$ to " +
			this->getOwner()->getName() + " for staying\nin his property.";
	}
}

void logic::Property::reset() {
	m_hasPayed = false;
	m_gameStatusMessage = "";
}

void logic::Property::calculateCharge() {
	m_charge = m_baseFee;	
}

void logic::Property::setOwner(logic::Player& player) {
	m_owner = &player;
}

void logic::Property::setUnderMortgage() {
	m_underMortgage = true;
}

void logic::Property::liftMortgage() {
	m_underMortgage = false;
}

std::string logic::Property::getName() const {
	return m_name;
}

float logic::Property::getPrice() const {
	return m_price;
}

logic::Player* logic::Property::getOwner() {
	return m_owner;
}

logic::GroupName logic::Property::getGroup() const {
	return m_group;
}

bool logic::Property::isBuildingArea() const {
	return m_buildingArea;
 }

bool logic::Property::isUnderMortgage() const {
	return m_underMortgage;
}

