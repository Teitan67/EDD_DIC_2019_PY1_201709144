#pragma once
#include <fstream> 
#include <string>
#include "../canciones.h"
using namespace std;
class ListaSimple
{
	class Nodo {
	public:
		Nodo(canciones *x) {
			siguiente = 0;
			dato = x;
		}
		Nodo *getNext() { return siguiente; }
		void setNext(Nodo *n) { siguiente = n; }
		canciones* getDato() { return dato; }
	private:
		Nodo *siguiente;
		canciones *dato;
	};
public:
	ListaSimple() {
		first = 0;
		last = 0;
		size = 0;
	}
	int getSize_LS() { return size; };
	void add_first_LS(canciones* dato);
	void graficar_LS();
	canciones* get_element_at_LS(int index);

private:
	bool isEmpty() { return size == 0; }
	int size;
	Nodo *first;
	Nodo *last;
};
inline void ListaSimple::add_first_LS(canciones * dato) {
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
		this->first = n;
		this->size++;
	}
}
inline canciones* ListaSimple::get_element_at_LS(int index)
{
	if (index >= 0 && index < size)
	{
		Nodo *iterador = this->first;
		int x = 0;
		while (x<size)
		{
			if (index == x) { return iterador->getDato(); }
			iterador = iterador->getNext();
			x++;	
		}
	}
	return 0;
}
inline void  ListaSimple::graficar_LS() {

	std::ofstream dot(".\\Grafico\\Codigo\\LS.txt", std::ofstream::out);

	dot << "digraph columnas{" << endl;
	dot << "    rankdir=TB;" << endl;
	dot << "    node [shape = record];" << endl;
	dot << "    graph [ranksep=\"1\"];" << endl << endl;
	dot << "    label=\"Lista Simple\";" << endl;

	for (int i = 1;i <= this->getSize_LS();i++) {
		dot << "    nodo" << i << "[label=\"" << this->get_element_at_LS(i - 1)->getName() << "\"];" << endl;
	}
	dot << endl << endl;
	for (int i = 1;i < this->getSize_LS();i++) {
		
			dot << "    nodo" << i << "->nodo" << (i + 1) << endl;
		
	}
	if (this->getSize_LS() == 0) { dot << "    nodo" << 0 << "[label=\"" << "Lista Vacia" << "\"];" << endl; }
	dot << "}" << endl;
	dot.close();
	system("dot -Tpng .\\Grafico\\Codigo\\LS.txt -o .\\Grafico\\LS.png");
	system(".\\grafico\\LS.png");
	system("pause");

}