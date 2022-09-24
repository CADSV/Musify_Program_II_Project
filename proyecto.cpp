#include <iostream>
#include <stdlib.h>
#include "windows.h"
#include "LibreriaEstetica.h"
#include "TDACanciones.h"
#include "TDATitulo.h"
#include "TDARep.h"
#include "TDAListas.h"
#include "Archivos.h"
using namespace std;

int op,opcionMenuCancion,opcionListaR,opcionVerCancion,QuieroOir,cancionAEliminar,listaOir,opcionVerLista,listaAgregar,cancionAgregarLista,cancionEliminarLista;
int artistaOir,generoOir,albumOir,cancionBuscar,albumBuscar,generoBuscar,artistaBuscar;
string nombreLista,nombreCancion,nombreArtista,nombreAlbum,nombreGenero;
NodoCancion *cancion=NULL;
NodoListas *lista=NULL;
NodoRep *rep=NULL;
NodoTitulo *titulo=NULL;
NodoTitulo *pilaCanciones=NULL;
int nTotalCanciones,nTotalListas,opcionGenero,opcionArtistas,opcionAlbumes;

void MenuVerCanciones(){
do{
	system("cls");
	int x = 38;
	int y = 7;
	gotoxy(x,y);
	cout<<" ______________.:M E N U:.______________"<<"\n";
	gotoxy(x,y+1);
	cout<<"|                                       |"<<"\n";
	gotoxy(x,y+2);
	cout<<"|         1. Reproducir cancion.        |"<<"\n";
	gotoxy(x,y+3);
	cout<<"|  2. Agregar a lista de reproduccion.  |"<<"\n";
	gotoxy(x,y+4);
	cout<<"|        3. Mostrar informacion.        |"<<"\n";
	gotoxy(x,y+5);		
	cout<<"|       4. Modificar informacion.       |"<<"\n";
	gotoxy(x,y+6);
	cout<<"|      5. Volver al menu anterior.      |"<< "\n";
	gotoxy(x,y+7);
	cout<<"|_______________________________________|"<<"\n\n";
	gotoxy(x-4,y+9);
	fflush(stdin);
	cout<< "Por favor introduzca la opcion que desea realizar: ";
	cin >> opcionVerCancion;
	
	switch(opcionVerCancion){
			case 1:{system("cls");
				CancionAReproducir(cancion,QuieroOir);
				ArtistaAReproducir(cancion,QuieroOir);
				Reproduccion(cancionAux,artistaAux);
				ReproducirCancion(cancion,QuieroOir);
				AgregarPilaCanciones(pilaCanciones,cancion,QuieroOir);
				cout<<"\n\n\n\n\n\n\n\n\n\n\n\n                                         ";
				system("pause");
				break;
			}
			case 2:{system("cls");
				nTotalListas=MostrarListas(lista,"USUARIO");
				fflush(stdin);
				cout<<"\n\n                      Por favor indique en cual lista de reproduccion desea agregar la cancion: ";
				cin>>listaAgregar;
				if ((listaAgregar>nTotalListas)||(listaAgregar<1)){
					cout<<"\n\n                  ";
					cout<<"\nIntrodujo un codigo invalido. Por favor intente de nuevo."<<endl;
				} else {
				nombreLista=BuscarNombreLista(lista,listaAgregar,"USUARIO");
				nombreCancion=BuscarNombreCancion(cancion,QuieroOir);
				nombreArtista=BuscarNombreArtista(cancion,QuieroOir);
				BuscarEInsertarTitulo(lista,nombreCancion,nombreArtista,nombreLista);
				BuscarEInsertarRep(cancion,nombreLista,nombreCancion);
					cout<<"\n\n                      La cancion ha sido agregada con exito a la lista de reproduccion "<<nombreLista; }
				cout<<"\n\n\n\n                                       ";
				system("pause");
				break;
			}
			case 3:{system("cls");
				BuscaryMostrarCancion(cancion,QuieroOir);
				cout<<"\n\n                                        ";
				system("pause");
				break;
			}
			case 4:{system("cls");
				gotoxy(20,8);
				BuscaryModificarCancion(cancion,QuieroOir);
				CambioEnArchivos(lista,cancion,titulo,rep,punt_nod);
				cout<<"\n\n                                        ";
				system("pause");
				opcionVerCancion=5;
				break;
			}
			case 5:{ 
			 break;
			}
		}
	
}while (opcionVerCancion!=5);
}

void MenuVerListasDeReproduccion(){
do{
	system("cls");
	int x = 38;
	int y = 7;
	gotoxy(x,y);
	cout<<" _____________________.:M E N U:.____________________"<<"\n";
	gotoxy(x,y+1);
	cout<<"|                                                    |"<<"\n";
	gotoxy(x,y+2);
	cout<<"|             1. Ver canciones de la lista           |"<<"\n";
	gotoxy(x,y+3);
	cout<<"|           2. Agregar canciones a la lista          |"<<"\n";
	gotoxy(x,y+4);
	cout<<"|          3. Eliminar canciones de la lista         |"<<"\n";
	gotoxy(x,y+5);		
	cout<<"|          4. Buscar una cancion de la lista         |"<<"\n";
	gotoxy(x,y+6);
	cout<<"|   5. Reproducir todas las canciones de la lista.   |"<< "\n";
	gotoxy(x,y+7);
	cout<<"|              6. Volver al menu anterior.           |"<< "\n";
	gotoxy(x,y+8);
	cout<<"|____________________________________________________|"<<"\n\n";
	gotoxy(x-4,y+10);
	fflush(stdin);
	cout<< "Por favor introduzca la opcion que desea realizar: ";
	cin >> opcionVerLista;	
	
	switch(opcionVerLista){
		case 1: { system("cls");
			nTotalCanciones=MostrarNombresCancionesListas(lista,listaOir,"USUARIO");
			fflush(stdin);
				cout<< "\n                               Introduzca el codigo numerico de la cancion seleccionada: ";
				cin>> QuieroOir;
				if ((QuieroOir>nTotalCanciones) || (QuieroOir<1)){
				
					cout<<"\n                                Introdujo un codigo invalido. Por favor intente de nuevo."<<endl;
				}else{
				nombreLista=BuscarNombreLista(lista,listaOir,"USUARIO");
				nombreCancion=BuscarNombreCancionLista(lista,QuieroOir,nombreLista);
				QuieroOir=NumeroCancion(cancion,nombreCancion);	
				MenuVerCanciones(); }
				cout<<"\n\n                                    ";
				system("pause");
			break;
		}
		
		case 2:{ system("cls");
				MostrarNombresCanciones(cancion);
				fflush(stdin);
				cout<< "Introduzca el codigo numerico de la cancion que desea agregar a la lista: ";
				cin>>cancionAgregarLista;
				if ((cancionAgregarLista>nTotalListas)||(cancionAgregarLista<1)){
					cout<<"\n\n                  ";
					cout<<"\nIntrodujo un codigo invalido. Por favor intente de nuevo."<<endl;
				} else {
				nombreLista=BuscarNombreLista(lista,listaOir,"USUARIO");
				nombreCancion=BuscarNombreCancion(cancion,cancionAgregarLista);
				nombreArtista=BuscarNombreArtista(cancion,cancionAgregarLista);
				BuscarEInsertarTitulo(lista,nombreCancion,nombreArtista,nombreLista);
				BuscarEInsertarRep(cancion,nombreLista,nombreCancion); }
				cout<<"\n\n                                      ";
				system("pause");
			break;
		}
		
		case 3:{ system("cls");
				nTotalListas=MostrarNombresCancionesListas(lista,listaOir,"USUARIO");
				fflush(stdin);
				cout<< "\n\n\n\n\n Introduzca el codigo numerico de la cancion que desea eliminar de la lista: ";
				cin>>cancionEliminarLista;
				if ((cancionEliminarLista>nTotalListas)||(cancionEliminarLista<1)){
					cout<<"\n\n                  ";
					cout<<"\nIntrodujo un codigo invalido. Por favor intente de nuevo."<<endl;
				} else {
				nombreLista=BuscarNombreLista(lista,listaOir,"USUARIO");
				nombreCancion=BuscarNombreCancionLista(lista,cancionEliminarLista,nombreLista);
				BuscarYEliminarTitulo(lista,nombreCancion,nombreLista);
				BuscarYEliminarRep(cancion,nombreLista,nombreCancion); }
				cout<<"\n\n                                          ";
				system("pause");
			break;
		}
		
		case 4:{ system("cls");
				fflush(stdin); 
				cout<<"Por favor indique el nombre de la cancion que desea buscar dentro de la lista: "<<endl;
				cout<<"Tenga en cuenta que para encontrar la cancion, esta debe estar escrita EXACTAMENTE igual. "<<endl;
				getline(cin,nombreCancion);
				Mayusculas(nombreCancion);
				nombreLista=BuscarNombreLista(lista,listaOir,"USUARIO");
				system("cls");
					if((BuscadorDeCancionesLista(lista,nombreLista,nombreCancion))==true){
					nTotalCanciones=MostrarCancionesBuscadorLista(lista,nombreLista,nombreCancion);
					cout<<"\n\nPor favor indique el codigo numerico de la cancion que desea ver: "<<endl;
					cin>>cancionBuscar;
					if ((cancionBuscar>nTotalCanciones)||(cancionBuscar<1)){
					cout<<"\n\n                  ";
					cout<<"\nIntrodujo un codigo invalido. Por favor intente de nuevo."<<endl;
				} else {
					QuieroOir=NumeroCancionBuscador(cancion,cancionBuscar,nombreCancion);
					MenuVerCanciones(); }

				} else {
					cout<<"La cancion ingresada no se encuentra dentro de esta lista de reproduccion. Disculpe las molestias."<<endl;
				}
				cout<<"\n\n                                      ";
				system("pause");
			break;
		}
		
		case 5:{ nTotalCanciones=MostrarNombresCancionesListas(lista,listaOir,"USUARIO");
				nombreLista=BuscarNombreLista(lista,listaOir,"USUARIO");
				int num=1;
				while(num<=nTotalCanciones){
				system("cls");
				nombreCancion=BuscarNombreCancionLista(lista,num,nombreLista);
				QuieroOir=NumeroCancion(cancion,nombreCancion);	
				CancionAReproducir(cancion,QuieroOir);
				ArtistaAReproducir(cancion,QuieroOir);
				Reproduccion(cancionAux,artistaAux);
				ReproducirCancion(cancion,QuieroOir);
				AgregarPilaCanciones(pilaCanciones,cancion,QuieroOir); 
				num++;
				}
				cout<<"\n\n\n\n\n\n\n\n\n\n\n\n                                         ";
				system("pause");
			break;
		}
		case 6: {
			break;
		}
	}
	
	}while(opcionVerLista!=6);
}


void MenuListasReproduccion(){
	string nombreNuevaLista;
	int listaEliminar;
do{
	system("cls");
	int x = 38;
	int y = 7;
	gotoxy(x,y);
	cout<<" _______________.:M E N U:._______________"<<"\n";
	gotoxy(x,y+1);
	cout<<"|                                         |"<<"\n";
	gotoxy(x,y+2);
	cout<<"|     1. Ver listas de reproduccion.      |"<<"\n";
	gotoxy(x,y+3);
	cout<<"|   2. Crear una lista de reproduccion.   |"<<"\n";
	gotoxy(x,y+4);
	cout<<"|   3. Eliminar listas de reproduccion.   |"<<"\n";
	gotoxy(x,y+5);		
	cout<<"|   4. Buscar una lista de reproduccion.  |"<<"\n";
	gotoxy(x,y+6);
	cout<<"|      5. Volver al menu principal.       |"<< "\n";
	gotoxy(x,y+7);
	cout<<"|_________________________________________|"<<"\n\n";
	gotoxy(x-4,y+9);
	fflush(stdin);
	cout<< "Por favor introduzca la opcion que desea realizar: ";
	cin >> opcionListaR;
	
	switch(opcionListaR){
			case 1:{system("cls");
				nTotalListas=MostrarListas(lista,"USUARIO");
				fflush(stdin);
				cout<<"\n\n                       ";
				cout<< "Introduzca el codigo numerico de la lista seleccionada: ";
					cin>> listaOir;
				if ((listaOir>nTotalListas)||(listaOir<1)){
					cout<<"\n\n                  ";
					cout<<"\nIntrodujo un codigo invalido. Por favor intente de nuevo."<<endl;
				} else{
				MenuVerListasDeReproduccion();
				cout<<"\n\n                                       ";
				system("pause");
				break;
				}
			}
			case 2:{system("cls");
				fflush(stdin);
				gotoxy(35,3);
				cout<<"Por favor ingrese el nombre de la nueva lista de reproduccion:\n\n                                    ";
				getline(cin,nombreNuevaLista);
				Mayusculas(nombreNuevaLista);
				system("cls");
				if((BuscadorDeListas(lista,nombreNuevaLista))==true){
					cout<<"\n\n                              Lo sentimos, el nombre de esta lista ya fue asignado a otra. "<<endl;
					cout<<"\n\n                                         Intentelo de nuevo con otro nombre. ";	
				} else {
				InsertarLista(lista,nombreNuevaLista,"USUARIO"); 
				cout<<"\n\n                                        Su lista "<<nombreNuevaLista<<" ha sido creada con exito.";
				}
				cout<<"\n\n\n\n                                         ";
				system("pause");
				break;
			}
			case 3:{system("cls");
				nTotalListas=MostrarListas(lista,"USUARIO");
				fflush(stdin);
				gotoxy(35,3);
				cout<<"Introduzca el codigo numero de la lista que desea eliminar: ";
				cin>>listaEliminar;
				if ((listaEliminar>nTotalListas)||(listaEliminar<1)){
					cout<<"\n\n                  ";
					cout<<"\nIntrodujo un codigo invalido. Por favor intente de nuevo."<<endl;
				} else {
				EliminarLista(lista,listaEliminar); }
				cout<<"\n\n                                       ";
				system("pause");
				break;
			}
			case 4:{system("cls");
				fflush(stdin); 
				gotoxy(30,3);
				cout<<"Por favor indique el nombre de la lista que desea buscar: "<<endl;
				gotoxy(20,4);
				cout<<"Tenga en cuenta que para encontrar la lista, esta debe estar escrita EXACTAMENTE igual. "<<endl;
				getline(cin,nombreLista);
				Mayusculas(nombreLista);
				system("cls");
				if((BuscarLista(lista,nombreLista))==true){
					nTotalCanciones=MostrarNombresCancionesListasBuscador(lista,nombreLista);
					cout<<"\n\n                 Por favor indique el codigo numerico de la cancion que desea ver: "<<endl;
					cin>>cancionBuscar;
					if ((cancionBuscar>nTotalCanciones)||(cancionBuscar<1)){
					cout<<"\n\n                  ";
					cout<<"\nIntrodujo un codigo invalido. Por favor intente de nuevo."<<endl;
				} else {
					nombreCancion=NombreCancionListaBuscador(lista,cancionBuscar,nombreLista);
					nombreArtista=NombreArtistaListaBuscador(lista,cancionBuscar,nombreLista);
					QuieroOir=NumeroCancionBuscadorListas(cancion,nombreCancion,nombreArtista);
					MenuVerCanciones(); }

				} else {
					cout<<"\n\n                    La lista ingresada no se encuentra dentro de Musify. Disculpe las molestias"<<endl;
				}
				
				cout<<"\n\n                                       ";
				system("pause");
				break;
			}
			case 5:{ break;
			}
		}
}while(opcionListaR!=5);

}

void MenuCanciones(){
	
do{
	system("cls");
	int x = 41;
	int y = 7;
	gotoxy(x,y);
	cout<<" ____________.:M E N U:._____________"<<"\n";
	gotoxy(x,y+1);
	cout<<"|                                    |"<<"\n";
	gotoxy(x,y+2);
	cout<<"|         1. Ver canciones.          |"<<"\n";
	gotoxy(x,y+3);
	cout<<"|       2. Agregar canciones.        |"<<"\n";
	gotoxy(x,y+4);
	cout<<"|       3. Eliminar canciones.       |"<<"\n";
	gotoxy(x,y+5);		
	cout<<"|       4. Buscar una cancion.       |"<<"\n";
	gotoxy(x,y+6);
	cout<<"| 5. Reproducir todas las canciones. |"<< "\n";
	gotoxy(x,y+7);
	cout<<"|    6. Volver al menu principal.    |"<< "\n";
	gotoxy(x,y+8);
	cout<<"|____________________________________|"<<"\n\n";
	gotoxy(x-4,y+10);
	fflush(stdin);
	cout<< "Por favor introduzca la opcion que desea realizar: ";
	cin >> opcionMenuCancion;
	
	switch(opcionMenuCancion){
			case 1:{system("cls");	
				nTotalCanciones= MostrarNombresCanciones(cancion);
				fflush(stdin);
				cout<< "\n                               Introduzca el codigo numerico de la cancion seleccionada: ";
				cin>> QuieroOir;
				if ((QuieroOir>nTotalCanciones) || (QuieroOir<1)){
				
					cout<<"\n                                Introdujo un codigo invalido. Por favor intente de nuevo."<<endl;
					cout<<"\n\n                                         ";
					system("pause");
					break;
				}else{
				MenuVerCanciones();
				break;
			}
		}
			case 2:{system("cls");
				gotoxy(20,8);
				int contVeces=0;
				string opcion="s";
				SolicitarDatosCancion(punt_nod);
				do{ 
				system("cls");
				fflush(stdin);
				cout<<"\n\n\n\n                       Por favor verifique si los datos de la cancion a agregar son correctos: \n";
				punt_nod->reproducciones=0;
				MostrarInfoCancion(punt_nod);
				fflush(stdin);
				if (contVeces==0){
				cout<<"\n\n\n\n                                     Desea modificar algun campo? (s/n)\n"; cin>>opcion;
				} else {
				cout<<"\n\n\n\n                                     Desea modificar otro campo?(s/n)\n"; cin>>opcion;
			}
				Mayusculas(opcion);
	
				if (opcion == "S"){
				ModificarCampoCancion(punt_nod); 
		contVeces++;
	}
		
	}while(opcion != "N"); 
		InsertarCancion(cancion,punt_nod,lista,0);
		BuscarEInsertarRep(cancion,"GENERAL",punt_nod->nombre);
		CreacionDeTitulos(lista,punt_nod->nombre,punt_nod->cantante,punt_nod->banda,"GENERAL");
				cout<<"\n\n                                 La cancion ha sido agregada con exito a Musify.\n";
				cout<<"\n\n                                     ";                                 
				system("pause");
				break;
			}
			case 3:{system("cls");
				nTotalCanciones= MostrarNombresCanciones(cancion);
				fflush(stdin);
				cout<<"\n\n                               Por favor indique el numero de la cancion que desea eliminar: ";
				cin>>cancionAEliminar;
				if ((cancionAEliminar>nTotalCanciones) || (cancionAEliminar<1)){
				
					cout<<"\n                                Introdujo un codigo invalido. Por favor intente de nuevo."<<endl;
				}else{
				EliminarCancion(cancion,lista,cancionAEliminar);
				cout<<"\n\n                                    La cancion ha sido eliminada con exito de Musify."; }
				cout<<"\n\n                                            ";
				system("pause");
				break;
			}
			case 4:{system("cls");
				fflush(stdin); 
				cout<<"\n                                   Por favor indique el nombre de la cancion que desea buscar: "<<endl;
				cout<<"\n                   Tenga en cuenta que para encontrar la cancion, esta debe estar escrita EXACTAMENTE igual.\n\n                                    ";
				getline(cin,nombreCancion);
				Mayusculas(nombreCancion);
				system("cls");
				if((BuscadorDeCanciones(cancion,nombreCancion))==true){
					cout<<"\n\n\n";
					nTotalCanciones=MostrarCancionesBuscador(cancion,nombreCancion);
					cout<<"\n\n                           Por favor indique el codigo numerico de la cancion que desea ver: ";
					cin>>cancionBuscar;
					if ((cancionBuscar>nTotalCanciones) || (cancionBuscar<1)){
				
					cout<<"\n                                Introdujo un codigo invalido. Por favor intente de nuevo."<<endl;
				} else {
					QuieroOir=NumeroCancionBuscador(cancion,cancionBuscar,nombreCancion);
					MenuVerCanciones(); }

				} else {
					cout<<"\n                   	La cancion ingresada no se encuentra dentro de Musify. Disculpe las molestias."<<endl;
				}
				cout<<"\n\n                                       ";
				system("pause");
				break;
			}
			case 5:{ nTotalCanciones=MostrarNombresCanciones(cancion);
				int n=1;
				while(n<=nTotalCanciones){
				system("cls");
				CancionAReproducir(cancion,n);
				ArtistaAReproducir(cancion,n);
				Reproduccion(cancionAux,artistaAux);
				ReproducirCancion(cancion,n);
				AgregarPilaCanciones(pilaCanciones,cancion,n); 
				n++;
				}
				cout<<"\n\n\n\n\n\n\n\n\n\n\n\n                                         ";
				system("pause");
				break;
			}
			case 6: {
				break;
			}
		}
	
}while(opcionMenuCancion!=6);
}


void MenuAlbumes(){
 do{
	system("cls");
	int x = 38;
	int y = 7;
	gotoxy(x,y);
	cout<<" _______________.:M E N U:._______________"<<"\n";
	gotoxy(x,y+1);
	cout<<"|                                         |"<<"\n";
	gotoxy(x,y+2);
	cout<<"|         1. Ver todos los albumes.       |"<<"\n";
	gotoxy(x,y+3);
	cout<<"|          2. Buscar un album.            |"<<"\n";
	gotoxy(x,y+4);
	cout<<"|       3. Volver al menu principal.      |"<<"\n";
	gotoxy(x,y+5);
	cout<<"|_________________________________________|"<<"\n\n";
	gotoxy(x-4,y+7);
	fflush(stdin);
	cout<< "Por favor introduzca la opcion que desea realizar: ";
	cin >> opcionAlbumes;
	
	switch(opcionAlbumes){
		case 1: { system("cls");
				nTotalListas=MostrarListas(lista,"ALBUM");
				fflush(stdin);
				cout<<"\nPor favor indique cual album desea ver: "<<endl;
				cin>>albumOir;
				system("cls");
				if ((albumOir>nTotalListas)||(albumOir<1)){
					cout<<"\n\n                  ";
					cout<<"\nIntrodujo un codigo invalido. Por favor intente de nuevo."<<endl;
				} else {
				nTotalCanciones=MostrarNombresCancionesListas(lista,albumOir,"ALBUM");
				fflush(stdin);
				cout<<"\nPor favor indique cual cancion de este album quiere ver: ";
				cin>>QuieroOir;
				system("cls");
				if ((QuieroOir>nTotalCanciones)||(QuieroOir<1)){
					cout<<"\n\n                  ";
					cout<<"\nIntrodujo un codigo invalido. Por favor intente de nuevo."<<endl;
				} else {
				nombreLista=BuscarNombreLista(lista,albumOir,"ALBUM");
				nombreCancion=BuscarNombreCancionLista(lista,QuieroOir,nombreLista);
				QuieroOir=NumeroCancion(cancion,nombreCancion);
				MenuVerCanciones(); } 
				}
				cout<<"\n\n"                                       ;
				system("pause");
			break;
		}
		case 2: { system("cls");
				fflush(stdin); 
				cout<<"\n                                   Por favor indique el nombre del album que desea buscar: "<<endl;
				cout<<"\n                   Tenga en cuenta que para encontrar el album, esta debe estar escrita EXACTAMENTE igual.\n\n                                    ";
				getline(cin,nombreAlbum);
				Mayusculas(nombreAlbum);
				system("cls");
				if((BuscadorDeListas(lista,nombreAlbum))==true){
					nTotalCanciones=MostrarNombresCancionesListasBuscador(lista,nombreAlbum);
					cout<<"\n\n                 Por favor indique el codigo numerico de la cancion que desea ver: "<<endl;
					cin>>albumBuscar;
					if ((albumBuscar>nTotalCanciones) || (albumBuscar<1)){
				
					cout<<"\n                                Introdujo un codigo invalido. Por favor intente de nuevo."<<endl;
					
				} else {
					nombreCancion=NombreCancionListaBuscador(lista,albumBuscar,nombreAlbum);
					nombreArtista=NombreArtistaListaBuscador(lista,albumBuscar,nombreAlbum);
					QuieroOir=NumeroCancionBuscadorListas(cancion,nombreCancion,nombreArtista);
					MenuVerCanciones(); }
				} else {
					cout<<"\n                   	El album ingresado no se encuentra dentro de Musify. Disculpe las molestias."<<endl;
				}
				cout<<"\n\n"                                       ;
				system("pause");
			break;
		}
		case 3: {
			break;
		}
	}
	
	
	}while(opcionAlbumes!=3);
}


void MenuArtistas(){
 do{
	system("cls");
	int x = 38;
	int y = 7;
	gotoxy(x,y);
	cout<<" _______________.:M E N U:._______________"<<"\n";
	gotoxy(x,y+1);
	cout<<"|                                         |"<<"\n";
	gotoxy(x,y+2);
	cout<<"|         1. Ver todos los artistas.      |"<<"\n";
	gotoxy(x,y+3);
	cout<<"|          2. Buscar un artista.          |"<<"\n";
	gotoxy(x,y+4);
	cout<<"|       3. Volver al menu principal.      |"<<"\n";
	gotoxy(x,y+5);
	cout<<"|_________________________________________|"<<"\n\n";
	gotoxy(x-4,y+7);
	fflush(stdin);
	cout<< "Por favor introduzca la opcion que desea realizar: ";
	cin >> opcionArtistas;
	
		switch(opcionArtistas){
			case 1:{ system("cls");
				nTotalListas=MostrarListas(lista,"ARTISTA");
				fflush(stdin);
				cout<<"\nPor favor indique cual artista desea ver: "<<endl;
				cin>>artistaOir;
				system("cls");
				if ((artistaOir>nTotalListas)||(artistaOir<1)){
					cout<<"\n\n                  ";
					cout<<"\nIntrodujo un codigo invalido. Por favor intente de nuevo."<<endl;
				} else {
				nTotalCanciones=MostrarNombresCancionesListas(lista,artistaOir,"ARTISTA");
				fflush(stdin);
				cout<<"\nPor favor indique cual cancion de este artista quiere ver: ";
				cin>>QuieroOir;
				system("cls");
				if ((QuieroOir>nTotalCanciones)||(QuieroOir<1)){
					cout<<"\n\n                  ";
					cout<<"\nIntrodujo un codigo invalido. Por favor intente de nuevo."<<endl;
				} else {
				nombreLista=BuscarNombreLista(lista,artistaOir,"ARTISTA");
				nombreCancion=BuscarNombreCancionLista(lista,QuieroOir,nombreLista);
				QuieroOir=NumeroCancion(cancion,nombreCancion);
				MenuVerCanciones(); } 
				}
				cout<<"\n\n"                                       ;
				system("pause");
				break;
			}
			case 2: { system("cls");
				fflush(stdin); 
				cout<<"\n                                   Por favor indique el nombre del artista que desea buscar: "<<endl;
				cout<<"\n                   Tenga en cuenta que para encontrar el artista, esta debe estar escrita EXACTAMENTE igual.\n\n                                    ";
				getline(cin,nombreArtista);
				Mayusculas(nombreArtista);
				system("cls");
				if((BuscadorDeListas(lista,nombreArtista))==true){
					nTotalCanciones=MostrarNombresCancionesListasBuscador(lista,nombreArtista);
					cout<<"\n\n                 Por favor indique el codigo numerico de la cancion que desea ver: "<<endl;
					cin>>artistaBuscar;
					if ((artistaBuscar>nTotalCanciones) || (artistaBuscar<1)){
				
					cout<<"\n                                Introdujo un codigo invalido. Por favor intente de nuevo."<<endl;
					
				} else {
					nombreCancion=NombreCancionListaBuscador(lista,artistaBuscar,nombreArtista);
					nombreArtista=NombreArtistaListaBuscador(lista,artistaBuscar,nombreArtista);
					QuieroOir=NumeroCancionBuscadorListas(cancion,nombreCancion,nombreArtista);
					MenuVerCanciones(); }
				} else {
					cout<<"\n                   	El artista ingresado no se encuentra dentro de Musify. Disculpe las molestias."<<endl;
				}
				cout<<"\n\n"                                       ;
				system("pause");
				break;
			}
			case 3: {
				break;
			}
		}

	}while(opcionArtistas!=3);
}


void MenuGeneros(){
 do{
	system("cls");
	int x = 38;
	int y = 7;
	gotoxy(x,y);
	cout<<" _______________.:M E N U:._______________"<<"\n";
	gotoxy(x,y+1);
	cout<<"|                                         |"<<"\n";
	gotoxy(x,y+2);
	cout<<"|         1. Ver todos los generos.       |"<<"\n";
	gotoxy(x,y+3);
	cout<<"|          2. Buscar un genero.           |"<<"\n";
	gotoxy(x,y+4);
	cout<<"|       3. Volver al menu principal.      |"<<"\n";
	gotoxy(x,y+5);
	cout<<"|_________________________________________|"<<"\n\n";
	gotoxy(x-4,y+7);
	fflush(stdin);
	cout<< "Por favor introduzca la opcion que desea realizar: ";
	cin >> opcionGenero;
	
	switch(opcionGenero){
		case 1: { system("cls");
				nTotalListas=MostrarListas(lista,"GENERO");
				fflush(stdin);
				cout<<"\nPor favor indique cual genero desea ver: "<<endl;
				cin>>generoOir;
				system("cls");
				if ((generoOir>nTotalListas)||(generoOir<1)){
					cout<<"\n\n                  ";
					cout<<"\nIntrodujo un codigo invalido. Por favor intente de nuevo."<<endl;
				} else {
				nTotalCanciones=MostrarNombresCancionesListas(lista,generoOir,"GENERO");
				fflush(stdin);
				cout<<"\nPor favor indique cual cancion de este genero quiere ver: ";
				cin>>QuieroOir;
				system("cls");
				if ((QuieroOir>nTotalCanciones)||(QuieroOir<1)){
					cout<<"\n\n                  ";
					cout<<"\nIntrodujo un codigo invalido. Por favor intente de nuevo."<<endl;
				} else {
				nombreLista=BuscarNombreLista(lista,generoOir,"GENERO");
				nombreCancion=BuscarNombreCancionLista(lista,QuieroOir,nombreLista);
				QuieroOir=NumeroCancion(cancion,nombreCancion);
				MenuVerCanciones(); } 
				}
				cout<<"\n\n"                                       ;
				system("pause");
			break;
		}
		case 2:{ system("cls");
				fflush(stdin); 
				cout<<"\n                                   Por favor indique el nombre del genero que desea buscar: "<<endl;
				cout<<"\n                   Tenga en cuenta que para encontrar el genero, esta debe estar escrita EXACTAMENTE igual.\n\n                                    ";
				getline(cin,nombreGenero);
				Mayusculas(nombreGenero);
				system("cls");
				if((BuscadorDeListas(lista,nombreGenero))==true){
					nTotalCanciones=MostrarNombresCancionesListasBuscador(lista,nombreGenero);
					cout<<"\n\n                 Por favor indique el codigo numerico de la cancion que desea ver: "<<endl;
					cin>>generoBuscar;
					if ((generoBuscar>nTotalCanciones) || (generoBuscar<1)){
				
					cout<<"\n                                Introdujo un codigo invalido. Por favor intente de nuevo."<<endl;
					
				} else {
					nombreCancion=NombreCancionListaBuscador(lista,generoBuscar,nombreGenero);
					nombreArtista=NombreArtistaListaBuscador(lista,generoBuscar,nombreGenero);
					QuieroOir=NumeroCancionBuscadorListas(cancion,nombreCancion,nombreArtista);
					MenuVerCanciones(); }
				} else {
					cout<<"\n                   	El genero ingresado no se encuentra dentro de Musify. Disculpe las molestias."<<endl;
				}
				cout<<"\n\n"                                       ;
				system("pause");
			break;
		}
		case 3:{
			break;
		}
	}


	}while(opcionGenero!=3);
}

void MenuPrincipal(){

do{	
	system("cls");
	int x = 38;
	int y = 7;
	gotoxy(x,y);
	cout<<" _______________.:M E N U:._______________"<<"\n";
	gotoxy(x,y+1);
	cout<<"|                                         |"<<"\n";
	gotoxy(x,y+2);
	cout<<"|              1. Canciones.              |"<<"\n";
	gotoxy(x,y+3);
	cout<<"|     2. Tus listas de reproducciones.    |"<<"\n";
	gotoxy(x,y+4);
	cout<<"|   3. Las canciones mas reproducidas.    |"<<"\n";
	gotoxy(x,y+5);
	cout<<"|        4. Historial de canciones.       |"<<"\n";
	gotoxy(x,y+6);
	cout<<"|                5. Artistas.             |"<<"\n";
	gotoxy(x,y+7);
	cout<<"|                6. Generos.              |"<<"\n";
	gotoxy(x,y+8);
	cout<<"|                7. Albumes.              |"<<"\n";
	gotoxy(x,y+9);
	cout<<"|                 8. Salir                |"<<"\n";
	gotoxy(x,y+10);
	cout<<"|_________________________________________|"<<"\n\n";
	gotoxy(x-4,y+12);
	fflush(stdin);
	cout<< "Por favor introduzca la opcion que desea realizar: ";
	cin >> op;
		switch(op){
			case 1:{system("cls");
				MenuCanciones();
				break;
			}
			case 2:{system("cls");
				MenuListasReproduccion();
				break;
			}
			case 3:{system("cls");
				TopCanciones(cancion, mayor, contTop,0,8);
				cout<<"\n\n                                       ";
				system("pause");
				break;
			}
			case 4:{system("cls");
				gotoxy(20,8);
				MostrarPila(pilaCanciones);
				cout<<"\n\n                                       ";
				system("pause");
				break;
			}
				case 5:{system("cls");
				MenuArtistas();
				cout<<"\n\n                                       ";
				system("pause");
				break;
			}
			case 6:{system("cls");
				MenuGeneros();
				cout<<"\n\n                                       ";
				system("pause");
				break;
			}
			case 7:{system("cls");
				MenuAlbumes();
				cout<<"\n\n                                       ";
				system("pause");
				break;
}
			case 8:{ AgregarCancionArchivo(lista,cancion);
				break;
			}
		}

} while(op!=8);
}

int main() {
	system("color 0D");
	gotoxy(32,11);
	Intro();
	CrearListasDesdeArchivos(cancion,lista,rep,titulo,punt_nod);
	MenuPrincipal();
	SacarPila(pilaCanciones);
	MensajeDespedida();
cout<<"\n\n\n\n\n\n\n                                           ";	
system("pause");
return 0;
}
