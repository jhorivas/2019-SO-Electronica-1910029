#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
    int my_file = open("Hola.txt", O_CREAT | O_WRONLY, S_IRWXU);
    
    int rc = fork();

    if (rc == 0)
    {
        const char * child_msg = "Hola, Soy el proceso hijo\n";
        printf("Proceso hijo\n");
        printf("Accediendo al descriptor de archivo (descriptor): %d\n", my_file);
        write(my_file, child_msg , strlen(child_msg));
    }
    else if (rc > 0)
    {
        const char * parent_msg = "Hola, Soy el proceso padre\n";
        printf("Proceso padre\n");
        printf("Accediendo al descriptor de archivo (descriptor): %d\n", my_file);
        write(my_file, parent_msg, strlen(parent_msg));
    }
    close(my_file);
    return 0;
}
