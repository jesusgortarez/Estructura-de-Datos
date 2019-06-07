#include <stdio.h>
#include <math.h>
void EstaDecimal();
void DecimalEsta();
int main () {

 int opcion;
   do{
    printf ("Decimal a Estandar precione 1 \n");
    printf ("Estandar a Decimal precione 2 \n");
    printf ("Salir precione 3\n");
    scanf ("%d", &opcion);
    switch(opcion){
        case 1:
            DecimalEsta();
            break;
        case 2:
             EstaDecimal ();
            break;

    }
    }while(opcion!=3);

return 0;
}
void DecimalEsta(){
    float decimal, temporal_entero, temporal_decimal, d;
    int i,b=0,c=0,signo=0,temp=0,contador=0;
    int mantisa [23];
    int exponente [8];
    int binario [15];
    int extra  [15];
    for(i=0;i<8;i++)
        exponente[i]=0;
    for(i=0;i<23;i++)
        mantisa[i]=0;
    for(i=0;i<15;i++){
        binario[i]=0;
        extra[i]=0;
    }


printf ("ingrece un numero decimal (entre -32767 y +32767): ");
    scanf ("%f", &decimal);
        if (decimal<0){
            signo=1;
            decimal=decimal*(-1);
        }
        temporal_entero = floor (decimal);
        temporal_decimal = ceil((decimal - floor(decimal))*10000);
        d = temporal_decimal;
        for (i=0; i<15; i++) {
            if (temporal_entero==0)
                break;
            if (fmod (temporal_entero, 2)==1) {
                binario [14-i]=1;
                temporal_entero=floor (temporal_entero/2);
            }
            else {
                binario [14-i]=0;
                temporal_entero=floor (temporal_entero/2);
            }
            b=b+1;
        }

        for (i=0; i<15; i++) {
            if (temporal_decimal==0)
                break;
            if (temporal_decimal*2>=10000) {
                temporal_decimal=temporal_decimal*2-10000;
                extra [i]=1;
            }
            else {
                temporal_decimal=temporal_decimal*2;
                extra [i]=0;
            }
            c=c+1;
            if (d==temporal_decimal)
                i=16;
        }

    contador=126+b;
    d=b-1;
    b=0;
    for (i=0; i<8; i++) {
        if (contador==0)
            break;
        if (fmod (contador, 2)==1) {
            exponente [7-i]=1;
            contador=floor (contador/2);
        }
        else {
            exponente [7-i]=0;
            contador=floor (contador/2);
        }
        b=b+1;
    }

    contador=0;
    if (signo==1)
        printf("Tu signo es (1 bit): -\n");
    else
        printf ("Tu signo es (1 bit): +\n");

    printf("Tu exponente es (8 bits): ");
    for (i=8-b; i<8; i++) {
            printf ("%d ", exponente [i]);
    }
    printf("\n");
    for (i=15-d; i<15; i++) {
            mantisa [contador]=binario[i];
            contador=contador+1;
    }

    for (i=contador;i<23;i++) {
        mantisa[i]=extra[temp];
        temp=temp+1;
    }

    printf("Tu mantisa es (23 bits): ");
    for (i=0;i<23;i++) {
        printf ("%d ", mantisa[i]);
    }
    printf("\n\n");

}
void EstaDecimal () {
    float d=1,temp=0;
    int i,c=0,b=1,g=0,f=0,contador=0,signo=0;
    int mantisa [23];
    int exponente [8];
    int binario [15];
    int extra  [15];
    for(i=0;i<8;i++)
        exponente[i]=0;
    for(i=0;i<23;i++)
        mantisa[i]=0;
    for(i=0;i<15;i++){
        binario[i]=0;
        extra[i]=0;
    }

    printf ("Dame tu signo: + (0) o - (1)\n");
    scanf ("%d", &signo);
    printf("Dame tu exponente:\n");
    for (i=0;i<8;i++) {
        scanf ("%d", &exponente[i]);
        if (exponente[i]==1)
            contador=contador + pow (2,7-i);
    }
    printf ("Dame tu mantisa:\n");
    for (i=0; i<23; i++) {
        scanf ("%d", &mantisa[i]);
    }

    contador=contador-126;

    for (i=b; i<contador; i++) {
        binario [i]=mantisa[i-1];
        printf ("%d ", binario[i]);
        b=b+1;
        if (b==15)
            i=contador+1;
    }
    for (i=b; i<23;i++) {
        extra[c]=mantisa[i-1];
        printf("%d ",extra[c]);
        c=c+1;
        if (c==15)
           i=24;
    }

    for (g=0;g<b;g++) {
        if (binario[g]==1)
            temp= temp + pow(2,b-(g+1));
    }
    for (f=0;f<c;f++) {
        if (extra[f]==0)
            d= d/2;
    }
    if (signo==1)
        printf ("tu numero es: - %.4f \n\n", temp+d);
    else
        printf ("tu numero es: + %.4f \n\n", temp+d);
}
