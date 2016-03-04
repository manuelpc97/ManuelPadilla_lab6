#include "games.h"
#include "user.h"
#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::endl;
using std::cout;
using std::cin;

int men();
int men2();
bool existGame(int, vector<games>&);

int main(int argc, char*argv[]){
	vector <user> personas;
	vector <games> juegos;	
	bool seguir = true;
	int menu, menu2, pos,id;
	int year;
	string desa, gen;
	string nombre;
	string contra, contra2, contraNueva;
	bool verificar = false;

	while(seguir){
		menu = men();
		if(menu == 1){
			cout<<"Ingrese un nombre: ";
			cin>>nombre;
			cout<<"Ingrese su contraseña: ";
			cin>>contra;
			for(int i = 0; i < personas.size(); i++){
				if(personas[i].getName().compare(nombre)==0){
					verificar = true;
				}
			}

			if(verificar == false){
				user usuario(nombre, contra);
				personas.push_back(usuario);
			}else{
				cout<<"Este nombre de usuario ya existe"<<endl;
			}		
		}else if(menu==2){
			cout<<"-----Log in------"<<endl;
			cout<<"Ingrese su nombre de usuario: ";
			cin>>nombre;
			cout<<"Ingrese su contraseña: "<<endl;
			cin>>contra;
			
			for(int i = 0; i < personas.size(); i++){
				if(personas[i].isValidPassword(contra) && personas[i].differName(nombre)){
					verificar = true;
					pos = i;
				}
			}

			if(verificar){
				menu2 = men2();
				if(menu2 == 1){
					cout<<"Ingrese el id del juego: "<<endl;
					cin>>id;

					if(existGame(id,juegos)){
						if(personas[pos].addGame(id)){
							cout<<"El juego se ha agregado exitosamente"<<endl;
						}else{
							cout<<"El juego no se ha podido guardar"<<endl;
						}	
					}else{
						cout<<"El juego no existe"<<endl;
					}								
				}else if(menu2 == 2){
					cout<<"Ingrese la id del juego: "<<endl;
					cin>>id;
					if(personas[pos].deleteGame(id)){
						cout<<"El juego ha sido borrado."<<endl;
					}else{
						cout<<"El juego no debe existir, ERROR"<<endl;
					}	
				}else if(menu2 == 3){
					cout<<"Ingrese su antigua contraseña."<<endl;
					cin>>contra2;
					if(contra2.compare(contra) == 0){
						cout<<"Ingrese su nueva contraseña"<<endl;
						cin>>contraNueva;
						personas[pos].setPassword(contraNueva);
					}else{
						cout<<"Contraseña no valida."<<endl;
					}			
				}else{
					cout<<"Opcion incorrecta"<<endl;
				}
			}else{
				cout<<"El usuario no existe."<<endl;
			}
		}else if(menu==3){
			cout<<"Ingrese el nombre del usuario que desea eliminar"<<endl;
			cin>>nombre;
			
			for(int i = 0; i < personas.size(); i++){
				if(personas[i].getName().compare(nombre)==0){
					pos = i;
					verificar = true;
				}
			}
			
			if(verificar){
				personas.erase(personas.begin()+pos);
			}else{
				cout<<"Este usuario no existe."<<endl;
			}	
		}else if(menu==4){
			cout<<"Ingrese un id"<<endl;
			cin>>id;
			cout<<"INgrese un nombre"<<endl;
			cin>>nombre;
			cout<<"Ingrese un año"<<endl;
			cin>>year;
			cout<<"Ingrese los desarrolladores"<<endl;
			cin>>desa;
			cout<<"Ingrese el genero"<<endl;
			cin>>gen;
			
			for(int i = 0; i < juegos.size(); i++){
				if(juegos[i].getId() == id){
					verificar = true;
				}
			}
			if(verificar == false){
				games a(id,nombre,year,desa,gen);
				juegos.push_back(a);
			}else{
				cout<<"Ya existe un juego con esta ID"<<endl;
			}	
		}else if(menu == 5){
			cout<<"Ingrese el id del juego que desea eliminar: "<<endl;
			cin>>id;

			for(int i = 0; i < juegos.size(); i++){
				if(id == juegos[i].getId()){
					verificar = true;
					pos = i;
				}
			}

			if(verificar){
				juegos.erase(juegos.begin()+pos);	
			}else{
				cout<<"El juego no existe"<<endl;
			}
		}else if(menu == 6){
			cout<<"***************************Usuarios***********************************"<<endl;
			for(int  i = 0; i < personas.size(); i++){
				cout<<i+1<<"--"<<personas[i].toString()<<endl;
				cout<<"************************"<<endl;
			}
		}else if(menu == 7){
			cout<<"*********************************Juegos*********************************"<<endl;
			for(int i = 0; i<juegos.size(); i++){
				cout<<juegos[i].toString()<<endl;
				cout<<"***************************************"<<endl;
			}
		}else if(menu == 8){
			seguir = false;
		}else{
			cout<<"Opcion incorrecta"<<endl;
		}
		verificar = false;
	}
	return 0;
}

int men(){
	int opcion = 0;

	cout<<"--------------Menu------------"<<endl;
	cout<<"1. Agregar un usuario "<<endl;
	cout<<"2. Modificar usuario"<<endl;
	cout<<"3. Eliminar un usuario"<<endl;
	cout<<"4. Agregar un juego"<<endl;
	cout<<"5. Eliminar un juego"<<endl;
	cout<<"6. Listar usuarios"<<endl;
	cout<<"7. Listar juegos"<<endl;
	cout<<"8. Salir "<<endl;
	cout<<"Ingrese: ";
	cin>>opcion;

	return opcion;
}

int men2(){
	int retorno;
	cout<<"1. Agregar juego"<<endl;
	cout<<"2. Eliminar juego"<<endl;
	cout<<"3. Cambiar contraseña"<<endl;	
	cout<<"Ingrese: ";
	cin>>retorno;
	
	return retorno;
}

bool existGame(int n, vector<games>& juegos){
	bool retorno = false;
	for(int  i = 0; i < juegos.size(); i++){
		if(juegos[i].getId() == n){
			retorno = true;
		}
	}
	return retorno;
}
