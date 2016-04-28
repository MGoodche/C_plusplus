#include <iostream>
#include "operaciones_rectangulo.h"
using namespace std;

int main()
{
unsigned short i=0;
cout << "¿Cuantos rectangulos quieres calcular?";
cin >> i;
Rectangulo r;
for(unsigned short c=0; c<i; c++)
{
cout << endl << "¿Cual es la base del rectangulo " << c+1 << "? ";
cin >> r.ancho;
cout << "¿Cual es la altura del rectangulo " << c+1 << "? ";
cin >> r.alto;
cout << endl << "El area del rectangulo " << c+1 << " es " <<
calcula_area(r) << endl;
cout << "El perimetro del rectangulo " << c+1 << " es " <<
calcula_perimetro(r) << endl;
}
return 0;
}
