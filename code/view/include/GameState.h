#pragma once

#include "State.h"
#include "DEFINITIONS.h"
#include <memory>
#include "Application.h"
#include "../include/DiceView.h"
#include "../code/logic/include/Game.h"
#include "../include/PlayerView.h"
#include "../include/GameBoardView.h"

namespace view {
	struct ApplicationData;

	struct PlayerNames {
	private:
		std::vector<std::string> m_playerNames;
	public:
		PlayerNames() {
			m_playerNames.emplace_back("Ferdek");
			m_playerNames.emplace_back("Pazdzioch");
		}
		std::vector<std::string>& getNames() {
			return m_playerNames;
		}
	};

	class GameState : public State {
		std::shared_ptr<ApplicationData> m_data;
		sf::Clock m_clock;

		PlayerNames m_playerNames;
		logic::Game m_game;

		view::GameBoard m_board;
		view::Dice m_diceOne, m_diceTwo;		
		
		Player m_playerOneToken;
		sf::Vector2f m_tokenPreviousPosition;
		sf::Vector2f m_tokenNextPosition;

		sf::Sprite m_background;
		sf::Sprite m_currentField;

		Button m_rollButton;
		Button m_payButton;
		Button m_endTurnButton;

	public:
		GameState(std::shared_ptr<ApplicationData> data);

		void initialise() override;
		void handleUserInput() override;
		void update(sf::Time) override;
		void draw() override;

		//on init
		void loadResources();
		void createBackground();
		void createButtons();
		void createDice();

		//update
		void calculateTokenPosition();
		void updateButtons();
		
		//on action 
		void rollTheDice();
	};
}