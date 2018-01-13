#pragma once

#include "../include/Player.h"
#include "../include/Field.h"

namespace logic {
	class PropertyManager {
	public:
		bool buyProperty(logic::Player&, logic::Field*);
		bool buyHouse(logic::Player&, logic::Field*);
		bool sellHouse(logic::Player&, logic::Field*);
		bool buyHotel(logic::Player&, logic::Field*);
		bool sellHotel(logic::Player&, logic::Field*);
		bool mortgageProperty(logic::Player&, logic::Field*);
		bool liftMortgage(logic::Player&, logic::Field*);
	};
}
