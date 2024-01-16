#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct alumno {
    int matricula;
    char nombre[50];
    char direccion[50];
    char carrera[50];
    float nota; 
};

void ingresarDatos(struct alumno *al);
void mostrarDatos(struct alumno *al, int n);

int main() {
    struct alumno alumnos[100]; 
    int n = 0, opcion;

    do {
        printf("\nMenu:\n");
        printf("1. Ingresar datos de alumno\n");
        printf("2. Mostrar datos de alumnos\n");
        printf("3. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        fflush(stdin);

        switch(opcion) {
            case 1:
                if (n < 100) {
                    ingresarDatos(&alumnos[n]);
                    n++;
                } else {
                    printf("Se ha alcanzado el número máximo de alumnos.\n");
                }
                break;
            case 2:
                mostrarDatos(alumnos, n);
                break;
            case 3:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion no valida\n");
        }
    } while(opcion != 3);

    return 0;
}

void ingresarDatos(struct alumno *al) {
    printf("Ingrese matricula: ");
    scanf("%d", &al->matricula);
    fflush(stdin);

    printf("Ingrese nombre: ");
    gets(al->nombre); 
    printf("Ingrese direccion: ");
    gets(al->direccion);

    printf("Ingrese carrera: ");
    gets(al->carrera);

    printf("Ingrese nota: ");
    scanf("%f", &al->nota);
    fflush(stdin);
}

void mostrarDatos(struct alumno *al, int n) {
    printf("\nDatos de los Alumnos:\n");
    for(int i = 0; i < n; i++) {
        printf("\nAlumno %d:\n", i + 1);
        printf("Matricula: %d\n", al[i].matricula);
        printf("Nombre: %s\n", al[i].nombre);
        printf("Direccion: %s\n", al[i].direccion);
        printf("Carrera: %s\n", al[i].carrera);
        printf("Nota: %.2f\n", al[i].nota);
    }
}
