#include "../include/Player.h"

template <typename T>
std::string toStringWithPrecision(const T a_value, const int n = 1) {
	std::stringstream stream;
	stream << std::fixed << std::setprecision(n) << a_value;
	std::string s = stream.str();
	return s;
}

std::string logic::Player::getPlayerInfo() {
	std::string info =
		"     " + m_name + "\n" +
		"Cash: " + toStringWithPrecision(m_cash) + "$\n";
	return info;
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
	m_position += number;
	if (m_position > 39) m_position -= 40;
}

void logic::Player::setPosition(int newPosition) {
	m_position = newPosition;
}

void logic::Player::startMoving() {
	m_isMoving = true;
}

void logic::Player::stopMoving() {
	m_isMoving = false;
}

void logic::Player::setTargetPosition(int newPosition) {
	m_targetPosition = newPosition;
}

void logic::Player::lockInJail() {
	
	m_turnsLeftInJail = JAIL_TIME;
	m_position = 10;
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

int logic::Player::getTargetPosition() const {
	return m_targetPosition;
}

bool logic::Player::isMoving() const {
	return m_isMoving;
}

int logic::Player::getTurnsLeftInJail() const {
	return m_turnsLeftInJail;
}

int logic::Player::getOutOfJailCards() const {
	return m_outOfJailCards;
}

