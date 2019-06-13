#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char** argv){
	pid_t pid,pid2;
	int status;

	pid = fork();
	if (pid != 0){
	pid2 = wait(&status);	
	printf("Soy el Padre mi ID es %d y el de mi Hijo es %d\n",getpid(),pid);
	} 
	else {
	sleep(3);
	printf("Soy el Hijo con ID %d y mi variable es %d\n",getpid(),pid);
	}

	return 0;
}
