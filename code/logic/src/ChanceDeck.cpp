#include "../include/ChanceDeck.h"

logic::ChanceDeck::ChanceDeck() {
	shuffleDeck(m_redChances);
	shuffleDeck(m_blueChances);

	m_redChances[0] = [&]() { redCard1(); };
	m_redChances[1] = [&]() { redCard2(); };
	m_redChances[2] = [&]() { redCard3(); };
	m_redChances[3] = [&]() { redCard4(); };
	m_redChances[4] = [&]() { redCard5(); };
	m_redChances[5] = [&]() { redCard6(); };
	m_redChances[6] = [&]() { redCard7(); };
	m_redChances[7] = [&]() { redCard8(); };
	m_redChances[8] = [&]() { redCard9(); };
	m_redChances[9] = [&]() { redCard10(); };
	m_redChances[10] = [&]() { redCard11(); };
	m_redChances[11] = [&]() { redCard12(); };
	m_redChances[12] = [&]() { redCard13(); };
	m_redChances[13] = [&]() { redCard14(); };
	m_redChances[14] = [&]() { redCard15(); };

	m_blueChances[0] = [&]() { blueCard1(); };
	m_blueChances[1] = [&]() { blueCard2(); };
	m_blueChances[2] = [&]() { blueCard3(); };
	m_blueChances[3] = [&]() { blueCard4(); };
	m_blueChances[4] = [&]() { blueCard5(); };
	m_blueChances[5] = [&]() { blueCard6(); };
	m_blueChances[6] = [&]() { blueCard7(); };
	m_blueChances[7] = [&]() { blueCard8(); };
	m_blueChances[8] = [&]() { blueCard9(); };
	m_blueChances[9] = [&]() { blueCard10(); };
	m_blueChances[10] = [&]() { blueCard11(); };
	m_blueChances[11] = [&]() { blueCard12(); };
	m_blueChances[12] = [&]() { blueCard13(); };
	m_blueChances[13] = [&]() { blueCard14(); };
	m_blueChances[14] = [&]() { blueCard15(); };
}

void logic::ChanceDeck::shuffleDeck(deck& deck) {
	std::random_shuffle(std::begin(deck), std::end(deck));
}

std::function<void()> logic::ChanceDeck::getTopCard(deck& deck) {
	return deck[deck.size() - 1];
}

void logic::ChanceDeck::moveTopCardToBottom(deck& deck) {
	auto tempArray = deck;

	for (size_t i = 0; i < deck.size() - 1; ++i) {
		tempArray[i + 1] = deck[i];
	}

	auto lastCard = deck[deck.size() - 1];
	deck[0] = lastCard;

	for (size_t i = 1; i < deck.size(); ++i) {
		deck[i] = tempArray[i];
	}
}

void logic::ChanceDeck::blueCard1() {

}

void logic::ChanceDeck::redCard1() {
	//m_mainMessage = "You are going back to Madrit.";	
}

void logic::ChanceDeck::redCard2() {
	//m_mainMessage = "You are going to East Station.\nIf you pass the start\n,you can collect money.";
}

void logic::ChanceDeck::redCard3() {
	//m_mainMessage = "You are going to Wroclaw.\nIf you pass the start\n,you can collect money.";
}

void logic::ChanceDeck::redCard4() {
	//m_mainMessage = "You are going back to Paris.\nIf you pass the start\n,you can collect money.";
}

void logic::ChanceDeck::redCard5() {
	//m_mainMessage = "You were drinking during the work, you pay 80$.";
}

void logic::ChanceDeck::redCard6() {
	//m_mainMessage = "The bank pays you intrests\nin the amount of 100$.";
}

void logic::ChanceDeck::redCard7() {
	//m_mainMessage = "The bank pays you intrests\nin the amount of 300$.";
}

void logic::ChanceDeck::redCard8() {
	//m_mainMessage = "You are paying 300$ for school";
}

void logic::ChanceDeck::redCard9() {
	//m_mainMessage = "You are going out of jail free.\nKeep this card and use later.";
}

void logic::ChanceDeck::redCard10() {
	//m_mainMessage = "You are going to jail.\n You don't pass the start.\nYou can't collect the money.";
}

void logic::ChanceDeck::redCard11() {
	//m_mainMessage = "You completed crossword!\nAs a reward, you get 200$.";
}

void logic::ChanceDeck::redCard12() {
	//calculateCharge();
	//m_mainMessage = "You need to renovate your buildings.\nFor every owned house\nyou pay 50$.For every owned hotel\nyou pay 200$.\nYou need to pay "
		//+ toStringWithPrecision(m_charge) + "$.";
}

void logic::ChanceDeck::redCard13() {
	//m_mainMessage = "You need to renovate your buildings.\nFor every owned house\nyou pay 80$.For every owned hotel\nyou pay 220$.\nYou need to pay "
		//+ toStringWithPrecision(m_charge) + "$.";
}

void logic::ChanceDeck::redCard14() {
	//m_mainMessage = "You are going 3 fields back.";
}

void logic::ChanceDeck::redCard15() {
	//m_mainMessage = "Speeding ticket, you have to pay 100$.";
}

void logic::ChanceDeck::blueCard1() {

}

void logic::ChanceDeck::blueCard2() {

}

void logic::ChanceDeck::blueCard3() {

}

void logic::ChanceDeck::blueCard4() {

}

void logic::ChanceDeck::blueCard5() {

}

void logic::ChanceDeck::blueCard6() {

}

void logic::ChanceDeck::blueCard7() {

}

void logic::ChanceDeck::blueCard8() {

}

void logic::ChanceDeck::blueCard9() {

}

void logic::ChanceDeck::blueCard10() {

}

void logic::ChanceDeck::blueCard11() {

}

void logic::ChanceDeck::blueCard12() {

}

void logic::ChanceDeck::blueCard13() {

}

void logic::ChanceDeck::blueCard14() {

}

void logic::ChanceDeck::blueCard15() {

}