#include "ant.hpp"

Ant::Ant(Coordenada coordenada, Orientation orientacion, cinta_orientacion cinta_inicial) 
				: orientacion_(orientacion), posicion_(coordenada), cinta_mov_(cinta_inicial) {}

void Ant::set_posicion(unsigned i, unsigned j) {
	cinta_mov_[i][j] = this->orientacion_to_num();
}

unsigned Ant::orientacion_to_num() const {
	if (orientacion_ == Orientation::izquierda) {
		return 0;
	} else if (orientacion_ == Orientation::derecha) {
		return 1;
	}	else if (orientacion_ == Orientation::arriba) {
		return 2;
	}	else if (orientacion_ == Orientation::abajo) {
		return 3;
	}
}

void Ant::girar_izq() {
	switch (orientacion_) {
		case Orientation::arriba:
			orientacion_ = Orientation::izquierda;
			break;
		case Orientation::izquierda:
			orientacion_ = Orientation::abajo;
			break;
		case Orientation::abajo:
			orientacion_ = Orientation::derecha;
			break;
		case Orientation::derecha:
			orientacion_ = Orientation::arriba;
			break;
		default:
			break;
	}
}

void Ant::girar_der() {
	switch (orientacion_) {
		case Orientation::arriba:
			orientacion_ = Orientation::derecha;
			break;
		case Orientation::izquierda:
			orientacion_ = Orientation::arriba;
			break;
		case Orientation::abajo:
			orientacion_ = Orientation::izquierda;
			break;
		case Orientation::derecha:
			orientacion_ = Orientation::abajo;
			break;
		default:
			break;
	}
}

void Ant::avanzar() {
	switch (orientacion_) {
		case Orientation::arriba:
			posicion_.x--;
			break;
		case Orientation::izquierda:
			posicion_.y--;
			break;
		case Orientation::abajo:
			posicion_.x++;
			break;
		case Orientation::derecha:
			posicion_.y++;
			break;
		default:
			break;
	}
}


Orientation num_to_orientacion(unsigned num) {
	if (num == 0) {
		return Orientation::izquierda;
	} else if (num == 1) {
		return Orientation::derecha;
	}	else if (num == 2) {
		return Orientation::arriba;
	}	else if (num == 3) {
		return Orientation::abajo;
	}
}

std::ostream& operator<<(std::ostream& os, const Ant& hormiga) {
	os << "-----VISUALIZACIÓN HORMIGA-----" << std::endl;
	for (unsigned i = 0; i < hormiga.get_size_cinta(); i++) {
		os << "|";
		for (unsigned j = 0; j < hormiga.get_col(); j++) {
			switch (hormiga.get_valor(i, j)) {
			case 0:
				os << "<";
				break;
			case 1:
				os << ">";
				break;
			case 2:
				os << "^";
				break;
			case 3:
				os << "v";
				break;
			case 4:
				os << " ";
				break;
			default:
				break;
			}
			os << " ";
		}
		os << "|";
		os << std::endl;
	}
	return os;
}
