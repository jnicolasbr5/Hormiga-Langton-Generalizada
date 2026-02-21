#pragma once

#include <fstream>
#include <iostream>
#include <ant.hpp>
#include <tape.hpp>


struct Fichero {
	unsigned cinta_size;
	unsigned cinta_col;
	Coordenada coordenada;
	Orientation orientacion;
	cinta_binaria cinta_entrada;
	cinta_orientacion cinta_inicial;
};

Fichero leerFichero(std::ifstream& datos);

class Simulator {

	public:
	// Constructor
		Simulator(const Fichero& datos);

		// Getters
		const Tape& get_tape() const {return cinta_;}
		const Ant& get_ant() const {return hormiga_;}

		// Simulación
		void run();
		void guardar_estado();

	private: 
		Tape cinta_;
		Ant hormiga_;
		unsigned count_;
};

std::ostream& operator<<(std::ostream& os, const Simulator& sim);