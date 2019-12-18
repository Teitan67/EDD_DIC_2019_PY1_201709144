#pragma once
#include <fstream> 
#include <string> 
#include "canciones.h"
using namespace std;
class cuboDisperso
{
	class Nodo {
	public:
		Nodo(string dato,int x, string y )
		{
			//Punteros
			arriba = 0;
			abajo = 0;
			izquierda = 0;
			derecha = 0;
			adelante = 0;
			atras = 0;
			//Datos
			this->dato = dato;
			this->x = x;
			this->y = y;
			//Rating
			rating = 0;
		}

		Nodo *getArriba() { return arriba; }
		Nodo *getAbajo() { return abajo; }
		Nodo *getIzquierda() { return izquierda; }
		Nodo *getDerecha() { return derecha; }
		Nodo *getAdelante() { return adelante; }
		Nodo *getAtras() { return atras; }
		int getx() { return x; }
		string getY() { return y; }

		void setArriba(Nodo *n) { arriba = n; }
		void setAbajo(Nodo *n) { abajo = n; }
		void setIzquierda(Nodo *n) { izquierda = n; }
		void setDerecha(Nodo *n) { derecha = n; }
		void setAdelante(Nodo *n) { adelante = n; }
		void setAtras(Nodo *n) { atras = n; }
		void setX(int x) { this->x = x; }
		void setY(string y) { this->y = y; }

		string getDato() { return this->dato; }
	private:
		Nodo *arriba;
		Nodo *abajo;
		Nodo *izquierda;
		Nodo *derecha;
		Nodo *adelante;
		Nodo *atras;
		string  dato;
		int x;
		string y;
		int rating;
	};
public:
	cuboDisperso(string artista) {
		this->root =new Nodo(artista,0,"0");
	}
	Nodo* buscarFila(string y);
	Nodo* buscarColumna(int x);
	Nodo* buscarZ(string z,Nodo* x);
	void insertar(string album, int year, string month);
private:
	Nodo *root;
};
cuboDisperso::Nodo* cuboDisperso::buscarColumna(int x){
	Nodo *aux = this->root;
	while (aux!=0)
	{
		if (aux->getx()==x) {return aux;}
		aux = aux->getDerecha();
	}
	return 0;
}
cuboDisperso::Nodo* cuboDisperso::buscarFila(string y) {
	Nodo *aux = this->root;
	while (aux != 0)
	{
		if (aux->getY() == y) { return aux; }
		aux = aux->getAbajo();
	}
	return 0;
}
cuboDisperso::Nodo* cuboDisperso::buscarZ(string z, cuboDisperso::Nodo* x) {
	Nodo *aux = x;
	while (aux != 0)
	{
		if (aux->getDato() == z) { return aux; }
		aux = aux->getAbajo();
	}
	return 0;
}
void cuboDisperso::insertar(string album, int year, string month){

	cuboDisperso::Nodo *nuevo = new cuboDisperso::Nodo(album,year,month);
	cuboDisperso::Nodo *columna=this->buscarColumna(year);
	cuboDisperso::Nodo *fila = this->buscarFila(month);
	cuboDisperso::Nodo *Z = this->buscarZ(album,fila);


}

