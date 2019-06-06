#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int total=0,id=0;

typedef struct Agenda{
    int id;
    char nombre[30];
    char apellido[30];
    int edad;
    int telefono;
};

enum boolean{
    false,true
};

typedef struct Nodo{
    struct Agenda datos;
    struct Nodo *siguiente;
}Nodo;

Nodo* crearNodo(struct Agenda x){
    Nodo *p;
    p = (Nodo*)malloc(sizeof(Nodo));
    p-> datos = x;
    p->siguiente=NULL;
    return p;
}

int verificaLista(Nodo** cabeza){
    Nodo *ultimo;
    ultimo = *cabeza;
    if(ultimo == NULL){
        return false;
    }
    else{
        return true;
    }
}

void insertarPrimero(Nodo** cabeza, struct Agenda dato){
    Nodo *nuevo;
    nuevo = crearNodo(dato);
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
}

void eliminar (Nodo** cabeza, int entrada){
	Nodo* actual, *anterior;
	int encontrado=0;


	actual = *cabeza; anterior = NULL;
	while((actual != NULL) && (encontrado==0)){
		if(actual->datos.id == entrada){
            encontrado=1;
		}
		if(encontrado==0){
			anterior = actual;
			actual = actual-> siguiente;
		}
	}
	if(actual == NULL){
        printf("NO SE ENCONTRO EL ID\n");
	}
	if(actual != NULL){
		if(actual == *cabeza){
			*cabeza  = actual ->siguiente;
		}
		else{
			anterior-> siguiente =actual ->siguiente;
			printf("OBJETIVO ELIMINADO\n");
		}
	}

	free(actual);
	getch();
}


void imprimirDatos(Nodo* cabeza){
    int i, j;
    Nodo* ptr;
    for(ptr = cabeza; ptr;){
        printf("id: %d\n", ptr->datos.id);
        printf("Nombre: ");
        for(i=0; i<strlen(ptr->datos.nombre);i++){
            printf("%c", ptr->datos.nombre[i]);
        }
        printf("\n");
        printf("Apellido: ");
        for(j=0; j<strlen(ptr->datos.apellido);j++){
            printf("%c", ptr->datos.apellido[j]);
        }
        printf("\n");
        printf("Edad: %d\n", ptr->datos.edad);
        printf("Num. Telefono: %d\n", ptr->datos.telefono);

        ptr = ptr->siguiente;
    }

    getch();
}

void insertarDatos(Nodo** cabeza){
    struct Agenda usuario;

    fflush(stdin);
    printf("Dame un nombre: ");
    gets(usuario.nombre);
    fflush(stdin);
    printf("Dame un apellido: ");
    gets(usuario.apellido);
    fflush(stdin);
    printf("Dame la edad: ");
    scanf("%d", &usuario.edad);
    printf("Dame el numero de telefono: ");
    scanf("%d", &usuario.telefono);
    usuario.id = id;

    insertarPrimero(cabeza, usuario);
    fflush(stdin);

}

main(){
    Nodo *cabeza, *ptr;
    int opcion, i;

	cabeza = NULL;


	do{
        printf("Que decea hacer: Agregar datos(1) Imprimir datos(2) Eliminar ID(3)Salir(Cualquier otro numero)\n");
        scanf("%d",&opcion);
		switch(opcion){

			case 1: insertarDatos(&cabeza);
                    total++;
                    id++;
					break;
			case 2: imprimirDatos(cabeza);
					break;
			case 3: printf("Dame el id: ");
                    scanf("%d", &i);
                    eliminar(&cabeza, i);
                    total--;
					break;

		}
	}while(opcion!=4);

}
