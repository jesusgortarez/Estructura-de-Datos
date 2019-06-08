#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento{
    int dato;
    struct Elemento* siguiente;
}Nodo;

Nodo* crearNodo(int x){
    Nodo *a;
    a=(Nodo*)malloc(sizeof(Nodo));
    a->dato=x;
    a->siguiente=NULL;
    return a;
}

void insertar(Nodo** cabeza, int entrada){
	Nodo *nuevo, *despues, *posicion;

	nuevo =crearNodo(entrada);
	if(*cabeza == NULL){
		*cabeza = nuevo;
	}
	else if(entrada<(*cabeza)->dato){
        nuevo->siguiente=*cabeza;
        *cabeza = nuevo;
        } else{
            despues=posicion=*cabeza;
            while((despues!=NULL)&&(despues->dato<entrada)){
                posicion= despues;
                despues = despues->siguiente;
            }
            if(entrada>posicion->dato)
                despues = posicion;
            nuevo->siguiente = despues->siguiente;
            despues->siguiente = nuevo;
          }
}

int main(){

    Nodo *cabeza, *ptr;
    cabeza = NULL;
return 0;
}
