#include "../include/RedChanceDeck.h"

logic::RedChanceDeck& logic::RedChanceDeck::getDeck() {
	static RedChanceDeck deck;
	return deck;
}

logic::RedChanceDeck::RedChanceDeck() {
	m_deck[0] = [&]() { redCard1(); };
	m_deck[1] = [&]() { redCard2(); };
	m_deck[2] = [&]() { redCard3(); };
	m_deck[3] = [&]() { redCard4(); };
	m_deck[4] = [&]() { redCard5(); };
	m_deck[5] = [&]() { redCard6(); };
	m_deck[6] = [&]() { redCard7(); };
	m_deck[7] = [&]() { redCard8(); };
	m_deck[8] = [&]() { redCard9(); };
	m_deck[9] = [&]() { redCard10(); };
	m_deck[10] = [&]() { redCard11(); };
	m_deck[11] = [&]() { redCard12(); };
	m_deck[12] = [&]() { redCard13(); };
	m_deck[13] = [&]() { redCard14(); };
	m_deck[14] = [&]() { redCard15(); };	
	shuffleDeck();
}

void logic::RedChanceDeck::redCard1() {
	//m_mainMessage = "You are going back to Madrit.";	
	std::cout << "Red chance 1";
}

void logic::RedChanceDeck::redCard2() {
	//m_mainMessage = "You are going to East Station.\nIf you pass the start\n,you can collect money.";
	std::cout << "Red chance 2";
}

void logic::RedChanceDeck::redCard3() {
	//m_mainMessage = "You are going to Wroclaw.\nIf you pass the start\n,you can collect money.";
	std::cout << "Red chance 3";
}

void logic::RedChanceDeck::redCard4() {
	//m_mainMessage = "You are going back to Paris.\nIf you pass the start\n,you can collect money.";
	std::cout << "Red chance 4";
}

void logic::RedChanceDeck::redCard5() {
	//m_mainMessage = "You were drinking during the work, you pay 80$.";
	std::cout << "Red chance 5";
}

void logic::RedChanceDeck::redCard6() {
	//m_mainMessage = "The bank pays you intrests\nin the amount of 100$.";
	std::cout << "Red chance 6";
}

void logic::RedChanceDeck::redCard7() {
	//m_mainMessage = "The bank pays you intrests\nin the amount of 300$.";
	std::cout << "Red chance 7";
}

void logic::RedChanceDeck::redCard8() {
	//m_mainMessage = "You are paying 300$ for school";
	std::cout << "Red chance 8";
}

void logic::RedChanceDeck::redCard9() {
	//m_mainMessage = "You are going out of jail free.\nKeep this card and use later.";
	std::cout << "Red chance 9";
}

void logic::RedChanceDeck::redCard10() {
	//m_mainMessage = "You are going to jail.\n You don't pass the start.\nYou can't collect the money.";
	std::cout << "Red chance 10";
}

void logic::RedChanceDeck::redCard11() {
	//m_mainMessage = "You completed crossword!\nAs a reward, you get 200$.";
	std::cout << "Red chance 11";
}

void logic::RedChanceDeck::redCard12() {
	//calculateCharge();
	//m_mainMessage = "You need to renovate your buildings.\nFor every owned house\nyou pay 50$.For every owned hotel\nyou pay 200$.\nYou need to pay "
		//+ toStringWithPrecision(m_charge) + "$.";
	std::cout << "Red chance 12";
}

void logic::RedChanceDeck::redCard13() {
	//m_mainMessage = "You need to renovate your buildings.\nFor every owned house\nyou pay 80$.For every owned hotel\nyou pay 220$.\nYou need to pay "
		//+ toStringWithPrecision(m_charge) + "$.";
	std::cout << "Red chance 13";
}

void logic::RedChanceDeck::redCard14() {
	//m_mainMessage = "You are going 3 fields back.";
	std::cout << "Red chance 14";
}

void logic::RedChanceDeck::redCard15() {
	//m_mainMessage = "Speeding ticket, you have to pay 100$.";
	std::cout << "Red chance 15";
}
