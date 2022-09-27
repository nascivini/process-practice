#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_main_process(int pid) {
    return pid == 0;
}

int main(){
	pid_t created = fork();
    pid_t created_after = fork();

    printf("PID 3 %d\n", created);
    printf("PID 1 %d\n", created_after);

	if(!is_main_process(created)) {
	    pid_t child = fork();
        printf("PID 1 %d\n", child);
	}
	if(!is_main_process(created_after)){
	    pid_t child = fork();
        printf("PID 2 %d\n", child);
	}
	return 0;
}