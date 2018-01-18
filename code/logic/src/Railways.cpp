#include "../include/Railways.h"


void logic::Railways::updateMessage() {
	std::string ownerInfo;
	if (m_owner == nullptr) {
		ownerInfo = "\nOwner: none";
	}
	else {
		ownerInfo = "\nOwner: " + m_owner->getName();
	}

	m_mainMessage = m_name + "\n\n" +
		"Purchase price : " + toStringWithPrecision(m_price) + "$\n\n" +
		"Base charge is 100$ and its\nmultiplied by number of \nother railways owned.\n\n\n\n\n\n" +
		ownerInfo;
}

void logic::Railways::calculateCharge() {
	checkOwnedRailways();
	m_charge = m_baseFee * m_railwaysOwnedByPlayer;
}

std::string logic::Railways::getPropertyInfo() {
	return m_name + "\n\n\n" +
		"Base charge is 100$ and its\nmultiplied by number of \nother railways owned.\n\n\n\n\n\n";
}

void logic::Railways::checkOwnedRailways() {
	if (m_owner->getProperties().size() > 0) {
		for (size_t i = 0; i < m_owner->getProperties().size(); ++i) {
			if (m_owner->getProperties()[i]->getName() == "South station" ||
				m_owner->getProperties()[i]->getName() == "West station" ||
				m_owner->getProperties()[i]->getName() == "North station" ||
				m_owner->getProperties()[i]->getName() == "East station") {
				m_railwaysOwnedByPlayer++;
			}
		}
	}
}

