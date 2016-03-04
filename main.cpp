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
	string nombre;
	string contra;
	bool verificar = false;

	while(seguir){
		menu = men();
		if(menu == 1){
			cout<<"Ingrese un nombre: ";
			cin>>nombre;
			cout<<"Ingrese su contraseña: ";
			cin>>contra;
			user usuario(nombre, contra);
			personas.push_back(usuario);		
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
						
				}else if(menu2 == 3){

				}else{
					cout<<"Opcion incorrecta"<<endl;
				}
			}else{
				cout<<"El usuario no existe."<<endl;
			}
		}else if(menu==3){

		}else if(menu==4){

		}else if(menu == 5){

		}else if(menu == 6){
			cout<<"----Usuarios-----"<<endl;
			for(int  i = 0; i < personas.size(); i++){
				cout<<i+1<<"--"<<personas[i].toString()<<endl;
			}
		}else if(menu == 7){
		
		}else if(menu == 8){
			seguir = false;
		}else{
			cout<<"Opcion incorrecta"<<endl;
		}
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
