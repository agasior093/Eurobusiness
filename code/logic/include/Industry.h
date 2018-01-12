#pragma once

#include "Property.h"

namespace logic {
	class Industry : public Property {
	public:
		Industry(std::string name, bool buildingArea, float price)
			: Property(name, buildingArea, price, 100) 
		{
			updateMessage();
		}
		virtual void updateMessage() override;
	};
}
