#include "artista.h" //Incluimos todas las librerï¿œas,
#include<string>
#include<iostream>
#include<list>
using namespace std; // Espacio de nombres para la entrada y salida de datos

//Constructor de vacio de Artista
Artista::Artista()
{
    _nombre="Sin nombre";
    _biografia="Sin biografia";
}

// Constructor parametrizado de la clase Artista
// El constructor recibe dos datos que proporcionan los parametros
// para el nombre y la biografia. Con ellos inicializa los miembros datos.
// Const quiere decir que no se puede cambiar dentro del codigo

Artista::Artista(const char*nombre,const char* biografia)
{
    _nombre=nombre;
    _biografia=biografia;
}
// Funcion Editar de la clase Artista
// Funcion que sirve para modificar los datos del Artista
// No es necasario pasarle datos ya que tiene acceso a los miembros dato
void Artista::editar()
{
    char seleccion;
    do
    {//En esta parte se desplegan los menues, y se ejecutan las opciones seleccionadas
        cout<<"---------------------------------------------------"<<endl;
        cout<<"Â¿Que dato desea editar del artista?:"<<endl;
        cout<<"1-Editar datos del artista"<<endl;
        cout<<"2-AÃ±adir/Editar discografia del artista"<<endl;
        cout<<"3-AÃ±adir/Editar conciertos del artista"<<endl;
        cin>>seleccion;
        switch (seleccion)
        {
        case '1':
        {
            cin.ignore();
            cout<<"Introduzca nuevo nombre: ";    //se pide por teclado un nombre y la biografia
            getline(cin,_nombre);
            cout<<"Introduzca su nueva biografia: ";
            getline(cin,_biografia);
            break;
        }
        case '2':
        {
            cin.ignore();
            cout<<"Â¿Desea editar discos existentes o crear un nuevo disco?:"<<endl;
            cout<<"1-Editar discos"<<endl;
            cout<<"2-Nuevo disco"<<endl;
            cin>>seleccion;
            switch(seleccion)
            {
            case '1':
            {
                if (discografia.size()==0) //Si el tamano de nuestra lista de discos es cero. El comando 'size' sirve para
                                           //saber el tamano del vector
                {
                    cout<<"Este artista no tiene discos para editar"<<endl;
                    break;
                }
                else //Si no es cero
                {
                    unsigned int opcion; //Una variable declarada unsigned siempre empleará valores enteros positivos, nunca negativos.
                    list<Disco>::iterator disc; //Se crea un iterator para recorrer 'Disco'
                    disc=discografia.begin(); //disc apunta al primer elemento de la lista de discos
                    cout<<"---------------------------------------------------"<<endl;
                    cout<<"Los discos de este artista/grupo son:"<<endl;
                    for(unsigned int i=0;i<discografia.size();i++) //Mediante el bucle for, mostramos todos los discos guardados
                    {                                              //y se muestran por pantalla
                        cout<<i+1<<"-";
                        disc->mostrar_disco(); //Se llama a la función mostrar_disco () de la clase 'Disco' y aparece el nombre
                        cout<<endl;            //de cada disco
                        disc++;                //para ir pasando al siguiente disco
                    }
                    cout<<"Seleccione disco para editar: ";
                    cin>>opcion;
                    if(opcion>discografia.size()||opcion<1)
                    {
                        cout<<"Valor incorrecto"<<endl;
                        break;
                    }
                    else
                    {
                        disc=discografia.begin();
                        for(unsigned int i=0;i<opcion-1;i++)
                        {
                            disc++;
                        }
                        disc->editar();
                    }
                }
                break;
            }
            case '2':
            {
                Disco d;
                d.nuevo();
                discografia.push_back(d);
                break;
            }
            default:
            {
                cout<<"Opcion incorrecta"<<endl;
                break;
            }
            }
            break;
        }
        case '3':
        {
            cin.ignore();
            cout<<"Â¿Desea editar conciertos existentes o crear un nuevo concierto?:"<<endl;
            cout<<"1-Editar conciertos"<<endl;
            cout<<"2-Nuevo concierto"<<endl;
            cin>>seleccion;
            switch(seleccion)
            {
            case '1':
            {
                if (conciertos.size()==0)
                {
                    cout<<"Este artista/grupo no tiene conciertos para editar"<<endl;
                    break;
                }
                else
                {
                    unsigned int opcion; //Una variable que declares unsigned siempre empleará valores enteros positivos, nunca negativos.
                    list<Concierto>::iterator conc; //Se crea un iterator para recorrer 'Concierto'
                    conc=conciertos.begin(); //conc apunta al primer elemento de la lista de conciertos
                    cout<<"---------------------------------------------------"<<endl;
                    cout<<"Los conciertos de este artista/grupo son:"<<endl;
                    for(unsigned int i=0;i<conciertos.size();i++)
                    {
                        cout<<i+1<<"-";
                        conc->mostrar_concierto();
                        cout<<endl;
                        conc++;
                    }
                    cout<<"Seleccione concierto para editar: ";
                    cin>>opcion;
                    if(opcion>conciertos.size()||opcion<1)
                    {
                        cout<<"Valor incorrecto"<<endl;
                        break;
                    }
                    else
                    {
                        conc=conciertos.begin();
                        for(unsigned int i=0;i<opcion-1;i++)
                        {
                            conc++;
                        }
                        conc->editar();
                    }
                }
                break;
            }
            case '2':
            {
                Concierto c;
                c.nuevo();
                conciertos.push_back(c);
                break;
            }
            default:
            {
                cout<<"Opcion incorrecta"<<endl;
                break;
            }
            }
            break;
        }
        default:
        {
            cout<<"Valor incorrecto"<<endl;
            break;
        }
        }
        cout<<"Â¿Desea seguir editando este artista? (1 si, otra tecla no) ";
        cin>>seleccion;
    }
    while(seleccion=='1');
}
// Funcion MostrarDatos de la clase Artista
// Funcion que mostraria los datos del Artista
// No es necasario pasarle datos ya que tiene acceso a los miembros dato
void Artista::mostrar_datos()
{
    char opcion;
    cout<<"---------------------------------------------------"<<endl;
    cout<<"Nombre: "<<_nombre<<endl;
    cout<<"Biografia: "<<_biografia<<endl;
    cout<<"Numero de discos: "<<discografia.size()<<endl;
    cout<<"---------------------------------------------------"<<endl;
    cout<<"Â¿Desea ver la informacion de los discos? (s/n)";
    cin>>opcion;
    if (opcion=='s')
    {
        if (discografia.size()==0) //Si el tamano de nuestra lista de discos es cero. El comando 'size' sirve para
                                   //saber el tamano del vector
        {
            cout<<"Este Artista/Grupo no tiene discos registrados"<<endl;
        }
        else //Si no es cero
        {
        list<Disco>::iterator it; //Se crea un iterator para recorrer 'Disco'
        it=discografia.begin(); //it apunta al primer elemento de la lista de discos
        cout<<"Los discos de "<<_nombre<<" son: "<<endl;
        for (unsigned int i=0; i<discografia.size();i++)     //Se visualizan todos los discos que tenga el artista
        {
            cout<<"---------------------------------------------------"<<endl;
            cout<<"Disco "<<i+1<<": "<<endl;
            it->mostrar_datos();
            it++;
        }
        }
    }
    cout<<"Â¿Desea ver la lista de conciertos? (s/n)";
    cin>>opcion;
    if (opcion=='s')
    {
        if (conciertos.size()==0)
        {
            cout<<"Este Artista/Grupo no tiene conciertos registrados"<<endl;
        }
        else
        {
        list<Concierto>::iterator it;
        it=conciertos.begin();
        cout<<"Los proximos conciertos de "<<_nombre<<" son: "<<endl;
        for (unsigned int i=0; i<conciertos.size();i++)
        {
            cout<<"---------------------------------------------------"<<endl;
            cout<<"Concierto "<<i+1<<": "<<endl;
            it->mostrar_datos();
            it++;
        }
        }
    }
}
void Artista::nuevo()
{
    cin.ignore();
    char opcion;
    cout<<"Introduzca nombre: ";    //se pide por teclado un nombre y la biografï¿œa
    getline(cin,_nombre);
    cout<<"Introduzca su biografia: ";
    getline(cin,_biografia);
    cout<<"Â¿Quiere crear tambien los discos? (s/n)";
    cin>>opcion;
    if (opcion=='s')
    {
        int i=1;
        while (opcion=='s')
        {
        cout<<"Creando disco "<<i<<endl;
        Disco b;
        b.nuevo();
        discografia.push_back(b);
        cout<<"Â¿Desea crear otro disco? (s/n)";
        cin>>opcion;
        i++;
        }
    }
    cout<<"Â¿Quiere crear los conciertos? (s/n)";
    cin>>opcion;
    if (opcion=='s')
    {
        int i=1;
        while (opcion=='s')
        {
        cout<<"Creando concierto "<<i<<endl;
        Concierto c;
        c.nuevo();
        conciertos.push_back(c);
        cout<<"Â¿Desea crear otro concierto? (s/n)";
        cin>>opcion;
        i++;
        }
    }
    cout<<"Artista creado correctamente"<<endl;
}
void Artista::mostrar_artista() //Este metodo sirve para mostrar los artistas cuando estemos en la Playlist
{
    cout<<_nombre;
}
/*
scan_fav(): En esta parte, llamamos
Argumentos: int &busqueda: busca el elemento pasado por parametro para su comparacion.
Return:	void
*/
void Artista::scan_fav(int& contador)
{
    list<Disco>::iterator disc;
    disc=discografia.begin();
    for (unsigned int i=0;i<discografia.size();i++)
    {
        disc->scan_fav(contador);
        disc++;
    }
}
void Artista::scan_rep(list<Cancion>& top10)
{
    list<Disco>::iterator disc;
    disc=discografia.begin();
    for (unsigned int i=0;i<discografia.size();i++)
    {
        disc->scan_rep(top10);
        disc++;
    }
}
/*
buscar(): Sirve para buscar una artista. El usuario introduce un artista y se busca si hay coincidencias
          Para encontrar el artista es suficiente que la clave de búsqueda coincida con una parte del nombre
          del artista. Esto se hace comparando caracter por caracter.
          Ej:
          Si hemos introducido para buscar lo siguiente:
          A r t i s  \0
          Y tenemos un artista registrado llamado:
          A r t i s t a \0
          Nos aparece que hemos encontrado a A r t i s t a\0
          Vamos comparando las dos cadenas caracter por caracter, y si coinciciden, se pasa al aiguiente.
          Si se llega a \0 quiere decir el fin de cada cadena.
Argumentos: string &busqueda: busca el elemento pasado por parametro para su comparacion.
Return:	void
*/
void Artista::buscar(string &busqueda)
{
    string auxiliar;            //Buscamos nombres de artista que contengan la clave de busqueda
    auxiliar=_nombre;
    unsigned int i=0,a=0;
    while (busqueda[i]!='\0'&&auxiliar[a]!='\0')    //Esta es la implementacion, vamos comparando las dos cadenas
    {
        if(busqueda[i]==auxiliar[a])        //Si el primer caracter de busqueda coincide pasa al siguiente
        {
                i++;
                a++;
        }
        else
        {
            a++;        //En cuanto algun caracter no coincida volvera a buscar la clave desde el principio
            i=0;
        }

    }
    if(auxiliar[a]=='\0'&&busqueda[i]!='\0') //Si las dos cadenas han llegado al final
    {i=0;}
    if (i!=0)   //Si la clave coincide entonces muestra toda la info del artista
    {
        cout<<"---------------------------------------------------"<<endl;
        cout<<"-"<<_nombre<<endl;
        list<Disco>::iterator disc;
        disc=discografia.begin();
        for(unsigned int n=0;n<discografia.size();n++)
        {
            disc->mostrar_disco_y_canciones();
            disc++;
        }
    }
    else    //Si la clave no coincide buscamos canciones dentro de ese artista que coincidan con la clave
    {
        list<Disco>::iterator disc;
        disc=discografia.begin();
        for(unsigned int n=0;n<discografia.size();n++)
        {
            disc->buscar(busqueda,_nombre);
            disc++;
        }
    }
}
/*
mostrar_discos(): Esta parte esta implementada para que el usuario elija el disco que desee de un artista para añadirlo
                  luego en la playlist
Return:	void
*/
Cancion* Artista::mostrar_discos() //Esta funcion la usamos para la playlist, en esta parte el usuario selecciona un disco
{                                  //entre los que tenemos registrados
    if(discografia.size()==0) //Comprobamos ei el tamano de nuestra lista de discos es cero. El comando 'size' sirve para
                              //saber el tamano del vector
    {
        cout<<"Este artista/grupo no tiene discos"<<endl;
        return NULL;
    }
    else
    {unsigned int opcion;
    cout<<"Los discos registrados son:"<<endl;
    list<Disco>::iterator disc; //Se crea un iterator para recorrer 'Disco'
    disc=discografia.begin(); //disc apunta al primer elemento de la lista de discos
    for (unsigned int i=0; i<discografia.size();i++)
    {
        cout<<i+1<<"-";
        disc->mostrar_disco();
        cout<<endl;
        disc++;
    }
    cout<<"Para aÃ±adir la cancion primero elija el disco en el que se encuentra: ";
    cin.ignore();
    cin>>opcion;
    cout<<"---------------------------------------------------"<<endl;
    if(opcion>discografia.size()||opcion<1)
    {
        cout<<"Valor incorrecto"<<endl;
    }
    else
    {
            list<Disco>::iterator disc;
            disc=discografia.begin();
            for(unsigned int c=0;c<opcion-1;c++)
            {
                disc++;
            }
            return disc->mostrar_canciones(_nombre);
    }
    }
}
