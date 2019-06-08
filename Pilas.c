#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento{
    int dato;
    struct Elemento* siguiente;
}Nodo;

void Cima(Nodo** cabeza);
void TamanoPila(Nodo** cabeza);
int verificaPila(Nodo** cabeza);
void Eliminar(Nodo** cabeza);
void Insertar(Nodo** cabeza, int entrada);
Nodo* crearNodo(int x);

int main(){
    Nodo *cabeza;
    cabeza = NULL;


return 0;
}


Nodo* crearNodo(int x){
    Nodo*a;
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

void Eliminar(Nodo** cabeza){
	Nodo* actual, *anterior;
	actual= *cabeza;
	anterior=NULL;
	if(actual!=NULL){
		if(actual==*cabeza)
            *cabeza=actual->siguiente;
		else
			anterior-> siguiente =actual ->siguiente;
	}
	free(actual);
}

int verificaPila(Nodo** cabeza){
    Nodo *Pila;
    Pila=*cabeza;
    if(Pila==NULL){
        return 0;
    }
    else{
        return 1;
    }
}

void TamanoPila(Nodo** cabeza){
    Nodo *despues;
    int cont=0;
    if(*cabeza == NULL)
		printf("La pila esta vacia");
	else{
        despues= *cabeza;
		while(despues!=NULL){
            despues=despues->siguiente;
			cont++;
        }
        printf("la pila contiene %d elementos\n",cont);
	}
}

void Cima(Nodo** cabeza){
    Nodo *elemento;
    elemento=*cabeza;
    if(*cabeza==NULL)
		printf("La pila esta vacia\n");
	else
        printf("El elemento de la cima es %d\n",elemento->dato);
}
