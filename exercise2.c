#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	for(int i = 0; i < 4; i++){
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
	}

	return 0;
}


