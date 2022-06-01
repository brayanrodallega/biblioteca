#include <iostream>
#include "Usuario.h"
using namespace std;

class Monitor : public Usuario{
	public:
		Monitor(){
			
		}
		
		~Monitor(){
			
		}
		
		void prestarLibro();
		void devolverLibro();
		void consultarLibro();
		void listaLibros();
};
