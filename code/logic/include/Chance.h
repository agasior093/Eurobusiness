#pragma once

#include "../include/Field.h"
#include <deque>

namespace logic {
	enum class ChanceType {
		RED, BLUE
	};

	class Chance : public Field {
		ChanceType m_type;
		std::deque<std::string> m_chances;
	public:
		Chance(ChanceType type) :
			Field(false), m_type(type)
		{		
			
		}
		~Chance() = default;

		ChanceType getType() { return m_type; }

		virtual std::string getMessage() override {
			return m_mainMessage;
		}

		virtual std::string getGameStatus() override {
			return m_gameStatusMessage;
		}
	};
}