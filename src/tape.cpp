#include "tape.hpp"

Tape::Tape(unsigned size, unsigned col) : size_(size), col_(col) {
	for (size_t i = 0; i < size; i++) {
		std::vector<unsigned> fila(col, 4);
		cinta_.push_back(fila);
	}
}

Tape::Tape(unsigned size, unsigned col, cinta_binaria celdas) 
					: size_(size), col_(col), cinta_(celdas) {}


unsigned Tape::consultar_celda(unsigned i, unsigned j) const {
	return cinta_[i][j];
}

void Tape::modificar_celda(unsigned i, unsigned j) {
	if (consultar_celda(i, j) == 0) {
		cinta_[i][j] = 1;
	}	else {
		cinta_[i][j] = 0;
	}
}

bool Tape::posicion_correcta(int i, int j) {
	if ((i < size_ && i >= 0) && (j < col_ && j >= 0)) {
		return true;
	}
	return false;
}

unsigned Tape::get_valor(unsigned i, unsigned j) {
	return cinta_[i][j];
}



std::ostream& operator<<(std::ostream& os, const Tape& cinta) {
	os << "-----VISUALIZACIÓN CINTA-----" << std::endl;
	unsigned size = cinta.get_size();
	unsigned columns = cinta.get_col();
	auto celdas = cinta.get_cinta();
	for (unsigned i = 0; i < size; i++) {
		os << "|";
		for (unsigned j = 0; j < columns; j++) {
			if (celdas[i][j] == 1) {
				os << "X" << " ";
			} else {
				os << "  ";
			}
		}
		os << "|";
		os << std::endl;
	}
	return os;
}

