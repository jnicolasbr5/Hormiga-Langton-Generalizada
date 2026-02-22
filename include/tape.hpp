#pragma once

#include <iostream>
#include <vector>

#include "ant.hpp"
#include "colours.hpp"

class Ant; 

typedef std::vector<std::vector<Colours>> cinta_colores;

class Tape {
	public:
		// Constructor
		Tape(unsigned size, unsigned col, unsigned colors, cinta_colores celdas);

		// Getters y setters
		unsigned get_size() const {return cinta_.size();}
		unsigned get_col() const { return col_; }
		unsigned get_num_colors() const { return num_colors_; }


		const cinta_colores& get_cinta() const {return cinta_;}

		// Consultar celda
		Colours consultar_celda(unsigned i, unsigned j) const;

		// Cambiar celda
		void modificar_celda(unsigned i, unsigned j);

		// Comprobar posicion
		bool posicion_correcta(int i, int j);

		// Visualizacion
		void mostrar_cinta(const std::vector<Ant*>& hormigas);

	private:
	// Blanco -> 0, Negro -> 1
		cinta_colores cinta_;
		unsigned size_;
		unsigned col_;
		unsigned num_colors_;
};

Colours number_to_color(unsigned num);

unsigned color_to_number(Colours color);
