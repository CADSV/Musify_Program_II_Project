// TDA Rep
#ifndef TDARep.h
#define TDARep.h

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

struct NodoRep{
	string nombre;
	NodoRep *siguiente;
} *punt_rep;

void InsertarRep(NodoRep *&rep, string titulo){
	NodoRep *nuevo_nodo = new NodoRep();
	nuevo_nodo->nombre = titulo;

	NodoRep *aux1=rep;
	NodoRep *aux2;	
	
	while((aux1!= NULL) && (((aux1->nombre)[0])<nuevo_nodo->nombre[0])) {
		aux2 = aux1;
		aux1 = aux1->siguiente;	
	}
	
	if (rep == aux1){
		rep = nuevo_nodo;
	} else {
		aux2->siguiente = nuevo_nodo;
	}
	
	nuevo_nodo->siguiente = aux1;
}

void MostrarRep(NodoRep *rep){
	NodoRep *actual = new NodoRep();
	int num=1;
	actual = rep;
	while (actual != NULL){
		cout<<num<<".- "<<actual->nombre<<endl;
		actual = actual->siguiente;
		num++;
	}
}

void EliminarRep(NodoRep *&rep, string titulo){
	if (rep != NULL){
		
		NodoRep *aux_borrar;
		NodoRep *anterior = NULL;
		aux_borrar = rep;
		
		while((aux_borrar != NULL) && ((aux_borrar->nombre) != titulo)){
			anterior = aux_borrar;
			aux_borrar = aux_borrar->siguiente;
		}
		
		if(aux_borrar == NULL){
			cout<<"La cancion no se encuentra en esa playlist.";
		} else if (anterior == NULL){
			rep = rep->siguiente;
			delete aux_borrar;
		} else{
			anterior->siguiente = aux_borrar->siguiente;
			delete aux_borrar;
		}
	}
}

void EliminarRepCompleto(NodoRep *&rep){
	while (rep != NULL){
		NodoRep *aux_borrar = rep;
		rep = rep -> siguiente;
		delete aux_borrar;
	}
}

string BuscarNombreRep(NodoRep *rep){
		return rep->nombre;
}

#endif
