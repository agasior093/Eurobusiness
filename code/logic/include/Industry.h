#pragma once

#include "Property.h"

namespace logic {
	class Industry : public Property {		
		int m_rollResult = 0;
	public:
		Industry(std::string name, GroupName group, float price)
			: Property(name, group, false, price, 100) 
		{
			updateMessage();
		}
		virtual void updateMessage() override;
		virtual void activate(logic::Player&) override;
		virtual void reset() override;
		virtual void checkRollResult(int, int, logic::Player&) override;
		virtual void calculateCharge() override;
	};
}
