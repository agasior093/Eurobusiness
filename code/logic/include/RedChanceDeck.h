#pragma once
#include "../include/ChanceDeck.h"

namespace logic {
	class RedChanceDeck : public ChanceDeck {		
	public:							
		static RedChanceDeck & getDeck();
	private:
		RedChanceDeck();
		RedChanceDeck(const RedChanceDeck&) {}
		
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
	};
}
