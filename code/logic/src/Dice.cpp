#include "../include/Dice.h"

void logic::Dice::rollNewNumber() {
	std::uniform_int_distribution<int> dist(1, 6);	 
	m_currentNumber = dist(rng);	
}

int logic::Dice::getCurrentNumber() const {
	return m_currentNumber;
}