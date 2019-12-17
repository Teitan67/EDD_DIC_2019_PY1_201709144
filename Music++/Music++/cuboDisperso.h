#pragma once
#include <fstream> 
#include <string> 
using namespace std;
template<class T>
class cuboDisperso
{
	class Nodo {
	public:
		Nodo(T x)
		{
			arriba = 0;
			abajo = 0;
			izquierda = 0;
			derecha = 0;
			adelante = 0;
			atras = 0;
			T = x;
		}

		Nodo *getArriba() { return arriba; }
		Nodo *getAbajo() { return abajo; }
		Nodo *getIzquierda() { return izquierda; }
		Nodo *getDerecha() { return derecha; }
		Nodo *getAdelante() { return adelante; }
		Nodo *getAtras() { return atras; }

		void setArriba(Nodo *n) { arriba = n; }
		void setAbajo(Nodo *n) { abajo = n; }
		void setIzquierda(Nodo *n) { izquierda = n; }
		void setDerecha(Nodo *n) { derecha = n; }
		void setAdelante(Nodo *n) { adelante = n; }
		void setAtras(Nodo *n) { atras = n; }

		T getDato() { return x; }
	private:
		Nodo *arriba;
		Nodo *abajo;
		Nodo *izquierda;
		Nodo *derecha;
		Nodo *adelante;
		Nodo *atras;
		T  x;
	};
	
};

