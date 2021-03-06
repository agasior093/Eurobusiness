#pragma once

#include "Property.h"

namespace logic {
	class City : public Property {				
		float m_housePrice;
		float m_hotelPrice;
		int m_numberOfHouses = 0;
		int m_numberOfHotels = 0;
	public:
		City(std::string name, GroupName group, bool buildingArea, float price, float housePrice,
			float baseFee)
			: Property(name, group, buildingArea, price, baseFee), m_housePrice(housePrice), m_hotelPrice(4*housePrice)
		{
			updateMessage();
		}

		virtual void updateMessage() override;	
		virtual void calculateCharge() override;
		virtual void addHouse() override;
		virtual void removeHouse() override;
		virtual void addHotel() override;
		virtual void removeHotel() override;

		virtual std::string getPropertyInfo() override;
		virtual int getNumberOfHouses() const override;
		virtual int getNumberOfHotels() const override;
		virtual float getHousePrice() const override;
		virtual float getHotelPrice() const override;
	};
}