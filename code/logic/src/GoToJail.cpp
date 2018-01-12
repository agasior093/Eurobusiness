#include "../include/GoToJail.h"
#include <iostream>

void logic::GoToJail::activate(logic::Player& player) {	
	if (m_rolledDoubles == false && m_usedCard == false) {
		player.sendToJail(true);
	}
	else {
		player.sendToJail(false);
	}
}

void logic::GoToJail::reset() {
	m_usedCard = false;
	m_rolledDoubles = false;
	m_mainMessage = m_defaultMainMessage;	
}

void logic::GoToJail::checkRollResult(int firstRoll, int secondRoll) {
	if (firstRoll == secondRoll) {
		m_rolledDoubles = true;
		m_mainMessage = "\n\n\n\n\n\n\n\n\n\n\n\n\nYou rolled doubles!\nTherefore, you avoided prison.";
	}
	else {
		m_rolledDoubles = false;
		m_mainMessage = "\n\n\n\n\n\n\n\n\n\n\n\n\nUnfortunatelly,\nyou didn't manage to roll\ndoubles.\n";
	}
}

void logic::GoToJail::useCard() {
	m_usedCard = true;
	m_mainMessage = "\n\n\n\n\n\n\n\n\n\n\n\n\nYou used your out of jail card\nto avoid prison.";
}