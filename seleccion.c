#include <stdio.h>

void seleccion(int [],int);

int main(){

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

    seleccion(arreglo,tamano);

    printf ("\nArreglo ordenado:");
    for(i=0;i<tamano;i++){
        printf ("%d",arreglo[i]);
    }
    return 0;
}

void seleccion(int arreglo[],int tamano){
int i,j,temp;
    for(i=0;i<tamano;i++){
        for(j=i;j<tamano;j++){
            if(arreglo[j]<arreglo[i]){
                temp=arreglo[j];
                arreglo[j]=arreglo[i];
                arreglo[i]=temp;
            }
        }
    }
}
