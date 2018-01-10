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
	
	};
}