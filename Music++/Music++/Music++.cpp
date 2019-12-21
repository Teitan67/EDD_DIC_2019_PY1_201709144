#include "pch.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <tchar.h>
#include <conio.h>
#include <strsafe.h>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "nlohmann/json.hpp"
#include "EDD/ListaSimple.h"
#include "EDD/ListaDoble.h"
#include "EDD/ListaCircularDoble.h"
#include "EDD/Pila.h"
#include "EDD/cola.h"
#include "Artista.h"
#include "albums.h"
#include "canciones.h"
#include "EDD/LDAlbum.h"


// por conveniencia 
using namespace std;
 
//EDD
Pila<int> *P = new Pila<int>();
ListaSimple *LS = new ListaSimple();
ListaDoble *LD = new ListaDoble();
ListaCircularDoble<int> *LCD = new ListaCircularDoble<int>();
cola<int> *c = new cola<int>();
album *album0;
album *album1;
canciones *ca;
LDAlbum *TopAlbu = new LDAlbum(); ;


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
	generarEspacios(1, "5. Artist Report");
	generarEspacios(1, "");
	generarEspacios(1, "6. Top 5 Artistas");
	generarEspacios(1, "");
	generarEspacios(1, "7. Top 5 Albums");
	generarEspacios(1, "");
	generarEspacios(1, "12. Salir");
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
int mes(string mes) {
	if ((mes.compare("Enero")) == 0 || (mes.compare("enero")) == 0)
	{
		return 1;
	}
	else if ((mes.compare("Febrero")) == 0 || (mes.compare("febrero")) == 0)
	{
		return 2;
	}
	else if ((mes.compare("Marzo")) == 0 || (mes.compare("marzo")) == 0)
	{
		return 3;
	}
	else if ((mes.compare("Abril")) == 0 || (mes.compare("abril")) == 0)
	{
		return 4;
	}
	else if ((mes.compare("Mayo")) == 0 || (mes.compare("mayo")) == 0)
	{
		return 5;
	}
	else if ((mes.compare("Junio")) == 0 || (mes.compare("junio")) == 0)
	{
		return 6;
	}
	else if ((mes.compare("Julio")) == 0 || (mes.compare("julio")) == 0)
	{
		return 7;
	}
	else if ((mes.compare("Agosto")) == 0 || (mes.compare("agosto")) == 0)
	{
		return 8;
	}
	else if ((mes.compare("Septiembre")) == 0 || (mes.compare("septiembre")) == 0)
	{
		return 9;
	}
	else if ((mes.compare("Octubre")) == 0 || (mes.compare("octubre")) == 0)
	{
		return 10;
	}
	else if ((mes.compare("Noviembre")) == 0 || (mes.compare("noviembre")) == 0)
	{
		return 11;
	}
	else if ((mes.compare("Diciembre")) == 0 || (mes.compare("diciembre")) == 0)
	{
		return 12;
	}
	return 13;
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
	Artista* artist;
	int x=-1, y = -1,ratingAlbum=0,ratingArtista=0;
	std::ifstream ifs(ruta);
	nlohmann::json Libreria = nlohmann::json::parse(ifs);
	for (const auto& Artista0 : Libreria["Library"]) 
	{		
		artist = new Artista(Artista0["Artist"]["Name"]);
		LD->add_first_LD(artist);
		ratingArtista = 0;
		int iteracionesAr = 0;
		for (const auto& albumI : Artista0["Artist"]["Albums"])
		{
			string x = albumI["Year"];
			string y = albumI["Month"];
			int cy =  mes(y);
			album0 = new album(albumI["Name"], albumI["Year"], albumI["Month"]);
			TopAlbu->add_first_LDA(album0);
			ratingAlbum = 0;
			int iteracionA = 0;
			for (const auto& cancionesI : albumI["Songs"])
			{
				string rating = cancionesI["Rating"];
				int ra = stoi(rating);
				ca = new canciones(cancionesI["Name"], cancionesI["File"], ra);
				album0->canciones->add_first_LS(ca);
				ratingAlbum = ratingAlbum + ra;
				iteracionA++;
			}
			album0->rating = ratingAlbum/ iteracionA;
			artist->getAlbum()->insertar(albumI["Name"], stoi(x), cy, album0);
			cout << endl << ratingAlbum << endl;
			ratingArtista = ratingArtista + ratingAlbum;
			iteracionesAr++;
		}
		artist->rating = ratingArtista/iteracionesAr;
		cout << endl << artist->rating << endl;
		//artist->getAlbum()->graficar_cubo();
	}
	
	system("pause");
}
string Navegador() {
	system("cls");
	int opc = 0;
	string input2;
	generarLinea(3, 10);
	generarLinea(9, 32);
	printf("%c", 201);
	generarLinea(34, 205);
	cout << "  MUSIC++   ";
	generarLinea(34, 205);
	printf("%c", 187);
	generarLinea(9, 32);
	generarEspacios(3, "");
	for (int i = 0;i < LD->getSize_LD();i++) {
		generarEspacios(1, LD->get_element_at_LD(i)->_nameArtist);
	}
	generarEspacios(5, "");
	generarEspacios(1, "Salir");
	generarEspacios(5, "");
	generarLinea(9, 32);
	printf("%c", 200);
	generarLinea(80, 205);
	printf("%c", 188);
	generarLinea(9, 32);
	cout << "\n\n";
	generarLinea(30, 32);
	cout << "Ingrese Nombre de Artista o Salir: ";
	cin.ignore();
	getline(cin,input2);
	cout << input2;
	cout << endl;
		return input2;
	}

int main()
{
	int opc = 0;
	system("mode con: cols=100 lines=40");
	TituloConsola();
	
	string file="",opc3="",A2="";
	string opc2 = "";
	do {
		system("cls");
		opc = menu();
		char input[4] = {000};
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
		case 5:
			LD->ordenarLista();
			LD->graficar_LD();
			break;
		case 4:
			LD->ordenarLista();
			opc2=Navegador();
			
			if (LD->get_element(opc2) != 0) {
				cout << "Artista: "<< opc2 << endl;
				cout<< LD->get_element(opc2)->getAlbum()->obtenerAlbuns()<< endl;
				cout <<"\t\t 1. Generar reporte\n";
				cout <<"\t\t 2. Abrir Album\n";
				cout << "\t\t 3. Salir\n";
				cout << "\t\t Ingrese opcion: ";
				cin.ignore();
			
				cin>>opc3;
				if ((opc3.compare("1"))==0) {
					cout << "\t\t Generando reporte...\n";
					LD->get_element(opc2)->getAlbum()->graficar_cubo();
					cout << "\t\t Reporte generado!\n";
				}
				else if ((opc3.compare("2")) == 0) {
					cout << "\n\t\t Ingrese Nombre de Album:";
					cin.ignore();
					getline(cin,A2);
					
					if(LD->get_element(opc2)->getAlbum()->buscarNodo(A2)!=0){
						int i2=LD->get_element(opc2)->getAlbum()->buscarNodo(A2)->getDato()->canciones->getSize_LS();
						for (int i = 1;i <= i2;i++) {
							cout<< "\n\t\t"<<LD->get_element(opc2)->getAlbum()->buscarNodo(A2)->getDato()->canciones->get_element_at_LS(i - 1)->getName() <<"\n" <<endl;
							cout << "\n\t\t\tFile: " << LD->get_element(opc2)->getAlbum()->buscarNodo(A2)->getDato()->canciones->get_element_at_LS(i - 1)->getFile() << "\n" << endl;
							cout << "\n\t\t\tRating: " << LD->get_element(opc2)->getAlbum()->buscarNodo(A2)->getDato()->canciones->get_element_at_LS(i - 1)->getRating() << "\n" << endl;
							

							
						}
						LD->get_element(opc2)->getAlbum()->buscarNodo(A2)->getDato()->canciones->graficar_LS();

					}
				}
				

				system("pause");
			}
			else {
				cout << "No se reconoce artitsta" << endl;
				system("pause");
			}
			break;
		case 6:
			LD->ordenarListaRating();
			LD->graficar_LD_R();
			break;
		case 7:
			TopAlbu->ordenarListaRating();
			TopAlbu->graficar_LD_R();
			break;

		case 12:
			return 0;
			break;
		default:
			cout << "\n";
			generarLinea(9, 32);
			cout << "OPCION INVALIDA!! \n";
			system("pause");
			break;
		}

	} while (opc != 12);
	return 0;
}
