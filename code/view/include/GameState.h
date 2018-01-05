#pragma once

#include "State.h"
#include "DEFINITIONS.h"
#include <memory>
#include "Application.h"
#include "../include/DiceView.h"
#include "../code/logic/include/Game.h"

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

		PlayerNames m_playerNames;
		logic::Game m_game;

		sf::Clock m_clock;
		sf::Sprite m_background;

		view::Dice m_firstDice;
		view::Dice m_secondDice;

		Button m_rollButton;
		Button m_payButton;
		Button m_endTurnButton;

	public:
		GameState(std::shared_ptr<ApplicationData> data);

		void initialise() override;
		void handleUserInput() override;
		void update(sf::Time) override;
		void draw() override;

		void loadResources();
		void createBackground();
		void createButtons();
		void createDice();

		void rollTheDice();
	};
}