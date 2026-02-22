#pragma once 

#include "ant.hpp"

class Ant_IDID: public Ant {
	public:
		using Ant::Ant;

		void elegir_giro(Colours color) override;
		std::string get_tipo() override {return "IDID";}

};