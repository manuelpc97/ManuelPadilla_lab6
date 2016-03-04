#pragma once
#include <string>
#include <vector>

using std::vector;
using std::string;

class user{
	string name;
	string password;
	vector<int> games;

	public: 
		user(string, string);
		void setPassword(string);
		string toString();
		bool addGame(int);
		bool deleteGame(int);
		bool isValidPassword(string);
		bool differName(string);
		string getName();
		string getContra();

};


