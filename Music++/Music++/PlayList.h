#pragma once
#include <string>
#include "PlayListPl.h"
using namespace std;
class PlayList
{
public:
	PlayList(string name)
	{
		this->Ply_NAME = name;
		this->canciones = new ListaDoblePl();
		rating = 0;
	}
	string getName() { return this->Ply_NAME; }
	void setName(string name) { this->Ply_NAME = name; }
	ListaDoblePl* getCancion() { return this->canciones; }
public:
	string Ply_NAME;
	ListaDoblePl *canciones;
	int rating;
};