#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct compu {
    int velocidad; // Velocidad de procesamiento en GHz (valor entre 1 y 3)
    int anio; // Año de fabricación (valor entre 2015 y 2024)
    int cantidad_nucleos; // Cantidad de núcleos (valor entre 1 y 8)
    char *tipo_cpu; // Tipo de procesador (apuntador a cadena de caracteres)
} Compu;

// DECALRACION DE MODULOS
void listarPCs(Compu pcs[], int cantidad);
void mostrarMasVieja(Compu pcs[], int cantidad);
void mostrarMasVeloz(Compu pcs[], int cantidad);

int main() {
    srand(time(NULL));

    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core",
"Pentium"};

    int cantidad = 5;

    Compu pcs[cantidad];

    for (int i = 0; i<cantidad; i++) {
        // genero los datos de la maquina aleatoriamente
        pcs[i].velocidad = (rand() % (3 - 1 + 1)) + 1;
        pcs[i].anio = (rand() % (2024 - 2015 + 1)) + 2015;
        pcs[i].cantidad_nucleos = (rand() % (8 - 1 + 1)) + 1;

        // le asigno un tipo de cpu
        int aleatorio = rand() % 6;
        pcs[i].tipo_cpu = tipos[aleatorio];
    }

    listarPCs(pcs, cantidad);
    printf("\n\n");
    mostrarMasVieja(pcs, cantidad);
    printf("\n\n");
    mostrarMasVeloz(pcs, cantidad); 

    return 0;
}

// MODULOS
void listarPCs(Compu pcs[], int cantidad) {
    printf("LISTADO DE PC'S \n");
    for (int i=0; i<cantidad; i++) {
        printf("PC's %d:\n", i);
        printf("Velocidad: %d\n", pcs[i].velocidad);
        printf("Anio: %d\n", pcs[i].anio);
        printf("Cantidad de nucleos: %d\n", pcs[i].cantidad_nucleos);
        printf("Tipo de CPU: %d\n", pcs[i].tipo_cpu);
    }
}

void mostrarMasVieja(Compu pcs[], int cantidad) {
    int masVieja = 0; // auxiliar para guardar la pc mas vieja
    int anioref = 10; // año de referencia para comparar
    for (int i=0; i<cantidad; i++) {
        if (pcs[i].anio > anioref) {
            masVieja = i;
            anioref = pcs[i].anio; // actualizo el año de referencia
        }
    }
    printf("La PC mas vieja es la %d\n", masVieja);
    printf("Velocidad: %d\n", pcs[masVieja].velocidad);
    printf("Anio: %d\n", pcs[masVieja].anio);
    printf("Cantidad de nucleos: %d\n", pcs[masVieja].cantidad_nucleos);
    printf("Tipo de CPU: %d\n", pcs[masVieja].tipo_cpu);
}

