#pragma once
#include "../include/ChanceDeck.h"

namespace logic {	

	class RedChanceDeck : public ChanceDeck {
	public:
		static RedChanceDeck & getDeck();
	private:
		RedChanceDeck();
		RedChanceDeck(const RedChanceDeck&) {}		
		
		void redCard1(logic::Player&, std::string&);
		void redCard2(logic::Player&, std::string&);
		void redCard3(logic::Player&, std::string&);
		void redCard4(logic::Player&, std::string&);
		void redCard5(logic::Player&, std::string&);
		void redCard6(logic::Player&, std::string&);
		void redCard7(logic::Player&, std::string&);
		void redCard8(logic::Player&, std::string&);
		void redCard9(logic::Player&, std::string&);
		void redCard10(logic::Player&, std::string&);
		void redCard11(logic::Player&, std::string&);
		void redCard12(logic::Player&, std::string&);
		void redCard13(logic::Player&, std::string&);
		void redCard14(logic::Player&, std::string&);
		void redCard15(logic::Player&, std::string&);
	};
}
