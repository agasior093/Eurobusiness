#include "../include/RedChanceDeck.h"

logic::RedChanceDeck& logic::RedChanceDeck::getDeck() {
	static RedChanceDeck deck;
	return deck;
}

logic::RedChanceDeck::RedChanceDeck() {
	m_deck[0] = [&](logic::Player& player, std::string& message) { redCard1(player, message); };	
	m_deck[1] = [&](logic::Player& player, std::string& message) { redCard2(player, message); };
	m_deck[2] = [&](logic::Player& player, std::string& message) { redCard3(player, message); };
	m_deck[3] = [&](logic::Player& player, std::string& message) { redCard4(player, message); };
	m_deck[4] = [&](logic::Player& player, std::string& message) { redCard5(player, message); };
	m_deck[5] = [&](logic::Player& player, std::string& message) { redCard6(player, message); };
	m_deck[6] = [&](logic::Player& player, std::string& message) { redCard7(player, message); };
	m_deck[7] = [&](logic::Player& player, std::string& message) { redCard8(player, message); };
	m_deck[8] = [&](logic::Player& player, std::string& message) { redCard9(player, message); };
	m_deck[9] = [&](logic::Player& player, std::string& message) { redCard10(player, message); };
	m_deck[10] = [&](logic::Player& player, std::string& message) { redCard11(player, message); };
	m_deck[11] = [&](logic::Player& player, std::string& message) { redCard12(player, message); };
	m_deck[12] = [&](logic::Player& player, std::string& message) { redCard13(player, message); };
	m_deck[13] = [&](logic::Player& player, std::string& message) { redCard14(player, message); };
	m_deck[14] = [&](logic::Player& player, std::string& message) { redCard15(player, message); };
	//shuffleDeck();
}

void logic::RedChanceDeck::redCard1(logic::Player& player, std::string& message) {
	message = "You are going back to Madrit.\nYou can't collect the money\nif you pass the start";
	player.changePosition(true, 14);	
}

void logic::RedChanceDeck::redCard2(logic::Player& player, std::string& message) {
	message = "You are going to West Station.\nIf you pass the start\nyou can collect money.";
	if (player.getPosition() > 15 && player.getPosition() < 39) {
		player.allowToCollectMoney(true);
	}
	player.changePosition(true, 15);
	
}

void logic::RedChanceDeck::redCard3(logic::Player& player, std::string& message) {
	message = "You are going to Wroclaw.\nIf you pass the start\nyou can collect money.";
	if (player.getPosition() > 8 && player.getPosition() < 39) {
		player.allowToCollectMoney(true);
	}
	player.changePosition(true, 8);
}

void logic::RedChanceDeck::redCard4(logic::Player& player, std::string& message) {
	message = "You are going to Paris.\nIf you pass the start\nyou can collect money.";
	if (player.getPosition() > 24 && player.getPosition() < 39) {
		player.allowToCollectMoney(true);
	}
	player.changePosition(true, 24);
}

void logic::RedChanceDeck::redCard5(logic::Player& player, std::string& message) {
	message = "You were drinking during\n the work, you have to pay 180$.";
	player.createPayment(180.f, nullptr);
}

void logic::RedChanceDeck::redCard6(logic::Player& player, std::string& message) {
	message = "The bank pays you intrests\nin the amount of 120$.";
	player.addCash(120.f);
}

void logic::RedChanceDeck::redCard7(logic::Player& player, std::string& message) {
	message = "The bank pays you intrests\nin the amount of 300$.";
	player.addCash(300.f);
}

void logic::RedChanceDeck::redCard8(logic::Player& player, std::string& message) {
	message = "You are obligated to pay\n 300$ for school";
	player.createPayment(300.f, nullptr);
}

void logic::RedChanceDeck::redCard9(logic::Player& player, std::string& message) {
	message = "You are going out of jail free.\nKeep this card and use later.";
	player.addOutOfJailCard();
}

void logic::RedChanceDeck::redCard10(logic::Player& player, std::string& message) {
	message = "You are going to jail.\n You don't pass the start.\nYou can't collect the money.";
	player.sendToJail(true);
}

void logic::RedChanceDeck::redCard11(logic::Player& player, std::string& message) {
	message = "You completed crossword!\nAs a reward, you get 200$.";
	player.addCash(200.f);
}

void logic::RedChanceDeck::redCard12(logic::Player& player, std::string& message) {	
	float payment = player.getNumberOfHouses() * 50.f + player.getNumberOfHotels() * 200.f;	
	message = "You need to renovate your buildings.\nFor every owned house\nyou pay 50$.For every owned hotel\nyou pay 200$.\nYou need to pay "
		+ toStringWithPrecision(payment) + "$.";
	player.createPayment(payment, nullptr);	
}

void logic::RedChanceDeck::redCard13(logic::Player& player, std::string& message) {
	float payment = player.getNumberOfHouses() * 80.f + player.getNumberOfHotels() * 220.f;
	message = "You need to renovate your buildings.\nFor every owned house\nyou pay 80$.For every owned hotel\nyou pay 220$.\nYou need to pay "
		+ toStringWithPrecision(payment) + "$.";
	player.createPayment(payment, nullptr);
}

void logic::RedChanceDeck::redCard14(logic::Player& player, std::string& message) {
	message = "You are going 3 fields back.";	
	int currentPosition = player.getPosition();
	int newPosition = currentPosition - 3;
	if (newPosition < 0) {
		newPosition += 40;
	}
	player.changePosition(true, newPosition);
}

void logic::RedChanceDeck::redCard15(logic::Player& player, std::string& message) {
	message = "Speeding ticket, you have to pay 150$.";
	player.createPayment(150.f, nullptr);
}
