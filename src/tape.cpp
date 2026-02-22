#include "colors.h"
#include "tape.hpp"

Tape::Tape(unsigned size, unsigned col, unsigned colors, cinta_colores celdas) 
					: size_(size), col_(col), num_colors_(colors), cinta_(celdas) {}


Colours Tape::consultar_celda(unsigned i, unsigned j) const {
	return cinta_[i][j];
}

void Tape::modificar_celda(unsigned i, unsigned j) {
	switch (consultar_celda(i, j)) {
		case Colours::Blanco: // Blanco -> Negro
			cinta_[i][j] = Colours::Negro;
			break;	
		case Colours::Negro:	// Negro -> Rojo
			cinta_[i][j] = Colours::Rojo;
			break;
		case Colours::Rojo:	// Rojo -> Amarillo
			cinta_[i][j] = Colours::Amarillo;
			break;
		case Colours::Amarillo: // Amarillo -> Blanco
			cinta_[i][j] = Colours::Blanco;
			break;
	}
}

bool Tape::posicion_correcta(int i, int j) {
	if ((i < size_ && i >= 0) && (j < col_ && j >= 0)) {
		return true;
	}
	return false;
}


Colours number_to_color(unsigned num) {
	switch (num) {
	case 1: 
		return Colours::Negro;
	case 2: 
		return Colours::Rojo;
	case 3: 
		return Colours::Amarillo;
	default:
		return Colours::Blanco;
	}
}


unsigned color_to_number(Colours color) {
	switch (color) {
		case Colours::Blanco:
			return 0;
		case Colours::Negro:
			return 1;
		case Colours::Rojo:
			return 2;
		case Colours::Amarillo:
			return 3;
	}
}


void Tape::mostrar_cinta(const std::vector<Ant*>& hormigas) {
	// Datos de cinta
	unsigned rows = get_size();
	unsigned columns = get_col();
	auto celdas = get_cinta();

	std::cout << "-----VISUALIZACIÓN CINTA-----" << std::endl;
	std::cout << "  ";
	for (unsigned i = 0; i < columns; i++) {
		std::cout << i;
	}
	std::cout << std::endl;
	for (unsigned i = 0; i < rows; i++) {
		std::cout << i << "|";
		for (unsigned j = 0; j < columns; j++) {
			char mov = ' ';
			for (auto ant : hormigas) {
				Coordenada pos = ant->get_posicion();
				if (pos.x == i && pos.y == j) {
					mov = ant->get_char_mov();
				}
			}
			if (mov != ' ') {
				switch (celdas[i][j]) {
				case Colours::Blanco:
					std::cout << BG_WHITE << mov << RESET;
					break;
				case Colours::Negro:
					std::cout << BG_BLACK << mov << RESET;
					break;
				case Colours::Rojo:
					std::cout << BG_RED << mov << RESET;
					break;
				case Colours::Amarillo:
					std::cout << BG_YELLOW << mov << RESET;
					break;
				}
			}	else {
 				switch (celdas[i][j]) {
					case Colours::Blanco:
						std::cout << BG_WHITE << " " << RESET;
						break;
					case Colours::Negro:
						std::cout << BG_BLACK << "1" << RESET;
						break;
					case Colours::Rojo:
						std::cout << BG_RED << "2" << RESET;
						break;
					case Colours::Amarillo:
						std::cout << BG_YELLOW << "3" << RESET;
						break;
				}
			}
		}
		std::cout << "|" << std::endl;
	}
}