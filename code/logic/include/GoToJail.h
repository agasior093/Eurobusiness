#pragma once

#include "../include/Field.h"

namespace logic {
	class GoToJail : public Field {
		//int m_rollCounter = 0;
		bool m_rolledDoubles = false;
		bool m_usedCard = false;
		std::string m_defaultMainMessage;
	public:
		GoToJail()
			: Field(false)
		{
			m_mainMessage = "\n\n\n\n\n\n\n\n\n\n\n\n\nYou are going to jail for 3 turns!\nYou can try rolling doubles or\nuse out of jail card\nif you have one.";
			m_defaultMainMessage = m_mainMessage;
		}
		~GoToJail() = default;
		virtual void activate(logic::Player&) override;
		virtual void reset() override;
		virtual void checkRollResult(int, int, logic::Player&) override;
		virtual void useCard(logic::Player&) override;
	};
}