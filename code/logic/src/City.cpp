#include "../include/City.h"

void logic::City::updateMessage() {
	std::string ownerInfo;
	if (m_owner == nullptr) {
		ownerInfo = "\nOwner: none";
	}
	else {
		ownerInfo = "\nOwner: " + m_owner->getName();
	}

	m_mainMessage = m_name + "\n\n" +
		"Purchase price: " + toStringWithPrecision(m_price) + "$\n" +
		"Base  charge: " + toStringWithPrecision(m_baseFee) + "$\n" +
		"Charge with 1 house: " + toStringWithPrecision(m_baseFee * 2) + "$\n" +
		"Charge with 2 houses: " + toStringWithPrecision(m_baseFee * 3) + "$\n" +
		"Charge with 3 houses: " + toStringWithPrecision(m_baseFee * 4) + "$\n" +
		"Charge with 4 houses: " + toStringWithPrecision(m_baseFee * 5) + "$\n" +
		"Charge with 1 hotel: " + toStringWithPrecision(m_baseFee * 7) + "$\n\n" +
		"Price of house: " + toStringWithPrecision(m_housePrice) + "$\n" +
		"Price of hotel: " + toStringWithPrecision(m_hotelPrice) + "$\n" +
		ownerInfo +
		"\nHouses: " + std::to_string(m_numberOfHouses) +
		"\nHotels: " + std::to_string(m_numberOfHotels);
}