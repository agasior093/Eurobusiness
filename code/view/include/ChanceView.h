#pragma once

#include "../include/FieldView.h"

namespace view {
	enum class ChanceType {
		RED, BLUE
	};

	class Chance : public Field {
		ChanceType m_type;
		bool m_isRevealed = false;
	public:
		Chance(float positionX, float positionY, ChanceType type)
			: Field(positionX, positionY), m_type(type)
		{
			if (m_type == ChanceType::RED) {
				m_texturePositionX = 200;
			}
			if(m_type == ChanceType::BLUE) {
				m_texturePositionX = 400;
			}			
		}
		virtual ~Chance() = default;		
		virtual void activate(std::map<std::string, view::Button*>, logic::Player&, logic::Field*) override;
		virtual void reveal() override;
		virtual void reset(std::map<std::string, view::Button*>) override;
	};
}
