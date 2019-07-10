#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int call = fork();

    if (call == 0)
    {
        printf("Hola\n");
	const char * argv[] = {"ls", NULL};
        const char * envp[] = {NULL};    //***//
	execl("/bin/ls", "ls", NULL);
	//execle("/bin/ls", "ls", NULL, envp);  //***//
        //execlp("/bin/ls", "ls", NULL);

	//char * const argv[] = {"ls", NULL}; //*-*//
        //char * const envp[] = {NULL}; //*-*//
	//execv("/bin/ls", argv);
        //execvp("ls", argv);
        //execvpe("ls", argv, envp); /*No se pudo compilar*/ 

    }

    else if (call > 0)
    {
	wait(NULL);
	printf("Adios\n");
    }
}
