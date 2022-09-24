// TDA Titulo
#ifndef TDATitulo.h
#define TDATitulo.h

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

struct NodoTitulo{
	string nombre;
	string artista;
	NodoTitulo *siguiente;
} *punt_titulo;

void InsertarTitulo(NodoTitulo *&titulo, string nombre, string artista){
	NodoTitulo *nuevo_nodo = new NodoTitulo();
	nuevo_nodo->nombre = nombre;
	nuevo_nodo->artista = artista;
	
	NodoTitulo *aux1 = titulo;
	NodoTitulo *aux2;
	
	while((aux1!= NULL) && (((aux1->nombre)[0])<nombre[0])){
		aux2 = aux1;
		aux1 = aux1->siguiente;	
	}
	
	if (titulo == aux1){
		titulo = nuevo_nodo;
	} else {
		aux2->siguiente = nuevo_nodo;
	}
	
	nuevo_nodo->siguiente = aux1;
		
}

void MostrarTitulo(NodoTitulo *titulo){
	NodoTitulo *actual = new NodoTitulo();
	
	actual = titulo;
	while (actual != NULL){
		cout<<actual->nombre<< " - "<< actual->artista <<endl;
		actual = actual->siguiente;
	}

}

void EliminarTituloCompleto(NodoTitulo *&titulo){
	while (titulo != NULL){
		NodoTitulo *aux_borrar = titulo;
		titulo = titulo -> siguiente;
		delete aux_borrar;
	}
}

void BuscarTitulo(NodoTitulo *titulo, string nombre){
	bool flag = false;
	NodoTitulo *actual = titulo;
	NodoTitulo *anterior=NULL;
	
	while ((actual != NULL)&&(flag==false)){
		if (actual->nombre == nombre){
			flag = true;
		} else {
			anterior=actual;
			actual = actual->siguiente; }
	}
	if(flag==true){
		NodoTitulo *aux_borrar=actual;
	if(anterior==NULL){
		actual=actual->siguiente;
	} else {
		anterior->siguiente=aux_borrar->siguiente;
	}
	delete aux_borrar;
	}
}

void EliminarTitulo(NodoTitulo *&titulo, string nombreTitulo){
	NodoTitulo *aux_borrar=titulo;
	NodoTitulo *anterior=NULL;
	
	while((aux_borrar!=NULL)&&(aux_borrar->nombre!=nombreTitulo)){
		anterior=aux_borrar;
		aux_borrar=aux_borrar->siguiente;	
	}
	if(anterior==NULL){
		titulo=titulo->siguiente;
	} else {
		anterior->siguiente=aux_borrar->siguiente;
	}
		delete aux_borrar;
}

string BuscarNombreTitulo(NodoTitulo *titulo, int n){
	int cont=1;
	while((titulo!=NULL)&&(cont<n)){
		titulo=titulo->siguiente;
		cont++;
	}
	return titulo->nombre;
}


#endif
