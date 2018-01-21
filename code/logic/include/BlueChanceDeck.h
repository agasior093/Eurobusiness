#pragma once
#include "../include/ChanceDeck.h"

namespace logic {
	class BlueChanceDeck : public ChanceDeck {
	public:
		static BlueChanceDeck & getDeck();
	private:
		BlueChanceDeck();
		BlueChanceDeck(const BlueChanceDeck&) {}

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
