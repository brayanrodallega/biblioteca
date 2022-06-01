#include <iostream>
using namespace std;

class Libro{
	private:
		string nombre,autor,editorial;
		int codigo,categoria,rama,estado;
		
	public:
		Libro(string nombre,string autor,string editorial,int codigo,int categoria,int rama,int estado){
			this->nombre = nombre;
			this->autor = autor;
			this->editorial = editorial;
			this->codigo = codigo;
			this->categoria = categoria;
			this->rama = rama;
			this->estado = estado;
		}
		
		Libro(){
			
		}
		
		~Libro(){
			
		}
		
		void setNombre(string nuevoNombre){
			this->nombre = nuevoNombre;
		}
		
		void setAutor(string nuevoAutor){
			this->autor = nuevoAutor;
		}
		
		void setEditorial(string nuevoEditorial){
			this->editorial = nuevoEditorial;
		}
		
		void setCodigo(int nuevoCodigo){
			this->codigo = nuevoCodigo;
		}
		
		void setCategoria(int nuevaCategoria){
			this->categoria = nuevaCategoria;
		}
		
		void setRama(int nuevaRama){
			this->rama = nuevaRama;
		}
		
		void setEstado(int nuevoEstado){
			this->estado = nuevoEstado;
		}
		
		string getNombre(){
			return nombre;
		}
		
		string getAutor(){
			return autor;
		}
		
		string getEditorial(){
			return editorial;
		}
		
		int getCodigo(){
			return codigo;
		}
		
		int getCategoria(){
			return categoria;
		}
		
		int getRama(){
			return rama;
		}
		
		int getEstado(){
			return estado;
		}
		
		void mostrarLibro();
};
