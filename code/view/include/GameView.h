#pragma once

#include <iostream>

#include "DEFINITIONS.h"
#include <SFML\Graphics.hpp>
#include <vector>
#include <memory>
#include <map>

#include "ResourceManager.h"
#include "InputManager.h"
#include "Button.h"
#include "MessageBox.h"
#include "../code/logic/include/Game.h"
#include "../include/DiceView.h"
#include "../include/PlayerView.h"
#include "../include/GameBoardView.h"
#include "../include/FieldView.h"
#include "../code/logic/include/GameBoard.h"

namespace view {
	struct Data {
		ResourceManager resourceManager;
		InputManager inputManager;
		sf::RenderWindow window;
		sf::Clock clock;
	};	
			
	class GameView {		
		std::unique_ptr<Data> m_data;
		void gameLoop();
		void initialise();
		void handleInput();
		void update(sf::Time); //
		void draw();

		//game components		
		int m_numberOfPlayers;
		logic::Game m_game;
		view::Dice m_diceOne, m_diceTwo;
		view::GameBoard m_board;
		
		std::vector<view::Player> m_players;
		unsigned m_activePlayer = 0;
		std::vector<view::MessageBox> m_playerLabels;
		std::vector<sf::CircleShape> m_playerTokenCopies;

		sf::Vector2f m_tokenPreviousPosition;
		sf::Vector2f m_tokenNextPosition;
		int m_playerPreviousPosition;

		//application components
		sf::Sprite m_background;
		sf::Sprite m_currentField;

		MessageBox m_gameStatus;
		MessageBox m_fieldInfo;
		
		std::map<std::string, Button*> m_buttons;
		//left menu buttons
		Button m_rollButton;	
		Button m_propertyManagerButton;
		Button m_endTurnButton;
		//right menu buttons
		Button m_payButton;
		Button m_buyButton;
		Button m_jailCardButton;
		Button m_jailRollButton;
		Button m_revealButton;
		Button m_collectButton;

		sf::Sound m_buySound;
		sf::Sound m_paySound;
		sf::Sound m_jailSound;
		bool m_shouldPlaySound = true;

	public:
		GameView(std::vector<std::string>&);
		~GameView() = default;				
		
		//on init
		void loadResources();
		void createBackground();
		void createButtons();
		void createDice();
		void createPlayers();
		void createMessageBoxes();
		void createSoundEffects();

		//on update
		void calculateTokenPosition();
		void updateButtons();
		void updatePlayerLabels();
		void updateCurrentField();

		//on event 
		void rollTheDice();
		void endTurn();
		void jailRoll();
		void industryRoll();
		
		view::Player& activePlayer();
		Button* getButton(std::string);

		template <typename T>
		std::string toStringWithPrecision(const T a_value, const int n = 1) {
			std::stringstream stream;
			stream << std::fixed << std::setprecision(n) << a_value;
			std::string s = stream.str();
			return s;
		}
	};
}