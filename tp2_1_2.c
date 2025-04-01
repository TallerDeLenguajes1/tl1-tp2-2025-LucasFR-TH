// codigo a completar
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

int main() {
    srand(time(NULL));
    double *punt;
    double vt[N];
    
    for(punt = vt; punt<vt+N; punt++) {
        *punt=1+rand()%100;
        printf("%.2lf\n", *punt);
    }
}