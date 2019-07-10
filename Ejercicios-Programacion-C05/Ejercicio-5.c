#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int rc = fork();

    if (rc == 0)
    {
        wait(NULL);
        printf("Soy el hijo\n");
    }
    else if (rc > 0) 
    {
	printf("Soy el Padre\n");
    }
}
