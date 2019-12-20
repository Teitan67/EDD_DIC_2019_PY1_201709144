#pragma once
#include <fstream> 
#include <string>
#include "albums.h"
using namespace std;
class cuboDisperso
{
	class Nodo
	{
	public:
		Nodo(string name, int x, int y)
		{
			//Punteros
			arriba = 0;
			abajo = 0;
			izquierda = 0;
			derecha = 0;
			adelante = 0;
			atras = 0;
			//Datos
			this->name = name;
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
		string getEtiqueta() { return this->name; }
		int getx() { return this->x; }
		int getY() { return y; }

		void setDato(album *data) { dato = data; }
		void setArriba(Nodo *n) { arriba = n; }
		void setAbajo(Nodo *n) { abajo = n; }
		void setIzquierda(Nodo *n) { izquierda = n; }
		void setDerecha(Nodo *n) { derecha = n; }
		void setAdelante(Nodo *n) { adelante = n; }
		void setAtras(Nodo *n) { atras = n; }
		void setX(int x) { this->x = x; }
		void setY(int y) { this->y = y; }

		album* getDato() { return this->dato; }
	private:
		Nodo *arriba;
		Nodo *abajo;
		Nodo *izquierda;
		Nodo *derecha;
		Nodo *adelante;
		Nodo *atras;
		album  *dato;
		int x;
		int y;
		int rating;
		string name;
	};
public:
	cuboDisperso(string root) {
		this->root = new Nodo(root, -1, -1);
	}

	Nodo* buscarColumna(int x) {
		Nodo *aux = this->root;
		while (aux != 0)
		{
			if (aux->getx() == x) { return aux; }
			aux = aux->getDerecha();
		}
		return 0;
	}
	cuboDisperso::Nodo* buscarFila(int y) {
		Nodo *aux = this->root;
		while (aux != 0)
		{
			if (aux->getY() == y) { return aux; }
			aux = aux->getAbajo();
		}
		return 0;
	}
	cuboDisperso::Nodo* buscarZ(string z, cuboDisperso::Nodo* x) {
		Nodo *aux = x;
		while (aux != 0)
		{
			if (aux->getDato()->_albumName.compare(z) == 0) { return aux; }
			aux = aux->getAbajo();
		}
		return 0;
	}
	cuboDisperso::Nodo* buscarNodo(int x, int y) {
		Nodo *aux = buscarColumna(x);
		if (aux != 0) {
			Nodo *data = aux;
			while (data != 0)
			{
				if (data->getY() == y) { return data; }
				data = data->getAbajo();
			}
		}
		
		return 0;
	}
	cuboDisperso::Nodo* buscarNodo(string entrada) {
		Nodo *b_y = this->root;
		if (b_y != 0) {
			while (b_y->getAbajo() != 0)
			{
				Nodo *b_x = b_y->getAbajo();
				if (b_x!=0)
				{
					while (b_x->getDerecha() != 0)
					{
						b_x = b_x->getDerecha();
						if ((b_x->getEtiqueta().compare(entrada) == 0)) { return b_x;break; }
					}
					b_y = b_y->getAbajo();
				}
			}
		}

		return 0;
	}

	Nodo* crearColumna(int x) 
	{
		Nodo *cabeza_columna = this->root;
		Nodo *columna = this->insertar_ordenado_columna(new Nodo(to_string(x), x, -1), cabeza_columna);
		return columna;
	}
	Nodo* crearFila(int y)
	{
		Nodo *cabeza_fila = this->root;
		Nodo *fila = this->insertar_ordenado_fila(new Nodo(to_string(y), -1, y), cabeza_fila);
		return fila;
	}
	void insertar(string album, int x, int y) {

		cuboDisperso::Nodo *nuevo = new cuboDisperso::Nodo(album, x, y);
		Nodo *z=buscarNodo(x,y);
		if (z != 0) {
			z->setAdelante(nuevo);
			nuevo->setAbajo(z);
			
		}
		else
		{
			cuboDisperso::Nodo *columna = this->buscarColumna(x);
			cuboDisperso::Nodo *fila = this->buscarFila(y);
			if (columna == 0 && fila == 0)
			{
				columna = crearColumna(x);

				fila = crearFila(y);

				nuevo = insertar_ordenado_columna(nuevo, fila);
				nuevo = insertar_ordenado_fila(nuevo, columna);
			}
			else if (columna == 0 && fila != 0)
			{

				columna = crearColumna(x);
				nuevo = insertar_ordenado_columna(nuevo, fila);
				nuevo = insertar_ordenado_fila(nuevo, columna);
				return;
			}
			else if (columna != 0 && fila == 0)
			{
				fila = crearFila(y);
				nuevo = insertar_ordenado_columna(nuevo, fila);
				nuevo = insertar_ordenado_fila(nuevo, columna);
				return;
			}
			else if (columna != 0 && fila != 0)
			{
				nuevo = insertar_ordenado_columna(nuevo, fila);
				nuevo = insertar_ordenado_fila(nuevo, columna);
			}
		}
	}

	cuboDisperso::Nodo* insertar_ordenado_columna(Nodo* nuevo, Nodo* columna)
	{
		Nodo *temp = columna;
		bool bandera = false;
		while (true)
		{
			if (temp->getx() == nuevo->getx())
			{
				temp->setY(nuevo->getY());
				temp->setDato(nuevo->getDato());
				return temp;
			}
			else if (temp->getx() > nuevo->getx())
			{
				bandera = true;

			}
			if (temp->getDerecha() != 0)
			{
				temp = temp->getDerecha();
			}
			else {
				break;
			}
		}
			if (bandera)
			{
				nuevo->setDerecha(temp);
				temp->getIzquierda()->setDerecha(nuevo);
				nuevo->setIzquierda(temp->getIzquierda());
				temp->setIzquierda(nuevo);
			}
			else
			{
				temp->setDerecha(nuevo);
				nuevo->setIzquierda(temp);
			}
			return nuevo;
	}
	cuboDisperso::Nodo* insertar_ordenado_fila(Nodo* nuevo, Nodo* fila)
	{
		Nodo *temp = fila;
		bool bandera = false;
		while (true)
		{
			if (temp->getY() == nuevo->getY())
			{
				temp->setX(nuevo->getx());
				temp->setDato(nuevo->getDato());
				return temp;
			}
			else if (temp->getY() > nuevo->getY())
			{
				bandera = true;
				break;
			}
			if (temp->getAbajo() != 0)
			{
				temp = temp->getAbajo();
			}
			else {
				break;
			}
		}
			if (bandera)
			{
				nuevo->setAbajo(temp);
				temp->getArriba()->setAbajo(nuevo);
				nuevo->setArriba(temp->getArriba());
				temp->setArriba(nuevo);
			}
			else
			{
				temp->setAbajo(nuevo);
				nuevo->setArriba(temp);
			}
			return nuevo;

		
		return 0;
	}
	void graficar_cubo() 
	{
		Nodo *aux = this->root;
		std::ofstream dot(".\\grafico\\codigo\\cubo.txt", std::ofstream::out);
		dot << "digraph cubo{" << endl;
		dot << "    rankdir=LR;" << endl;
		dot << "    node [shape = box, color=cornflowerblue];" << endl;
		dot << "    graph [ranksep=\"1\"];" << endl << endl;
		dot << "    label=\"Cubo Ortogonal\";" << endl;

		if (aux == 0) { dot << "    nodo" << 0 << "[label=\"" << "Lista Vacia" << "\"];" << endl; }
		int i=0;
		Nodo *aux2;
		while (aux!= 0)
		{
			aux2 = aux;
			while (aux2!=0)
			{
				dot << "    nodo"<<i++  << "[label=\"" << aux2->getEtiqueta() << "\", pos=\""<<aux2->getx()<<","<<aux2->getY()<<"!\"];" << endl;
				if (aux2->getAdelante() != 0) {
					dot << "    nodo" << i << "z[label=\"" << aux2->getAdelante()->getEtiqueta() << "\", pos=\"" << aux2->getAdelante()->getx()+0.2 << "," << aux2->getAdelante()->getY()+0.2 << "!\"];" << endl;
				}
				aux2 = aux2->getDerecha();
				
			}
			aux = aux->getAbajo();
		}
		
		
		
		dot << "}" << endl;
		dot.close();
		system("neato -Tpng .\\grafico\\codigo\\cubo.txt -o .\\grafico\\cubo.png");
		system(".\\grafico\\cubo.png");
	}
private:
	Nodo *root;
};


