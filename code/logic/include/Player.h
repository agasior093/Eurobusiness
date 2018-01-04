#pragma once
#include <string>
#include <memory>

namespace logic {
	class Player {
		std::string m_name;
		
		float m_cash = 3500;
		float m_currentPayment = 0;
		std::unique_ptr<Player> m_loanHolder = nullptr;

		int m_position = 0;
		int m_targetPosition = 0;
		bool m_isMoving = false;

		int m_turnsLeftInJail = 0;
		int m_outOfJailCards = 0;

	public:
		Player() {}
		Player(std::string name) 
			: m_name(name)
		{ }
		~Player() = default;

		//getters
		std::string getName();
		
		float getCash();
		float getCurrentPayment();		

		int getPosition();
		int getTargetPosition();
		bool isMoving();

		int getTurnsLeftInJail();
		int getOutOfJailCards();
	};
}