#pragma once
#include <string>
#include "EDD/ListaSimple.h"
#include "canciones.h"
using namespace std;
class album
{
public:
	album(string name, string year,string month)
	{
		this->_albumName = name;
		this->_year = year;
		this->_month = month;
		this->canciones = new ListaSimple();
	}
public:
	string _albumName;
	string _year;
	string _month;
	ListaSimple *canciones;
	
};
