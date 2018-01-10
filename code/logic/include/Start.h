#pragma once

#include "../include/Field.h"

namespace logic {
	class Start : public Field {
	public:
		Start()
			: Field(false)
		{
			
		}
		~Start() = default;

		virtual std::string getMessage() override {
			return m_mainMessage;
		}

		virtual std::string getGameStatus() override {
			return m_gameStatusMessage;
		}
	};
}