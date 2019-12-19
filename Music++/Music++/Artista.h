#pragma once
#include <string>
#include "cuboDisperso.h"
using namespace std;
class Artista
{
public:
	Artista(string name)
	{
		this->_nameArtist = name;
		this->Albums = new cuboDisperso(_nameArtist);
	}
	string getName() { return this->_nameArtist; }
	void setName(string name) { this->_nameArtist = name; }
	cuboDisperso* getAlbum() { return this->Albums; }
public:
	string _nameArtist;
	cuboDisperso *Albums;
};
