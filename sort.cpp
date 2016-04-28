#include <iostream>
#include <iomanip>

int main(){
int j;
int i;
int num;
int a[10]; // mi vector es de tamanio 10
int cambios;
std::cout <<"\n¡Buenas!. Una vez cumplidos los deberes civicos, empezemos el programa.\n";

         for (j = 0; j < 10; j++) //Ciclo de repeticion
             {
              std::cout << "\nIntroduzca el numero " << j + 1 << "\n"; //Pedimos 10 numeros

              std::cin >> a[j];
              }

//Este metodo se basa en realizar sucesivos recorridos del vector. En cada etapa del recorrido
//se intercambian aquellos numeros que se encuentren desordenados
     for (i=1; i<10; i++)
          for (j=0; j<10 - i; j++)
          // ¿ el elemento a[j] es mayor que el a[j +1] ?
               if (a[j] > a[j+1])
                    {
                    /* Intercambiamos */
                    cambios = a[j];
                    a[j] = a[j+1];
                    a[j+1] = cambios;
            }

    std::cout << "\nLos valores ordenados serán : \n";

    for ( i = 0 ; i < 10 ; i++ )
    {
        std::cout << std::setfill ('0') << std::setw (4); //Mostramos el resultado
        
        std::cout << a[i] << "\n";
    }

    return 0;
}
