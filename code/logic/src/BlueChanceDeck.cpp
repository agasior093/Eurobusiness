#include "../include/BlueChanceDeck.h"

logic::BlueChanceDeck& logic::BlueChanceDeck::getDeck() {
	static BlueChanceDeck deck;
	return deck;
}

logic::BlueChanceDeck::BlueChanceDeck() {
	m_deck[0] = [&]() { blueCard1(); };
	m_deck[1] = [&]() { blueCard2(); };
	m_deck[2] = [&]() { blueCard3(); };
	m_deck[3] = [&]() { blueCard4(); };
	m_deck[4] = [&]() { blueCard5(); };
	m_deck[5] = [&]() { blueCard6(); };
	m_deck[6] = [&]() { blueCard7(); };
	m_deck[7] = [&]() { blueCard8(); };
	m_deck[8] = [&]() { blueCard9(); };
	m_deck[9] = [&]() { blueCard10(); };
	m_deck[10] = [&]() { blueCard11(); };
	m_deck[11] = [&]() { blueCard12(); };
	m_deck[12] = [&]() { blueCard13(); };
	m_deck[13] = [&]() { blueCard14(); };
	m_deck[14] = [&]() { blueCard15(); };
	shuffleDeck();
}

void logic::BlueChanceDeck::blueCard1() {

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