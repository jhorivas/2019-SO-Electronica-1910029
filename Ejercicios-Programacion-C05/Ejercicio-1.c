#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main()
{
    int x;
    x = 100;
    int call = fork();

    if (call == 0) 
    	{
        printf("Proceso Hijo\n");
        printf("Valor de  X: %d\n", x);
	x = 200;
        printf("Nuevo valor de x: %d\n", x);
        } 

    else if (call > 0)
   	{
        wait(NULL);
        printf("Proceso Padre\n");
        printf("Valor de X: %d\n", x);
	x = 300;
        printf("Nuevo valor x: %d\n", x);
    	}

return 0;
}
