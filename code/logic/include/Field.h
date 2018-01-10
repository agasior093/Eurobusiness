#pragma once

#include <string>

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
		virtual std::string getMessage() { return ""; }
		virtual std::string getGameStatus() { return ""; }
	};
}

