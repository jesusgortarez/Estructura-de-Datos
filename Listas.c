#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento{
    int dato;
    struct Elemento* siguiente;
}Nodo;

Nodo* crearNodo(int);
void InsertarPrimero(Nodo** cabeza, int );
void InsertarUltimo(Nodo** cabeza, int );
void Insertar(Nodo** cabeza, int , int );
void Eliminar (Nodo** cabeza, int );
void Localizar(Nodo** cabeza, int );
int VerificaLista(Nodo** cabeza);
void TamanoLista(Nodo** cabeza);

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

void InsertarPrimero(Nodo** cabeza, int entrada){
    Nodo *nuevo;
    nuevo=crearNodo(entrada);
    nuevo->siguiente=*cabeza;
    *cabeza=nuevo;
}

void InsertarUltimo(Nodo** cabeza, int entrada){
    Nodo *ultimo;
    ultimo=*cabeza;
    if(ultimo==NULL){
        *cabeza=crearNodo(entrada);
    } else{
        while(ultimo->siguiente){
            ultimo=ultimo->siguiente;
        }
        ultimo->siguiente=crearNodo(entrada);
    }
}

void Insertar(Nodo** cabeza, int testigo, int entrada){
	Nodo *nuevo, *despues;
	int encontrado;
	nuevo=crearNodo(entrada);
	if(*cabeza==NULL){
		*cabeza=nuevo;
	}
	else{
		encontrado=0;
		despues=*cabeza;
		while((despues!=NULL)&&encontrado==0){
			if(despues->dato!=testigo){
				despues=despues->siguiente;
			} else
				encontrado=1;
		}

		if(encontrado==1){
            nuevo->siguiente=despues->siguiente;
            despues->siguiente=nuevo;
        } else{
            printf("Elemento no encontrado\n");
        }
	}
}

void Eliminar (Nodo** cabeza, int entrada){
	Nodo* actual, *anterior;
	int encontrado=0;

	actual=*cabeza;
	anterior=NULL;
	while((actual!=NULL)&&(encontrado==0)){
		if(actual->dato==entrada){
            encontrado=1;
		}
		if(encontrado==0){
			anterior=actual;
			actual=actual->siguiente;
		}
	}
	if(actual!=NULL){
		if(actual==*cabeza)
			*cabeza=actual->siguiente;
		else
			anterior->siguiente=actual->siguiente;
	}
	free(actual);
}

void Localizar(Nodo** cabeza, int testigo){
    Nodo *despues;
    int encontrado=0;
    if(*cabeza==NULL)
		printf("Se encontro el elemento\n");
	else{
        encontrado=0;
		despues= *cabeza;
		while((despues!=NULL)&&encontrado==0){
			if(despues->dato!=testigo)
				despues=despues->siguiente;
			else
				encontrado=1;
		if(encontrado==1)
            printf("Se encontro el elemento\n");
        else
            printf("No se encontro el elemento\n");
        }
    }
}
int VerificaLista(Nodo** cabeza){
    Nodo *Lista;
    Lista= *cabeza;
    if(Lista==NULL)
        return 0;
    else
        return 1;
}

void TamanoLista(Nodo** cabeza){
    Nodo *despues;
    int cont = 0;
    if(*cabeza == NULL)
		printf("la lista contiene %d elementos\n",cont);
	else{
        despues= *cabeza;
		while(despues!=NULL){
            despues=despues->siguiente;
			cont++;
        }
        printf("la lista contiene %d elementos\n",cont);
	}
}
