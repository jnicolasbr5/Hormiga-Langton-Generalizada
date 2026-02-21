#pragma once

#include <iostream>
#include <print>
#include <vector>

typedef std::vector<std::vector<unsigned>> cinta_orientacion;

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
		Ant(Coordenada coordenada, Orientation orientacion, cinta_orientacion cinta);

		// Setters y getters
		void set_posicion(unsigned i, unsigned j);
		unsigned get_valor(unsigned i, unsigned j) const {return cinta_mov_[i][j];}

		int get_size_cinta() const {return cinta_mov_.size();}
		unsigned get_col() const { return cinta_mov_[0].size(); }

		Coordenada get_posicion() const {return posicion_;}
		Orientation get_orientacion() const { return orientacion_; }
		
		unsigned orientacion_to_num() const;

		// Métodos
		void girar_izq();
		void girar_der();
		void avanzar();

		void guardar_posicion(unsigned i, unsigned j);


	private:
		Coordenada posicion_;
		Orientation orientacion_;
		cinta_orientacion cinta_mov_;
};

Orientation num_to_orientacion(unsigned num);

std::ostream& operator<<(std::ostream& os, const Ant& hormiga);