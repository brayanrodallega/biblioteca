#include <iostream>
#include "Usuario.h"
using namespace std;

class Administrador : public Usuario{
	public:
		Administrador(){
			
		}
		
		~Administrador(){
			
		}
	
	public:
		void registrarUsuario();
		//void actualizarUsuario();
		//void eliminarUsuario();
		void sancionarUsuario();
		void consultarUsuario();
		void listadoUsuario();
};
