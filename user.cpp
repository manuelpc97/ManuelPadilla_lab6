#include "user.h"
#include <sstream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::stringstream;

user::user(string nombre, string contra){
	this->name = nombre;
	this->password = contra;
}

void user::setPassword(string contra){
	this->password = contra;
}

string user::toString(){
	stringstream ss;
	ss<<"nombre: "<<name<<"\n"<<"Contraseña: "<<password;
	return ss.str();
}
		
bool user::addGame(int juego){
	bool add = true;
	for(int i = 0; i < games.size(); i++){
		if(games[i] == juego){
			add = false;
		}
	}
	if(add){
		games.push_back(juego);
		return add;
	}else{
		return add;
	}
}

bool user::deleteGame(int id){
	int pos;
	bool del = false;
	for(int i = 0; i<games.size(); i++){
		if(games[i] == id){
			 pos = i;
			 del = true;
		}
	}
	if(del){
		games.erase(games.begin()+pos);
	}
	return del;
}


bool user::isValidPassword(string word){
	if(word == password){
		return true;
	}else{
		return false;
	}
}
		
bool user::differName(string n){
	if(name == n){
		return true;
	}else{
		return false;
	}
}

string user::getName(){
	return name;	
}

string user::getContra(){
	return password;
}
