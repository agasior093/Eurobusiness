#pragma once

#include "../include/Field.h"
#include "../include/Player.h"
#include <iostream>

namespace logic {
	enum class GroupName {
		Bulgaria, Poland, Spain, Italy, France, England, Russia, Germany, Railways, Industries
	};
	
	class Property : public Field {
		std::string m_name;
		GroupName m_group;

		bool m_buildingArea;
		bool m_underMortgage = false;

		float m_price;
		float m_housePrice;
		float m_hotelPrice;

		float m_baseFee;

		int m_numberOfHouses = 0;
		int m_numberOfHotels = 0;
		
		logic::Player* m_owner = nullptr;

		float m_charge;
		float m_defaultCharge;

	public:
		Property(std::string name, GroupName group, bool buildingArea, 
			float price, float housePrice, float baseFee)
			: Field(true), m_name(name), m_group(group), m_buildingArea(buildingArea), 
			m_price(price), m_housePrice(housePrice), m_hotelPrice(4*housePrice), m_baseFee(baseFee)
		{			
			
		}
		~Property() = default;

		void updateMessage() {
			this->m_mainMessage = "AAAAAA";
		}

		virtual std::string getMessage() override {
			updateMessage();
			return m_mainMessage;
		}

		virtual std::string getGameStatus() override {
			return m_gameStatusMessage;
		}
		
	};
}