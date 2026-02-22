#include "ant.hpp"

Ant::Ant(Coordenada coordenada, Orientation orientacion) 
				: orientacion_(orientacion), posicion_(coordenada) {}


char Ant::get_char_mov() {
	switch (orientacion_) {
	case Orientation::izquierda:
		return '<';
	case Orientation::derecha:
		return '>';
	case Orientation::arriba:
		return '^';
	case Orientation::abajo:
		return 'v';
	default:
		break;
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


unsigned orientacion_to_num(Orientation orientacion) {
	switch (orientacion) {
		case Orientation::izquierda:
			return 0;
		case Orientation::derecha:
			return 1;
		case Orientation::arriba:
			return 2;
		case Orientation::abajo:
			return 3;
	}
}


 /*
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
*/