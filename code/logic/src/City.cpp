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

void logic::City::calculateCharge() {
	if (m_numberOfHotels == 0) {
		m_charge = m_baseFee * (m_numberOfHouses + 1);
	}
	else {
		m_charge = m_baseFee * 7;
	}
}

void logic::City::addHouse() {
	m_numberOfHouses++;
}

void logic::City::removeHouse() {
	m_numberOfHouses--;
}

void logic::City::addHotel() {
	m_numberOfHotels++;
}

void logic::City::removeHotel() {
	m_numberOfHotels--;
}

std::string logic::City::getPropertyInfo() {
	std::string mortgage;
	if (this->m_underMortgage == true) {
		mortgage = "Yes, \nyou need " + toStringWithPrecision((m_price / 2) + (m_price * 0.1)) +
			"$ to pay it off.";
	}
	else {
		mortgage = "No";
	}

	return m_name + "\n\nBase  charge: " + toStringWithPrecision(m_baseFee) + "$\n" +
		"Under mortgage: " + mortgage + "\n"
		"Charge with 1 house: " + toStringWithPrecision(m_baseFee * 2) + "$\n" +
		"Charge with 2 houses: " + toStringWithPrecision(m_baseFee * 3) + "$\n" +
		"Charge with 3 houses: " + toStringWithPrecision(m_baseFee * 4) + "$\n" +
		"Charge with 4 houses: " + toStringWithPrecision(m_baseFee * 5) + "$\n" +
		"Charge with 1 hotel: " + toStringWithPrecision(m_baseFee * 7) + "$\n\n" +
		"Price of house: " + toStringWithPrecision(m_housePrice) + "$\n" +
		"Price of hotel: " + toStringWithPrecision(m_hotelPrice) + "$\n" +

		"\nHouses: " + std::to_string(m_numberOfHouses) +
		"\nHotels: " + std::to_string(m_numberOfHotels);
}

int logic::City::getNumberOfHouses() const {
	return m_numberOfHouses;
}

int logic::City::getNumberOfHotels() const {
	return m_numberOfHotels;
}

float logic::City::getHousePrice() const {
	return m_housePrice;
}

float logic::City::getHotelPrice() const {
	return m_hotelPrice;
}