#pragma once
#pragma once
#pragma once
#include <fstream> 
#include <string> 
#include "canciones.h"
using namespace std;
class ListaCanciones
{
	class Nodo {
	public:
		Nodo(canciones *x)
		{
			next = 0;
			before = 0;
			dato = x;
		}

		Nodo *getNext() { return next; }
		Nodo *getBefore() { return before; }
		void setNext(Nodo *n) { next = n; }
		void setBefore(Nodo *n) { before = n; }
		canciones *getDato() { return dato; }
		void setDato(canciones *a) { this->dato = a; }
	private:
		Nodo *next;
		Nodo *before;
		canciones *dato;
	};
public:
	ListaCanciones()
	{
		first = 0;
		last = 0;
		size = 0;
	}
	int getSize_LD() { return size; }
	void add_first_LD(canciones *dato)
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
	void add_at(canciones *dato, int index)
	{
		if (index >= 0 && index <= this->size)
		{
			if (index == 0) { this->add_first_LD(dato); return; }
			Nodo *aux = this->first;
			int x = 0;
			while (aux != 0)
			{
				if (x == index) { break; }
				aux = aux->getNext();
				x++;
			}
			Nodo *n = new Nodo(dato);
			aux->getBefore()->setNext(n);
			n->setBefore(aux->getBefore());
			n->setNext(aux);
			aux->setBefore(n);
			this->size++;
		}
	}


	canciones* get_element_at_LD(int index)
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
	canciones* get_element(string index)
	{
		Nodo *iterador = this->first;
		while (iterador != 0)
		{
			if (index.compare(iterador->getDato()->getName()) == 0) { return iterador->getDato(); }
			iterador = iterador->getNext();
		}
		return 0;
	}

	void ordenarLista()
	{
		Nodo *actual, *siguiente;
		canciones* t;

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


	void graficar_LD(int pintar) {
		std::ofstream dot(".\\grafico\\codigo\\LD.txt", std::ofstream::out);
		dot << "digraph columnas{" << endl;
		dot << "    rankdir=TB;" << endl;
		dot << "    node [shape = box];" << endl;
		dot << "    graph [ranksep=\"1\"];" << endl << endl;
		dot << "    label=\"Lista Doble de Artistas\";" << endl;

		for (int i = 1;i <= this->getSize_LD();i++) {
			if (pintar == i) {
				dot << "    nodo" << i << "[label=\"" << this->get_element_at_LD(i - 1)->getName() << "\",style=filled,fillcolor=red];" << endl;
			}
			else
			{
				dot << "    nodo" << i << "[label=\"" << this->get_element_at_LD(i - 1)->getName() << "\"];" << endl;
			}

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
