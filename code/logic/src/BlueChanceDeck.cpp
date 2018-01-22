#include "../include/BlueChanceDeck.h"

logic::BlueChanceDeck& logic::BlueChanceDeck::getDeck() {
	static BlueChanceDeck deck;
	return deck;
}

logic::BlueChanceDeck::BlueChanceDeck() {
	m_deck[0] = [&](logic::Player& player, std::string& message) { blueCard1(player, message); };
	m_deck[1] = [&](logic::Player& player, std::string& message) { blueCard1(player, message); };
	m_deck[2] = [&](logic::Player& player, std::string& message) { blueCard1(player, message); };
	m_deck[3] = [&](logic::Player& player, std::string& message) { blueCard1(player, message); };
	m_deck[4] = [&](logic::Player& player, std::string& message) { blueCard1(player, message); };
	m_deck[5] = [&](logic::Player& player, std::string& message) { blueCard1(player, message); };
	m_deck[6] = [&](logic::Player& player, std::string& message) { blueCard1(player, message); };
	m_deck[7] = [&](logic::Player& player, std::string& message) { blueCard1(player, message); };
	m_deck[8] = [&](logic::Player& player, std::string& message) { blueCard1(player, message); };
	m_deck[9] = [&](logic::Player& player, std::string& message) { blueCard1(player, message); };
	m_deck[10] = [&](logic::Player& player, std::string& message) { blueCard1(player, message); };
	m_deck[11] = [&](logic::Player& player, std::string& message) { blueCard1(player, message); };
	m_deck[12] = [&](logic::Player& player, std::string& message) { blueCard1(player, message); };
	m_deck[13] = [&](logic::Player& player, std::string& message) { blueCard1(player, message); };
	m_deck[14] = [&](logic::Player& player, std::string& message) { blueCard1(player, message); };
	shuffleDeck();
}

void logic::BlueChanceDeck::blueCard1(logic::Player& player, std::string& message) {

}

void logic::BlueChanceDeck::blueCard2() {

}

void logic::BlueChanceDeck::blueCard3() {

}

void logic::BlueChanceDeck::blueCard4() {

}

void logic::BlueChanceDeck::blueCard5() {

}

void logic::BlueChanceDeck::blueCard6() {

}

void logic::BlueChanceDeck::blueCard7() {

}

void logic::BlueChanceDeck::blueCard8() {

}

void logic::BlueChanceDeck::blueCard9() {

}

void logic::BlueChanceDeck::blueCard10() {

}

void logic::BlueChanceDeck::blueCard11() {

}

void logic::BlueChanceDeck::blueCard12() {

}

void logic::BlueChanceDeck::blueCard13() {

}

void logic::BlueChanceDeck::blueCard14() {

}

void logic::BlueChanceDeck::blueCard15() {
	
}