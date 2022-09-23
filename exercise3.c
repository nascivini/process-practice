#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

pid_t first, second;

int main(){

	pid_t created = fork();
	if(created == 0){
		pid_t processId = getpid();
		printf("Processo filho %d\n", processId);
		exit(1);				
	}
	else {
		pid_t processId = getpid();
		printf("Processo pai %d criou %d\n", processId, created);					
	}

	return 0;
}