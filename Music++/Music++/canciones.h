#pragma once
#include <string>
using namespace std;
class canciones
{
	
	canciones(string name,string file, string rating) {
		this->name = name;
		this->file = file;
		this->rating = rating;
	}
	string getName() { return this->name; }
	string getFile() { return this->file; }
	string getRating() { return this->rating; }
	void setName(string n) { name=n; }
	void setFile(string f) { file = f; }
	void setRating(string r) { rating = r; }
private:
	string name;
	string file;
	string rating;
};


