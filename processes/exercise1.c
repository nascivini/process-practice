#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

pid_t id;

int main(void) {
	id = fork();
	printf("Novo processo criado!\n");
}