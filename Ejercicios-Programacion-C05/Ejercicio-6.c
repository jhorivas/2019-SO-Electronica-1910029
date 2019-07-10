#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int rc = fork();

    if (rc == 0)
    {
        printf("Soy el hijo\n");
    }
    else if (rc > 0) 
    {
	int estado;
        waitpid(rc, &estado, 0);
        printf("Soy el Padre\n");
    }
}

