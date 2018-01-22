#pragma once

#include <string>
#include "Player.h"

namespace logic {
	enum class GroupName {
		Bulgaria, Poland, Spain, Italy, France, England, Russia, Germany, Railways, Industries
	};

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
				
		virtual void activate(logic::Player&) {}
		virtual void updateMessage() {}
		virtual void reset() {}
		virtual void checkRollResult(int, int, logic::Player&) {}
		virtual void useCard(logic::Player&) {}		
		virtual void calculateCharge() { }
		virtual void pay(logic::Player&) {}
		virtual void buy(logic::Player&) {}		
		virtual void reveal(logic::Player&) {}
		virtual void moveForward(logic::Player&) {}
		virtual void moveBackwards(logic::Player&) {}
		virtual void setOwner(logic::Player&) {}
		virtual void setUnderMortgage() {}
		virtual void liftMortgage() {}
		virtual void addHouse() {}
		virtual void removeHouse() {}
		virtual void addHotel() {}
		virtual void removeHotel() {}
		
		virtual std::string getMessage() { return m_mainMessage; }
		virtual std::string getGameStatus() { return m_gameStatusMessage; }
		virtual std::string getPropertyInfo() { return ""; }
		virtual logic::Player* getOwner() { return nullptr; }
		virtual logic::GroupName getGroup() const { return GroupName::Bulgaria; }
		virtual std::string getName() const { return ""; };
		virtual float getPrice() const { return 0; }		
		virtual float getHousePrice() const { return 0; }
		virtual float getHotelPrice() const { return 0; }
		virtual int getNumberOfHouses() const { return 0; }
		virtual int getNumberOfHotels() const { return 0; }		
		virtual bool isBuildingArea() const { return false; }
		virtual bool isUnderMortgage() const { return false; }

		template <typename T>
		std::string toStringWithPrecision(const T a_value, const int n = 1) {
			std::stringstream stream;
			stream << std::fixed << std::setprecision(n) << a_value;
			std::string s = stream.str();
			return s;
		}
	};
}

