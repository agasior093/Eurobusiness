#pragma once

#include <SFML\Graphics.hpp>
#include "../code/logic/include/Player.h"
#include <memory>

namespace view {
	class Player {
		std::shared_ptr<logic::Player> m_player;
		//logic::Player* m_player;
		sf::CircleShape m_token;
		float m_position = 0.f;
		float m_targetPosition = 0.f;
		bool m_isMoving = false;
	public:
		Player() {}
		~Player() = default;

		bool isMoving() const;

		void create(logic::Player&);
		void setNewPosition(int);
		void setPosition(int);
		void move();

		sf::CircleShape& get();
		float getStep() const;
		sf::Vector2f getJumpOffSet() const;
		float getPosition() const;
	};
}