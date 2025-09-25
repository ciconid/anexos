#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

// Variables globales
int g_argc;

void *calcular_promedio(void *arg) {

	//printf("Hola desde el hilo \n");
	
	int cantidad = g_argc - 1;
	char **numeros = (char **) arg;
	//printf("Cantidad de numeros=%d \n", g_argc - 1);

	float suma = 0;
	float num;
	for (int i = 1; i < g_argc; i++) {
		num = atof(numeros[i]);
		suma += num;
	}
	
	float promedio = suma / cantidad;
	printf("promedio: %.2f \n", promedio);

	pthread_exit(EXIT_SUCCESS);
}


int main(int argc, char *argv[]) {

	g_argc = argc;

	pthread_t hilo;
	pthread_create(&hilo, NULL, calcular_promedio, argv);
	pthread_join(hilo, NULL);

	exit(EXIT_SUCCESS);
}

