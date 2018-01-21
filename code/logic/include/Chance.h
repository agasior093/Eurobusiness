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
		ChanceType m_type;
		float m_charge;	
				
	public:
		Chance(ChanceType type);
		~Chance() = default;

		ChanceType getType() { return m_type; }		
		virtual void activate(logic::Player&) override;
		virtual void reveal() override;
		virtual void moveForward(logic::Player&) override;
		virtual void moveBackwards(logic::Player&) override;
		virtual void calculateCharge() override;			
	};
}