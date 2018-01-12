#pragma once

#include "../include/Field.h"

namespace logic {
		class Tax : public Field {
		std::string m_name;
		int m_charge;
		int m_defaultCharge;
		std::string m_defaultMessage;
	public:
		Tax(std::string name, int charge)
			: Field(false), m_name(name), m_charge(charge)
		{
			m_mainMessage = m_name + "\n\nYou are obligated to\npay " + std::to_string(m_charge) + "$.";
			m_defaultMessage = m_mainMessage;
			m_defaultCharge = m_charge;
		}
		~Tax() = default;

		virtual void activate(logic::Player&) override;
		virtual void pay(logic::Player&) override;
		virtual void reset() override;	
	};
}