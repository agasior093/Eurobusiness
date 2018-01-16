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

std::string logic::Railways::getPropertyInfo() {
	return m_name + "\n";
}

