#pragma once

#include <iostream>
#include <vector>

typedef std::vector<std::vector<unsigned>> cinta_binaria;

class Tape {
	public:
		// Constructor
		Tape(unsigned size, unsigned col);
		Tape(unsigned size, unsigned col, cinta_binaria celdas);

		// Getters y setters
		unsigned get_size() const {return cinta_.size();}
		unsigned get_col() const { return col_; }
		const cinta_binaria& get_cinta() const {return cinta_;}

		unsigned get_valor(unsigned i, unsigned j);

		// Consultar celda
		unsigned consultar_celda(unsigned i, unsigned j) const;

		// Cambiar celda
		void modificar_celda(unsigned i, unsigned j);

		// Comprobar posicion
		bool posicion_correcta(int i, int j);

	private:
	// Blanco -> 0, Negro -> 1
		cinta_binaria cinta_;
		unsigned size_;
		unsigned col_;
};

std::ostream& operator<<(std::ostream& os, const Tape& cinta);
