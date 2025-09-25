#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
	fork();
	fork();
	fork();
	puts("Hello World!");
	return EXIT_SUCCESS;
}
