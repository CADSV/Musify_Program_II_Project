#ifndef Archivos.h
#define Archivos.h

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include "TDACanciones.h"
#include "TDATitulo.h"
#include "TDARep.h"
#include "TDAListas.h"
#include "TDATitulo.h"

using namespace std;

 char nombre_archivo[]="C://Users//W10DELLCI74GEN//Desktop//ProyectoPlaylist//Musify.txt";

void AgregarCancionArchivo(NodoListas *&lista, NodoCancion *&cancion){
	ofstream archivo;
	bool flag=true;
	string nombre;
	NodoCancion aux;
	
	archivo.open(nombre_archivo,ios::out);
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo. ";
		exit(1);
	} 
	NodoCancion *actual= new NodoCancion();
	
		while(lista!=NULL){
			if((lista->opcion=="USUARIO")||(lista->opcion=="GENERAL")) {
				archivo<<"%%%%"<<endl;
				archivo<<lista->nombreLista<<endl;
				archivo<<"----"<<endl;
			
				while(lista->sig_cancion!=NULL){
					NodoTitulo *aux_borrar=lista->sig_cancion;
					NodoTitulo *epa;
					nombre=aux_borrar->nombre;
					
				actual=cancion;
				while((actual!=NULL)&&(nombre!=actual->nombre)){
					if(actual->siguiente!=NULL) {
						actual=actual->siguiente; }
				}
				if(actual!=NULL){
					archivo<<actual->nombre<<endl;
			 		archivo<<actual->cantante<<endl;
					archivo<<actual->compositor<<endl;
					archivo<<actual->anio<<endl;
					archivo<<actual->banda<<endl;
					archivo<<actual->album<<endl;
					archivo<<actual->duracion<<endl;
					archivo<<actual->espacio<<endl;
					archivo<<actual->genero<<endl;
					archivo<<actual->reproducciones<<endl;
					archivo<<"----"<<endl; 
			 	}
										
			  		lista->sig_cancion=aux_borrar->siguiente;
					delete aux_borrar;	
				}
			
			
			if(lista->sig_cancion==NULL){			
				NodoListas *aux_borrar=lista;
				lista=lista->siguiente;
				delete aux_borrar; }
 		} else {
 			EliminarTituloCompleto(lista->sig_cancion);
 				NodoListas *aux_borrar=lista;
				lista=lista->siguiente;
				delete aux_borrar;
		 }
		 		 
 	}
 	
	 while(cancion!=NULL){
 		EliminarRepCompleto(cancion->sig_rep);
 				NodoCancion *aux_borrar=cancion;
 				cancion=cancion->siguiente;
 				delete aux_borrar; }		
 				
	archivo.close();
	
}

void CrearListasDesdeArchivos(NodoCancion *&cancion, NodoListas *&lista, NodoRep *&rep, NodoTitulo *&titulo, NodoCancion *&punt){
	ifstream archivo;
	string texto;
	string nombreLista;
	bool flag=false,stop=false;
	int nstop=0;
	
	archivo.open(nombre_archivo,ios::in);
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo. ";
		exit(1);
	} 
	int cont=1;
	
	while (!archivo.eof()){
		getline(archivo,texto);	
	
		if((texto!="----")&&(texto!="%%%%")&&(flag==false)){
		switch(cont){
			
			case 1: {
				punt->nombre=texto;
				break;
			}
			
			case 2: { punt->cantante=texto;
						
				break;
			}
			
			case 3: { punt->compositor=texto;
				break;
			}
			
			case 4: { punt->anio=texto;
				break;
			}
			
			case 5: { punt->banda=texto;
					if((BuscarLista(lista,texto)==false)&&(texto!="@")) {
						InsertarLista(lista,texto,"ARTISTA");
					}  else {
						if((BuscarLista(lista,punt->cantante)==false)&&(punt->cantante!="@")) {
							InsertarLista(lista,punt->cantante,"ARTISTA");
					 	}	  
						if (((BuscarLista(lista,punt->cantante)==true)&&((BuscarCancion(cancion,punt->nombre)==false)))) {
							CreacionDeTitulos(lista,punt->nombre,punt->cantante,punt->banda,punt->cantante); }
					}
					if (((BuscarLista(lista,texto)==true)&&((BuscarCancion(cancion,punt->nombre)==false)))) {
						CreacionDeTitulos(lista,punt->nombre,punt->cantante,punt->banda,texto); }
				break;			}
			case 6: { punt->album=texto;
					if((BuscarLista(lista,texto)==false)&&(texto!="@")) {
						InsertarLista(lista,texto,"ALBUM");	
					}
					if (((BuscarLista(lista,texto)==true)&&((BuscarCancion(cancion,punt->nombre)==false)))) {
						CreacionDeTitulos(lista,punt->nombre,punt->cantante,punt->banda,texto); }
				break;
			}
			
			case 7: { punt->duracion=texto;
				break;
			}
			
			case 8: { punt->espacio=texto;
				break;
			}
			
			case 9: { punt->genero=texto;
						if((BuscarLista(lista,texto)==false)&&(texto!="@")) {
						InsertarLista(lista,texto,"GENERO");
						} 
						if (((BuscarLista(lista,texto)==true)&&((BuscarCancion(cancion,punt->nombre)==false)))) {
							CreacionDeTitulos(lista,punt->nombre,punt->cantante,punt->banda,texto); }
				break;
			}
			
			case 10: { punt->reproducciones=atoi(texto.c_str());
						if((stop==false)&&(nstop<2)) {
						InsertarCancion(cancion,punt,lista,1); }
						BuscarEInsertarRep(cancion,nombreLista,punt->nombre);
						CreacionDeTitulos(lista,punt->nombre,punt->cantante,punt->banda,nombreLista);
				break;
			}
		}
	 } else {
	 	if(texto=="%%%%"){
	 		flag=true;
	 		stop=true;
	 		nstop++;
		 }
	 	cont=0;
	 }
	 
	 if((flag==true)&&(texto!="%%%%")){
	 		nombreLista=texto;
			flag=false;
			stop=false;
			if(texto=="GENERAL"){
				InsertarLista(lista,texto,"GENERAL");	
			} else {
				InsertarLista(lista,texto,"USUARIO");
			}
		}
		
		cont++;
	}
	
	archivo.close();
	
}

void CambioEnArchivos(NodoListas *&lista,NodoCancion *&cancion,NodoTitulo *&titulo,NodoRep *&rep,NodoCancion *&punt){
	AgregarCancionArchivo(lista,cancion);
	CrearListasDesdeArchivos(cancion,lista,rep,titulo,punt_nod);	
}


#endif
