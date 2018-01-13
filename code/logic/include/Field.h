#pragma once

#include <string>
#include "Player.h"

namespace logic {
	class Field {
	protected:
		bool m_buyable;
		std::string m_mainMessage;
		std::string m_gameStatusMessage;
	public:
		Field(bool buyable)
			: m_buyable(buyable)
		{

		}
		virtual ~Field() = default;
		virtual std::string getMessage() { return m_mainMessage; }
		virtual std::string getGameStatus() { return m_gameStatusMessage; }

		virtual void activate(logic::Player&) {}
		virtual void reset() {}

		virtual void checkRollResult(int, int, logic::Player&) {}
		virtual void useCard(logic::Player&) {}		

		virtual void calculateCharge() {}
		virtual void pay(logic::Player&) {}		
		
		virtual void setOwner(logic::Player&) {}
		virtual void setUnderMortgage() {}
		virtual void liftMortgage() {}
		virtual void addHouse() {}
		virtual void sellHouse() {}
		virtual void buyHotel() {}
		virtual void sellHotel() {}

		virtual float getPrice() const { return 0; }
		virtual logic::Player* getOwner() { return nullptr; }

		template <typename T>
		std::string toStringWithPrecision(const T a_value, const int n = 1) {
			std::stringstream stream;
			stream << std::fixed << std::setprecision(n) << a_value;
			std::string s = stream.str();
			return s;
		}
	};
}

