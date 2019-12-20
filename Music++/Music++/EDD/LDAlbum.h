#pragma once
#include <fstream> 
#include <string> 
#include "../albums.h"
using namespace std;
class LDAlbum
{
	class Nodo {
	public:
		Nodo(album *x)
		{
			next = 0;
			before = 0;
			dato = x;
		}

		Nodo *getNext() { return next; }
		Nodo *getBefore() { return before; }
		void setNext(Nodo *n) { next = n; }
		void setBefore(Nodo *n) { before = n; }
		album *getDato() { return dato; }
		void setDato(album *a) { this->dato = a; }
	private:
		Nodo *next;
		Nodo *before;
		album *dato;
	};
public:
	LDAlbum()
	{
		first = 0;
		last = 0;
		size = 0;
	}
	bool isEmptyA() { return this->size == 0; }
	int getSize_LDA() { return size; }
	void add_first_LDA(album *dato)
	{
		Nodo *n = new Nodo(dato);
		if (this->isEmptyA())
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

	album* get_element_at_LDA(int index)
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
	
	void ordenarListaRating()
	{
		Nodo *actual, *siguiente;
		album* t;

		actual = this->first;
		if (actual != 0) {
			while (actual->getNext() != 0)
			{
				siguiente = actual->getNext();

				while (siguiente != 0)
				{
					if (actual->getDato()->rating < siguiente->getDato()->rating)
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
	void graficar_LD_R() {
		std::ofstream dot(".\\grafico\\codigo\\RA.txt", std::ofstream::out);
		dot << "digraph columnas{" << endl;
		dot << "    rankdir=TB;" << endl;
		dot << "    node [shape = box];" << endl;
		dot << "    graph [ranksep=\"1\"];" << endl << endl;
		dot << "    label=\"Lista Doble de Artistas\";" << endl;
		int rango = 0;
		if (this->getSize_LDA() < 5) {
			rango = this->getSize_LDA();
		}
		else {
			rango = 5;
		}
		for (int i = 1;i <= rango;i++) {
			dot << "    nodo" << i << "[label=\"" << this->get_element_at_LDA(i - 1)->_albumName << "\n" << this->get_element_at_LDA(i - 1)->rating << "\"];" << endl;
		}
		dot << endl << endl;
		for (int i = 1;i < rango;i++) {

			dot << "    nodo" << i << "->nodo" << (i + 1) << endl;
			dot << "    nodo" << (i + 1) << "->nodo" << i << endl;

		}
		if (this->getSize_LDA() == 0) { dot << "    nodo" << 0 << "[label=\"" << "Lista Vacia" << "\"];" << endl; }
		dot << "}" << endl;
		dot.close();
		system("dot -Tpng .\\grafico\\codigo\\RA.txt -o .\\grafico\\RA.png");
		system(".\\grafico\\RA.png");
	}
private:
	
	int size;
	Nodo *first;
	Nodo *last;
};
