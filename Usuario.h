#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
using namespace std;

class Usuario{
	public:
		string usuario,clave,nombre,apellido;
		int carnet,perfil,dni,tel,sancion;
		
	public:
		Usuario(string usuario,string clave,int carnet,string nombre,string apellido,int perfil,int dni,int tel,int sancion){
			this->usuario = usuario;
			this->clave = clave;
			this->carnet = carnet;
			this->nombre = nombre;
			this->apellido = apellido;
			this->perfil = perfil;
			this->dni = dni;
			this->tel = tel;
			this->sancion = sancion;
		}
		
		Usuario(){
			
		}
		
		~Usuario(){
			
		}
		
		void setUsuario(string nuevoUsuario){
			this->usuario = nuevoUsuario;
		}
		
		void setClave(string nuevaClave){
			this->clave = nuevaClave;
		}
		
		void setCarnet(int nuevoCarnet){
			this->carnet = nuevoCarnet;
		}
		
		void setNombre(string nuevoNombre){
			this->nombre = nuevoNombre;
		}
		
		void setApellido(string nuevoApellido){
			this->apellido = nuevoApellido;
		}
		
		void SetPerfil(int nuevoPerfil){
			this->perfil = nuevoPerfil;
		}
		
		void setDni(int nuevoDni){
			this->dni = nuevoDni;
		}
		
		void setTel(int nuevoTel){
			this->tel = nuevoTel;
		}
		
		void setSancion(int sancion){
			this->sancion = sancion;
		}
		
		string getUsuario(){
			return usuario;
		}
		
		string getClave(){
			return clave;
		}
		
		int getCarnet(){
			return carnet;
		}
		
		string getNombre(){
			return nombre;
		}
		
		string getApellido(){
			return apellido;
		}
		
		int getPerfil(){
			return perfil;
		}
		
		int getDni(){
			return dni;
		}
		
		int getTel(){
			return tel;
		}
		
		int getSancion(){
			return sancion;
		}
		
		void mostrarDatos();
		string mostrarPerfil(int cPerfil);
		string mostrarSancion(int cSancion);
};

#endif
