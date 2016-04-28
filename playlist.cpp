/****************************************************************
   * En esta seccion el usuario puede:
   -Crear una nueva lista de reproduccion, introducciendo canciones. Esto
   se hara recorriendo primero los artistas/grupos, luego sus discos y finalmente sus canciones
   -Se verán los datos de la lista, es decir los datos del artista y del disco
   -Reproducir la lista de reproduccion entera

 ***************************************************************/

#include "playlist.h" //Incluimos todas las librerï¿œas,
#include "artista.h"
#include "grupo.h"
using namespace std;
Playlist::Playlist()
{
    _nombre="Sin nombre";
}

Playlist::Playlist(const char*nombre)
{
    _nombre=nombre;
}
/*
nuevo():  Sirve para añadir canciones a nuestra lista de reproducción. Esta función primero dara la opción de elegir
          entre los artistas registrados. Una vez que se elije el artista, aparecen por pantalla sus discos. Y una vez que
          se ha escogido un disco, aparecen sus canciones. Y se introducen.
Argumentos: list<Artista>&artistas.
            list<Grupo>&grupos
Return:	void
*/
void Playlist::nuevo(list<Artista>&artistas,list<Grupo>&grupos)
{
    char seguir;
    cin.ignore();
    cout<<"¿Cual sera el nombre de la playlist?: ";
    cin>>_nombre;
    cout<<"Introduzca canciones: "<<endl;
    cout<<"---------------------------------------------------"<<endl;
    do
    {
        if(artistas.size()==0&&grupos.size()==0)
        {
            cout<<"No hay artistas registrados"<<endl;
            break;
        }
        else
        {
        unsigned int opcion;
        cout<<"Los artistas y grupos registrados son:"<<endl;
        list<Artista>::iterator ar;
        ar=artistas.begin();
        for (unsigned int i=0; i<artistas.size();i++)
        {
            cout<<i+1<<"-";
            ar->mostrar_artista();
            cout<<endl;
            ar++;
        }
        list<Grupo>::iterator it;
        it=grupos.begin();
        for (unsigned int i=0; i<grupos.size();i++)
        {
            cout<<i+1+artistas.size()<<"-";
            it->mostrar_artista();
            cout<<endl;
            it++;
        }
        cout<<"Para seleccionar canciones primero elija artista: ";
        cin>>opcion;
        cout<<"---------------------------------------------------"<<endl;
        if(opcion>artistas.size()+grupos.size()||opcion<1) //Si introducimos un valor mayor que el numero de artistas y grupos que tenemos
        {                                                  //quiere decir que no hay artistas registrados
            cout<<"Valor incorrecto"<<endl;
            break;
        }
        else
        {
            if(opcion>artistas.size())
            {
                list<Grupo>::iterator it;
                it=grupos.begin();
                for(unsigned int c=artistas.size();c<opcion-1;c++)
                {
                    it++;
                }
                Cancion*aux=it->mostrar_discos();
                if(aux==NULL&&canciones.size()==0)
                {
                    cout<<"Error al aÃ±adir datos"<<endl;
                    break;
                }
                else
                {
                    canciones.push_back(aux);
                }
            }
            else
            {
                list<Artista>::iterator ar;
                ar=artistas.begin();
                for(unsigned int c=0;c<opcion-1;c++)
                {
                    ar++;
                }
                Cancion*aux=ar->mostrar_discos();
                if(aux==NULL&&canciones.size()==0)
                {
                    cout<<"Error al añadir datos"<<endl;
                    break;
                }
                else
                {
                    canciones.push_back(aux);
                }
            }
        }
        }
        cout<<"¿Desea seguir introduciendo canciones? (s/n): ";
        cin>>seguir;
    }
    while(seguir=='s');
    if(canciones.size()!=0)
    {
    cout<<"Playlist creada"<<endl;
    }
}
/*
mostrar_datos():  Sirve para mostrar los datos de las canciones de la playlist
Argumentos: list<Artista> &artistas
            list<Grupo> &grupos
Return:	void
*/
void Playlist::mostrar_datos(list<Artista> &artistas, list<Grupo> &grupos)
{
    char opcion;
    cout<<"---------------------------------------------------"<<endl;
    cout<<"Esta es la lista "<<_nombre<<": "<<endl;
    list<Cancion*>::iterator canc;
    canc=canciones.begin();
    list<Artista>::iterator ar;
    list<Grupo>::iterator gr;
    int existe=0;
    for (unsigned int i=0;i<canciones.size();i++)
    {
        existe=0;
        for (ar=artistas.begin();ar!=artistas.end();ar++)        //Comprobamos que la cancion sea de un artista/Grupo que siga existiendo
        {
            if((*canc)->get_artista()==ar->get_artista())
            {
                cout<<i+1<<"-";
                (*canc)->mostrar_cancion(); //De la cancion que apunta se muestra la cancion con los datos
                (*canc)->mostrar_artista_titulo();
                cout<<endl;
                existe=1;
            }
        }
        for (gr=grupos.begin();gr!=grupos.end();gr++)
        {
            if((*canc)->get_artista()==gr->get_artista())
            {
                cout<<i+1<<"-";
                (*canc)->mostrar_cancion(); //usamos un puntero que va apuntando a esa lista
                (*canc)->mostrar_artista_titulo(); //porque canc es un puntero que apunta a un puntero que apunta a una canción
                                                   //(*canc) es el puntero que apunta a la cancion
                cout<<endl;
                existe=1;
            }
        }
        if(existe==0)
        {
            canciones.erase(canc);
        }
        canc++;
    }
    cout<<"¿Desea reproducir esta lista? (s/n)";
    cin>>opcion;
    if (opcion=='s')
    {
        this->reproducir();
    }
}

/*
reproducir():  Sirve para reproducir una playlist. Nos muestra la duracion total de la lista y tambien
la cancion que se esta reproduciendo en cada momento

Return:	void
*/
void Playlist::reproducir()
{
    cout<<"---------------------------------------------------"<<endl;
    cout<<"Reproduciendo playlist: "<<_nombre<<endl;
    int espera=0; //Lo inicializamos a cero para hacer la suma de duraciones
    list<Cancion*>::iterator canc; //Se crea un iterator para recorrer 'Cancion'
    canc=canciones.begin(); //canc apunta al primer elemento de la lista de canciones
    for(unsigned int i=0;i<canciones.size();i++)
    {
       espera=espera+(*canc)->get_duracion();
       canc++;                                  //Para saber la duracion del disco sumamos las duraciones de cada cancion individual, y al ser atributos privados utilizamos la funcion get_duracion
    }
    cout<<"Duracion total de la playlist: "<<espera/60<<":"<<espera%60<<" minutos"<<endl;    //Operacion que muestra la duracion total en minutos
    canc=canciones.begin();
    for(unsigned int i=0;i<canciones.size();i++)
    {
        (*canc)->reproducir();
        canc++;
          //Esto sirve para mostrar que cancion nos esta reproduciendo en cada momento
    }
    cout<<"Fin de la reproduccion de la playlist"<<endl;
    cout<<"---------------------------------------------------"<<endl;
}
