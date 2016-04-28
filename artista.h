#ifndef ARTISTA_H
#define ARTISTA_H
#include<string>
#include<iostream>
#include<list>
#include"disco.h"
#include"concierto.h"
using namespace std;
/************************************
Clase: Artista
Responsabilidad: -Crear una nuevo artista, editarlo, mostrarlao, marcarlo como
                 favorito y buscar coincidencias.
Colaboración: ninguna
************************************/
class Artista
{
protected: // Datos miembro de la clase "Artista"
           //El acceso protected es equivalente al acceso privado, pero con respecto a las clases derivadas se comporta como publico.
    string _nombre;
    string _biografia;
    list<Disco> discografia; //Se crea una lista 'discografia' con los elementos de Disco
    list<Concierto> conciertos; //Se crea una lista 'conciertos' con los elementos de Concierto
public:
    Artista();  //Constructor vacio
    Artista(const char*nombre,const char* biografia);   //Constructor parametrizado
    void nuevo(); //Se crea un nuevo artista
    void eliminar(); //Se elimina un artista
    void editar(); //Se edita un artista
    void mostrar_datos(); //Se muestran los datos del artista
    void mostrar_artista(); //Se muestra el nombre del artista, esto lo usamos para la playlist
    string get_artista(){return _nombre;} //Devuelve el nombre del artista
    Cancion *mostrar_discos();
    void buscar(string& busqueda); //Para buscar artistas
    void scan_fav(int &contador);
    void scan_rep(list<Cancion> &top10);
    ~Artista(){}           //Destructor
};

#endif // ARTISTA_H
