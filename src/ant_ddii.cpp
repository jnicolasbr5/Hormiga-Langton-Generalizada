#include "ant_ddii.hpp"

void Ant_DDII::elegir_giro(Colours color) {
	switch (color) {
	case Colours::Blanco:
		girar_der();
		break;
	case Colours::Negro:
		girar_der();
		break;
	case Colours::Rojo:
		girar_izq();
		break;
	case Colours::Amarillo:
		girar_izq();
		break;
	default:
		break;
	}
}