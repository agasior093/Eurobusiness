#pragma once

#include "../include/Field.h"

namespace logic {
	class JailVisitor : public Field {
	public:
		JailVisitor()
			: Field(false)
		{
			
		}
		~JailVisitor() = default;
		virtual std::string getMessage() override {
			return m_mainMessage;
		}

		virtual std::string getGameStatus() override {
			return m_gameStatusMessage;
		}
	};
}