// algoritmosPlaneacion.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include<cstdlib>
#include <queue>
#include <list>

using namespace std;


typedef  struct listaGeneral
{
	char id;
	int tiempo;
	int prioridad;
	bool operator<(listaGeneral const &other)  { return tiempo < other.tiempo; }// para realizar el metodo de ordenamiento tomando tiempo
	
};
typedef struct listaPrioridad // copia de estructura general para utilizarla unicamente en algoritmo de prioridad
{
	char id;
	int tiempo;
	int prioridad;
	bool operator<(listaPrioridad const &other)  { return prioridad < other.prioridad; }// ordenamiento con prioridad
};

void estructuraFifo(list<listaGeneral>);
void estructuraSJF(list<listaGeneral>);
void roundRobin(list<listaGeneral>);
void prioridad(list<listaPrioridad>);

int _tmain(int argc, _TCHAR* argv[])
{
	listaGeneral listaDatos;
	listaPrioridad priori;
	list<listaGeneral>listaScaners;
	list<listaPrioridad>listaPriori;
	int cont = 1;
	cout << "ingresa los cinco procesos a usar" << endl;
	cout << "\n";
	while (cont < 6)
	{
	
		cout << "ingresa la inicial de este proceso" << endl;
		cin>>listaDatos.id;
		priori.id= listaDatos.id;// igualando a estruct para algoritmo por prioridad
		cout << "ingresa la prioridad de este proceso" << endl;
		cin >> listaDatos.prioridad;
		priori.prioridad = listaDatos.prioridad;
		cout << "ingresa el tiempo de ejecucion de este proceso" << endl;
		cin >> listaDatos.tiempo;
		priori.tiempo = listaDatos.tiempo;
		listaScaners.push_back(listaDatos);
		listaPriori.push_back(priori);
		cout << "guardado corrctamente" << endl;
		cont++;
	}
	cout << "\n" << endl;
	estructuraFifo(listaScaners);
	cout << "\n" << endl;
	estructuraSJF(listaScaners);
	cout << "\n" << endl;
	roundRobin(listaScaners);
	cout << "\n" << endl;

	prioridad(listaPriori);

		system("pause");
	}
	
void estructuraFifo(list<listaGeneral>l)
{
	list<listaGeneral> listaFifo;
	listaFifo = l; //asigne lista fifo a la lista que se recibe como parametro
	int acum=0;
	cout << "FIFO\n" << endl;
	for (list<listaGeneral>::iterator it = listaFifo.begin(); it != listaFifo.end(); it++)
	{
		acum = acum + it->tiempo; // acumula la variable tiempo de la lista
		cout << "proceso \t" << it->id << endl;
		cout << "prioridad\t" << it->prioridad << endl;
		cout << "tiempo de ejecucion\t" << acum << endl;

	}
}
void estructuraSJF(list<listaGeneral>l)
{
	list< listaGeneral >listaSJF;
	listaSJF = l;
	int acum = 0;
	cout << "SJF\n" << endl;
	listaSJF.sort();
	for (list<listaGeneral>::iterator it = listaSJF.begin(); it != listaSJF.end(); it++)
	{
		acum += it->tiempo;
		cout << "proceso \t" << it->id << endl;
		cout << "prioridad\t" << it->prioridad << endl;
		cout << "tiempo de ejecucion\t" << acum << endl;
	}

}

void roundRobin(list<listaGeneral>l)
{

	list<listaGeneral>rR;
		rR = l;
		int acum = 0;
		int quantum;
		listaGeneral aux;
		cout << "round Robin\t" << endl;
		for (list<listaGeneral>::iterator it = rR.begin(); it != rR.end(); it++)
		{
			acum += it->tiempo;
		}
		quantum = acum / rR.size();
		acum = 0;

		for (list<listaGeneral>::iterator i = rR.begin(); i != rR.end();i++ )
		{
			if (quantum >= i->tiempo){
				acum += i->tiempo;
				cout << "proceso \t" << i->id << endl;
				cout << "prioridad\t" << i->prioridad << endl;
				cout << "tiempo de ejecucion\t" << acum << endl;
			}
			else{
				i->tiempo = i->tiempo - quantum;
				aux.id = i->id;
				aux.prioridad = i->prioridad;
				aux.tiempo = i->tiempo;
				rR.push_back(aux);
				acum += quantum;
				
			}
		}
}

void prioridad(list<listaPrioridad>l)
{
	list<listaPrioridad>prioridad;
	prioridad = l;
	int acum = 0;
	double quantum;
	listaPrioridad aux;
	cout << "Prioridad\t" << endl;

	for (list<listaPrioridad>::iterator it = prioridad.begin(); it != prioridad.end(); it++)
	{
		acum += it->tiempo;
	}
	prioridad.sort();
	quantum = acum / prioridad.size();
	acum = 0;
	for (list<listaPrioridad>::iterator i = prioridad.begin(); i != prioridad.end(); i++){
		//prioridad.sort();
		if (quantum >= i->tiempo){
			
			acum += i->tiempo;
			cout << "proceso \t" << i->id << endl;
			cout << "prioridad\t" << i->prioridad << endl;
			cout << "tiempo de ejecucion\t" << acum << endl;
			
		}
		else{
			i->tiempo = i->tiempo - quantum;
			i->prioridad += i->prioridad;
			acum += quantum;
			prioridad.sort();
			
			
			
		}
	}
	}





