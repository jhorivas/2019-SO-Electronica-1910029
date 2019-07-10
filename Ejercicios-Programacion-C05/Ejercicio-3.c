#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int call = fork();

    if (call == 0) 
        {
        printf("Hola\n");
        } 
    else if (call > 0)
        {
	sleep(1);
        printf("Adios\n");
        }
return 0;
}
