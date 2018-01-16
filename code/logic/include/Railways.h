#pragma once

#include "Property.h"

namespace logic {
	class Railways : public Property {
	public:
		Railways(std::string name, GroupName group,float price)
			: Property(name, group, false, price, 100)
		{
			updateMessage();
		}
		virtual void updateMessage() override;		
		virtual std::string getPropertyInfo() override;
		virtual void calculateCharge() override;
	};
}