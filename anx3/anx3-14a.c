#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
	
	pid_t pid = 1;	 // la inicializo en 1 para que entre la primera vez al else de PADRE

	for (int i = 0; i < 10; i++) {
		
		if (pid == -1) {
			perror("fork() error");
			exit(EXIT_FAILURE);
		} else if (pid == 0) {
			sleep(10);
			exit(EXIT_SUCCESS);
		} else if (pid > 0) {
			// PADRE
			pid = fork();
		}
	}

	sleep(20);

}
