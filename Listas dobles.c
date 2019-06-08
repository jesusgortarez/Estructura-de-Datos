#include <stdio.h>
#include <stdlib.h>

typedef struct N{
    int dato;
    struct Nodo *adelante;
    struct Nodo *atras;
}Nodo;

Nodo* crearNodo(int);
void InsertarAelante(Nodo** anterior, int);
void InsertarAtras(Nodo** cabeza, int);
void Insertar(Nodo** cabeza, int testigo, int);

int main(){
    Nodo *cabeza;
    cabeza = NULL;


return 0;
}


Nodo* crearNodo(int x){
    Nodo *a;
    a=(Nodo*)malloc(sizeof(Nodo));
    a->dato=x;
    a->adelante=NULL;
    a->atras=NULL;
    return a;
}

void InsertarAelante(Nodo** anterior, int entrada){
    Nodo *nuevo;
    nuevo=crearNodo(entrada);
    nuevo->adelante= *anterior;
    nuevo->atras=NULL;
    *anterior=nuevo;
}

void InsertarAtras(Nodo** cabeza, int entrada){
    Nodo *nuevo;
    nuevo=crearNodo(entrada);
    nuevo->atras= *cabeza;
    nuevo->adelante=NULL ;
    *cabeza=nuevo;
}

void Insertar(Nodo** cabeza, int testigo, int entrada){
	Nodo *nuevo, *anterior, *posicon;
    int encontrado=0;
	nuevo=crearNodo(entrada);
	if(*cabeza==NULL)
		*cabeza=nuevo;
	else{
		encontrado=0;
		anterior= *cabeza;
		while((anterior!=NULL)&&encontrado==0){
			if(anterior->dato!=testigo&&posicon->dato!=NULL){
				anterior=anterior->adelante;
				posicon=anterior->adelante;
			} else
				encontrado=1;
		}

		if(encontrado==1){
            nuevo->adelante=anterior->adelante;
            nuevo->atras=anterior;
            anterior->adelante=nuevo;
            posicon=nuevo->adelante;
            posicon->atras=nuevo;
        }
        else
            printf("No se encontro el elemento\n");
	}
}
