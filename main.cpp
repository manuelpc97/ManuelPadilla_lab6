#include "games.h"
#include "user.h"
#include <iostream>

using std::endl;
using std::cout;
using std::cin;

int men();
int main(int argc, char*argv[]){
	bool seguir = true;
	while(seguir){
		int menu = men();
		if(menu == 1){
			string nombre;
			string contra;
			cout<<"Ingrese un nombre: ";
			cin>>nombre;
			cout<<"Ingrese su contraseña: ";
			cin>>contra;
			user usuario(nombre, contra);		
		}else if(menu==2){

		}else if(menu==3){

		}else if(menu==4){

		}else if(menu == 5){

		}else if(menu == 6){

		}else if(menu == 7){
			seguir = false;
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
	cin>>opcion;

	return opcion;
}
