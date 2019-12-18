#pragma once
#include <string>
using namespace std;
class canciones
{
	
	canciones(string name,string file, int rating) {
		this->name = name;
		this->file = file;
		this->rating = rating;
	}
	string getName() { return this->name; }
	string getFile() { return this->file; }
	int getRating() { return this->rating; }
	void setName(string n) { name=n; }
	void setFile(string f) { file = f; }
	void setRating(int r) { rating = r; }
private:
	string name;
	string file;
	int rating;
public:

};


