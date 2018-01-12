#pragma once

#include "../include/Field.h"

namespace logic {
	class GoToJail : public Field {
	public:
		GoToJail()
			: Field(false)
		{
			m_mainMessage = "\n\n\n\n\n\n\n\n\n\n\n\n\nYou are going to jail!\nYou can try rolling doubles or\nuse out of jail card\nif you have one.";
		}
		~GoToJail() = default;
		virtual void activate(logic::Player&) override;
	};
}