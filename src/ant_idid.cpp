#include "ant_idid.hpp"

void Ant_IDID::elegir_giro(Colours color) {
	switch (color) {
	case Colours::Blanco:
		girar_izq();
		break;
	case Colours::Negro:
		girar_der();
		break;
	case Colours::Rojo:
		girar_izq();
		break;
	case Colours::Amarillo:
		girar_der();
		break;
	default:
		break;
	}
}