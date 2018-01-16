#pragma once

#include <SFML\Graphics.hpp>
#include "../code/logic/include/Player.h"
#include <memory>

namespace view {
	class Player {		
		logic::Player* m_player;

		//token
		sf::CircleShape m_token;
		float m_position = 0.f;
		float m_targetPosition = 0.f;
		bool m_isMoving = false;

		//label
		sf::RectangleShape m_label;
		sf::Texture m_texture;
	public:
		Player(logic::Player&);
		~Player() = default;
		
		void create(sf::Color, float, float, float, float);
		void setTargetPosition();
		void setPosition(float);
		void move();		
		void updateLabel();
		
		sf::CircleShape& getToken();
		sf::CircleShape getTokenCopy();
		sf::RectangleShape& getLabel();
		sf::Vector2f getJumpOffSet() const;
		std::string getPlayerInfo();		
		float getStep() const;		
		float getPosition() const;
		bool isMoving() const;

		template <typename T>
		std::string toStringWithPrecision(const T a_value, const int n = 1) {
			std::stringstream stream;
			stream << std::fixed << std::setprecision(n) << a_value;
			std::string s = stream.str();
			return s;
		}
	};
}