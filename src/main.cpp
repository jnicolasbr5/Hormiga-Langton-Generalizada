// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructuras Avanzadas de Datos
// Curso: 2º
// Práctica 2: Hormiga de Langton Generalizada
// Autor: Juan Nicolás Becerra Rogatinscaia
// Correo: alu0101743011@ull.edu.es
// Fecha: 24/02/2026


#include <fstream>
#include <iostream>
#include <print>

#include "ant.hpp"
#include "simulator.hpp"
#include "tape.hpp"

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::println("Nº de argumentos incorrecto.");
		return 1;
	}
	std::ifstream file(argv[1]);
	if (!file.is_open()) {
		std::print("Archivo no se ha podido abrir.");
		return 1;
	}
	Fichero datos = leerFichero(file); 
	Simulator langton(datos);
	langton.run();
	langton.guardar_estado();
	return 0;
}