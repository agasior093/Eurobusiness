#pragma once

#include "DEFINITIONS.h"

#include <sstream>
#include <iomanip>
#include <string>
#include <memory>

namespace logic {
	class Player {
		bool m_isActive = false;
		std::string m_name;		
		
		float m_cash = 3500;
		float m_currentPayment = 0;
		Player* m_loanHolder = nullptr;

		int m_position = 0;
		int m_positionDifference = 0; //total result of last dice roll		
		bool m_isMoving = false;		

		bool m_isSentToJail = false;
		int m_turnsLeftInJail = 0;
		int m_outOfJailCards = 0;

	public:
		Player() {}
		Player(std::string name)
			: m_name(name)
		{ }
		~Player() = default;

		void setAsActive(bool);			

		void addCash(float);
		bool substractCash(float);

		void createPayment(float, Player*);
		bool pay();

		void incrementPosition(int);
		void setPosition(int);	

		void sendToJail(bool);
		void lockInJail();
		void decrementTurnsInJail();

		void addOutOfJailCard();
		void useOutOfJailCard();		

		//getters
		std::string getName() const;		
		
		float getCash() const;
		float getCurrentPayment() const;
		Player* getLoanHolder() const;

		int getPosition() const;
		int getPositionDifference() const;

		bool isSentToJail() const;
		int getTurnsLeftInJail() const;
		int getOutOfJailCards() const;

		bool isActive() const;
	};
}