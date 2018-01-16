#pragma once

#include "../include/PropertyView.h"

namespace view {
	class Industry : public Property {
		bool m_hasRolled = false;
	public:
		Industry(float positionX, float positionY, float signPositionX, float signPositionY)
			: Property(positionX, positionY, signPositionX, signPositionY) 	{ }

		virtual void activate(std::map<std::string, view::Button*>, logic::Player&, logic::Field*) override;
		virtual void roll() override;
		virtual void reset(std::map<std::string, view::Button*> buttons) override;
	};
}