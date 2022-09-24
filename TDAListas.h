#ifndef TDAListas.h
#define TDAListas.h

#include <iostream>
#include <stdlib.h>
#include <string>
#include "TDATitulo.h"
#include "LibreriaEstetica.h"
using namespace std;

struct NodoListas{
	string nombreLista;
	string opcion;
	NodoListas *siguiente;
	NodoTitulo *sig_cancion=NULL;
}nodlis,*punt_listas=&nodlis;


void InsertarLista(NodoListas *&lista, string nombre,string parametro){
	NodoListas *nuevo_nodo=new NodoListas();
	nuevo_nodo->nombreLista=nombre;
	nuevo_nodo->opcion=parametro;
	
	NodoListas *aux1=lista;
	NodoListas *aux2;
	
	while(aux1!= NULL) {
		aux2=aux1;
		aux1=aux1->siguiente;
	} 
	
	if(lista==aux1){
		lista=nuevo_nodo;
	} else{
		aux2->siguiente=nuevo_nodo;
	}
	nuevo_nodo->siguiente=aux1;
}

void EliminarLista(NodoListas *&lista, int n){
	int cont=1;
	if(lista!=NULL){
		NodoListas *aux_borrar=lista;
		NodoListas *anterior=NULL;
			while((aux_borrar!=NULL)&&(cont!=n)){
				if(aux_borrar->opcion=="USUARIO") {
					cont++;
				}
				anterior=aux_borrar;
				aux_borrar=aux_borrar->siguiente;
			}
		if(anterior==NULL){
			lista=lista->siguiente;
		 } else {
			anterior->siguiente=aux_borrar->siguiente;
		}
			delete aux_borrar;
	}
}

void EliminarListaCompleta(NodoListas *&lista){
			while(lista!=NULL){
				NodoListas *aux_borrar=lista;
				lista=lista->siguiente;
				delete aux_borrar;		
			}
}

bool BuscarLista(NodoListas *lista,string nombre){
	NodoListas *actual= lista;
	while((actual!=NULL)&&(nombre!=actual->nombreLista)){
		actual=actual->siguiente;
	}
	if(actual==NULL) {
		return false; 
		} else {
		return true; }
}

int MostrarListas(NodoListas *lista,string parametro){
	int num=1;
	int x=51;
	int y=3;
	NodoListas *actual= new NodoListas();
	actual=lista;
	while(actual!=NULL){
		if((actual->opcion==parametro)&&(actual->nombreLista!="GENERAL")) {
		gotoxy(x,y);	
		cout<<num<<". > "<<actual->nombreLista<<endl;
		num++;
		y++; }
		actual=actual->siguiente;
	}
	num=num-1;
	return num;
}

int MostrarNombresCancionesListas(NodoListas *lista,int n,string parametro){
	int num=1,cont=0;
	bool flag=false;
	int x=40;
	int y=3;

	while(lista!=NULL){
		if(parametro==lista->opcion){
			cont++;
		}
		if(cont==n) {
			break;
		} else {
		lista=lista->siguiente; }
	}
	NodoTitulo *actual= lista->sig_cancion;
	while(actual!=NULL){
		gotoxy(x,y);
		cout<<num<<". > "<<actual->nombre<<" - "<<actual->artista<<endl;
		num++;
		y++;
		actual=actual->siguiente;
	}
	if(num==1){
		cout<<"\n\n                                Lo sentimos, esta lista de reproduccion esta vacia. "<<endl;
		cout<<"\n\n                                    Por favor ingrese canciones a la lista."<<endl;
	} 
	return num-1;
} 

void BuscarEInsertarTitulo(NodoListas *&lista, string nombre, string artista, string nombreLista){
	NodoListas *inicio= new NodoListas();
	inicio=lista;
	while((lista!=NULL)&&(lista->nombreLista!=nombreLista)){
		lista=lista->siguiente;
	}
	InsertarTitulo(lista->sig_cancion,nombre,artista);
	lista=inicio;
}
	
	
void NumeroListas(NodoListas *lista){
	int n=1;
	while(lista!=NULL){
		cout<<"LISTA NUMERO "<<n<<": "<<endl;
		cout<<"Nombre: "<<lista->nombreLista<<endl;
		cout<<"Opcion: "<<lista->opcion<<endl;
		cout<<"----------"<<endl<<endl;
		lista=lista->siguiente;
		n++;
	}
	cout<<"Numero de listas creadas: "<<n<<endl;
}


void CreacionDeTitulos(NodoListas *&lista, string nombre,string cantante, string banda, string texto){
	if(banda!="@"){
		BuscarEInsertarTitulo(lista,nombre,banda,texto);
	} else {
	if(cantante==banda) {
		BuscarEInsertarTitulo(lista,nombre,banda,texto);
	} else {
		BuscarEInsertarTitulo(lista,nombre,cantante,texto);	
	}
}
}

string BuscarNombreLista(NodoListas *lista, int n, string parametro){
	int cont=0;
	while((lista!=NULL)&&(cont!=n)){
				if(lista->opcion==parametro) {
					cont++;
				}
				if(cont!=n)
				lista=lista->siguiente;
			}
		return lista->nombreLista;
	
}

void BuscarYEliminarTitulo(NodoListas *&lista, string nombre, string nombreLista){
	NodoListas *inicio= new NodoListas();
	inicio=lista;
	while((lista!=NULL)&&(lista->nombreLista!=nombreLista)){
		lista=lista->siguiente;
	}
	EliminarTitulo(lista->sig_cancion,nombre);
	lista=inicio;
}

string BuscarNombreCancionLista(NodoListas *lista, int n, string nombreLista){
	while((lista!=NULL)&&(lista->nombreLista!=nombreLista)){
		lista=lista->siguiente;
	}
	return BuscarNombreTitulo(lista->sig_cancion,n);
}

int MostrarNombresCancionesListasBuscador(NodoListas *lista,string nombreLista){
	int num=1;
	while((lista!=NULL)&&(lista->nombreLista!=nombreLista)){
		lista=lista->siguiente; 
	}
	NodoTitulo *actual= lista->sig_cancion;
	while(actual!=NULL){
		cout<<num<<". > "<<actual->nombre<<" - "<<actual->artista<<endl;
		num++;
		actual=actual->siguiente;
	}
	return num-1;
} 

string NombreCancionListaBuscador(NodoListas *lista,int n,string nombreLista){
	int num=1;
	while((lista!=NULL)&&(lista->nombreLista!=nombreLista)){
		lista=lista->siguiente; 
	}
	NodoTitulo *actual= lista->sig_cancion;
	while((actual!=NULL)&&(num<n)){
		num++;
		actual=actual->siguiente;
	}
	return actual->nombre;
} 

string NombreArtistaListaBuscador(NodoListas *lista,int n, string nombreLista){
	int num=1;
	while((lista!=NULL)&&(lista->nombreLista!=nombreLista)){
		lista=lista->siguiente; 
	}
	NodoTitulo *actual= lista->sig_cancion;
	while((actual!=NULL)&&(num<n)){
		num++;
		actual=actual->siguiente;
	}
	return actual->artista;
} 

bool BuscadorDeCancionesLista(NodoListas *lista,string nombreLista,string nombreCancion){
	while((lista!=NULL)&&(lista->nombreLista!=nombreLista)){
		lista=lista->siguiente; 
	}
	NodoTitulo *actual= lista->sig_cancion;
	while((actual!=NULL)&&(actual->nombre!=nombreCancion)){
		actual=actual->siguiente;
	}
	if(actual==NULL){
		return false;
	} else {
	return true; }
} 

int MostrarCancionesBuscadorLista(NodoListas *lista,string nombreLista,string nombreCancion){
	int num=1;
	while((lista!=NULL)&&(lista->nombreLista!=nombreLista)){
		lista=lista->siguiente; 
	}
	NodoTitulo *actual= lista->sig_cancion;
	while(actual!=NULL){
		if(actual->nombre==nombreCancion){
			cout<<num<<".< "<<actual->nombre<<" - "<<actual->artista<<endl;
			num++;
		}
		actual=actual->siguiente;
	}
	return num-1;
}

bool BuscadorDeListas(NodoListas *lista,string nombre){
	while((lista!=NULL)&&(lista->nombreLista!=nombre)){
		lista=lista->siguiente;
	}
	if(lista==NULL){
		return false;
	} else {
		return true;
	}
}



#endif


