#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char** argv){
	pid_t pid;
	printf("Hola\n"); //Se ejecuta uno solo
                     /* Antes de invcar fork() tengo un solo proceso en el sistema */
	pid = fork(); /* Una vez invoco fork() ya tengo dos procesos
			 en el sistema */
	printf("Hola a todos\n"); //Se ejecutan dos; el del Padre y el del Hijo
	if (pid != 0){
	printf("Soy el Padre mi ID es %d y el de mi Hijo es %d\n",getpid(),pid);
	} 	/* getpid() Obtiene el identificador de cada proceso */
	else {
	printf("Soy el Hijo con ID %d y mi variable es %d\n",getpid(),pid);
	}

	return 0;
}
