#include <stdio.h>

void calcular (int *);

int main () {
    int decimal = 0;
    calcular (&decimal);
    printf("Tu numero decimal es: %d", decimal);
}

void calcular (int *decimal) {
    char romano [10] = {0,0,0,0,0,0,0,0,0,0};
    int temp [11] = {0,0,0,0,0,0,0,0,0,0,0};

    printf("Numero a convertir de romano a decimal\n");
    scanf("%s", &romano);

    for (int i=0; i<10; i++) {
        switch(romano[i]){
            case 'M':
                temp[i]=1000;
                break;
            case 'D':
                temp[i]=500;
                break;
            case 'C':
                temp[i]=100;
                break;
            case 'L':
                temp[i]=50;
                break;
            case 'X':
                temp[i]=10;
                break;
            case 'V':
                temp[i]=5;
                break;
            case 'I':
                temp[i]=1;
                break;
        }
    }
    for (int i=0; i<10; i++) {
        if (temp[i]>=temp[i+1]) {
            *decimal=*decimal+temp[i];
        }
        else {
            *decimal=*decimal+(temp[i+1]-temp[i]);
            i=i+1;
        }
    }
}
