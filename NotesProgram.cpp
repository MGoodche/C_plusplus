#include <iostream.h>
#include <stdlib.h>
#include <string>
const int MAXIMO = 230 ;
//Definición de estructuras
struct Alumno
{
string n_alumno;
int test1,test2;
int parcial, final;
string notaglobal;
};

//Definicion de tipos
typedef Alumno Curso[MAXIMO];
//Prototipos de funciones
void LeerRegistro(Alumno & alu);
void MostrarRegistro(Alumno alu);
void CalcularNotaRegistro(Alumno & alu);
int main()
{
//Declaro un vector para almacenar la información de
//los alumnos
Curso micurso;
int numero;
bool seguir;
int i, elementos; //Numero de alumnos introducidos
seguir = true;
i = 0;
do{
//Lee datos
LeerRegistro(micurso[i]);
//Calcula nota global
CalcularNotaRegistro(micurso[i]);
//Muestro el resultado
MostrarRegistro(micurso[i]);
//Compruebo condicion de salida
if (i > MAXIMO)
seguir = false;
cout << "Para terminar pulse 0. Para continuar
1\n";
cin >> numero;
if (numero == 0)
seguir = false;
i++;
}while (seguir);
elementos = i;
cout << "Notas almacenadas en esta sesion:" << endl;
for (i = 0; i < elementos ; i++)
MostrarRegistro(micurso[i]);
return 0;
}
void LeerRegistro(Alumno &alu)

{

//Leo cada elemento de la estructura de forma
//independiente
cout << "Nombre: " ;
getline(cin,alu.n_alumno);
cout << endl;
cout << "Introduce las calificaciones\n";
cout << "Test 1: ";
cin >> alu.test1;
cout << endl;
cout << "Test 2: " ;
cin >> alu.test2;
cout << endl;
cout << "Parcial: ";
cin >> alu.parcial;
cout << endl;
cout << "Final: ";
cin >> alu.final;
return;
}

//Escribo los datos almacenados en el registro por pantalla

void MostrarRegistro(Alumno alu)

{

cout << "Nombre: ";
cout << alu.n_alumno << endl;
cout << "\t\tCalificaciones: ";
<< alu.parcial << " " << alu.final << endl;
cout << "\t\tCalificacion global: ";
cout << "\t" << alu.notaglobal<< endl;
return;
}

//Calculo la nota final

void CalcularNotaRegistro(Alumno & alu)

{
float notanumerica;
notanumerica = (alu.test1 + alu.test2) * 25 / 20 +
(alu.final / 2 ) + (alu.parcial / 4);
if (notanumerica > 90.0)
alu.notaglobal= "Sobresaliente";
else if (notanumerica > 70.0)
alu.notaglobal= "Notable";
else if (notanumerica > 50.0 )
alu.notaglobal="Aprobado";
else
alu.notaglobal="Suspendido";
return;
}
