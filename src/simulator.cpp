#include <iostream>
#include <print>
#include <sstream>
#include "tape.hpp"
#include "simulator.hpp"

Fichero leerFichero(std::ifstream& datos) {
	Fichero file;

	// Línea 1: Tamaño de la cinta
	std::string linea;
	std::getline(datos, linea);
	std::stringstream ss(linea);
	ss >> file.cinta_size;
	ss >> file.cinta_col;
	
	// Inicializo las cintas
	for (size_t i = 0; i < file.cinta_size; i++) {
		std::vector<unsigned> fila(file.cinta_col, 0);
		file.cinta_entrada.push_back(fila);
		std::vector<unsigned> fila2(file.cinta_col, 4);
		file.cinta_inicial.push_back(fila2);
	}

	// Línea 2: Posición inicial y orientación de la hormiga
	std::getline(datos, linea);
	std::stringstream ss2(linea);
	unsigned x, y, direccion;
	ss2 >> x >> y >> direccion;
	file.coordenada.x = x;
	file.coordenada.y = y;
	file.orientacion = num_to_orientacion(direccion);

	// Línea 3...n: Posiciones de las celdas negras
	while(std::getline(datos, linea)) {
		if (linea.empty()) break;
		std::stringstream ss(linea);
		ss >> x >> y;
		file.cinta_entrada[x][y] = 1;
	}
	return file;
}


Simulator::Simulator(const Fichero& datos) : 
				cinta_(datos.cinta_size, datos.cinta_col, datos.cinta_entrada), 
				hormiga_(datos.coordenada, datos.orientacion, datos.cinta_inicial),
				count_(0) {}

void Simulator::run() {

	while (true) {

		// Visualización
		std::println("\nNº de pasos ejecutados: {}", count_);
		std::cout << cinta_ << std::endl;
		std::cout << hormiga_ << std::endl;

		// Paso a paso
		std::print("Continuar simulación o finalizar[P, F]: ");
		char c;
		std::cin >> c;
		if (c == 'F') break;

		// Comienza en una celda con una direccion
		Coordenada posicion = hormiga_.get_posicion();

		// Comprueba que la celda esté en la cinta
		if (!cinta_.posicion_correcta(posicion.x, posicion.y)) {
			std::println("La hormiga ha salido de la cinta.");
			break;
		}
		
		// Asigno la posicion en la cinta
		hormiga_.set_posicion(posicion.x, posicion.y);

		// Modifico el color de la celda
		cinta_.modificar_celda(posicion.x, posicion.y);

		// Si la celda es blanca
		if (cinta_.consultar_celda(posicion.x, posicion.y) == 0) {
			hormiga_.girar_izq();
		} 

		// Si la celda es negra
		else {
				hormiga_.girar_der();
		}

		// Avanza
		hormiga_.avanzar();
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
	const Tape &cinta = sim.get_tape();
	unsigned size = cinta.get_size();
	os << size << std::endl;
	const Ant& hormiga = sim.get_ant();
	Coordenada posicion = hormiga.get_posicion();
	os << posicion.x << " " << posicion.y << " " << hormiga.orientacion_to_num() << std::endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (cinta.consultar_celda(i, j) == 1) {
				os << i << " " << j << std::endl;
			}
		}
	}
	return os;
}