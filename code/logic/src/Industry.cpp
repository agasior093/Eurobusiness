#include "../include/Industry.h"


void logic::Industry::updateMessage() {
	std::string ownerInfo;
	if (m_owner == nullptr) {
		ownerInfo = "\nOwner: none";
	}
	else {
		ownerInfo = "\nOwner: " + m_owner->getName();
	}

	m_mainMessage = m_name + "\n\n" +
		"Purchase price : " + toStringWithPrecision(m_price) + "$\n\n" +
		"Base charge is 100$ and its\nmultiplied by number rolled by\nplayer that stays here.\n" +
		"If both industries are owned\nthis number is doubled\n\n\n\n\n\n" +
		ownerInfo;
}
