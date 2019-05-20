#include <stdio.h>

struct Libreria{
    char Titulo[20];
    char Autor[20];
    int anio;
};

int main(){
int total=0,i;
int opcion=1;
struct Libreria libro[10];

    do{
        printf("\nLibros totales: %d\n",total);
        printf("Que decea hacer: Agregar libros(1) Imprimir libros(2) Salir(Cualquier otro numero)\n");
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                if(total<11){
                    printf("Titulo del libro: ");
                    scanf("%s",&libro[total].Titulo);
                    printf("Autor del libro: ");
                    scanf("%s",&libro[total].Autor);
                    printf("Fecha del libro: ");
                    scanf("%d",&libro[total].anio);
                    total++;
                }else printf("Libreria llena!");
                break;
            case 2:
                printf("\nTus libros son:\n");
                for(i=0;i<total;i++){
                    printf("Libro numero: %d\n",i+1);
                    printf("Titulo del libro: %s\n",libro[i].Titulo);
                    printf("Autor del libro: %s\n",libro[i].Autor);
                    printf("Fecha del libro: %d\n\n",libro[i].anio);
                }
                break;

            case 3:
                printf("Gracias por usar el programa\n");
                break;

        }
    }while (opcion!=3);

return 0;
}
