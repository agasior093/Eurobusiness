#include "../include/Player.h"

void logic::Player::setAsActive(bool argument) {
	m_isActive = argument;
}

void logic::Player::addCash(float amount) {
	m_cash += amount;
}

bool logic::Player::substractCash(float amount) {
	if (m_cash >= amount) {
		m_cash -= amount;
		return true;
	} 
	else {
		return false;
	}
}

void logic::Player::createPayment(float amount, Player* player) {
	m_currentPayment = amount;
	m_loanHolder = player;
}

bool logic::Player::pay() {
	if (m_cash >= m_currentPayment) {
		m_cash -= m_currentPayment;
		m_loanHolder->addCash(m_currentPayment);
		m_currentPayment = 0;
		m_loanHolder = nullptr;
		return true;
	}
	else {
		return false;
	}
}

void logic::Player::incrementPosition(int number) {
	m_positionDifference = number;
	m_position += number;
	if ((m_position += 0.001f) > 40)
		m_position -= 40;
}

void logic::Player::setPosition(int newPosition) {
	m_position = newPosition;
}

void logic::Player::lockInJail() {	
	m_turnsLeftInJail = JAIL_TIME;
	m_position = 10;
	//m_isSentToJail = true;
}

void logic::Player::decrementTurnsInJail() {
	if(m_turnsLeftInJail > 0) m_turnsLeftInJail--;
}

void logic::Player::addOutOfJailCard() {
	m_outOfJailCards++;
}

void logic::Player::useOutOfJailCard() {
	if (m_outOfJailCards > 0) {
		m_outOfJailCards--;
		m_turnsLeftInJail = 0;
	}
}

//getters
bool logic::Player::isActive() const {
	return m_isActive;
}

std::string logic::Player::getName() const {
	return m_name;
}

float logic::Player::getCash() const {
	return m_cash;
}

float logic::Player::getCurrentPayment() const {
	return m_currentPayment;
}

logic::Player* logic::Player::getLoanHolder() const {
	return m_loanHolder;
}

int logic::Player::getPosition() const {
	return m_position;
}

int logic::Player::getPositionDifference() const {	
	return m_positionDifference;
}

bool logic::Player::isSentToJail() const {
	return m_isSentToJail;
}

int logic::Player::getTurnsLeftInJail() const {
	return m_turnsLeftInJail;
}

int logic::Player::getOutOfJailCards() const {
	return m_outOfJailCards;
}

