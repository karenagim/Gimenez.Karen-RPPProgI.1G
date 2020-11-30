#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    int procesador;
    char marca[20];
    float precio;

}Notebook;

#define TAMNOT 6

/*Crear una función llamada calcularIVA que reciba como
 parámetro el precio bruto de un producto y devuelva el
 valor del impuesto (el IVA es 21%). Realizar la llamada
 desde main. *
*/
float calcularIva(float precio);

/*Crear una función que se llame reemplazarCaracter
que reciba una cadena de caracteres como primer parámetro,
 como segundo parámetro el carácter a reemplazar y como
 tercero el nuevo carácter y devuelva la cantidad de veces
 que se reemplazo el carácter. int reemplazarCaracter(char [],
char, char); *
*/
int reemplazarCaracter(char cadena[], char charReemp, char charNuevo);
/*
Dada la estructura Notebook(id, procesador, marca, precio) generar una función que
 permita ordenar un array de dicha estructura por marca. Ante igualdad de marca deberá
 ordenarse por precio. Hardcodear datos y mostrarlos desde el main.

*/
void ordenarNotebooks(Notebook lista[],int tam);

int main()
{
    char letras[]= {'r', 'e', 'c','u', 'p', 'e', 'r','a','t', 'o', 'r', 'i','o'};
    printf("La letra elegida fue reemplazada : %d veces\n\n",reemplazarCaracter(letras,'e','h'));

    float precioProd = 2000;

    printf("El precio $ %.2f , con el impuesto IVA queda: %.2f\n", precioProd,calcularIva(precioProd));

     Notebook notebooks [TAMNOT]=
     {
         {1, 111,"PCBOX",1500.50},
         {2,222,"SORNY",1800.50},
         {3,777,"COMMODO",3000},
         {4,888,"DELL",7000.80},
         {5,999,"MAC",7500},
         {2, 968,"PCBOX",300.50}
     };


    ordenarNotebooks(notebooks,TAMNOT);
    printf(" ID   Procesador        Marca         Precio\n\n");
    for(int i=0; i<TAMNOT; i++)
    {
        printf(" %d     %d        %6s       %.2f\n", notebooks[i].id, notebooks[i].procesador, notebooks[i].marca, notebooks[i].precio);
    }


    return 0;
}


float calcularIva(float precio)
{
    float impuesto=0;

    if(precio>0)
    {
        impuesto= precio+ (precio*.21);
    }
    return impuesto;

}

int reemplazarCaracter(char cadena[], char charReemp, char charNuevo)
{
    int contador = 0;
    int largo = strlen(cadena);

    for(int i=0; i<largo;i++)
    {
        if(cadena[i]== charReemp)
        {
            cadena[i]= charNuevo;
            contador++;
        }
    }
    return contador;
}

void ordenarNotebooks(Notebook lista[],int tam)
{

    Notebook aux;

    for (int i=0; i<tam-1;i++)
    {
        for(int j=i+1; j<tam;j++)
        {
            if(strcmp(lista[i].marca,lista[j].marca)> 0)
            {
                aux= lista[i];
                lista[i]=lista[j];
                lista[j]= aux;
            }
            else if(strcmp(lista[i].marca,lista[j].marca)==0 && lista[i].precio>lista[j].precio)
            {
                aux= lista[i];
                lista[i]=lista[j];
                lista[j]= aux;
            }
        }
    }
}


