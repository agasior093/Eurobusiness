#include "NewGame.h"

void NewGame::start() {
	std::cout << "***Welcome to Eurobusiness Board Game***\n" <<
		"How many players are going to play? [2, 3 or 4] \n";
	do {
		std::cin >> m_numberOfPlayers;
	} while (m_numberOfPlayers < 2 || m_numberOfPlayers > 4);

	for (size_t i = 0; i < m_numberOfPlayers; ++i) {
		bool isNameUnique;
		std::string name;
		std::cout << "Enter name of player nr " << i + 1 << "\n";		

		do {
			std::cin >> name;
			isNameUnique = true;
			if (m_playerNames.size() > 0) {
				for (size_t i = 0; i < m_playerNames.size(); ++i) {
					if (name == m_playerNames[i]) {
						std::cout << "Choose unique name for every player. \n";
						isNameUnique = false;
					}
					else {
						isNameUnique = true;
					}
				}
			}			
		} while (!isNameUnique);	
		m_playerNames.push_back(name);
	}
	
	view::GameView newGameView(m_playerNames);
}
