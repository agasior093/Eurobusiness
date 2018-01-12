#pragma once

#include "../include/Field.h"
#include "../include/Player.h"
#include <iostream>

namespace logic {
	
	
	class Property : public Field {
	protected:
		std::string m_name;
		
		float m_price;

		bool m_buildingArea;
		bool m_underMortgage = false;		

		float m_baseFee;	
		
		logic::Player* m_owner = nullptr;

		float m_charge;
		float m_defaultCharge;
	public:
		Property(std::string name, bool buildingArea, float price, float baseFee)
			: Field(true), m_name(name), m_buildingArea(buildingArea), m_price(price), m_baseFee(baseFee)
		{			
			updateMessage();
		}
		~Property() = default;

		virtual void updateMessage() {}
		
		void setOwner(logic::Player&);
		void setUnderMortgage();
		void liftMortgage();

		template <typename T>
		std::string toStringWithPrecision(const T a_value, const int n = 1) {
			std::stringstream stream;
			stream << std::fixed << std::setprecision(n) << a_value;
			std::string s = stream.str();
			return s;
		}
	};
}