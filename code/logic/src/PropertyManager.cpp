#include "../include/PropertyManager.h"

logic::PropertyManager::PropertyManager(logic::GameBoard& board) {
	m_board = &board;		
}

void logic::PropertyManager::setActivePlayer(logic::Player* player) {
	m_player = player;	
	setActiveProperty();
}

logic::Player& logic::PropertyManager::getActivePlayer() {
	return *m_player;
}

int logic::PropertyManager::getActivePropertyID() const {
	return m_activePropertyID;
}

void logic::PropertyManager::buyHouse(){
	m_activeProperty->addHouse();		
	m_player->substractCash(m_activeProperty->getHousePrice());
	m_player->increaseTransactionCounter();
}

void logic::PropertyManager::sellHouse(){
	m_activeProperty->removeHouse();
	m_player->addCash(m_activeProperty->getHousePrice());		
}

void logic::PropertyManager::buyHotel(){
	for (int i = 0; i < 4; i++) {
		m_activeProperty->removeHouse();
	}	
	m_activeProperty->addHotel();
	m_player->substractCash(m_activeProperty->getHotelPrice());
	m_player->increaseTransactionCounter();
}

void logic::PropertyManager::sellHotel() {
	m_activeProperty->removeHotel();
	m_player->addCash(m_activeProperty->getHotelPrice());
}

void logic::PropertyManager::mortgageProperty(){
	m_activeProperty->setUnderMortgage();
	m_player->addCash(m_activeProperty->getPrice() / 2);
}

void logic::PropertyManager::liftMortgage(){
	m_activeProperty->liftMortgage();
	m_player->substractCash((m_activeProperty->getPrice() / 2) + (m_activeProperty->getPrice() * 0.1f));
}

void logic::PropertyManager::setActiveProperty() {
	m_activePropertyID = 0;
	if (m_player->getProperties().size() > 0) {
		m_activeProperty = m_player->getProperties()[m_activePropertyID];
	}
	else {
		m_activeProperty = nullptr;
	}	
}

void logic::PropertyManager::goToNextProperty() {
	m_activePropertyID++;
	if (m_activePropertyID >= m_player->getProperties().size()) {
		m_activePropertyID = 0;
	}	
	m_activeProperty = m_player->getProperties()[m_activePropertyID];
}

void logic::PropertyManager::goToPreviousProperty() {
	m_activePropertyID--;
	if (m_activePropertyID < 0) {
		m_activePropertyID = m_player->getProperties().size() - 1;
	}
	m_activeProperty = m_player->getProperties()[m_activePropertyID];
}

bool logic::PropertyManager::hasOneOwner() {
	if (m_activeProperty != nullptr) {		
		auto group = m_activeProperty->getGroup();
		switch (group) {
		case GroupName::Bulgaria: {			
			if (m_board->getField(1).getOwner() == m_board->getField(3).getOwner()
				&& m_board->getField(1).getOwner() != nullptr) {
				return true;
			}
			else {
				return false;
			}
			break;
		}

		case GroupName::Poland: {			
			if (m_board->getField(6).getOwner() == m_board->getField(8).getOwner()
				&& m_board->getField(8).getOwner() == m_board->getField(9).getOwner()
				&& m_board->getField(6).getOwner() != nullptr) {
				return true;
			}
			else {
				return false;
			}
			break;
		}

		case GroupName::Spain: {
			if (m_board->getField(11).getOwner() == m_board->getField(13).getOwner()
				&& m_board->getField(13).getOwner() == m_board->getField(14).getOwner()
				&& m_board->getField(14).getOwner() != nullptr) {
				return true;
			}
			else {
				return false;
			}
			break;
		}

		case GroupName::Italy: {
			if (m_board->getField(16).getOwner() == m_board->getField(18).getOwner()
				&& m_board->getField(18).getOwner() == m_board->getField(19).getOwner()
				&& m_board->getField(16).getOwner() != nullptr) {
				return true;
			}
			else {
				return false;
			}
			break;
		}

		case GroupName::France: {
			if (m_board->getField(21).getOwner() == m_board->getField(23).getOwner()
				&& m_board->getField(23).getOwner() == m_board->getField(24).getOwner()
				&& m_board->getField(21).getOwner() != nullptr) {
				return true;
			}
			else {
				return false;
			}
			break;
		}

		case GroupName::England: {
			if (m_board->getField(26).getOwner() == m_board->getField(27).getOwner()
				&& m_board->getField(27).getOwner() == m_board->getField(29).getOwner()
				&& m_board->getField(26).getOwner() != nullptr) {
				return true;
			}
			else {
				return false;
			}
			break;
		}

		case GroupName::Russia: {
			if (m_board->getField(31).getOwner() == m_board->getField(32).getOwner()
				&& m_board->getField(32).getOwner() == m_board->getField(34).getOwner()
				&& m_board->getField(31).getOwner() != nullptr) {
				return true;
			}
			else {
				return false;
			}
			break;
		}

		case GroupName::Germany: {
			if (m_board->getField(37).getOwner() == m_board->getField(39).getOwner()
				&& m_board->getField(37).getOwner() != nullptr) {
				return true;
			}
			else {
				return false;
			}
			break;
		}
		}
	}
	else {
		return false;
	}
	
}

bool logic::PropertyManager::shouldEnableMortgage() {
	if (m_activeProperty != nullptr) {
		if (!m_activeProperty->isUnderMortgage()
			&& m_activeProperty->getNumberOfHouses() == 0 && m_activeProperty->getNumberOfHotels() == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
	
}

bool logic::PropertyManager::shouldEnableLiftMortgage() {
	if (m_activeProperty != nullptr) {
		if (m_activeProperty->isUnderMortgage() &&
			(m_player->getCash() >= (m_activeProperty->getPrice() / 2) + (m_activeProperty->getPrice() * 0.1))) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
	
}

bool logic::PropertyManager::shouldEnableBuyHouse() {
	if (m_activeProperty != nullptr) {
		if (m_player->getTransactionCounter() < 4 &&
			hasOneOwner() &&
			m_activeProperty->isBuildingArea() &&
			m_activeProperty->getNumberOfHotels() == 0 &&
			m_activeProperty->getNumberOfHouses() < 4 &&
			m_player->getCash() >= m_activeProperty->getHousePrice()) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}	
}

bool logic::PropertyManager::shouldEnableSellHouse() {
	if (m_activeProperty != nullptr) {
		if (m_activeProperty->getNumberOfHouses() > 0) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}	
}

bool logic::PropertyManager::shouldEnableBuyHotel() {
	if (m_activeProperty != nullptr) {
		if (m_player->getTransactionCounter() < 4 && 
			m_activeProperty->isBuildingArea() &&
			m_activeProperty->getNumberOfHouses() == 4 && 
			m_activeProperty->getNumberOfHotels() == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
	
}

bool logic::PropertyManager::shouldEnableSellHotel() {
	if (m_activeProperty != nullptr) {
		if (m_activeProperty->getNumberOfHotels() == 1) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}	
}

logic::Field* logic::PropertyManager::getActiveProperty() {
	return m_activeProperty;
}