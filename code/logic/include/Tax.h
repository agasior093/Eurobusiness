#pragma once

#include "../include/Field.h"

namespace logic {
	class Tax : public Field {
	public:
		Tax()
			: Field(false)
		{
			
		}
		~Tax() = default;
	
	};
}