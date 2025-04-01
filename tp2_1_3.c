#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define M 7

int main() {
    srand(time(NULL));

    // int i,j;
    int *punt;
    int mt[N][M];

    for(punt=&mt[0][0]; punt<&mt[0][0] + N*M; punt++) { // apunto el puntero a la direccion del primer elemento y recorro tanto para generar como para mostrar losnumeros
            *punt=1+rand()%100;
            printf("%d \n", *punt);
        }
    printf("\n");

    return 0;
}