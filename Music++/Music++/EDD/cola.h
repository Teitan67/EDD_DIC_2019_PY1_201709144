#pragma once
#include <fstream> 
#include <string> 
using namespace std;
template<class T>
class cola
{
	class Nodo {
	public:
		Nodo(T x)
		{
			next = 0;
			before = 0;
			dato = x;
		}

		Nodo *getNext() { return next; }
		Nodo *getBefore() { return before; }
		void setNext(Nodo *n) { next = n; }
		void setBefore(Nodo *n) { before = n; }
		T getDato() { return dato; }
	private:
		Nodo *next;
		Nodo *before;
		T dato;
	};
public:
	cola()
	{
		first = 0;
		last = 0;
		size = 0;
	}

	int getSize() { return size; }
	void add_first(T dato);
	void graficar();
	T get_element_at(int index);
	T getLast();

private:
	bool isEmpty() { return size == 0; }
	int size;
	Nodo *first;
	Nodo *last;
};

template<class T>
void cola<T>::add_first(T dato)
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

template<class T>
T cola<T>::get_element_at(int index)
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
template <class T>
T cola<T>::getLast() {
	if (size>0) {
		Nodo *aux = this->last;
		this->last = this->last->getBefore();
		this->last->setNext(0);
		--size;
		return aux->getDato();
	}
	return 0;
}
template <class T>
void  cola<T>::graficar() {


	std::ofstream dot(".\\grafico\\codigo\\C.txt", std::ofstream::out);
	dot << "digraph columnas{" << endl;
	dot << "    rankdir=TB;" << endl;
	dot << "    node [shape = record];" << endl;
	dot << "    graph [ranksep=\"1\"];" << endl << endl;
	dot << "    label=\"Cola\";" << endl;

	for (int i = 1;i <= this->getSize();i++) {
		dot << "    nodo" << i << "[label=\"" << this->get_element_at(i - 1) << "\"];" << endl;
	}
	dot << endl << endl;
	for (int i = 1;i < this->getSize();i++) {

		dot << "    nodo" << i << "->nodo" << (i + 1) << endl;
		dot << "    nodo" << (i + 1) << "->nodo" << i << endl;

	}
	if (this->getSize() == 0) { dot << "    nodo" << 0 << "[label=\"" << "Lista Vacia" << "\"];" << endl; }
	dot << "}" << endl;
	dot.close();
	system("dot -Tpng .\\grafico\\codigo\\C.txt -o .\\grafico\\C.png");
	system(".\\grafico\\C.png");


}