#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void *print_tid(void *arg) {
	pthread_t tid = pthread_self();
	printf("tid=%lu \n", tid);

	sleep(10);

	pthread_exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[]) {

	if (argc != 2) {
		printf("Ingrese numero de hilos a crear! \n");
		printf("./anx4-4a <numero_de_hilos_a_crear> \n");
		exit(EXIT_FAILURE);
	}

	int n = atoi(argv[1]);
	pthread_t hilos[n];

	// crear hilos
	for (int i = 0; i < n; i++) {
		pthread_create(&hilos[i], NULL, print_tid, NULL);	
	}

	// joinear hilos
	for (int i = 0; i < n; i++) {
		pthread_join(hilos[i], NULL);
	}

	printf("## SALIENDO DE MAIN ## \n");
	exit(EXIT_SUCCESS);
}

