#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void QuickStort(int [],int);
void qs(int [],int ,int );
int main () {

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

    QuickStort(arreglo,tamano);

    printf ("\nArreglo ordenado:");
    for(i=0;i<tamano;i++){
        printf ("%d",arreglo[i]);
    }
    return 0;
}

void QuickStort(int arreglo[],int tamano){
    qs(arreglo,0,tamano-1);
}

void qs(int arreglo[],int izquierda,int derecha){
    srand (time(NULL));
    int Vderecha,Vizquierda,pivote,temp,random;
    Vderecha=derecha;
    Vizquierda=izquierda;
    //pivote=arreglo[rand()%(Vderecha+1)-Vizquierda];
    pivote=arreglo[(Vizquierda+Vderecha)/2];

    do{
        while(arreglo[Vizquierda]<pivote) Vizquierda++;
        while(arreglo[Vderecha]>pivote) Vderecha--;
        if(Vizquierda<=Vderecha){
            temp=arreglo[Vderecha];
            arreglo[Vderecha]=arreglo[Vizquierda];
            arreglo[Vizquierda]=temp;
            Vizquierda++;
            Vderecha--;
        }
    }while(Vizquierda<=Vderecha);

    if(izquierda<Vderecha){
        qs(arreglo,izquierda,Vderecha);
    }
    if(derecha>Vizquierda){
        qs(arreglo,Vizquierda,derecha);
    }
}
