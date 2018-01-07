#pragma once

#include <SFML\Graphics.hpp>

namespace view {
	class Player {
		int m_playerID;
		sf::CircleShape m_token;
		float m_position = 0.f;
		float m_targetPosition = 0.f;
		bool m_isMoving = false;
	public:
		Player() {}
		~Player() = default;

		bool isMoving() const;

		void create();
		void setNewPosition(int);
		void setPosition(int);
		void move();

		sf::CircleShape& get();
		float getStep() const;
		sf::Vector2f getJumpOffSet() const;
		float getPosition() const;
	};
}