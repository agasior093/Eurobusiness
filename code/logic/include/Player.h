#pragma once

#include "DEFINITIONS.h"

#include <sstream>
#include <iomanip>
#include <string>
#include <memory>
#include <vector>

namespace logic {
	class Field;

	class Player {
		std::string m_name;
		std::vector<logic::Field*> m_properties;
		Player* m_loanHolder = nullptr;
		float m_cash = 3500;
		float m_currentPayment = 0;
		int m_position = 0;
		int m_positionDifference = 0; 				
		int m_turnsLeftInJail = 0;
		int m_outOfJailCards = 0;
		int m_transactionCounter = 0;	
		bool m_isActive = false;
		bool m_isSentToJail = false;

	public:		
		Player(std::string name)
			: m_name(name)	{ }
		~Player() = default;

		void setAsActive(bool);		
		void addProperty(logic::Field*);
		void addCash(float);
		void substractCash(float);
		void createPayment(float, Player*);
		void incrementPosition(int);
		void setPosition(int);	
		void sendToJail(bool);
		void lockInJail();
		void decrementTurnsInJail();
		void addOutOfJailCard();
		void useOutOfJailCard();			
		void increaseTransactionCounter();
		void resetTransactionCounter();
		bool pay();
		
		std::string getName() const;	
		std::vector<logic::Field*>& getProperties();
		Player* getLoanHolder() const;
		float getCash() const;
		float getCurrentPayment() const;			
		int getPosition() const;
		int getPositionDifference() const;		
		int getTurnsLeftInJail() const;
		int getOutOfJailCards() const;
		int getTransactionCounter() const;
		bool isActive() const;
		bool isSentToJail() const;
	};
}