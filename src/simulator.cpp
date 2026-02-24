#include <iostream>
#include <print>
#include <sstream>
#include "tape.hpp"
#include "simulator.hpp"
#include "ant_ddii.hpp"
#include "ant_didi.hpp"
#include "ant_idid.hpp"

Fichero leerFichero(std::ifstream& datos) {
	Fichero file;

	// Línea 1: Tamaño de la cinta y numero de colores
	std::string linea;
	std::getline(datos, linea);
	std::stringstream ss(linea);
	ss >> file.cinta_size;
	ss >> file.cinta_col;
	ss >> file.num_colores;
	
	// Inicializo las cintas
	for (size_t i = 0; i < file.cinta_size; i++) {
		std::vector<Colours> fila(file.cinta_col, Colours::Blanco);
		file.cinta_entrada.push_back(fila);
	}

	// Línea 2: Posición inicial y orientación de la hormiga
	std::getline(datos, linea);
	std::stringstream ss2(linea);
	std::string tipo;
	unsigned direccion;
	Coordenada punto;
	Orientation orientacion;
	while (ss2 >> tipo >> punto.x >> punto.y >> direccion) {
		// std::println("DEBUG: {} {} {} {}\n{}", tipo, punto.x, punto.y, direccion, linea);
		orientacion = num_to_orientacion(direccion);
		if (tipo == "DDII") {
			Ant_DDII *hormiga = new Ant_DDII(punto, orientacion);
			file.vec_hormiga.push_back(hormiga);
		} else if (tipo == "IDID") {
			Ant_IDID *hormiga = new Ant_IDID(punto, orientacion);
			file.vec_hormiga.push_back(hormiga);
		}	else if (tipo == "DIDI") {
			Ant_DIDI *hormiga = new Ant_DIDI(punto, orientacion);
			file.vec_hormiga.push_back(hormiga);
		}
		ss2.ignore(2, ';'); // Ignoro el punto y coma y el siguiente espacio
	}

	// Línea 3...n: Posiciones de las celdas negras
	unsigned x, y, color;	
	while(std::getline(datos, linea)) {
		if (linea.empty()) break;
		std::stringstream ss(linea);
		ss >> x >> y >> color;
		file.cinta_entrada[x][y] = number_to_color(color);
	}
	return file;
}


Simulator::Simulator(const Fichero& datos) : 
				cinta_(datos.cinta_size, datos.cinta_col, datos.num_colores, datos.cinta_entrada), 
				hormigas_(datos.vec_hormiga),
				count_(0) {}


Simulator::~Simulator() {
	for (auto ant : hormigas_) {
		delete ant;
	}
	hormigas_.clear();
}


void Simulator::run() {
	while (true) {

		// Visualización
		std::println("\nNº de pasos ejecutados: {}", count_);
		cinta_.mostrar_cinta(get_hormigas());

		// Paso a paso
		std::print("Continuar simulación o finalizar[P, F]: ");
		char c;
		std::cin >> c;
		if (c == 'F') break;
	
		// Pasos de cada hormiga
		for (auto ant : hormigas_) {
			// Comienza en una celda con una direccion
			Coordenada posicion = ant->get_posicion();

			// Comprueba que la celda esté en la cinta
			if (!cinta_.posicion_correcta(posicion.x, posicion.y)) {
				std::println("La hormiga {} ha salido de la cinta.", ant->get_tipo());
				return;
			}

			// Modifico el color de la celda
			cinta_.modificar_celda(posicion.x, posicion.y);

			// Girar
			Colours color = cinta_.consultar_celda(posicion.x, posicion.y);
			ant->elegir_giro(color);

			// Avanza
			ant->avanzar();
		}
		++count_;
	}
}


void Simulator::guardar_estado() {
	std::print("\n¿Desea salvar el estado de la simulación en un fichero?[S, N] -> ");
	char decision;
	std::cin >> decision;
	if (decision != 'S') {
		std::println("\n-----PROGRAMA FINALIZADO-----");
		return;
	}
	std::ofstream file("output.txt");
	file << *this;
	std::println("\nDatos enviados a 'output.txt'.");
	std::println("-----PROGRAMA FINALIZADO-----");
}

std::ostream& operator<<(std::ostream& os, const Simulator& sim) {
	auto cinta = sim.get_tape();
	auto hormigas = sim.get_hormigas();
	// Línea 1: cinta
	os << cinta.get_size() << " " << cinta.get_col() << " " << cinta.get_num_colors() << std::endl;
	
	// Línea 2: hormigas
	for (auto ant : hormigas) {
		Coordenada pos = ant->get_posicion();
		Orientation orientacion = ant->get_orientacion();
		os << ant->get_tipo() << " " << pos.x << " " << pos.y << " " << orientacion_to_num(orientacion);
		os << " ; ";
	}
	os << std::endl;

	// Línea 3: Posición celdas no blancas
	for (unsigned i = 0; i < cinta.get_size(); i++) {
		for (unsigned j = 0; j < cinta.get_col(); j++) {
			Colours color = cinta.consultar_celda(i, j);
			if (color != Colours::Blanco) {
				os << i << " " << j << " " << color_to_number(color) << std::endl;
			}
		}
	}
	return os;
}