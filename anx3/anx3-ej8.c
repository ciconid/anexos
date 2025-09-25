#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int idata = 111;

int main(int argc, char *argv[]){
	
	int istack = 222;
	int *heapVar;
	pid_t childPid;

	heapVar = (int *) malloc(sizeof(int));
	if (heapVar == NULL) {
		perror("...");
		exit(EXIT_FAILURE);
	}
	*heapVar = 333;

	switch (childPid = fork() ) {
		case -1:
			perror("...");
			exit(EXIT_FAILURE);
		case 0:
			printf("Soy el proceso hijo \n");

			idata *= 3;
			istack *= 3;
			*heapVar *= 3;
			break;
		default:
			printf("Soy el proceso padre \n");
			sleep(3);
			*heapVar += 6;
			break;
	}

	printf("PID=%ld %s idata=%d istack=%d heapVar=%d \n", (long) getpid(), 
			(childPid == 0) ? "(hijo)" : "(padre)", idata, istack, *heapVar);
	free(heapVar);
	exit(EXIT_SUCCESS);
}
