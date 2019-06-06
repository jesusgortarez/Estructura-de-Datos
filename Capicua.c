#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento{
    int dato;
    struct Elemento* siguiente;
}Nodo;

Nodo* crearNodo(int x){
    Nodo *p;
    p = (Nodo*)malloc(sizeof(Nodo));
    p->dato=x;
    p->siguiente=NULL;
    return p;
}

void insertar(Nodo** cabeza, int entrada){
    Nodo *nuevo;
    nuevo = crearNodo(entrada);
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
}

int eliminar_pila (Nodo** cabeza){
	Nodo* actual, *anterior;
	int encontrado=0;

	actual = *cabeza; anterior = NULL;
	if(actual != NULL){
		if(actual == *cabeza){
			*cabeza  = actual ->siguiente;
		}
		else{
			anterior-> siguiente =actual ->siguiente;
		}
	}
	return actual -> dato;
	free(actual);
}

int eliminar_cola (Nodo** cabeza){
	Nodo* actual, *anterior, *antes;

	actual = *cabeza;
	while(actual != NULL){
            antes = anterior;
			anterior = actual;
			actual = actual-> siguiente;
	}
	antes -> siguiente = NULL;
	return anterior -> dato;
	free(anterior);
}

main(){
    int num,tam, i, pila, cola;
    Nodo *cabeza_pila, *cabeza_cola;
    cabeza_pila = NULL;
    cabeza_cola = NULL;
    printf("Tamano del numero: ");
    scanf("%d", &tam);

    for(i=0; i<tam; i++){
        printf("Ingresa el dijito %d: ",i+1);
        scanf("%d", &num);
        insertar(&cabeza_pila, num);
        insertar(&cabeza_cola, num);
    }
    for(i=0; i<tam; i++){
        if((eliminar_pila(&cabeza_pila))!=(eliminar_cola(&cabeza_cola))){
            printf("No es un numero capicua");
            return 0;
        }
    }
    printf("Es un numero capicua");
    return 0;
}
