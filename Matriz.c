#include <stdio.h>
#include <stdlib.h>


void crearmatriz (int a[11][11], int ren, int col);
 //  int filas = (sizeof(edades)/sizeof(edades[0]));
   // int columnas = (sizeof(edades[0])/sizeof(edades[0][0]));
void imprime (int a[11][11],int ren, int col);
void transpuesta (int a[11][11], int b[11][11], int ren, int col);

main(){

srand (time(NULL));
int i,j,tam,Tamanofilas,Tamanocolumnas,ren,col;
ren=rand()%10+1;
col=rand()%10+1;
int a[11][11],b[11][11];
crearmatriz(a,ren,col);
imprime(a,ren,col);
printf("\n");
transpuesta(a,b,ren,col);
imprime(b,col,ren);
MayorMenor(a,ren,col);
    return 0;

}

void transpuesta (int a[11][11], int b[11][11], int ren, int col) {
   int i,j;
    for (i=0;i<ren;i++) {
        for (j=0;j<col;j++) {
            b[j][i]=a[i][j];
        }
    }
}

void imprime (int n[11][11],int ren, int col){
int i,j;
    for (i=0;i<ren;i++) {
        for (j=0;j<col;j++) {
            printf("%d ",n[i][j]);
        }
        printf("\n");
    }
}

void MayorMenor (int n[11][11],int ren, int col){
int i,j,MA=0,me=50;
    for (i=0;i<ren;i++) {
        for (j=0;j<col;j++) {
            if(MA<n[i][j])
                MA=n[i][j];
            if(me>n[i][j])
             me=n[i][j];
        }
    }
    printf("\nMayor:%d\n",MA);
    printf("Menor:%d",me);
}


void crearmatriz (int a[11][11],int ren, int col) {
int i, j;
    for (i=0;i<ren;i++) {
        for (j=0;j<col;j++) {
            a[i][j]=rand()%10;
        }
    }
}
