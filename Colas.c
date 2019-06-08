#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento{
    int dato;
    struct Elemento* siguiente;
}Nodo;

Nodo* crearNodo(int);
void Insertar(Nodo** cabeza, int);
void Eliminar (Nodo** cabeza);
int VerificarCola(Nodo** cabeza);
void TamanoCola(Nodo** cabeza);
void frente(Nodo** cabeza);

int main(){

    Nodo *cabeza;
    cabeza = NULL;

return 0;
}


Nodo* crearNodo(int x){
    Nodo *a;
    a=(Nodo*)malloc(sizeof(Nodo));
    a->dato=x;
    a->siguiente=NULL;
    return a;
}

void Insertar(Nodo** cabeza, int entrada){
    Nodo *nuevo;
    nuevo=crearNodo(entrada);
    nuevo->siguiente= *cabeza;
    *cabeza=nuevo;
}

void Eliminar (Nodo** cabeza){
	Nodo* actual, *anterior, *antes;
	actual= *cabeza;

	while(actual!=NULL){
        antes=anterior;
		anterior=actual;
        actual=actual->siguiente;
	}
	antes->siguiente=NULL;
	free(anterior);
}

int VerificarCola(Nodo** cabeza){
    Nodo *Cola;
    Cola=*cabeza;
    if(Cola==NULL)
        return 0;
    else
        return 1;
}

void TamanoCola(Nodo** cabeza){
    Nodo *despues;
    int cont=0;
    if(*cabeza == NULL)
		printf("La cola esta vacia");
	else{
        despues= *cabeza;
		while(despues!=NULL){
            despues=despues->siguiente;
			cont++;
        }
        printf("la cola contiene %d elementos\n",cont);
	}
}

void frente(Nodo** cabeza){
    Nodo *despues, *anterior;

    if(*cabeza==NULL)
		printf("La cola esta vacia");
	else{
        despues=*cabeza;
        while(despues!=NULL){
            anterior=despues;
            despues=despues->siguiente;
        }
        printf("El elemento Frente es %d\n", anterior->dato);
	}
}
