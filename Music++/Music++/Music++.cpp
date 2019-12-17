#include "pch.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <tchar.h>
#include <conio.h>
#include <strsafe.h>
#include <fstream>
#include "nlohmann/json.hpp"
#include "EDD/ListaSimple.h"
#include "EDD/ListaDoble.h"
#include "EDD/ListaCircularDoble.h"
#include "EDD/Pila.h"
#include "EDD/cola.h"


// por conveniencia 
using namespace std;
Pila<int> *P = new Pila<int>();
ListaSimple<int> *LS = new ListaSimple<int>();
ListaDoble<int> *LD = new ListaDoble<int>();
ListaCircularDoble<int> *LCD = new ListaCircularDoble<int>();
cola<int> *c = new cola<int>();


//----------------------------Declaracion de funciones-----------------------
void generarLinea(int t, int c);
void generarEspacios(int t, string d);
//---------------------------------------------------------------------------
int menu() {
	int opc = 0;
	char input[4];
	generarLinea(3, 10);
	generarLinea(9, 32);
	printf("%c", 201);
	generarLinea(34, 205);
	cout << "  MUSIC++   ";
	generarLinea(34, 205);
	printf("%c", 187);
	generarLinea(9, 32);
	generarEspacios(3, "");
	generarEspacios(1, "1. Importar Musica");
	generarEspacios(1, "");
	generarEspacios(1, "2. Importar PlayList");
	generarEspacios(1, ""); 
	generarEspacios(1, "3. Explorar Musica");
	generarEspacios(1, "");
	generarEspacios(1, "4. Explorar Artistas");
	generarEspacios(1, "");
	generarEspacios(1, "8. Salir");
	generarEspacios(5, "");
	generarLinea(9, 32);
	printf("%c", 200);
	generarLinea(80, 205);
	printf("%c", 188);
	generarLinea(9, 32);
	cout << "\n\n";
	generarLinea(30, 32);
	cout << "Ingrese su opcion: ";
	cin.clear();
	cin >> input;
	cout << endl;
	return atoi(input);
}
void generarLinea(int t, int c)
{
	for (int i = 0; i < t; i++)
	{
		printf("%c", c);
	}
}
void generarEspacios(int t, string d) {
	for (int i = 0; i < t; i++)
	{
		generarLinea(9, 32);
		printf("%c", 186);
		generarLinea(20, 32);
		std::cout << d;
		generarLinea(60 - d.size(), 32);
		printf("%c", 186);
		generarLinea(9, 32);

	}
}
void TituloConsola() {
	TCHAR szOldTitle[MAX_PATH];
	TCHAR szNewTitle[MAX_PATH];

	// Save current console title.

	if (GetConsoleTitle(szOldTitle, MAX_PATH))
	{
		// Build new console title string.

		StringCchPrintf(szNewTitle, MAX_PATH, TEXT("MUSIC++"), szOldTitle);

		// Set console title to new title
		if (!SetConsoleTitle(szNewTitle))
		{
			_tprintf(TEXT("SetConsoleTitle failed (%d)\n"), GetLastError());
		}
		else
		{
			_tprintf(TEXT("SetConsoleTitle succeeded.\n"));
		}
	}
}
void Abrir(string ruta) 
{
	std::ifstream ifs(ruta);
	nlohmann::json Libreria = nlohmann::json::parse(ifs);
	for (const auto& Artista : Libreria["Library"]) 
	{
		std::cout << Artista["Artist"]["Name"]<<endl;
		for (const auto& album : Artista["Artist"]["Albums"])
		{
			std::cout << "\t"<<  album["Name"] << endl;
			std::cout << "\t\t" << album["Year"] << endl;
			std::cout << "\t\t" << album["Month"] << endl;
			for (const auto& canciones : album["Songs"])
			{
			std::cout << "\t\t\t" << canciones["Name"] << endl;
			std::cout << "\t\t\t" << canciones["File"] << endl;
			std::cout << "\t\t\t" << canciones["Rating"] << endl<<endl;
			}
		}
	}

	system("pause");
}
int main()
{
	int opc = 0;
	system("mode con: cols=100 lines=40");
	TituloConsola();

	do {
		system("cls");
		opc = menu();
		char input[4] = {000};
		string file;
		switch (opc)
		{
		case 1:
			cout << "\t\t\tIngrese nombre de archivo: ";
			cin.clear();
			cin >> file;
			Abrir("Importaciones/"+file);
			
			break;
		case 2:
			system("pause");
			break;
		case 8:
			return 0;
			break;
		default:
			cout << "\n";
			generarLinea(9, 32);
			cout << "OPCION INVALIDA!! \n";
			system("pause");
			break;
		}

	} while (opc != 8);
	return 0;
}
