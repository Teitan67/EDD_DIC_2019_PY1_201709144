#pragma once
#include <fstream> 
#include <string> 
#include "PlayList.h"
	using namespace std;
	class ListaDobleP
	{
		class Nodo {
		public:
			Nodo(PlayList *x)
			{
				next = 0;
				before = 0;
				dato = x;
			}

			Nodo *getNext() { return next; }
			Nodo *getBefore() { return before; }
			void setNext(Nodo *n) { next = n; }
			void setBefore(Nodo *n) { before = n; }
			PlayList *getDato() { return dato; }
			void setDato(PlayList *a) { this->dato = a; }
		private:
			Nodo *next;
			Nodo *before;
			PlayList *dato;
		};
	public:
		ListaDobleP()
		{
			first = 0;
			last = 0;
			size = 0;
		}
		int getSize_LD() { return size; }
		void add_first_LD(PlayList *dato)
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

		PlayList* get_element_at_LD(int index)
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
		PlayList* get_element(string index)
		{
			Nodo *iterador = this->first;
			while (iterador != 0)
			{
				if (index.compare(iterador->getDato()->ply_name) == 0) { return iterador->getDato(); }
				iterador = iterador->getNext();
			}
			return 0;
		}

		void ordenarLista()
		{
			Nodo *actual, *siguiente;
			PlayList* t;

			actual = this->first;
			if (actual != 0) {
				while (actual->getNext() != 0)
				{
					siguiente = actual->getNext();

					while (siguiente != 0)
					{
						if ((actual->getDato()->ply_name.compare(siguiente->getDato()->ply_name)) > 0)
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
		
		
		
	private:
		bool isEmpty() { return size == 0; }
		int size;
		Nodo *first;
		Nodo *last;
	};

