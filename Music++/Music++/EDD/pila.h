#pragma once
#include <fstream> 
#include <string>
using namespace std;
template <class T> 
class Pila
{
	class Nodo
	{
	public:
		Nodo(T x)
		{
			dato = x;
			next = 0;
		}
		void setNext(Nodo *n)
		{
			next = n;
		}
		Nodo *getNext()
		{
			return next;
		}
		T getDato()
		{
			return dato;
		}
	private:
		Nodo *next;
		T dato;
	};
public:
	Pila<T>()
	{
		cima = 0; 
		size = 0; 
	}
	bool estaVacia();
	void push(T dato);
	int getSize() { return this->size; }
	T pop();
	T peek();
	void graficar();

private:
	Nodo *cima;
	int size;

};
template<class T>
bool Pila<T>::estaVacia()
{
	return this->size == 0;
}
template<class T>
void Pila<T>::push(T dato)
{
	Nodo *n = new Nodo(dato);
	if (estaVacia())
	{
		this->cima = n;
		this->size++;
	}
	else
	{
		n->setNext(this->cima);
		this->cima = n;
		this->size++;
	}
}
template<class T>
T Pila<T>::pop()
{
	T aux = this->cima->getDato();
	this->cima = this->cima->getNext();
	this->size--;
	return aux;
}
template<class T>
T Pila<T>::peek()
{
	T aux = this->cima->getDato();
	return aux;
}
template <class T>
void  Pila<T>::graficar() {


	std::ofstream dot(".\\grafico\\codigo\\P.txt", std::ofstream::out);
	dot << "digraph columnas{" << endl;
	dot << "    rankdir=TB;" << endl;
	dot << "    node [shape = record];" << endl;
	dot << "    graph [ranksep=\"1\"];" << endl << endl;
	dot << "    label=\"Pila\";" << endl;
	Nodo *aux = this->cima;
	for (int i = 1;i <= this->getSize();i++) {
		dot << "    nodo" << i << "[label=\"" <<aux->getDato()<< "\"];" << endl;
		aux = aux->getNext();
	}
	dot << endl << endl;
	for (int i = 1;i < this->getSize();i++) {

		dot << "    nodo" << i << "->nodo" << (i + 1) << endl;
		

	}
	if (this->getSize() == 0) { dot << "    nodo" << 0 << "[label=\"" << "Lista Vacia" << "\"];" << endl; }
	dot << "}" << endl;
	dot.close();
	system("dot -Tpng .\\grafico\\codigo\\P.txt -o .\\grafico\\P.png");
	system(".\\grafico\\P.png");


}
