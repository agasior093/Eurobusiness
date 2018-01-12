#pragma once

#include "Property.h"

namespace logic {
	enum class GroupName {
		Bulgaria, Poland, Spain, Italy, France, England, Russia, Germany, Railways, Industries
	};

	class City : public Property {
		GroupName m_group;		
		float m_housePrice;
		float m_hotelPrice;
		int m_numberOfHouses = 0;
		int m_numberOfHotels = 0;
	public:
		City(std::string name, GroupName group, bool buildingArea, float price, float housePrice,
			float baseFee)
			: Property(name, buildingArea, price, baseFee), m_group(group), m_housePrice(housePrice), m_hotelPrice(4*housePrice)
		{
			updateMessage();
		}

		virtual void updateMessage() override;
	};
}