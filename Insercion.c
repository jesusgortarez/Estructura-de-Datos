#include <stdio.h>

int main(){

void Insercion(int [],int);

int arreglo[50],tamano,i;

    printf("Dame el tamano del arreglo \n");
    scanf("%d",&tamano);


    printf("Dame el arreglo \n");
    for(i=0;i<tamano;i++){
        scanf("%d",&arreglo[i]);
    }
    printf ("Arreglo:");
    for(i=0;i<tamano;i++){
        printf ("%d",arreglo[i]);
    }

    Insercion(arreglo,tamano);

    printf ("\nArreglo ordenado:");
    for(i=0;i<tamano;i++){
        printf ("%d",arreglo[i]);
    }
    return 0;
}

void Insercion(int arreglo[],int tamano){
int actual, temp, i,j;

    for(i=1;i<tamano;i++){
        actual=arreglo[i];
        for (j=i;j>0;j--){
            if(arreglo[j-1]>actual){
                temp=arreglo[j-1];v
                arreglo[j-1]=actual;
                arreglo[j]=temp;
            }
        }
    }

}
