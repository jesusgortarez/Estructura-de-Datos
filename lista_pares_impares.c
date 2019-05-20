#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento{
    int dato;
    struct Elemento* siguiente;
}Nodo;

void insertarPrimero(Nodo** cabeza, int entrada);
Nodo* crearNodo(int x);
void separador(Nodo** cabeza,Nodo** par,Nodo** impar);

int main(){
    int i,d=0;
    Nodo *cabeza,*par,*impar,*ptr;
    cabeza=par=impar=NULL;


    for(i=0;i<5;i++){
        printf("\nDame un valor: ");
        scanf("%d",&d);
        insertarPrimero(&cabeza, d);
    }
    separador(&cabeza,&par,&impar);

    printf("\nPares: ");
    for(ptr=par;ptr;ptr=ptr->siguiente){
        printf("%d ",ptr->dato);
    }
    printf("\nImpares: ");
    for(ptr=impar;ptr;ptr=ptr->siguiente){
        printf("%d ",ptr->dato);
    }
    printf("\n\n");
    return 0;
}

void insertarPrimero(Nodo** cabeza, int entrada){
    Nodo *nuevo;
    nuevo=crearNodo(entrada);
    nuevo->siguiente=*cabeza;
    *cabeza=nuevo;
}


Nodo* crearNodo(int x){
    Nodo *a;
    a=(Nodo*)malloc(sizeof(Nodo));
    a->dato=x;
    a->siguiente=NULL;
    return a;
}

void separador(Nodo** cabeza,Nodo** par,Nodo** impar){
    Nodo*despues;
	despues=*cabeza;
	while(despues != NULL){
        if(despues->dato%2==0) insertarPrimero(par,despues->dato);
		else insertarPrimero(impar,despues->dato);
		despues=despues->siguiente;
    }
}
