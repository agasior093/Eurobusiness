#pragma once

#include "../include/Field.h"

namespace logic {
	class Parking : public Field {
	public:
		Parking()
			: Field(false)
		{
			
		}
		~Parking() = default;
		virtual std::string getMessage() override {
			return m_mainMessage;
		}

		virtual std::string getGameStatus() override {
			return m_gameStatusMessage;
		}
	};
}