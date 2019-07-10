#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int rc = fork();

    if (rc == 0)
    {
        close(STDOUT_FILENO);
        printf("Soy el hijo\n");
    }
    else if (rc > 0) 
    {
	wait(NULL);
        printf("Soy el Padre\n");
    }
}

