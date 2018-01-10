#pragma once

#include "../include/Field.h"

namespace logic {
	class Start : public Field {
	public:
		Start()
			: Field(false)
		{
			
		}
		~Start() = default;
	
	};
}