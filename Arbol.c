#include <stdio.h>
#include <stdlib.h>

struct nodo {
	int dato;
	struct nodo *izdo, *dcho;
};

typedef struct nodo Nodo;

Nodo* crearNodo(int);
void insertar(Nodo** raiz, int);
void eliminar(Nodo** raiz, int);
void reemplazar(Nodo** intermedio);
void buscar(Nodo** raiz, int);
int profundidad(Nodo** raiz);
//Tipos de recorridos
void preorden(Nodo* raiz);
void posorden(Nodo* raiz);
void enorden(Nodo* raiz);

int main(){
	int elemento;
	Nodo* raiz=NULL;
	do{
		printf("Ingrese un dato al arbol menos el 0: ");
		scanf("%d",&elemento);
		insertar(&raiz,elemento);
	}while(elemento!=0);

	printf("Profundidad: %d\n", profundidad(&raiz));
	preorden(raiz);


return 0;


}

Nodo* crearNodo(int x){
	Nodo* a;
	a=(Nodo*)malloc(sizeof(Nodo));
	a->dato=x;
	a->izdo=NULL;
	a->dcho=NULL;
	return a;
}

void insertar(Nodo** raiz, int dato){
	if(!(*raiz))
		*raiz=crearNodo(dato);
	else if(dato<(*raiz)->dato)
		insertar(&(*raiz)->izdo,dato);
	else
		insertar(&(*raiz)->dcho,dato);
}

void eliminar(Nodo** raiz, int dato){
    Nodo* a;
	if(!(*raiz))
		printf("El elemento no se encuentra");
	else if(dato < (*raiz)->dato)
		eliminar(&(*raiz)->izdo,dato);
        else if(dato > (*raiz)->dato)
            eliminar(&(*raiz)->dcho,dato);
            else{
                a=(*raiz);
                if(a->izdo == NULL)
                    (*raiz)=a->dcho;
                else if(a->dcho == NULL)
                    (*raiz)=a->dcho;
                    else
                        reemplazar(&a);
                free(a);
            }
}

void reemplazar(Nodo** intermedio){
	Nodo *a, *p;
	p=*intermedio;
	a=(*intermedio)->izdo;
	while(a->dcho){
		p=a;
		a=a->dcho;
	}
	(*intermedio)-> dato = a ->dato;
	if(p==(*intermedio))
		p->izdo=a-> izdo;
	else
		p->dcho=a->dcho;
	(*intermedio)=a;
}

void buscar(Nodo** raiz, int dato){
    if(!(*raiz))
		printf("El elemento no se encuentra");
	else if(dato<(*raiz)->dato)
		buscar(&(*raiz)->izdo,dato);
        else if(dato > (*raiz)->dato)
            buscar(&(*raiz)->dcho,dato);
	if((*raiz)->dato==dato)
            printf("El elemento se ha encontrado");
}

int profundidad(Nodo** raiz){
    if(!(*raiz))
        return 0;
    else{
        int profundidadI=profundidad(&(*raiz)->izdo);
        int profundidadD=profundidad(&(*raiz)->dcho);
        if(profundidadI>profundidadD)
            return profundidadI+1;
        else
            return profundidadD+1;
    }
}

void preorden(Nodo* raiz){
	if(raiz){
		printf("%d ",raiz->dato);
		preorden(raiz->izdo);
		preorden(raiz->dcho);
	}
}

void posorden(Nodo* raiz){
	if(raiz){
		posorden(raiz->izdo);
		posorden(raiz->dcho);
		printf("%d ",raiz->dato);
	}
}

void enorden(Nodo* raiz){
	if(raiz){
		posorden(raiz->izdo);
		printf("%d ",raiz->dato);
		posorden(raiz->dcho);
	}
}
