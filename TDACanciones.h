#ifndef TDACanciones.h
#define TDACanciones.h

#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include "LibreriaEstetica.h"
#include "TDARep.h"
#include "TDATitulo.h"
#include "TDAListas.h"

using namespace std;

struct NodoCancion{
	string nombre;
	string cantante;
	string compositor;
	string anio;
	string banda;
	string album;
	string duracion;
	string espacio;
	string genero;
	int reproducciones=0;
	NodoRep *sig_rep=NULL;
	NodoCancion *siguiente;
}nod,*punt_nod=&nod;

string cancionAux, artistaAux;
int mayor=0;
int contTop=1;
int tope;

void DatoVacio(string &dato){
	while(dato==""){
		fflush(stdin);
		cout<<"\n                                       Por favor introduzca un dato:\n                                      "; 
		getline(cin,dato);
	}
}

bool BuscarListaCantante(NodoCancion *cancion, int n){
		int cont=1;
	NodoCancion *actual;
	actual=cancion;
	while((cancion!=NULL)&&(cont<n)){
		cancion=cancion->siguiente;
		cont++;
	}
}

void ModificarNombre(NodoCancion *&punt, string nuevo_nombre){
	Mayusculas(nuevo_nombre);
	
	punt->nombre=nuevo_nombre;
}

void ModificarCantante(NodoCancion *&punt, string nuevo_cantante){
	Mayusculas(nuevo_cantante);
	punt->cantante=nuevo_cantante;
}

void ModificarCompositor(NodoCancion *&punt, string nuevo_compositor){
	Mayusculas(nuevo_compositor);
	punt->compositor=nuevo_compositor;
}

void ModificarAnio(NodoCancion *&punt, string nuevo_anio){
	punt->anio=nuevo_anio;
}

void ModificarBanda(NodoCancion *&punt, string nueva_banda){
	Mayusculas(nueva_banda);
	punt->banda=nueva_banda;
}

void ModificarAlbum(NodoCancion *&punt, string nuevo_album){
	Mayusculas(nuevo_album);
	punt->album=nuevo_album;
}

void ModificarDuracion(NodoCancion *&punt, string nueva_duracion){
	Mayusculas(nueva_duracion);
	punt->duracion=nueva_duracion;
}

void ModificarEspacio(NodoCancion *&punt, string nuevo_espacio){
	Mayusculas(nuevo_espacio);
	punt->espacio=nuevo_espacio;
}

void ModificarGenero(NodoCancion *&punt, string nuevo_genero){
	Mayusculas(nuevo_genero);
	punt->genero=nuevo_genero;
}

void ModificarCampoCancion(NodoCancion *&punt){
	int op=0,nuevo_anio;
	int x=50;
	int y=7;
	string nuevo_dato;
		system("cls");
		gotoxy(x,y);
		cout<<"1.Nombre.";
		gotoxy(x,y+1);
		cout<<"2.Cantante.";
		gotoxy(x,y+2);
		cout<<"3.Compositor.";
		gotoxy(x,y+3);
		cout<<"4.Anio.";
		gotoxy(x,y+4);
		cout<<"5.Banda.";
		gotoxy(x,y+5);
		cout<<"6.Album.";
		gotoxy(x,y+6);
		cout<<"7.Duracion.";
		gotoxy(x,y+7);
		cout<<"8.Espacio de memoria.";
		gotoxy(x,y+8);
		cout<<"9.Genero.";
		gotoxy(x-20,y+10);
			cout<<"Por favor introduzca el numero del campo que desea modificar:   ";  cin>>op;
		system("cls");
		switch (op){
			case 1: {
				fflush(stdin);
				gotoxy(x-20,y);
				cout<<"Por favor ingrese el nuevo nombre de la cancion:\n\n                                 ";  getline(cin,nuevo_dato);
				DatoVacio(nuevo_dato);
				ModificarNombre(punt,nuevo_dato);
				cout<<"\n\n                                    ";
				system("pause");
				break;
			}
			
			case 2: {
				fflush(stdin);
				gotoxy(x-20,y);
				cout<<"Por favor ingrese el nuevo cantante de la cancion:\n\n                                 ";  getline(cin,nuevo_dato);
				DatoVacio(nuevo_dato);
				ModificarCantante(punt,nuevo_dato);
				cout<<"\n\n                                    ";
				system("pause");
				break;
			}
			
			case 3: {
				fflush(stdin);
				gotoxy(x-20,y);
				cout<<"Por favor ingrese el nuevo compositor de la cancion:\n\n                                 ";  getline(cin,nuevo_dato);
				DatoVacio(nuevo_dato);
				ModificarCompositor(punt,nuevo_dato);
				cout<<"\n\n                                    ";
				system("pause");
				break;
			}
			
			case 4: {
				fflush(stdin);
				gotoxy(x-20,y);
				cout<<"Por favor ingrese el nuevo anio de la cancion:\n\n                                 ";  getline(cin,nuevo_dato);
				DatoVacio(nuevo_dato);
				ModificarAnio(punt,nuevo_dato);
				cout<<"\n\n                                    ";
				system("pause");
				break;
			}
			
			case 5: {
				fflush(stdin);
				gotoxy(x-20,y);
				cout<<"Por favor ingrese la nueva banda de la cancion:\n\n                                 ";  getline(cin,nuevo_dato);
				DatoVacio(nuevo_dato);
				ModificarBanda(punt,nuevo_dato);
				cout<<"\n\n                                    ";
				system("pause");
				break;
			}
			
			case 6: {
				fflush(stdin);
				gotoxy(x-20,y);
				cout<<"Por favor ingrese el nuevo album de la cancion:\n\n                                 ";  getline(cin,nuevo_dato);
				DatoVacio(nuevo_dato);
				ModificarAlbum(punt,nuevo_dato);
				cout<<"\n\n                                    ";
				system("pause");
				break;
			}
			
			case 7: {
				fflush(stdin);
				gotoxy(x-20,y);
				cout<<"Por favor ingrese la nueva duracion de la cancion con el formato 00:00:\n\n                                 ";  getline(cin,nuevo_dato);
				DatoVacio(nuevo_dato);
				ModificarDuracion(punt,nuevo_dato);
				cout<<"\n\n                                    ";
				system("pause");
				break;
			}
			
			case 8: {
				fflush(stdin);
				gotoxy(x-20,y);
				cout<<"Por favor ingrese el nuevo espacio de memoria de la cancion con el formato  00MB:\n\n                                 ";  getline(cin,nuevo_dato);
				DatoVacio(nuevo_dato);
				ModificarEspacio(punt,nuevo_dato);
				cout<<"\n\n                                    ";
				system("pause");
				break;
			}
			
			case 9: {
				fflush(stdin);
				gotoxy(x-20,y);
				cout<<"Por favor ingrese el nuevo genero de la cancion:\n\n                                 ";  getline(cin,nuevo_dato);
				DatoVacio(nuevo_dato);
				ModificarGenero(punt,nuevo_dato);
				cout<<"\n\n                                    ";
				system("pause");
				
				break;
			}
		}
		cout<<"\n\n                                  ";
		cout<<"El campo ha sido modificado con exito.\n";
		cout<<"\n\n                                    ";
	   	system("pause");	
	
}

void ReproducirCancion(NodoCancion *&cancion, int n){
	int cont=1;
	NodoCancion *aux;
	aux=cancion;
	
	while((aux!=NULL)&&(cont<n)){
		cancion=cancion->siguiente;
		cont++;
	}
	
	cancion->reproducciones++;
	cancion = aux;
}

void MostrarInfoCancion(NodoCancion *punt){
	int x=40;
	int y=8;
	gotoxy(x,y);
	cout<<"Nombre de la cancion: "<<punt->nombre;
	y++;
	if (punt->cantante != "@"){
	gotoxy(x,y);
	cout<<"Nombre del cantante: "<<punt->cantante;
	y++;
	}
	if (punt->compositor != "@"){
	gotoxy(x,y);
	y++;	
	cout<<"Nombre del compositor: "<<punt->compositor;
	}
	gotoxy(x,y);
	y++;
	cout<<"Anio de origen: "<<punt->anio;
	if (punt->banda != "@"){
	gotoxy(x,y);
	y++;
	cout<<"Nombre de la banda: "<<punt->banda;
	}
	if (punt->album != "@"){
	gotoxy(x,y);
	y++;
	cout<<"Nombre del album: "<<punt->album;
	}
	gotoxy(x,y);
	y++;
	cout<<"Duracion: "<<punt->duracion;
	gotoxy(x,y);
	y++;
	cout<<"Espacio de memoria: "<<punt->espacio;
	gotoxy(x,y);
	y++;
	cout<<"Genero: "<<punt->genero;
	gotoxy(x,y);
	y++;
	cout<<"Numero de reproducciones: "<<punt->reproducciones;
	
}

void SolicitarDatosCancion(NodoCancion *&punt_nod){
	int x=38;
	int y=3;
	fflush(stdin);	
	system("cls");
	gotoxy(x,y);
	cout<<"Introduzca el nombre de la cancion:\n\n                                         ";
	getline(cin, punt_nod->nombre); 
	DatoVacio(punt_nod->nombre);
	Mayusculas(punt_nod->nombre);
	
	system("cls");
	fflush(stdin);
	gotoxy(x,y);
	cout<<"Introduzca el nombre del cantante: ";
	gotoxy(x,y+1);
	cout<<"Si no aplica por favor coloque @:\n\n                                          ";  getline(cin, punt_nod->cantante);  
	DatoVacio(punt_nod->cantante);
	Mayusculas(punt_nod->cantante);
	
	system("cls");
	fflush(stdin);
	gotoxy(x,y);
	cout<<"Introduzca el nombre del compositor:\n\n                                          ";
    getline(cin, punt_nod->compositor);  
	DatoVacio(punt_nod->compositor);
	Mayusculas(punt_nod->compositor);
	
	system("cls");
	fflush(stdin);
	gotoxy(x,y);
	cout<<"Introduzca el anio de origen de la cancion:\n\n                                          ";
	 getline(cin, punt_nod->anio);  
	DatoVacio(punt_nod->anio);
	
	system("cls");
	fflush(stdin);
	gotoxy(x,y);
	cout<<"Introduzca el nombre de la banda: ";
	gotoxy(x,y+1);
	cout<<"Si no aplica por favor coloque @:\n\n                                          ";  getline(cin, punt_nod->banda);  
	DatoVacio(punt_nod->banda);
	Mayusculas(punt_nod->banda);

	system("cls");
	fflush(stdin);
	gotoxy(x,y);
	cout<<"Introduzca el nombre del album: ";
	gotoxy(x,y+1);
	cout<<"Si no aplica por favor coloque @:\n\n                                          ";  getline(cin, punt_nod->album); 
	DatoVacio(punt_nod->album);
	Mayusculas(punt_nod->album);
	
	system("cls");
	fflush(stdin);
	gotoxy(x,y);
	cout<<"Introduzca la duracion de la cancion en formato 00:00:\n\n                                          ";
	getline(cin, punt_nod->duracion); 
	DatoVacio(punt_nod->duracion);
	Mayusculas(punt_nod->duracion);
	
	system("cls");
	fflush(stdin);
	gotoxy(x,y);
	cout<<"Introduzca el espacio en disco en formato 00MB:\n\n                                           ";
	getline(cin, punt_nod->espacio);  
	DatoVacio(punt_nod->espacio);
	Mayusculas(punt_nod->espacio);
	
	system("cls");
	fflush(stdin);
	gotoxy(x,y);
	cout<<"Introduzca el genero de la cancion:\n\n                                          ";
	getline(cin, punt_nod->genero);  
	DatoVacio(punt_nod->genero); 
	Mayusculas(punt_nod->genero);
	system("cls");
	fflush(stdin);
	
	cout<<"\n\n                              La informacion de la nueva cancion ha sido agregada con exito.\n\n                                         ";
	system("pause");
	
}

bool BuscarCancion(NodoCancion *cancion,string nombre){
	while((cancion!=NULL)&&(cancion->nombre!=nombre)){
		cancion=cancion->siguiente;	
	}
	if(cancion==NULL) {
		return false;
	} else {
		return true;
	}
	
}

void BuscarEInsertarRep(NodoCancion *&cancion, string nombreLista, string nombreCancion){
	NodoCancion *inicio;
	inicio=cancion;
	while((cancion!=NULL)&&(cancion->nombre!=nombreCancion)){
		cancion=cancion->siguiente;
	}
	
	InsertarRep(cancion->sig_rep,nombreLista);
	cancion=inicio;
}

void InsertarCancion(NodoCancion *&cancion, NodoCancion *punt,NodoListas *lista,int n){
	NodoCancion *nuevo_nodo=new NodoCancion();
	nuevo_nodo->nombre=punt->nombre;
	nuevo_nodo->cantante=punt->cantante;
	nuevo_nodo->compositor=punt->compositor;
	nuevo_nodo->anio=punt->anio;
	nuevo_nodo->banda=punt->banda;
	nuevo_nodo->album=punt->album;
	nuevo_nodo->duracion=punt->duracion;
	nuevo_nodo->espacio=punt->espacio;
	nuevo_nodo->genero=punt->genero; 
	nuevo_nodo->reproducciones=0;
	
	NodoCancion *aux1=cancion;
	NodoCancion *aux2;
	
	while((aux1!= NULL) && (((aux1->nombre)[0])<nuevo_nodo->nombre[0])){
		aux2=aux1;
		aux1=aux1->siguiente;
	} 
	
	if(cancion==aux1){
		cancion=nuevo_nodo;
	} else{
		aux2->siguiente=nuevo_nodo;
	}
	nuevo_nodo->siguiente=aux1;
	
	if((BuscarLista(lista,nuevo_nodo->cantante)==false)&&(nuevo_nodo->cantante!="@")) {
		InsertarLista(lista,nuevo_nodo->cantante,"ARTISTA");
	 }  
	if ((BuscarLista(lista,nuevo_nodo->cantante)==true)&&(n==0)) {
		CreacionDeTitulos(lista,nuevo_nodo->nombre,nuevo_nodo->cantante,nuevo_nodo->banda,nuevo_nodo->cantante); }
		
	if((BuscarLista(lista,nuevo_nodo->banda)==false)&&(nuevo_nodo->banda!="@")) {
		InsertarLista(lista,nuevo_nodo->banda,"ARTISTA");
	}
	if ((BuscarLista(lista,nuevo_nodo->banda)==true)&&(n==0)) {
		CreacionDeTitulos(lista,nuevo_nodo->nombre,nuevo_nodo->cantante,nuevo_nodo->banda,nuevo_nodo->banda); }						


	if((BuscarLista(lista,nuevo_nodo->album)==false)&&(nuevo_nodo->album!="@")) {
		InsertarLista(lista,nuevo_nodo->album,"ALBUM");	
	}
	if ((BuscarLista(lista,nuevo_nodo->album)==true)&&(n==0)) {
		CreacionDeTitulos(lista,nuevo_nodo->nombre,nuevo_nodo->cantante,nuevo_nodo->banda,nuevo_nodo->album); }
	
	if((BuscarLista(lista,nuevo_nodo->genero)==false)&&(nuevo_nodo->genero!="@")) {
		InsertarLista(lista,nuevo_nodo->genero,"GENERO");
	} 
	if ((BuscarLista(lista,nuevo_nodo->genero)==true)&&(n==0)){
			CreacionDeTitulos(lista,nuevo_nodo->nombre,nuevo_nodo->cantante,nuevo_nodo->banda,nuevo_nodo->genero); }
	
		if(nuevo_nodo->cantante!="@") BuscarEInsertarRep(cancion,nuevo_nodo->cantante,nuevo_nodo->nombre);
		if(nuevo_nodo->banda!="@")  BuscarEInsertarRep(cancion,nuevo_nodo->banda,nuevo_nodo->nombre);
		if(nuevo_nodo->album!="@")BuscarEInsertarRep(cancion,nuevo_nodo->album,nuevo_nodo->nombre);
		BuscarEInsertarRep(cancion,nuevo_nodo->genero,nuevo_nodo->nombre);
}
int MostrarNombresCanciones(NodoCancion *cancion){
	int num=1;
	int x=36;
	int y=3;
	NodoCancion *actual= new NodoCancion();
	actual=cancion;
	while(actual!=NULL){
		if(actual->cantante=="@"){
		gotoxy(x,y);
		cout<<num<<". > "<<actual->nombre<<" - "<<actual->banda<<endl;
		}else {
		gotoxy(x,y);
		cout<<num<<". > "<<actual->nombre<<" - "<<actual->cantante<<endl;
		}
		num++;
		y++;
		actual=actual->siguiente;
	}
	num=num-1;
return num;	
}

void EliminarCancion(NodoCancion *&cancion,NodoListas *&lista, int n){
	int cont=1;
	string nombreLista;
	if(cancion!=NULL){
		NodoCancion *aux_borrar=cancion;
		NodoCancion *anterior=NULL;
			while((aux_borrar!=NULL)&&(cont!=n)){
				anterior=aux_borrar;
				aux_borrar=aux_borrar->siguiente;
				cont++;
			}
			NodoListas *inicio=lista;

			while(aux_borrar->sig_rep!=NULL){
				NodoRep *auxiliar=new NodoRep();
				auxiliar=aux_borrar->sig_rep;
				nombreLista=BuscarNombreRep(auxiliar);
				lista=inicio;
				while((lista!=NULL)&&(lista->nombreLista!=nombreLista)){
					lista=lista->siguiente;
				}
				EliminarTitulo(lista->sig_cancion,aux_borrar->nombre);
				
				aux_borrar->sig_rep=auxiliar->siguiente;
				delete auxiliar;
			} 

		if(anterior==NULL){
			cancion=cancion->siguiente;
		 } else {
			anterior->siguiente=aux_borrar->siguiente;
		}
			delete aux_borrar;
			lista=inicio;
	}
}


void BuscaryMostrarCancion(NodoCancion *cancion, int n){
	int cont=1;
	NodoCancion *actual;
	actual=cancion;
	while((cancion!=NULL)&&(cont<n)){
		cancion=cancion->siguiente;
		cont++;
	}
	gotoxy(41,4);
	cout<<"La informacion de la cancion es: "<<endl;
	MostrarInfoCancion(cancion);
	cancion = actual;
}

void BuscaryModificarCancion(NodoCancion *cancion, int n){
	int cont=1, contVeces=0;
	string opcion="s";
	NodoCancion *actual;
	actual=cancion;
	while((cancion!=NULL)&&(cont<n)){
		cancion=cancion->siguiente;
		cont++;
	}
do{	
	if (contVeces==0){
		ModificarCampoCancion(cancion); 
		contVeces++; 
	}else {
		system("cls");
		MostrarInfoCancion(cancion);
		cout<<"\n\n                                          Desea modificar otro campo? ( s / n ):    "; cin>>opcion;
		Mayusculas(opcion);
	
		if (opcion == "S"){
		ModificarCampoCancion(cancion); 
		contVeces++;
		}
	}
		
}while (opcion!="N");

	cancion = actual;
}

void MostrarNombresRep(NodoCancion *cancion, int n){
	int cont=1,num=1;
	
	while((cancion!=NULL)&&(cont<n)){
		cancion=cancion->siguiente;
		cont++;
	}
	
	NodoRep *actual=new NodoRep();
	actual=cancion->sig_rep;
	
	while(actual!=NULL){
		cout<<num<<". > "<<actual->nombre<<endl;
		num++;
		actual=actual->siguiente;
	}
}

void AgregarPilaCanciones(NodoTitulo *&pilaCanciones, NodoCancion *cancion, int n){
		int cont=1;
		NodoCancion *actual;
		actual=cancion;
		while((cancion!=NULL)&&(cont<n)){
			cancion=cancion->siguiente;
			cont++;
		}
		
		NodoTitulo *nuevo_nodo = new NodoTitulo();
		nuevo_nodo->nombre = cancion->nombre;
		if (cancion->banda != "@"){
		nuevo_nodo->artista = cancion->banda; 
		}else{
		nuevo_nodo->artista = cancion->cantante;
		}
		nuevo_nodo->siguiente = pilaCanciones;
		pilaCanciones = nuevo_nodo;
	
}

void MostrarPila(NodoTitulo *pilaCanciones){
	NodoTitulo *aux;
	aux = pilaCanciones;
	int y=5;
	
	while (pilaCanciones!=NULL){
		gotoxy(40,y);
		cout<<"  >. " << pilaCanciones->nombre <<" - "<< pilaCanciones->artista <<endl;
		pilaCanciones=pilaCanciones->siguiente;
		y++; 
	}
	
	if(pilaCanciones==NULL){
		cout<<"\n\n                                         Aun no se ha reproducido ninguna cancion."<<endl;
	}
	
	pilaCanciones = aux;
}

void SacarPila(NodoTitulo *&pilaCanciones){
	while(pilaCanciones!=NULL){
	NodoTitulo *aux = pilaCanciones;
	pilaCanciones = aux->siguiente;
	delete aux;
	}
}


string BuscarNombreCancion(NodoCancion *cancion, int n){
	int cont=1;
	while((cancion!=NULL)&&(cont!=n)){
				cancion=cancion->siguiente;
				cont++;
			}
		return cancion->nombre;
}

string BuscarNombreArtista(NodoCancion *cancion, int n){
	int cont=1;
	while((cancion!=NULL)&&(cont!=n)){
				cancion=cancion->siguiente;
				cont++;
			}
		if(cancion->banda!="@") {
		return cancion->banda; 
		} else {
			return cancion->cantante;
		}
}

void BuscarYEliminarRep(NodoCancion *&cancion, string nombreLista, string nombreCancion){
	NodoCancion *inicio;
	inicio=cancion;
	while((cancion!=NULL)&&(cancion->nombre!=nombreCancion)){
		cancion=cancion->siguiente;
	}
	
	EliminarRep(cancion->sig_rep,nombreLista);
	cancion=inicio;
}

int NumeroCancion(NodoCancion *cancion, string nombreCancion){
	int cont=1;
	while((cancion!=NULL)&&(cancion->nombre!=nombreCancion)){
		cont++;
		cancion=cancion->siguiente;
	}
	return cont;
}

bool BuscadorDeCanciones(NodoCancion *cancion, string nombreCancion){
	while((cancion!=NULL)&&(cancion->nombre!=nombreCancion)){
		cancion=cancion->siguiente;
	}
	if(cancion==NULL){
		return false; 
	} else {
		return true;
	}
}

int MostrarCancionesBuscador(NodoCancion *cancion, string nombreCancion){
	int num=1;
	while(cancion!=NULL){
		if(cancion->nombre==nombreCancion){
			if(cancion->banda!="@"){
			cout<<"                                         "<<num<<".< "<<cancion->nombre<<" - "<<cancion->banda<<endl;	
			} else {
			cout<<"                                         "<<num<<".< "<<cancion->nombre<<" - "<<cancion->cantante<<endl;
			}
			num++;
		}
		cancion=cancion->siguiente;
	}
	return num-1;
}

int NumeroCancionBuscador(NodoCancion *cancion, int n,string nombreCancion){
	int cont=0;
	while(cancion!=NULL){
		if(cancion->nombre==nombreCancion){
			n--;
		}
		cont++;
		cancion=cancion->siguiente;
		if(n==0){
			return cont;
		}
		
	}
}

int NumeroCancionBuscadorListas(NodoCancion *cancion, string nombreCancion, string nombreArtista){
	int cont=1;
	while(cancion!=NULL){
		if(cancion->nombre==nombreCancion&&((cancion->cantante==nombreArtista)||(cancion->banda==nombreArtista))){
			return cont;
		}
		cont++;
		cancion=cancion->siguiente;
	}
}

void ArtistaAReproducir(NodoCancion *cancion,int n){
	
	int cont=1;
	NodoCancion *inicio;
	inicio=cancion;
	
	while((cancion!=NULL)&&(cont<n)){
		cancion=cancion->siguiente;
		cont++;
	}
	
		if (cancion->cantante == "@"){
			artistaAux=cancion->banda;	
		}else{
			artistaAux=cancion->cantante;
		}

	cancion=inicio;
}

void CancionAReproducir(NodoCancion *cancion, int n){
	
	int cont=1;
	NodoCancion *inicio;
	inicio=cancion;
	
	while((cancion!=NULL)&&(cont<n)){
		cancion=cancion->siguiente;
		cont++;
	}
	
	cancionAux=cancion->nombre;

	cancion=inicio;
}

int TopCanciones(NodoCancion *cancion, int mayor, int contTop,int numTotal,int y){
	int contPos=1;
	int cont=1;
	int menor=0;
	int pos,veces=0;
	
	mayor=0;
	NodoCancion *inicio;
	inicio=cancion;
	
if (contTop < 11){
	
	if (contTop == 1){
	
		while(cancion!=NULL){
		if ((cancion->reproducciones)>mayor){
			mayor=cancion->reproducciones;
			cancion=cancion->siguiente;
			pos=contPos;
			contPos++;
		} else{
			cancion=cancion->siguiente;
			contPos++;
		}
		}
		tope = mayor;
	}else{
		while(cancion!=NULL){
		if (((cancion->reproducciones)<tope) && ((cancion->reproducciones)>menor) && (cancion->reproducciones >= mayor)){
			mayor=cancion->reproducciones;
			cancion=cancion->siguiente;
			pos=contPos;
			contPos++;
		} else{
			cancion=cancion->siguiente;
			contPos++;
		}
		}	
	}
	
	cancion = inicio;
	
  while(cancion!=NULL){
	if((cancion->reproducciones==mayor)&&(numTotal<10)){
		gotoxy(20,y);
	if(cancion->cantante == "@"){
		cout<< contTop<< ". >. "<<cancion->nombre << " - " << cancion->banda<< ".   Reproducida "<< mayor << " veces."<<endl;
	} else{
		cout<< contTop<< ". >. "<<cancion->nombre << " - " << cancion->cantante<< ".   Reproducida "<< mayor << " veces."<<endl;
	} contTop++; numTotal++; y++;
	}
	cancion=cancion->siguiente;
}

	tope = mayor;
	cancion = inicio;
	if(numTotal<10)	
	TopCanciones(cancion,tope,contTop,numTotal,y);
	 
}
}

#endif
