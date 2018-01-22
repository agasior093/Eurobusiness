#include "../include/ChanceDeck.h"

void logic::ChanceDeck::shuffleDeck() {		
	std::random_shuffle(std::begin(m_deck), std::end(m_deck));
}

logic::function logic::ChanceDeck::getTopCard() {
	auto topCard = m_deck[m_deck.size() - 1];
	//moveTopCardToBottom();
	return m_deck[0];
}

void logic::ChanceDeck::moveTopCardToBottom() {
	auto tempArray = m_deck;

	for (size_t i = 0; i < m_deck.size() - 1; ++i) {
		tempArray[i + 1] = m_deck[i];
	}

	auto lastCard = m_deck[m_deck.size() - 1];
	m_deck[0] = lastCard;

	for (size_t i = 1; i < m_deck.size(); ++i) {
		m_deck[i] = tempArray[i];
	}
}

