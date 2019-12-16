#pragma once
#include <fstream> 
#include <string>
using namespace std;
template <class T>
class ListaCircularDoble
{
	class Nodo {
	public:
		Nodo(T x) {
			siguiente = 0;
			anterior = 0;
			dato = x;
		}
		Nodo *getNext() { return siguiente; }
		Nodo *getBefore() { return anterior; }
		void setNext(Nodo *n) { siguiente = n; }
		void setBefore(Nodo *n) { anterior = n; }
		T getDato() { return dato; }
	private:
		Nodo *siguiente;
		Nodo *anterior;
		T dato;
	};
public:
	ListaCircularDoble() {
		first = 0;
		last = 0;
		size = 0;
	}
	int getSize() { return size; }
	void add_first(T dato);
	void add_at(T dato, int index);
	void graficar();
	T get_element_at(int index);

private:
	bool isEmpty() { return size == 0; }
	int size;
	Nodo *first;
	Nodo *last;
	~ListaCircularDoble();
};
template <class T>
void ListaCircularDoble<T>::add_first(T dato) {
	Nodo *n = new Nodo(dato);
	if (this->isEmpty())
	{
		this->first = n;
		this->last = n;
		n->setNext(this->first);
		n->setBefore(this->last);
		this->size++;
	}
	else
	{
		Nodo *aux = this->first;
		while (aux->getNext() != this->first)
		{
			aux = aux->getNext();
		}
		aux->setNext(n);
		n->setBefore(aux);
		n->setNext(this->first);
		first->setBefore(n);
		this->first = n;
		this->size++;
	}
}
template<class T>
T ListaCircularDoble<T>::get_element_at(int index)
{
	if (index >= 0 && index < size)
	{
		Nodo *iterador = this->first;
		int x = 0;
		while (x < size)
		{
			if (index == x) { return iterador->getDato(); }
			iterador = iterador->getNext();
			x++;
		}
	}
	return 0;
}
template<class T>
void ListaCircularDoble<T>::add_at(T dato, int index)
{
	if (index >= 0 && index <= this->size)
	{
		if (index == 0) { this->add_first(dato); return; }
		if (index == this->size) { this->add_last(dato); return; }
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
template <class T>
void  ListaCircularDoble<T>::graficar() {

	string Ruta = ".\\Grafico\\Codigo\\LCD.txt";
	std::ofstream dot(Ruta, std::ofstream::out);

	dot << "digraph columnas{" << endl;
	dot << "    rankdir=TB;" << endl;
	dot << "    node [shape = record];" << endl;
	dot << "    graph [ranksep=\"1\"];" << endl << endl;
	dot << "    label=\"Lista Circular\";" << endl;

	for (int i = 1;i <= this->getSize();i++) {
		dot << "    nodo" << i << "[label=\"" << this->get_element_at(i - 1) << "\"];" << endl;
	}
	dot << endl << endl;
	for (int i = 1;i <= this->getSize();i++) {
		if (i == this->getSize()) {
			dot << "    nodo" << i << "->nodo" << 1 << endl;
			dot << "    nodo" << 1 << "->nodo" << i << endl;
		}
		else {
			dot << "    nodo" << i << "->nodo" << (i + 1) << endl;
			dot << "    nodo" << (i + 1) << "->nodo" << i << endl;
		}
	}
	if (this->getSize() == 0) { dot << "    nodo" << 0 << "[label=\"" << "Lista Vacia" << "\"];" << endl; }
	dot << "}" << endl;
	dot.close();
	system("circo -Tpng .\\Grafico\\Codigo\\LCD.txt -o .\\Grafico\\LCD.png");
	system(".\\Grafico\\LCD.png");

}