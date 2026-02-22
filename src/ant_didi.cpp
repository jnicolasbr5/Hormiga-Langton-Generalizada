#include "ant_didi.hpp"

void Ant_DIDI::elegir_giro(Colours color) {
	switch (color) {
	case Colours::Blanco:
		girar_der();
		break;
	case Colours::Negro:
		girar_izq();
		break;
	case Colours::Rojo:
		girar_der();
		break;
	case Colours::Amarillo:
		girar_izq();
		break;
	default:
		break;
	}
}