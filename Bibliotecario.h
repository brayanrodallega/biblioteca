#ifndef BIBLIOTECARIO_H
#define BIBLIOTECARIO_H

#include <iostream>
#include "Usuario.h"
using namespace std;

class Bibliotecario : public Usuario{
	public:
		Bibliotecario(){
			
		}
		
		~Bibliotecario(){
			
		}
	
		void registrarLibro();
		void actualizarLibro();
		void eliminarLibro();
		void reservarLibro();
		void prestarLibro();
		void devolverLibro();
		void consultarLibro();
		void listaLibros();
};

#endif
