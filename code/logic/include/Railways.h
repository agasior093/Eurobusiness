#pragma once

#include "Property.h"

namespace logic {
	class Railways : public Property {
	public:
		Railways(std::string name, float price)
			: Property(name, false, price, 100)
		{
			updateMessage();
		}
		virtual void updateMessage() override;		
	};
}