#pragma once

#include "../include/Player.h"
#include "../include/Field.h"

namespace logic {
	class PropertyManager {
	public:
		std::string buyProperty(logic::Player&, logic::Field*);
		bool buyHouse(logic::Player&, logic::Field*);
		bool sellHouse(logic::Player&, logic::Field*);
		bool buyHotel(logic::Player&, logic::Field*);
		bool sellHotel(logic::Player&, logic::Field*);
		bool mortgageProperty(logic::Player&, logic::Field*);
		bool liftMortgage(logic::Player&, logic::Field*);

		template <typename T>
		std::string toStringWithPrecision(const T a_value, const int n = 1) {
			std::stringstream stream;
			stream << std::fixed << std::setprecision(n) << a_value;
			std::string s = stream.str();
			return s;
		}
	};
}
