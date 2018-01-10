#pragma once

#include "../include/Field.h"

namespace logic {
	class Tax : public Field {
	public:
		Tax()
			: Field(false)
		{
			
		}
		~Tax() = default;

		virtual std::string getMessage() override {
			return m_mainMessage;
		}

		virtual std::string getGameStatus() override {
			return m_gameStatusMessage;
		}
	};
}