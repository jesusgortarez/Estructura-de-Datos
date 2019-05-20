#include <stdio.h>
#include <stdlib.h>

void shell(int [], int);

main(){
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

    shell(arreglo,tamano);

    printf ("\nArreglo ordenado:");
    for(i=0;i<tamano;i++){
        printf ("%d",arreglo[i]);
    }
return(0);
}

void shell(int arreglo[], int tamano){

    int Intervalo,i,j,k,temp;
    Intervalo=tamano/2;
    while(Intervalo>0){
        for(i=Intervalo;i<tamano;i++){
           j=i-Intervalo;
           while(j>=0){
                k=j+Intervalo;
                if(arreglo[j]<=arreglo[k]){
                    j=-1;
                }
                else{
                    temp=arreglo[j];
                    arreglo[j]=arreglo[k];
                    arreglo[k]=temp;
                    i=j-Intervalo;
                }
           }
        }
    Intervalo=Intervalo/2;
    }

}
