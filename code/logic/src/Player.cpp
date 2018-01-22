#include "../include/Player.h"
#include <iostream>

void logic::Player::setAsActive(bool argument) {
	m_isActive = argument;
}

void logic::Player::addProperty(logic::Field* property) {
	m_properties.emplace_back(property);
}

void logic::Player::addCash(float amount) {
	m_cash += amount;
}

void logic::Player::substractCash(float amount) {
	if (m_cash >= amount) {
		m_cash -= amount;
	}	
}

void logic::Player::createPayment(float amount, Player* player) {
	m_currentPayment = amount;
	m_loanHolder = player;
}

void logic::Player::incrementPosition(int number) {
	m_positionDifference = number;
	m_position += number;
	if ((m_position += 0.001f) > 39) {
		m_position -= 40;
	}
}

void logic::Player::setPosition(int newPosition) {
	m_position = newPosition;
}

void logic::Player::sendToJail(bool argument) {
	m_isSentToJail = argument;
}

void logic::Player::lockInJail() {	
	m_turnsLeftInJail = JAIL_TIME;
	m_position = 10;		
}

void logic::Player::changePosition(bool argument, int newPosition) {
	m_isPositionChanged = argument;
	if (m_isPositionChanged == true) {
		m_position = newPosition;
	}	
}

void logic::Player::allowToCollectMoney(bool argument) {
	m_canCollectMoney = argument;
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

void logic::Player::increaseTransactionCounter() {
	m_transactionCounter++;
}

void logic::Player::resetTransactionCounter() {
	m_transactionCounter = 0;
}

void logic::Player::addHouse() {
	m_numberOfHouses++;
}

void logic::Player::removeHouse() {
	m_numberOfHouses--;
}

void logic::Player::addHotel() {
	m_numberOfHotels++;
}

void logic::Player::removeHotel() {
	m_numberOfHotels--;
}

bool logic::Player::pay() {
	if (m_cash >= m_currentPayment) {
		m_cash -= m_currentPayment;
		if (m_loanHolder != nullptr) m_loanHolder->addCash(m_currentPayment);
		m_currentPayment = 0;
		m_loanHolder = nullptr;
		return true;
	}
	else {
		return false;
	}
}

logic::Player* logic::Player::getLoanHolder() const {
	return m_loanHolder;
}

std::vector<logic::Field*>& logic::Player::getProperties() {
	return m_properties;
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

int logic::Player::getTransactionCounter() const {
	return m_transactionCounter;
}

int logic::Player::getPosition() const {
	return m_position;
}

int logic::Player::getPositionDifference() const {	
	return m_positionDifference;
}

int logic::Player::getTurnsLeftInJail() const {
	return m_turnsLeftInJail;
}

int logic::Player::getOutOfJailCards() const {
	return m_outOfJailCards;
}

int logic::Player::getNumberOfHouses() const {
	return m_numberOfHouses;
}

int logic::Player::getNumberOfHotels() const {
	return m_numberOfHotels;
}

bool logic::Player::isActive() const {
	return m_isActive;
}

bool logic::Player::isSentToJail() const {
	return m_isSentToJail;
}

bool logic::Player::isPositionChanged() const {
	return m_isPositionChanged;
}

bool logic::Player::canCollectMoney() const {
	return m_canCollectMoney;
}

