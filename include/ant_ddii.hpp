#pragma once 

#include "ant.hpp"

class Ant_DDII: public Ant {
	public:
		using Ant::Ant;

		void elegir_giro(Colours color) override;
		std::string get_tipo() override {return "DDII";}
};