#pragma once

#include "../include/Field.h"
#include "../include/Player.h"
#include <vector>

namespace logic {	
	

	class Property : public Field {
	protected:
		std::string m_name;
		
		float m_price;

		bool m_buildingArea;
		bool m_underMortgage = false;		

		float m_baseFee;	
		
		logic::Player* m_owner = nullptr;		
		logic::GroupName m_group;

		float m_charge;
		float m_defaultCharge;
		bool m_hasPayed = false;
	public:
		Property(std::string name, GroupName group, bool buildingArea, float price, float baseFee)
			: Field(true), m_name(name), m_buildingArea(buildingArea), m_price(price), m_baseFee(baseFee), m_group(group)
		{						
			updateMessage();
		}
		~Property() = default;

		virtual void updateMessage() override {}
		
		virtual void activate(logic::Player&) override;
		virtual void pay(logic::Player&) override;
		virtual void buy(logic::Player&) override;
		virtual void reset() override;

		virtual void calculateCharge();

		virtual void setOwner(logic::Player&) override;
		virtual void setUnderMortgage() override;
		virtual void liftMortgage() override;

		virtual std::string getName() const override;
		virtual float getPrice() const override;
		virtual logic::Player* getOwner() override;
		virtual logic::GroupName getGroup() const override;
		virtual bool isBuildingArea() const override;
		virtual bool isUnderMortgage() const override;
	};
}