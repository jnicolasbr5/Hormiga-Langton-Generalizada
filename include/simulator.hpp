#pragma once

#include <fstream>
#include <iostream>
#include "ant.hpp"
#include "tape.hpp"


struct Fichero {
	unsigned cinta_size;
	unsigned cinta_col;
	unsigned num_colores;
	std::vector<Ant*> vec_hormiga;
	cinta_colores cinta_entrada;
};

Fichero leerFichero(std::ifstream& datos);

class Simulator {

	public:
	// Constructor
		Simulator(const Fichero& datos);
	
	// Destructor
		~Simulator();

		// Getters
		const Tape& get_tape() const {return cinta_;}
		const std::vector<Ant*>& get_hormigas() const { return hormigas_; }

		// Simulación
		void run();
		void guardar_estado();

	private: 
		Tape cinta_;
		std::vector<Ant*> hormigas_;
		unsigned count_;
};

std::ostream& operator<<(std::ostream& os, const Simulator& sim);