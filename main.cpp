#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include "Libro.h"
#include "Usuario.h"
#include "Administrador.h"
#include "Bibliotecario.h"
#include "Monitor.h"
using namespace std;

char rpt;

int X = 101;
int Y = 201;
int Z = 301;

int k=0,l=0,a=0,b=0,m=0;
const int L = 50;
Libro libros[L];
const int A = 5;
Administrador admins[A];
const int B = 10;
Bibliotecario biblios[B];
const int M = 15;
Monitor monitores[M];

int indiceLogin,indiceBusqueda,indiceLibro,perfiLogin,perfilBusqueda;
bool loggin,encontroUsuario,encontroLibro;

void recuperarUsuario();
void recuperarLibro();
void inicioSesion();
void menuAdmin();
void registrarAdmin();
void registrarBiblio();
void registrarMonitor();
void buscarUsuario(int);
void menuBiblio();
void buscarLibro(int);
void menuMonitor();
void guardaUsuario();
void guardaLibro();

void categorias();
string tCategoria(int);
void ramas();
string tRama(int);
void estados();
string tEstado(int);

void modificarLibro();
void modificarNombre();
void modificarAutor();
void modificarEditorial();
void modificarCategoria(int);
void modificarRama(int);
void modificarEstado(int);

int main(int argc, char** argv) {
	
	for(int i=0;i<A;i++){
		admins[i].setSancion(0);
	}
	for(int i=0;i<B;i++){
		biblios[i].setSancion(0);
	}
	for(int i=0;i<M;i++){
		monitores[i].setSancion(0);
	}
	for(int i=0;i<L;i++){
		libros[i].setEstado(0);
	}
	
	recuperarLibro();
	recuperarUsuario();
	inicioSesion();
	if(loggin){
		
		switch(perfiLogin){
			case 1:
				menuAdmin();
				break;
			case 2:
				menuBiblio();
				break;
			case 3:
				menuMonitor();
				break;
		}
		guardaLibro();
		guardaUsuario();
	}
	guardaLibro();
	guardaUsuario();
	getch();
	return 0;
}

void recuperarUsuario(){
	
	string usuario,clave,nombre,apellido;
	int carnet,perfil,dni,tel,sancion;
	
	ifstream archivo;
	archivo.open("Usuarios.txt",ios::in);
	
	if(archivo.fail()){
		cout<<"\nERROR AL ABRIR EL ARCHIVO!"<<endl;
		getch();
		exit(1);
	}
	else{
		while(archivo>>usuario>>clave>>carnet>>nombre>>apellido>>perfil>>dni>>tel>>sancion){
			
			if(perfil == 1){
				admins[a].setUsuario(usuario);
				admins[a].setClave(clave);
				admins[a].setCarnet(carnet);
				admins[a].setNombre(nombre);
				admins[a].setApellido(apellido);
				admins[a].SetPerfil(perfil);
				admins[a].setDni(dni);
				admins[a].setTel(tel);
				admins[a].setSancion(sancion);
				a++;
			}
			if(perfil == 2){
				biblios[b].setUsuario(usuario);
				biblios[b].setClave(clave);
				biblios[b].setCarnet(carnet);
				biblios[b].setNombre(nombre);
				biblios[b].setApellido(apellido);
				biblios[b].SetPerfil(perfil);
				biblios[b].setDni(dni);
				biblios[b].setTel(tel);
				biblios[b].setSancion(sancion);
				b++;
			}
			if(perfil == 3){
				monitores[m].setUsuario(usuario);
				monitores[m].setClave(clave);
				monitores[m].setCarnet(carnet);
				monitores[m].setNombre(nombre);
				monitores[m].setApellido(apellido);
				monitores[m].SetPerfil(perfil);
				monitores[m].setDni(dni);
				monitores[m].setTel(tel);
				monitores[m].setSancion(sancion);
				m++;
			}
		}		
	}
	archivo.close();
}

void recuperarLibro(){
	
	string nombre,autor,editorial;
	int codigo,categoria,rama,estado;
	
	ifstream archivo;
	archivo.open("Libros.txt",ios::in);
	
	if(archivo.fail()){
		cout<<"\nERROR AL ABRIR EL ARCHIVO!"<<endl;
		getch();
		exit(1);
	}
	else{
		while(archivo>>nombre>>autor>>editorial>>codigo>>categoria>>rama>>estado){
			
			libros[l].setNombre(nombre);
			libros[l].setAutor(autor);
			libros[l].setEditorial(editorial);
			libros[l].setCodigo(codigo);
			libros[l].setCategoria(categoria);
			libros[l].setRama(rama);
			libros[l].setEstado(estado);
			l++;
			
		}		
	}
	archivo.close();
}

void inicioSesion(){
	
	string usuario = "", clave = "";
	int contador = 0;
	
	do{
		cout<<"\n\t\t\t\t\t\tINICIAR SESION\n\n";
		cout<<"\t\t\t\t\tDigite el usuario: "; cin>>usuario;
		cout<<"\t\t\t\t\tDigite la clave: "; cin>>clave;
		
		for(int i=0;i<A;i++){
			if(admins[i].getUsuario() == usuario && admins[i].getClave() == clave){
				perfiLogin = admins[i].getPerfil();
				indiceLogin = i;
				loggin = true;
				break;
			}
			else{
				for(int i=0;i<B;i++){
					if(biblios[i].getUsuario() == usuario && biblios[i].getClave() == clave){
						perfiLogin = biblios[i].getPerfil();
						indiceLogin = i;
						loggin = true;
						break;
					}
					else{
						for(int i=0;i<M;i++){
							if(monitores[i].getUsuario() == usuario && monitores[i].getClave() == clave){
								perfiLogin = monitores[i].getPerfil();
								indiceLogin = i;
								loggin = true;
								break;
							}
							else{
								loggin = false;
							}
						}
					}
				}
			}
		}
		
		if(!loggin){
			contador++;
			cout<<"\n\t\t\t\t\tUsuario o clave incorrecta!";
			cout<<"\n\t\t\t\t\tNumero de intentos: ("<<contador<<"/3)"<<endl;
		}
		cout<<"\n\t\t\t\t\t";
		system("pause");
		system("cls");
	}while(!loggin && contador<3);
	
	if(contador == 3){
		cout<<"\n\n\t\t\t\tDemasiados intentos, ADIOS!\n\n";
		getch();
		guardaUsuario();
		exit(1);
	}
}

void menuAdmin(){
	
	int opc;
	
	do{
		system("cls");
		cout<<"\n\tUsuario: "<<admins[indiceLogin].getNombre();
		cout<<"\t\t\t\t\t\t\t\t\t\tCarnet: "<<admins[indiceLogin].getCarnet();
		cout<<"\n\n\t\t\t\t\t\tADMINISTRADOR" <<endl;
		cout<<"\n\t\t\t\t\tQue desea hacer?\n\n";
		cout<<"\t\t\t\t\t1. Registrar usuario"<<endl;
		cout<<"\t\t\t\t\t2. Sancionar usuario"<<endl;
		cout<<"\t\t\t\t\t3. Consultar usuario"<<endl;
		cout<<"\t\t\t\t\t4. Lista de usuarios"<<endl;
		cout<<"\t\t\t\t\t5. Cerrar\n\n";
		
		cout<<"\t\t\t\t\tOpcion: "; cin>>opc;
		
		switch(opc){
			case 1:
				admins[indiceLogin].registrarUsuario();
				guardaUsuario();
				break;
			case 2:
				admins[indiceLogin].sancionarUsuario();
				guardaUsuario();
				break;
			case 3:
				admins[indiceLogin].consultarUsuario();
				break;
			case 4:
				admins[indiceLogin].listadoUsuario();
				break;
			case 5:
				system("cls");
				cout<<"\n\n\n\n\t\t\t\t\t\t\tBYE!\n\n\n\n\n";
				guardaUsuario();
				getch();
				exit(1);
			default:
				cout << "\n\n\t\t\t\t\tOpcion incorrecta!\n\n";
		}
		cout<<"\n\n\t\t\t\t\t";
		system("pause");
		system("cls");
	}while(opc != 5);
}

void Administrador::registrarUsuario(){
	
	system("cls");
			
	int opc;
	
	do{
		cout<<"\n\tUsuario: "<<admins[indiceLogin].getNombre();
		cout<<"\t\t\t\t\t\t\t\t\t\tCarnet: "<<admins[indiceLogin].getCarnet();
		cout << "\n\n\t\t\t\t\t\tQUE DESEA REGISTRAR?\n\n";
		cout << "\t\t\t\t\t1. Administrador" << endl;
		cout << "\t\t\t\t\t2. Bibliotecario" << endl;
		cout << "\t\t\t\t\t3. Monitor de biblioteca" << endl;
		cout << "\t\t\t\t\t4. Volver atras" << endl;
		cout << "\n\t\t\t\t\tOpcion: "; cin>>opc;
		
		switch(opc){
			case 1:
				registrarAdmin();
				break;
			case 2:
				registrarBiblio();
				break;
			case 3:
				registrarMonitor();
				break;
			case 4:
				menuAdmin();
				break;
			default:
				cout << "\n\t\t\t\t\tOpcion incorrecta!" << endl;
		}
		cout<<"\n\n\t\t\t\t\t";
		system("pause");
		system("cls");
	}while(opc != 4);
}

void registrarAdmin(){
	
	string usuario,clave,nombre,apellido;
	int carnet,perfil,dni,tel,sancion;
	
	system("cls");
	cout<<"\n\n\t\t\t\t\t\tREGISTRAR USUSARIO\n\n";
	cout<<"\t\t\t\t\tDigite el usuario: "; cin>>usuario;
	cout<<"\t\t\t\t\tDigite la clave: "; cin>>clave;
	system("cls");
	cout<<"\n\n\t\t\t\t\t\tDATOS PERSONALES\n\n";
	cout<<"\t\t\t\t\t\tNombre: "; cin>>nombre;
	cout<<"\t\t\t\t\t\tApellido: "; cin>>apellido;
	cout<<"\t\t\t\t\t\tDni: "; cin>>dni;
	cout<<"\t\t\t\t\t\tTelefono: "; cin>>tel;
	admins[a].setUsuario(usuario);
	admins[a].setClave(clave);
	admins[a].setCarnet(X+a);
	admins[a].setNombre(nombre);
	admins[a].setApellido(apellido);
	admins[a].SetPerfil(1);
	admins[a].setDni(dni);
	admins[a].setTel(tel);
	admins[a].setSancion(0);
	a++;
}

void registrarBiblio(){
	
	string usuario,clave,nombre,apellido;
	int carnet,perfil,dni,tel,sancion;
				
	system("cls");
	cout<<"\n\n\t\t\t\t\t\tREGISTRAR\n\n";
	cout<<"\t\t\t\t\tDigite el usuario: "; cin>>usuario;
	cout<<"\t\t\t\t\tDigite la clave: "; cin>>clave;
	system("cls");
	cout<<"\n\n\t\t\t\t\t\tDATOS PERSONALES\n\n";
	cout<<"\t\t\t\t\t\tNombre: "; cin>>nombre;
	cout<<"\t\t\t\t\t\tApellido: "; cin>>apellido;
	cout<<"\t\t\t\t\t\tDni: "; cin>>dni;
	cout<<"\t\t\t\t\t\tTelefono: "; cin>>tel;
	biblios[b].setUsuario(usuario);
	biblios[b].setClave(clave);
	biblios[b].setCarnet(Y+b);
	biblios[b].setNombre(nombre);
	biblios[b].setApellido(apellido);
	biblios[b].SetPerfil(2);
	biblios[b].setDni(dni);
	biblios[b].setTel(tel);
	biblios[b].setSancion(0);
	b++;
}

void registrarMonitor(){
	
	string usuario,clave,nombre,apellido;
	int carnet,perfil,dni,tel,sancion;
				
	system("cls");
	cout<<"\n\n\t\t\t\t\t\tREGISTRAR\n\n";
	cout<<"\t\t\t\t\tDigite el usuario: "; cin>>usuario;
	cout<<"\t\t\t\t\tDigite la clave: "; cin>>clave;
	system("cls");
	cout<<"\n\n\t\t\t\t\t\tDATOS PERSONALES\n\n";
	cout<<"\t\t\t\t\t\tNombre: "; cin>>nombre;
	cout<<"\t\t\t\t\t\tApellido: "; cin>>apellido;
	cout<<"\t\t\t\t\t\tDni: "; cin>>dni;
	cout<<"\t\t\t\t\t\tTelefono: "; cin>>tel;
	monitores[m].setUsuario(usuario);
	monitores[m].setClave(clave);
	monitores[m].setCarnet(Z+m);
	monitores[m].setNombre(nombre);
	monitores[m].setApellido(apellido);
	monitores[m].SetPerfil(3);
	monitores[m].setDni(dni);
	monitores[m].setTel(tel);
	monitores[m].setSancion(0);
	m++;
}

void Administrador::sancionarUsuario(){
	
	int carnet;
	
	system("cls");
	cout<<"\n\tUsuario: "<<admins[indiceLogin].getNombre();
	cout<<"\t\t\t\t\t\t\t\t\t\tCarnet: "<<admins[indiceLogin].getCarnet();
	cout<<"\n\t\t\t\t\t\t.:SANCIONAR USUARIO:.\n\n";
	cout<<"\t\t\t\t\t\tDigite el carnet: "; cin>>carnet;
	buscarUsuario(carnet);
	
	if(encontroUsuario){
		switch(perfilBusqueda){
			case 1:
				admins[indiceBusqueda].setSancion(1);
				break;
			case 2:
				biblios[indiceBusqueda].setSancion(1);
				break;
			case 3:
				monitores[indiceBusqueda].setSancion(1);
				break;
		}
		system("cls");
		cout<<"\n\n\n\t\t\t\t\t\tSancion aplicada!\n\n\n";
	}
	else{
		system("cls");
		cout<<"\n\n\n\t\t\t\t\t\tUsuario no encontrado!\n\n\n";
	}
}

void Administrador::consultarUsuario(){
	
	int carnet;
	
	system("cls");
	cout<<"\n\tUsuario: "<<admins[indiceLogin].getNombre();
	cout<<"\t\t\t\t\t\t\t\t\t\tCarnet: "<<admins[indiceLogin].getCarnet();
	cout<<"\n\t\t\t\t\t\t.:CONSULTAR USUARIO:.\n\n";
	cout<<"\t\t\t\t\t\tDigite el carnet: "; cin>>carnet;
	buscarUsuario(carnet);
	
	if(encontroUsuario){
		switch(perfilBusqueda){
			case 1:
				admins[indiceBusqueda].mostrarDatos();
				break;
			case 2:
				biblios[indiceBusqueda].mostrarDatos();
				break;
			case 3:
				monitores[indiceBusqueda].mostrarDatos();
				break;
		}
	}
	else{
		system("cls");
		cout<<"\n\n\n\t\t\t\t\t\tUsuario no encontrado!\n\n\n";
	}
	cout<<"\n\t\t\t\t\t";
	system("pause");
	menuAdmin();
}

void buscarUsuario(int carnet){
	
	for(int i=0;i<A;i++){
		if(admins[i].getCarnet() == carnet){
			perfilBusqueda = admins[i].getPerfil();
			indiceBusqueda = i;
			encontroUsuario = true;
			break;
		}
		else{
			for(int i=0;i<B;i++){
				if(biblios[i].getCarnet() == carnet){
					perfilBusqueda = biblios[i].getPerfil();
					indiceBusqueda = i;
					encontroUsuario = true;
					break;
				}
				else{
					for(int i=0;i<M;i++){
						if(monitores[i].getCarnet() == carnet){
							perfilBusqueda = monitores[i].getPerfil();
							indiceBusqueda = i;
							encontroUsuario = true;
							break;
						}
						else{
							encontroUsuario = false;
						}
					}
				}
			}
		}
	}
}

void Usuario::mostrarDatos(){
	cout<<"\n\n\t\t\t\t\t\tLOGIN:"<<endl;
	cout<<"\t\t\t\t\t\tUsuario: "<<usuario;
	cout<<"\n\t\t\t\t\t\tClave: "<<clave;
	cout<<"\n\n\t\t\t\t\t\tDATOS PERSONALES:"<<endl;
	cout<<"\t\t\t\t\t\tNombre: "<<nombre;
	cout<<"\n\t\t\t\t\t\tApellido: "<<apellido;
	cout<<"\n\t\t\t\t\t\tPerfil: "<<mostrarPerfil(perfil);
	cout<<"\n\t\t\t\t\t\tDni: "<<dni;
	cout<<"\n\t\t\t\t\t\tTelefono: "<<tel;
	cout<<"\n\t\t\t\t\t\tSancion: "<<mostrarSancion(sancion)<<"\n\n\n";
}

void Administrador::listadoUsuario(){
	
	int c=0;
	
	system("cls");
	fflush(stdin);
	cout<<"\n\tUsuario: "<<admins[indiceLogin].getNombre();
	cout<<"\t\t\t\t\t\t\t\t\t\tCarnet: "<<admins[indiceLogin].getCarnet();
	cout<<"\n\n\t\t\t\t\t\t.:LISTA DE USUARIOS:.\n\n";
	cout<<"\n\t\t\t\t\tADMINISTRADORES:\n";
	cout<<"\n\t\t\t\t\tNOMBRE\t"<<"APELLIDO\t"<<"CARNET\t"<<"SANCION"<<endl;
	
	for(int i=0;i<A;i++){
		if(admins[i].getUsuario() != "")
		{
		   	cout<<"\t\t\t\t\t"<<admins[i].getNombre()<<"\t"<<admins[i].getApellido()<<"\t"<<admins[i].getCarnet()<<"\t"<<mostrarSancion(admins[i].getSancion())<<endl;
		   	c++;
		}   		
    }
    
    cout<<"\n\t\t\t\t\tBIBLIOTECARIOS:\n";
	cout<<"\n\t\t\t\t\tNOMBRE\t"<<"APELLIDO\t"<<"CARNET\t"<<"SANCION"<<endl;
	
	for(int i=0;i<B;i++){
		if(biblios[i].getUsuario() != "")
		{
		   	cout<<"\t\t\t\t\t"<<biblios[i].getNombre()<<"\t"<<biblios[i].getApellido()<<"\t"<<biblios[i].getCarnet()<<"\t"<<mostrarSancion(biblios[i].getSancion())<<endl;
		   	c++;
		}   		
    }
    
    cout<<"\n\t\t\t\t\tMONITORES:\n";
	cout<<"\n\t\t\t\t\tNOMBRE\t"<<"APELLIDO\t"<<"CARNET\t"<<"SANCION"<<endl;
	
	for(int i=0;i<M;i++){
		if(monitores[i].getUsuario() != "")
		{
		   	cout<<"\t\t\t\t\t"<<monitores[i].getNombre()<<"\t"<<monitores[i].getApellido()<<"\t"<<monitores[i].getCarnet()<<"\t"<<mostrarSancion(monitores[i].getSancion())<<endl;
		   	c++;
		}   		
    }
    
    if(c>0)
    {
    	cout<<"\n\n\t\t\t\t\tUSUARIOS -> "<<c;
	}
    if(c==0)
	{
		fflush(stdin);
		system("cls");
		cout<<"\n\n\n\t\t\t\t\t\tNO HAY NINGUN USUARIO REGISTRADO";
	}
}

string Usuario::mostrarPerfil(int cPerfil){
	if(cPerfil == 1){
		return "Administrador";
	}
	else if(cPerfil == 2){
		return "Bibliotecario";
	}
	else{
		return "Monitor";
	}
}

string Usuario::mostrarSancion(int cSancion){
	if(cSancion == 0){
		return "No sancionado";
	}
	else{
		return "Sancionado";
	}
}

void menuBiblio(){
	
	int opc;
	
	do{
		system("cls");
		cout<<"\n\tUsuario: "<<biblios[indiceLogin].getNombre();
		cout<<"\t\t\t\t\t\t\t\t\t\tCarnet: "<<biblios[indiceLogin].getCarnet();
		cout<<"\n\n\t\t\t\t\t\t\tBIBLIOTECARIO" <<endl;
		cout<<"\n\t\t\t\t\t\tQue desea hacer?\n\n";
		cout<<"\t\t\t\t\t\t1. Registrar libro"<<endl;
		cout<<"\t\t\t\t\t\t2. Actualizar libro"<<endl;
		cout<<"\t\t\t\t\t\t3. Eliminar libro"<<endl;
		cout<<"\t\t\t\t\t\t4. Reservar libro"<<endl;
		cout<<"\t\t\t\t\t\t5. Prestar libro"<<endl;
		cout<<"\t\t\t\t\t\t6. Devolver libro"<<endl;
		cout<<"\t\t\t\t\t\t7. Consultar libro"<<endl;
		cout<<"\t\t\t\t\t\t8. Lista de libros"<<endl;
		cout<<"\t\t\t\t\t\t9. Cerrar\n\n";
		
		cout<<"\t\t\t\t\t\tOpcion: "; cin>>opc;
		
		switch(opc){
			case 1:
				biblios[indiceLogin].registrarLibro();
				guardaLibro();
				break;
			case 2:
				biblios[indiceLogin].actualizarLibro();
				guardaLibro();
				break;
			case 3:
				biblios[indiceLogin].eliminarLibro();
				guardaLibro();
				break;
			case 4:
				biblios[indiceLogin].reservarLibro();
				guardaLibro();
				break;
			case 5:
				biblios[indiceLogin].prestarLibro();
				guardaLibro();
				break;
			case 6:
				biblios[indiceLogin].devolverLibro();
				guardaLibro();
				break;
			case 7:
				biblios[indiceLogin].consultarLibro();
				break;
			case 8:
				biblios[indiceLogin].listaLibros();
				break;
			case 9:
				system("cls");
				cout<<"\n\n\n\n\t\t\t\t\t\t\tBYE!\n\n\n\n\n";
				guardaLibro();
				getch();
				exit(1);
			default:
				cout << "\n\n\t\t\t\t\tOpcion incorrecta!\n\n";
		}
		cout<<"\n\n\t\t\t\t\t";
		system("pause");
		system("cls");
	}while(opc != 9);
}

void Bibliotecario::registrarLibro(){
	
	string nombre,autor,editorial;
	int codigo,categoria,rama,estado;
	
	system("cls");
	cout<<"\n\tUsuario: "<<biblios[indiceLogin].getNombre();
	cout<<"\t\t\t\t\t\t\t\t\t\tCarnet: "<<biblios[indiceLogin].getCarnet();
	cout<<"\n\n\t\t\t\t\t\t.:REGISTRAR LIBRO:.\n\n";
	cout<<"\t\t\t\t\t\tNombre: "; cin>>nombre;
	cout<<"\t\t\t\t\t\tAutor: "; cin>>autor;
	cout<<"\t\t\t\t\t\tEditorial: "; cin>>editorial;
	cout<<"\t\t\t\t\t\tCodigo: "; cin>>codigo;
	system("cls");
	cout<<"\n\tUsuario: "<<biblios[indiceLogin].getNombre();
	cout<<"\t\t\t\t\t\t\t\t\t\tCarnet: "<<biblios[indiceLogin].getCarnet();
	categorias();
	cout<<"\n\t\t\t\t\t\tCategoria: "; cin>>categoria;
	system("cls");
	cout<<"\n\tUsuario: "<<biblios[indiceLogin].getNombre();
	cout<<"\t\t\t\t\t\t\t\t\t\tCarnet: "<<biblios[indiceLogin].getCarnet();
	ramas();
	cout<<"\n\t\t\t\t\t\tRama: "; cin>>rama;
	libros[l].setNombre(nombre);
	libros[l].setAutor(autor);
	libros[l].setEditorial(editorial);
	libros[l].setCodigo(codigo);
	libros[l].setCategoria(categoria);
	libros[l].setRama(rama);
	libros[l].setEstado(0);
	l++;
}

void categorias(){
	cout<<"\n\n\t\t\t\t\t\tCATEGORIAS"<<endl;
	cout<<"\n\t\t\t\t\t\t1. Acciones"<<endl;
	cout<<"\t\t\t\t\t\t2. Comedias"<<endl;
	cout<<"\t\t\t\t\t\t3. Infantil"<<endl;
	cout<<"\t\t\t\t\t\t4. Terrores"<<endl;
	cout<<"\t\t\t\t\t\t5. Fantasia"<<endl;
}

void estados(){
	cout<<"\n\n\t\t\t\t\t\tESTADOS"<<endl;
	cout<<"\n\t\t\t\t\t\t0. Disponible"<<endl;
	cout<<"\t\t\t\t\t\t1. Prestado"<<endl;
	cout<<"\t\t\t\t\t\t2. Reservado"<<endl;
}

string tCategoria(int categoria){
	if(categoria == 1){
		return "Acciones";
	}
	else if(categoria == 2){
		return "Comedias";
	}
	else if(categoria == 3){
		return "Infantil";
	}
	else if(categoria == 4){
		return "Terrores";
	}
	else if(categoria == 5){
		return "Fantasia";
	}
}

void ramas(){
	cout<<"\n\n\t\t\t\t\t\tRAMAS"<<endl;
	cout<<"\n\t\t\t\t\t\t1. Artes&Huma"<<endl;
	cout<<"\t\t\t\t\t\t2. Cien&Salud"<<endl;
	cout<<"\t\t\t\t\t\t3. Matematica"<<endl;
	cout<<"\t\t\t\t\t\t4. CienSocial"<<endl;
	cout<<"\t\t\t\t\t\t5. Ingenieria"<<endl;
	cout<<"\t\t\t\t\t\t6. _Ciencias_"<<endl;
}

string tRama(int Rama){
	if(Rama == 1){
		return "Artes&Huma";
	}
	else if(Rama == 2){
		return "Cien&Salud";
	}
	else if(Rama == 3){
		return "Matematica";
	}
	else if(Rama == 4){
		return "CienSocial";
	}
	else if(Rama == 5){
		return "Ingenieria";
	}
	else if(Rama == 6){
		return "_Ciencias_";
	}
}

void Bibliotecario::actualizarLibro(){
	
	system("cls");
	
	string nombre,autor,editorial;
	int codigo,categoria,rama,estado,opc;
	
	
		cout<<"\n\tUsuario: "<<biblios[indiceLogin].getNombre();
		cout<<"\t\t\t\t\t\t\t\t\t\tCarnet: "<<biblios[indiceLogin].getCarnet();
		cout << "\n\n\t\t\t\t\t\t\tACTUALIZAR LIBRO\n\n";
		cout << "\t\t\t\t\tDigite el codigo del libro que desea actualizar" << endl;
		cout << "\t\t\t\t\tCodigo: "; cin>>codigo;
		buscarLibro(codigo);
		
		
		if(encontroLibro){
			
			do{
				system("cls");
				cout<<"\n\tUsuario: "<<biblios[indiceLogin].getNombre();
				cout<<"\t\t\t\t\t\t\t\t\t\tCarnet: "<<biblios[indiceLogin].getCarnet();
				cout << "\n\n\t\t\t\t\t\t\tACTUALIZAR LIBRO\n\n";
				cout << "\t\t\t\t\tDigite el codigo del libro que desea actualizar" << endl;
				cout << "\t\t\t\t\tCodigo: "<<codigo;
				modificarLibro();
				system("cls");
				cout<<"\n\tUsuario: "<<biblios[indiceLogin].getNombre();
				cout<<"\t\t\t\t\t\t\t\t\t\tCarnet: "<<biblios[indiceLogin].getCarnet();
				cout << "\n\n\t\t\t\t\t\t\tACTUALIZAR LIBRO\n\n";
				cout << "\t\t\t\t\tDigite el codigo del libro que desea actualizar" << endl;
				cout << "\t\t\t\t\tCodigo: "<<codigo;
							
				if(k == 1){
					modificarNombre();
				}
				else if(k == 2){
					modificarAutor();
				}
				else if(k == 3){
					modificarEditorial();
				}
				else if(k == 4){
					modificarCategoria(codigo);
				}
				else if(k == 5){
					modificarRama(codigo);
				}
				else if(k == 6){
					modificarEstado(codigo);
				}
				else if(k == 7){
					break;
				}
				else{
					cout << "\n\t\t\t\t\tOpcion incorrecta!" << endl;
				}
				
			}while( rpt == 's' || rpt == 'S' );
		}
		else{
			system("cls");
			cout<<"\n\n\n\t\t\t\t\t\tLibro no encontrado!\n\n\n";
		}
}

void modificarLibro(){
	
	cout << "\n\n\t\t\t\t\tQUE DESEA MODIFICAR?\n";
	cout << "\n\t\t\t\t\t1. Nombre: \t" <<libros[indiceLibro].getNombre();
	cout << "\n\t\t\t\t\t2. Autor: \t" <<libros[indiceLibro].getAutor();
	cout << "\n\t\t\t\t\t3. Editorial: \t" <<libros[indiceLibro].getEditorial();
	cout << "\n\t\t\t\t\t4. Categoria: \t" <<tCategoria(libros[indiceLibro].getCategoria());
	cout << "\n\t\t\t\t\t5. Rama: \t" <<tRama(libros[indiceLibro].getRama());
	cout << "\n\t\t\t\t\t6. Estado: \t" <<tEstado(libros[indiceLibro].getEstado());
	cout << "\n\n\t\t\t\t\t7. Volver atras" << endl;
	cout << "\n\t\t\t\t\tOpcion: "; cin>>k;
}

void modificarNombre(){
	
	string nombre;
	
	cout << "\n\n\t\t\t\t\tESCRIBA EL NUEVO NOMBRE...\n";
	cout << "\n\t\t\t\t\t1. Nombre: \t"; cin>>nombre; libros[indiceLibro].setNombre(nombre);
	cout << "\t\t\t\t\t2. Autor: \t" <<libros[indiceLibro].getAutor();
	cout << "\n\t\t\t\t\t3. Editorial: \t" <<libros[indiceLibro].getEditorial();
	cout << "\n\t\t\t\t\t4. Categoria: \t" <<tCategoria(libros[indiceLibro].getCategoria());
	cout << "\n\t\t\t\t\t5. Rama: \t" <<tRama(libros[indiceLibro].getRama());
	cout << "\n\t\t\t\t\t6. Estado: \t" <<tEstado(libros[indiceLibro].getEstado());
	cout << "\n\n\t\t\t\t\tEl nombre ha sido cambiado!\n";
	cout << "\n\t\t\t\t\tDesea modificar algo mas? Si[s] / No[n]: "; cin>>rpt;
}

void modificarAutor(){
	
	string autor;
	
	cout << "\n\n\t\t\t\t\tESCRIBA EL NUEVO AUTOR...\n";
	cout << "\n\t\t\t\t\t1. Nombre: \t"<<libros[indiceLibro].getNombre();
	cout << "\n\t\t\t\t\t2. Autor: \t"; cin>>autor; libros[indiceLibro].setAutor(autor);
	cout << "\t\t\t\t\t3. Editorial: \t" <<libros[indiceLibro].getEditorial();
	cout << "\n\t\t\t\t\t4. Categoria: \t" <<tCategoria(libros[indiceLibro].getCategoria());
	cout << "\n\t\t\t\t\t5. Rama: \t" <<tRama(libros[indiceLibro].getRama());
	cout << "\n\t\t\t\t\t6. Estado: \t" <<tEstado(libros[indiceLibro].getEstado());
	cout << "\n\n\t\t\t\t\tEl autor ha sido cambiado!\n";
	cout << "\n\t\t\t\t\tDesea modificar algo mas? Si[s] / No[n]: "; cin>>rpt;
}

void modificarEditorial(){
	
	string editorial;
	
	cout << "\n\n\t\t\t\t\tESCRIBA EL NUEVO EDITORIAL...\n";
	cout << "\n\t\t\t\t\t1. Nombre: \t"<<libros[indiceLibro].getNombre();
	cout << "\n\t\t\t\t\t2. Autor: \t"<<libros[indiceLibro].getAutor();
	cout << "\n\t\t\t\t\t3. Editorial: \t"; cin>>editorial; libros[indiceLibro].setEditorial(editorial);
	cout << "\t\t\t\t\t4. Categoria: \t" <<tCategoria(libros[indiceLibro].getCategoria());
	cout << "\n\t\t\t\t\t5. Rama: \t" <<tRama(libros[indiceLibro].getRama());
	cout << "\n\t\t\t\t\t6. Estado: \t" <<tEstado(libros[indiceLibro].getEstado());
	cout << "\n\n\t\t\t\t\tEl editorial ha sido cambiado!\n";
	cout << "\n\t\t\t\t\tDesea modificar algo mas? Si[s] / No[n]: "; cin>>rpt;
}

void modificarCategoria(int codigo){
	
	int categoria;
	
	cout << "\n\n\t\t\t\t\tELIGA LA NUEVA CATEGORIA...";
	categorias();
	cout << "\n\t\t\t\t\tCategoria: "; cin>>categoria; libros[indiceLibro].setCategoria(categoria);
	system("cls");
	
	cout<<"\n\tUsuario: "<<biblios[indiceLogin].getNombre();
	cout<<"\t\t\t\t\t\t\t\t\t\tCarnet: "<<biblios[indiceLogin].getCarnet();
	cout << "\n\n\t\t\t\t\t\t\tACTUALIZAR LIBRO\n\n";
	cout << "\t\t\t\t\tDigite el codigo del libro que desea actualizar" << endl;
	cout << "\t\t\t\t\tCodigo: "<<codigo;
	
	cout << "\n\n\t\t\t\t\tDATOS DEL LIBRO...";
	cout << "\n\n\t\t\t\t\t1. Nombre: \t"<<libros[indiceLibro].getNombre();
	cout << "\n\t\t\t\t\t2. Autor: \t"<<libros[indiceLibro].getAutor();
	cout << "\n\t\t\t\t\t3. Editorial: \t"<<libros[indiceLibro].getEditorial();
	cout << "\n\t\t\t\t\t4. Categoria: \t" <<tCategoria(libros[indiceLibro].getCategoria());
	cout << "\n\t\t\t\t\t5. Rama: \t" <<tRama(libros[indiceLibro].getRama());
	cout << "\n\t\t\t\t\t6. Estado: \t" <<tEstado(libros[indiceLibro].getEstado());
	cout << "\n\n\t\t\t\t\tLa categoria ha sido cambiada!\n";
	cout << "\n\t\t\t\t\tDesea modificar algo mas? Si[s] / No[n]: "; cin>>rpt;
}

void modificarRama(int codigo){
	
	int rama;
	
	cout << "\n\n\t\t\t\t\tELIGA LA NUEVA RAMA...";
	ramas();
	cout << "\n\t\t\t\t\tRama: "; cin>>rama; libros[indiceLibro].setRama(rama);
	system("cls");
	
	cout<<"\n\tUsuario: "<<biblios[indiceLogin].getNombre();
	cout<<"\t\t\t\t\t\t\t\t\t\tCarnet: "<<biblios[indiceLogin].getCarnet();
	cout << "\n\n\t\t\t\t\t\t\tACTUALIZAR LIBRO\n\n";
	cout << "\t\t\t\t\tDigite el codigo del libro que desea actualizar" << endl;
	cout << "\t\t\t\t\tCodigo: "<<codigo;
	
	cout << "\n\n\t\t\t\t\tDATOS DEL LIBRO...";
	cout << "\n\n\t\t\t\t\t1. Nombre: \t"<<libros[indiceLibro].getNombre();
	cout << "\n\t\t\t\t\t2. Autor: \t"<<libros[indiceLibro].getAutor();
	cout << "\n\t\t\t\t\t3. Editorial: \t"<<libros[indiceLibro].getEditorial();
	cout << "\n\t\t\t\t\t4. Categoria: \t" <<tCategoria(libros[indiceLibro].getCategoria());
	cout << "\n\t\t\t\t\t5. Rama: \t" <<tRama(libros[indiceLibro].getRama());
	cout << "\n\t\t\t\t\t6. Estado: \t" <<tEstado(libros[indiceLibro].getEstado());
	cout << "\n\n\t\t\t\t\tLa rama ha sido cambiada!\n";
	cout << "\n\t\t\t\t\tDesea modificar algo mas? Si[s] / No[n]: "; cin>>rpt;
}

void modificarEstado(int codigo){
	
	int estado;
	
	cout << "\n\n\t\t\t\t\tELIGA EL NUEVO ESTADO...";
	estados();
	cout << "\n\t\t\t\t\tEstado: "; cin>>estado; libros[indiceLibro].setEstado(estado);
	system("cls");
	
	cout<<"\n\tUsuario: "<<biblios[indiceLogin].getNombre();
	cout<<"\t\t\t\t\t\t\t\t\t\tCarnet: "<<biblios[indiceLogin].getCarnet();
	cout << "\n\n\t\t\t\t\t\t\tACTUALIZAR LIBRO\n\n";
	cout << "\t\t\t\t\tDigite el codigo del libro que desea actualizar" << endl;
	cout << "\t\t\t\t\tCodigo: "<<codigo;
	
	cout << "\n\n\t\t\t\t\tDATOS DEL LIBRO...";
	cout << "\n\n\t\t\t\t\t1. Nombre: \t"<<libros[indiceLibro].getNombre();
	cout << "\n\t\t\t\t\t2. Autor: \t"<<libros[indiceLibro].getAutor();
	cout << "\n\t\t\t\t\t3. Editorial: \t"<<libros[indiceLibro].getEditorial();
	cout << "\n\t\t\t\t\t4. Categoria: \t" <<tCategoria(libros[indiceLibro].getCategoria());
	cout << "\n\t\t\t\t\t5. Rama: \t" <<tRama(libros[indiceLibro].getRama());
	cout << "\n\t\t\t\t\t6. Estado: \t" <<tEstado(libros[indiceLibro].getEstado());
	cout << "\n\n\t\t\t\t\tEl estado ha sido cambiado!\n";
	cout << "\n\t\t\t\t\tDesea modificar algo mas? Si[s] / No[n]: "; cin>>rpt;
}

void Libro::mostrarLibro(){
	cout << "\n\t\t\t\t\tDATOS DEL LIBRO:"<<endl;
	cout << "\n\t\t\t\t\tNombre: " <<nombre;
	cout << "\n\t\t\t\t\tAutor: " <<autor;
	cout << "\n\t\t\t\t\tEditorial: " <<editorial;
	cout << "\n\t\t\t\t\tCategoria: " <<tCategoria(categoria);
	cout << "\n\t\t\t\t\tRama: " <<tRama(rama);
	cout << "\n\t\t\t\t\tEstado: " <<tEstado(estado);
}

string tEstado(int estado){
	if(estado == 0){
		return "Disponible";
	}
	else if(estado == 1){
		return "Prestado";
	}
	else if(estado == 2){
		return "Reservado";
	}
}

void Bibliotecario::eliminarLibro(){
	
	system("cls");
	
	char rpt;
	int codigo;
	
	cout<<"\n\tUsuario: "<<biblios[indiceLogin].getNombre();
	cout<<"\t\t\t\t\t\t\t\t\t\tCarnet: "<<biblios[indiceLogin].getCarnet();
	cout << "\n\n\t\t\t\t\t\t\tELIMINAR LIBRO\n\n";
	cout << "\t\t\t\t\tDigite el codigo del libro que desea eliminar" << endl;
	cout << "\t\t\t\t\tCodigo: "; cin>>codigo;
	buscarLibro(codigo);
	
	if(encontroLibro){
	libros[indiceLibro].mostrarLibro();
	
	cout << "\n\n\t\t\t\t\tSeguro desea eliminar este libro? Si[s] / No[n]: "; cin>>rpt;
	if(rpt == 's' || rpt == 'S'){
		libros[indiceLibro].setNombre("");
		libros[indiceLibro].setAutor("");
		libros[indiceLibro].setEditorial("");
		libros[indiceLibro].setCodigo(0);
		libros[indiceLibro].setCategoria(0);
		libros[indiceLibro].setRama(0);
		libros[indiceLibro].setEstado(0);
		cout << "\n\n\t\t\t\t\tEl libro ha sido eliminado!" << endl;
	}
	}
	else{
		system("cls");
		cout<<"\n\n\n\t\t\t\t\t\tLibro no encontrado!\n\n\n";
	}
}

void Bibliotecario::reservarLibro(){
	
	system("cls");
	
	char rpt;
	int codigo;
	
	cout<<"\n\tUsuario: "<<biblios[indiceLogin].getNombre();
	cout<<"\t\t\t\t\t\t\t\t\t\tCarnet: "<<biblios[indiceLogin].getCarnet();
	cout << "\n\n\t\t\t\t\t\t\t.:RESERVER LIBRO:.\n\n";
	cout << "\t\t\t\t\tDigite el codigo del libro que desea hacer la reserva" << endl;
	cout << "\t\t\t\t\tCodigo: "; cin>>codigo;
	buscarLibro(codigo);
	
	if(encontroLibro){
	libros[indiceLibro].mostrarLibro();
	
	cout << "\n\n\t\t\t\t\tEste es el libro ha reservar? Si[s] / No[n]: "; cin>>rpt;
	if(rpt == 's' || rpt == 'S'){
		libros[indiceLibro].setEstado(2);
		cout << "\n\n\t\t\t\t\tLibro reservado con exito!" << endl;
	}
	}
	else{
		system("cls");
		cout<<"\n\n\n\t\t\t\t\t\tLibro no encontrado!\n\n\n";
	}
}

void Bibliotecario::prestarLibro(){
	
	system("cls");
	
	char rpt;
	int codigo;
	
	cout<<"\n\tUsuario: "<<biblios[indiceLogin].getNombre();
	cout<<"\t\t\t\t\t\t\t\t\t\tCarnet: "<<biblios[indiceLogin].getCarnet();
	cout << "\n\n\t\t\t\t\t\t\t.:PRESTAR LIBRO:.\n\n";
	cout << "\t\t\t\t\tDigite el codigo del libro ha prestar" << endl;
	cout << "\t\t\t\t\tCodigo: "; cin>>codigo;
	buscarLibro(codigo);
	
	if(encontroLibro){
	libros[indiceLibro].mostrarLibro();
	
	cout << "\n\n\t\t\t\t\tEste es el libro ha prestar? Si[s] / No[n]: "; cin>>rpt;
	if(rpt == 's' || rpt == 'S'){
		libros[indiceLibro].setEstado(1);
		cout << "\n\n\t\t\t\t\tLibro prestado con exito!" << endl;
	}
	}
	else{
		system("cls");
		cout<<"\n\n\n\t\t\t\t\t\tLibro no encontrado!\n\n\n";
	}
}

void Bibliotecario::devolverLibro(){
	
	system("cls");
	
	char rpt;
	int codigo;
	
	cout<<"\n\tUsuario: "<<biblios[indiceLogin].getNombre();
	cout<<"\t\t\t\t\t\t\t\t\t\tCarnet: "<<biblios[indiceLogin].getCarnet();
	cout << "\n\n\t\t\t\t\t\t\t.:DEVOLVER LIBRO:.\n\n";
	cout << "\t\t\t\t\tDigite el codigo del libro que desea devolver" << endl;
	cout << "\t\t\t\t\tCodigo: "; cin>>codigo;
	buscarLibro(codigo);
	
	if(encontroLibro){
	libros[indiceLibro].mostrarLibro();
	
	cout << "\n\n\t\t\t\t\tEste es el libro que desea devolver? Si[s] / No[n]: "; cin>>rpt;
	if(rpt == 's' || rpt == 'S'){
		libros[indiceLibro].setEstado(0);
		cout << "\n\n\t\t\t\t\tLibro devuelto con exito!" << endl; 
	}
	}
	else{
		system("cls");
		cout<<"\n\n\n\t\t\t\t\t\tLibro no encontrado!\n\n\n";
	}
}

void Bibliotecario::consultarLibro(){
	
	system("cls");
	
	int codigo;
	
	cout<<"\n\tUsuario: "<<biblios[indiceLogin].getNombre();
	cout<<"\t\t\t\t\t\t\t\t\t\tCarnet: "<<biblios[indiceLogin].getCarnet();
	cout << "\n\n\t\t\t\t\t\t.:CONSULTAR LIBRO:.\n\n";
	cout << "\t\t\t\t\tDigite el codigo del libro que desea consultar" << endl;
	cout << "\t\t\t\t\tCodigo: "; cin>>codigo;
	buscarLibro(codigo);
	
	if(encontroLibro){
		libros[indiceLibro].mostrarLibro();
	}
	else{
		system("cls");
		cout<<"\n\n\n\t\t\t\t\t\tLibro no encontrado!\n\n\n";
	}
}

void Bibliotecario::listaLibros(){
	
	int c=0;
	
	system("cls");
	fflush(stdin);
	cout<<"\n\tUsuario: "<<biblios[indiceLogin].getNombre();
	cout<<"\t\t\t\t\t\t\t\t\t\tCarnet: "<<biblios[indiceLogin].getCarnet();
	cout<<"\n\n\t\t\t\t\t\t.:LISTA DE LIBROS:.\n\n";
	cout<<"\n\t\t\tNOMBRE\t\t"<<"CATEGORIA\t"<<"RAMA\t\t"<<"CODIGO\t"<<"ESTADO"<<endl;
	
	for(int i=0;i<L;i++){
		if(libros[i].getNombre() != "")
		{
		   	cout<<"\t\t\t"<<libros[i].getNombre()<<"\t"<<tCategoria(libros[i].getCategoria())<<"\t"<<tRama(libros[i].getRama())<<"\t"<<libros[i].getCodigo()<<"\t"<<tEstado(libros[i].getEstado())<<endl;
		   	c++;
		}   		
    }
    
    if(c>0)
    {
    	cout<<"\n\n\t\t\tLIBROS -> "<<c<<"\n\n";
	}
    if(c==0)
	{
		fflush(stdin);
		system("cls");
		cout<<"\n\n\n\t\t\t\t\t\tNO HAY NINGUN LIBRO REGISTRADO"<<endl;
	}
}

void menuMonitor(){
	
	int opc;
	
	do{
		system("cls");
		cout<<"\n\tUsuario: "<<monitores[indiceLogin].getNombre();
		cout<<"\t\t\t\t\t\t\t\t\t\tCarnet: "<<monitores[indiceLogin].getCarnet();
		cout<<"\n\n\t\t\t\t\t\t\tMONITOR" <<endl;
		cout<<"\n\t\t\t\t\t\tQue desea hacer?\n\n";
		cout<<"\t\t\t\t\t\t1. Prestar libro"<<endl;
		cout<<"\t\t\t\t\t\t2. Devolver libro"<<endl;
		cout<<"\t\t\t\t\t\t3. Consultar libro"<<endl;
		cout<<"\t\t\t\t\t\t4. Lista de libros"<<endl;
		cout<<"\t\t\t\t\t\t5. Cerrar\n\n";
		cout<<"\t\t\t\t\t\tOpcion: "; cin>>opc;
		
		switch(opc){
			case 1:
				monitores[indiceLogin].prestarLibro();
				guardaLibro();
				break;
			case 2:
				monitores[indiceLogin].devolverLibro();
				guardaLibro();
				break;
			case 3:
				monitores[indiceLogin].consultarLibro();
				guardaLibro();
				break;
			case 4:
				monitores[indiceLogin].listaLibros();
				guardaLibro();
				break;
			case 5:
				system("cls");
				cout<<"\n\n\n\n\t\t\t\t\t\t\tBYE!\n\n\n\n\n";
				guardaLibro();
				getch();
				exit(1);
			default:
				cout << "\n\n\t\t\t\t\tOpcion incorrecta!\n\n";
		}
		cout<<"\n\n\t\t\t\t\t";
		system("pause");
		system("cls");
	}while(opc != 5);
}

void Monitor::prestarLibro(){
	
	system("cls");
	
	char rpt;
	int codigo;
	
	cout<<"\n\tUsuario: "<<monitores[indiceLogin].getNombre();
	cout<<"\t\t\t\t\t\t\t\t\t\tCarnet: "<<monitores[indiceLogin].getCarnet();
	cout << "\n\n\t\t\t\t\t\t\t.:PRESTAR LIBRO:.\n\n";
	cout << "\t\t\t\t\tDigite el codigo del libro ha prestar" << endl;
	cout << "\t\t\t\t\tCodigo: "; cin>>codigo;
	buscarLibro(codigo);
	
	if(encontroLibro){
	libros[indiceLibro].mostrarLibro();
	
	cout << "\n\n\t\t\t\t\tEste es el libro ha prestar? Si[s] / No[n]: "; cin>>rpt;
	if(rpt == 's' || rpt == 'S'){
		libros[indiceLibro].setEstado(1);
		cout << "\n\n\t\t\t\t\tLibro prestado con exito!" << endl;
	}
	}
	else{
		system("cls");
		cout<<"\n\n\n\t\t\t\t\t\tLibro no encontrado!\n\n\n";
	}
}

void Monitor::devolverLibro(){
	
	system("cls");
	
	char rpt;
	int codigo;
	
	cout<<"\n\tUsuario: "<<monitores[indiceLogin].getNombre();
	cout<<"\t\t\t\t\t\t\t\t\t\tCarnet: "<<monitores[indiceLogin].getCarnet();
	cout << "\n\n\t\t\t\t\t\t\t.:DEVOLVER LIBRO:.\n\n";
	cout << "\t\t\t\t\tDigite el codigo del libro que desea devolver" << endl;
	cout << "\t\t\t\t\tCodigo: "; cin>>codigo;
	buscarLibro(codigo);
	
	if(encontroLibro){
	libros[indiceLibro].mostrarLibro();
	
	cout << "\n\n\t\t\t\t\tEste es el libro que desea devolver? Si[s] / No[n]: "; cin>>rpt;
	if(rpt == 's' || rpt == 'S'){
		libros[indiceLibro].setEstado(0);
		cout << "\n\n\t\t\t\t\tLibro devuelto con exito!" << endl; 
	}
	}
	else{
		system("cls");
		cout<<"\n\n\n\t\t\t\t\t\tLibro no encontrado!\n\n\n";
	}
}

void Monitor::consultarLibro(){
	
	system("cls");
	
	int codigo;
	
	cout<<"\n\tUsuario: "<<monitores[indiceLogin].getNombre();
	cout<<"\t\t\t\t\t\t\t\t\t\tCarnet: "<<monitores[indiceLogin].getCarnet();
	cout << "\n\n\t\t\t\t\t\t.:CONSULTAR LIBRO:.\n\n";
	cout << "\t\t\t\t\tDigite el codigo del libro que desea consultar" << endl;
	cout << "\t\t\t\t\tCodigo: "; cin>>codigo;
	buscarLibro(codigo);
	
	if(encontroLibro){
		libros[indiceLibro].mostrarLibro();
	}
	else{
		system("cls");
		cout<<"\n\n\n\t\t\t\t\t\tLibro no encontrado!\n\n\n";
	}
}

void Monitor::listaLibros(){
	
	int c=0;
	
	system("cls");
	fflush(stdin);
	cout<<"\n\tUsuario: "<<monitores[indiceLogin].getNombre();
	cout<<"\t\t\t\t\t\t\t\t\t\tCarnet: "<<monitores[indiceLogin].getCarnet();
	cout<<"\n\n\t\t\t\t\t\t.:LISTA DE LIBROS:.\n\n";
	cout<<"\n\t\t\tNOMBRE\t\t"<<"CATEGORIA\t"<<"RAMA\t\t"<<"CODIGO\t"<<"ESTADO"<<endl;
	
	for(int i=0;i<L;i++){
		if(libros[i].getNombre() != "")
		{
		   	cout<<"\t\t\t"<<libros[i].getNombre()<<"\t"<<tCategoria(libros[i].getCategoria())<<"\t"<<tRama(libros[i].getRama())<<"\t"<<libros[i].getCodigo()<<"\t"<<tEstado(libros[i].getEstado())<<endl;
		   	c++;
		}   		
    }
    
    if(c>0)
    {
    	cout<<"\n\n\t\t\tLIBROS -> "<<c<<"\n\n";
	}
    if(c==0)
	{
		fflush(stdin);
		system("cls");
		cout<<"\n\n\n\t\t\t\t\t\tNO HAY NINGUN LIBRO REGISTRADO"<<endl;
	}
}

void buscarLibro(int codigo){
	for(int i=0;i<L;i++){
		if(libros[i].getCodigo() == codigo){
			indiceLibro = i;
			encontroLibro = true;
			break;
		}
		else{
			encontroLibro = false;
		}
	}
}

void guardaUsuario(){
	
	ofstream archivo;
	archivo.open("Usuarios.txt",ios::out | ios::trunc);
	
	for(int i=0;i<A;i++){
		if(admins[i].getUsuario() != ""){
			archivo<<admins[i].getUsuario()<<" "<<admins[i].getClave()<<" "<<admins[i].getCarnet()<<" "<<admins[i].getNombre()<<" "<<admins[i].getApellido()<<" "<<admins[i].getPerfil()<<" "<<admins[i].getDni()<<" "<<admins[i].getTel()<<" "<<admins[i].getSancion()<<endl;
		}
	}
	for(int i=0;i<B;i++){
		if(biblios[i].getUsuario() != ""){
			archivo<<biblios[i].getUsuario()<<" "<<biblios[i].getClave()<<" "<<biblios[i].getCarnet()<<" "<<biblios[i].getNombre()<<" "<<biblios[i].getApellido()<<" "<<biblios[i].getPerfil()<<" "<<biblios[i].getDni()<<" "<<biblios[i].getTel()<<" "<<biblios[i].getSancion()<<endl;
		}
	}
	for(int i=0;i<M;i++){
		if(monitores[i].getUsuario() != ""){
			archivo<<monitores[i].getUsuario()<<" "<<monitores[i].getClave()<<" "<<monitores[i].getCarnet()<<" "<<monitores[i].getNombre()<<" "<<monitores[i].getApellido()<<" "<<monitores[i].getPerfil()<<" "<<monitores[i].getDni()<<" "<<monitores[i].getTel()<<" "<<monitores[i].getSancion()<<endl;
		}
	}
	
	archivo.close();
}

void guardaLibro(){
	
	ofstream archivo;
	archivo.open("Libros.txt",ios::out | ios::trunc);
	
	for(int i=0;i<L;i++){
		if(libros[i].getNombre() != ""){
			archivo<<libros[i].getNombre()<<" "<<libros[i].getAutor()<<" "<<libros[i].getEditorial()<<" "<<libros[i].getCodigo()<<" "<<libros[i].getCategoria()<<" "<<libros[i].getRama()<<" "<<libros[i].getEstado()<<endl;
		}
	}
	
	archivo.close();
}

/*
BY BRAYAN ESTIBEN RODALLEGA SAAVEDRA
Twitter: https://twitter.com/brayan1a1
YouTube: https://www.youtube.com/c/brayan1a1
GitHub: https://github.com/brayanrodallega
LinkedIn: https://www.linkedin.com/in/brayanrodallega
*/
