#pragma once
#include <fstream> 
#include <string>
using namespace std;
template <class T>
class ListaSimple
{
	class Nodo {
	public:
		Nodo(T x) {
			siguiente = 0;
			dato = x;
		}
		Nodo *getNext() { return siguiente; }
		void setNext(Nodo *n) { siguiente = n; }
		T getDato() { return dato; }
	private:
		Nodo *siguiente;
		T dato;
	};
public:
	ListaSimple() {
		first = 0;
		last = 0;
		size = 0;
	}
	int getSize() { return size; };
	void add_first(T dato);
	void graficar();
	T get_element_at(int index);

private:
	bool isEmpty() { return size == 0; }
	int size;
	Nodo *first;
	Nodo *last;
};
template <class T>
void ListaSimple<T>::add_first(T dato) {
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

template<class T>
T ListaSimple<T>::get_element_at(int index)
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
template <class T>
void  ListaSimple<T>::graficar() {

	std::ofstream dot(".\\Grafico\\Codigo\\LS.txt", std::ofstream::out);

	dot << "digraph columnas{" << endl;
	dot << "    rankdir=TB;" << endl;
	dot << "    node [shape = record];" << endl;
	dot << "    graph [ranksep=\"1\"];" << endl << endl;
	dot << "    label=\"Lista Simple\";" << endl;

	for (int i = 1;i <= this->getSize();i++) {
		dot << "    nodo" << i << "[label=\"" << this->get_element_at(i - 1) << "\"];" << endl;
	}
	dot << endl << endl;
	for (int i = 1;i < this->getSize();i++) {
		
			dot << "    nodo" << i << "->nodo" << (i + 1) << endl;
		
	}
	if (this->getSize() == 0) { dot << "    nodo" << 0 << "[label=\"" << "Lista Vacia" << "\"];" << endl; }
	dot << "}" << endl;
	dot.close();
	system("dot -Tpng .\\Grafico\\Codigo\\LS.txt -o .\\Grafico\\LS.png");
	system(".\\grafico\\LS.png");
	system("pause");

}