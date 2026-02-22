#pragma once

#include <iostream>
#include <print>
#include <vector>

#include "tape.hpp"
#include "colours.hpp"

enum Orientation {
	izquierda,
	derecha,
	arriba,
	abajo
};

struct Coordenada {
	int x;
	int	y;
};

class Ant {
	public:
	// Constructor
		Ant() = default;
		Ant(Coordenada coordenada, Orientation orientacion);

	// Destructor
		virtual ~Ant() {};

		// Setters y getters
		Coordenada get_posicion() const {return posicion_;}
		Orientation get_orientacion() const { return orientacion_; }
		char get_char_mov();
		

		// Métodos
		void girar_izq();
		void girar_der();
		void avanzar();

		// Modificacion
		virtual void elegir_giro(Colours color) {}
		virtual std::string get_tipo() {return "";}

		void guardar_posicion(unsigned i, unsigned j);

	protected:
		Coordenada posicion_;
		Orientation orientacion_;
};

Orientation num_to_orientacion(unsigned num);
unsigned orientacion_to_num(Orientation orientacion);

std::ostream& operator<<(std::ostream& os, const Ant& hormiga);
 //((mov == ' ') ? mov : ' ') 