#pragma once

#include "../include/Field.h"
#include "../include/RedChanceDeck.h"
#include "../include/BlueChanceDeck.h"
#include <array>
#include <algorithm>

namespace logic {
	enum class ChanceType {
		RED, BLUE
	};
	
	class Chance : public Field {	
		float m_charge = 0;
		ChanceType m_type;						
	public:
		Chance(ChanceType type);
		~Chance() = default;

		ChanceType getType() { return m_type; }	
		virtual void activate(logic::Player&) override;
		virtual void reset() override;
		virtual void reveal(logic::Player&) override;
		virtual void pay(logic::Player&) override;
	};
}