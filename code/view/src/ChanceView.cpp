#include "../include/ChanceView.h"

void view::Chance::activate(std::map<std::string, view::Button*> buttons, logic::Player& player, logic::Field* field) {
	if (m_isRevealed == false) {
		buttons["Reveal"]->enable();
		buttons["End turn"]->disable();
	}
	else {		
		buttons["Reveal"]->disable();
	}

	if (player.getCurrentPayment() > 0 && (player.getCash() >= player.getCurrentPayment())) {
		buttons["Pay"]->enable();
	}
	else {
		buttons["Pay"]->disable();
	}

	if (player.getCurrentPayment() == 0 && m_isRevealed == true) {
		buttons["End turn"]->enable();
	}
}

void view::Chance::reveal() {
	m_isRevealed = true;	
}

void view::Chance::reset(std::map<std::string, view::Button*> buttons) {
	m_isRevealed = false;
	buttons["Reveal"]->disable();
}

template <typename T>
		std::string toStringWithPrecision(const T a_value, const int n = 1) {
			std::stringstream stream;
			stream << std::fixed << std::setprecision(n) << a_value;
			std::string s = stream.str();
			return s;
		}