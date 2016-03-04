#include "games.h"
#include <sstream>
#include <string>

using std::string;
using std::stringstream;

games::games(int i, string n, int a, string d, string g){
	this->id = i;
	this->nombre = n;
	this->year = a;
	this->desarrolladores = d;
	this->genero = g;
}

int games::getId(){
	return id;
}
		
string games::getNombre(){
	return nombre;
}

string games::toString(){
	stringstream ss;
	ss<<"Id: "<<id<<"\n"<<"nombre: "<<nombre;
	return ss.str();
}
