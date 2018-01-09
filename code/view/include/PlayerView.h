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
		
		void create(sf::Color, int, int);
		void setTargetPosition();
		void setPosition(int);
		void move();		

		sf::CircleShape& getToken();
		sf::RectangleShape& getLabel();

		bool isMoving() const;
		float getStep() const;
		sf::Vector2f getJumpOffSet() const;
		float getPosition() const;
	};
}