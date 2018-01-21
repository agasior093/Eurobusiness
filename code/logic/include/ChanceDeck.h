#pragma once
#include "DEFINITIONS.h"
#include <functional>
#include <array>

namespace logic {

	using deck = std::array<std::function<void()>, CHANCE_DECK_SIZE>;

	class ChanceDeck {		
	public:
		ChanceDeck();		
		std::function<void()> getTopCard(deck&);	
	private:
		deck m_redChances;
		deck m_blueChances;

		void shuffleDeck(deck&);
		void moveTopCardToBottom(deck&);

		void redCard1();
		void redCard2();
		void redCard3();
		void redCard4();
		void redCard5();
		void redCard6();
		void redCard7();
		void redCard8();
		void redCard9();
		void redCard10();
		void redCard11();
		void redCard12();
		void redCard13();
		void redCard14();
		void redCard15();

		void blueCard1();
		void blueCard2();
		void blueCard3();
		void blueCard4();
		void blueCard5();
		void blueCard6();
		void blueCard7();
		void blueCard8();
		void blueCard9();
		void blueCard10();
		void blueCard11();
		void blueCard12();
		void blueCard13();
		void blueCard14();
		void blueCard15();			
	};
}
