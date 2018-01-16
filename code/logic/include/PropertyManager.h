#pragma once

#include "../include/Player.h"
#include "../include/Field.h"
#include "../include/GameBoard.h"

namespace logic {
	class PropertyManager {
		GameBoard* m_board;
		Player* m_player;
		Field* m_activeProperty;
		int m_activePropertyId = 0;
	public:		
		PropertyManager(logic::GameBoard&);
		
		void buyHouse();
		void sellHouse();
		void buyHotel();
		void sellHotel();
		void mortgageProperty();
		void liftMortgage();

		void setActivePlayer(logic::Player*);		
		void setActiveProperty();
		void goToNextProperty();
		void goToPreviousProperty();
		bool hasOneOwner();

		bool shouldEnableMortgage();
		bool shouldEnableLiftMortgage();
		bool shouldEnableBuyHouse();
		bool shouldEnableSellHouse();
		bool shouldEnableBuyHotel();
		bool shouldEnableSellHotel();

		logic::Player& getActivePlayer();
		logic::Field* getActiveProperty();
		int getActivePropertyId() const;

		template <typename T>
		std::string toStringWithPrecision(const T a_value, const int n = 1) {
			std::stringstream stream;
			stream << std::fixed << std::setprecision(n) << a_value;
			std::string s = stream.str();
			return s;
		}
	};
}
