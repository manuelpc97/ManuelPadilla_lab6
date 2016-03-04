#pragma once
#include <string>

using std::string;

class games{
	int id;
	string nombre;
	int year;
	string desarrolladores;
	string genero;

	public: 
		games(int, string, int, string, string);
		int getId();
		string getNombre();
		string toString();

};
