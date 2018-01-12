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
		virtual void checkRollResult(int, int, logic::Player&) {}
		virtual void useCard(logic::Player&) {}
		virtual void pay(logic::Player&) {}
		virtual void reset() {}
	};
}

