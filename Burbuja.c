#include <stdio.h>


void burbuja(int [],int);

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

    burbuja(arreglo,tamano);

    printf ("\nArreglo ordenado:");
    for(i=0;i<tamano;i++){
        printf ("%d",arreglo[i]);
    }
    return 0;
}

void burbuja(int arreglo[],int tamano){
    int temp,i,j;

    for(i=0;i<tamano;i++){
        for(j=0;j<tamano;j++){
			if(arreglo[j]>arreglo[j+1]){
			    temp=arreglo[j+1];
				arreglo[j+1]=arreglo[j];
				arreglo[j]=temp;
			}
		}
	}
}
