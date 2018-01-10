#pragma once

#include "../include/Field.h"

namespace logic {
	class GoToJail : public Field {
	public:
		GoToJail()
			: Field(false)
		{
			m_mainMessage = "You are going to jail!\n";
		}
		~GoToJail() = default;
		virtual std::string getMessage() override {
			return m_mainMessage;
		}

		virtual std::string getGameStatus() override {
			return m_gameStatusMessage;
		}
	};
}