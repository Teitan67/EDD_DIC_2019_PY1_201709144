#pragma once
#include <fstream> 
#include <string> 
#include "Artista.h"
using namespace std;
class ListaDoble
{
	class Nodo {
	public:
		Nodo(Artista *x)
		{
			next = 0;
			before = 0;
			dato = x;
		}

		Nodo *getNext() { return next; }
		Nodo *getBefore() { return before; }
		void setNext(Nodo *n) { next = n; }
		void setBefore(Nodo *n) { before = n; }
		Artista *getDato() { return dato; }
		void setDato(Artista *a) { this->dato = a; }
	private:
		Nodo *next;
		Nodo *before;
		Artista *dato;
	};
public:
	ListaDoble()
	{
		first = 0;
		last = 0;
		size = 0;
	}
	int getSize_LD() { return size; }
	void add_first_LD(Artista *dato)
	{
		Nodo *n = new Nodo(dato);
		if (this->isEmpty())
		{
			this->first = n;
			this->last = n;
			this->size++;
		}
		else
		{
			n->setNext(this->first);
			this->first->setBefore(n);
			this->first = n;
			this->size++;
		}
	}

	Artista* get_element_at_LD(int index)
	{
		if (index >= 0 && index < size)
		{
			Nodo *iterador = this->first;
			int x = 0;
			while (iterador != 0)
			{
				if (index == x) { return iterador->getDato(); }
				iterador = iterador->getNext();
				x++;
			}
		}
		return 0;
	}
	
	void ordenarLista()
	{
		Nodo *actual, *siguiente;
		Artista* t;

		actual = this->first;
		if (actual != 0) {
			while (actual->getNext() != 0)
			{
				siguiente = actual->getNext();

				while (siguiente != 0)
				{
					if ((actual->getDato()->getName().compare(siguiente->getDato()->getName())) > 0)
					{
						t = siguiente->getDato();
						siguiente->setDato(actual->getDato());
						actual->setDato(t);
					}
					siguiente = siguiente->getNext();
				}
				actual = actual->getNext();
				siguiente = actual->getNext();

			}

		}
	}

	void graficar_LD() {
		std::ofstream dot(".\\grafico\\codigo\\LD.txt", std::ofstream::out);
		dot << "digraph columnas{" << endl;
		dot << "    rankdir=TB;" << endl;
		dot << "    node [shape = box];" << endl;
		dot << "    graph [ranksep=\"1\"];" << endl << endl;
		dot << "    label=\"Lista Doble de Artistas\";" << endl;

		for (int i = 1;i <= this->getSize_LD();i++) {
			dot << "    nodo" << i << "[label=\"" << this->get_element_at_LD(i - 1)->getName() << "\"];" << endl;
		}
		dot << endl << endl;
		for (int i = 1;i < this->getSize_LD();i++) {

			dot << "    nodo" << i << "->nodo" << (i + 1) << endl;
			dot << "    nodo" << (i + 1) << "->nodo" << i << endl;

		}
		if (this->getSize_LD() == 0) { dot << "    nodo" << 0 << "[label=\"" << "Lista Vacia" << "\"];" << endl; }
		dot << "}" << endl;
		dot.close();
		system("dot -Tpng .\\grafico\\codigo\\LD.txt -o .\\grafico\\LD.png");
		system(".\\grafico\\LD.png");
	}
private:
	bool isEmpty() { return size == 0; }
	int size;
	Nodo *first;
	Nodo *last;
};
