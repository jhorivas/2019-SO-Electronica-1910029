INFORME TAREA

PUNTO 1 mem.c
Para este punto se dejo el codigo que teniamos anteriormente, primero
adquirimos el permiso de superusuario para deshabilitar la generacion 
aleatoria de direcciones de memoria del computador para lograr que siempre
le asigne la misma direccion de memoria a los programas con el comando.
sudo sh -c 'echo 0 > /proc/sys/kernel/randomize_va_space'

PUNTO 2 threads.c
Para este punto se modificaron lìneas de còdigo, con la guìa suministrada
por el docente, donde nos daba las pautas para la implementaciòn.
Se creò una variable llamada puerta, se inicializò la variable dentro del main
se llamò una funcion "cerrar puerta" antes de que incrementara la variable 
counter para que cuando un hilo entrara a incrementarla, el otro esperara 
hasta que el primer hilo terminara. Se puso una funciòn "Abrir puerta" para 
que cuando el hilo que modificò la variable counter termine, permita que el 
otro hilo que està esperando ingrese a incrementar la variable. Y al final
se "destruye la puerta" para que vuelva a iniciar el ciclo mutex.

PUNTO 3 io.c
Para este punto se tomò como referencia el ejemplo de Fibonacci realizado
en la clase anterior, tambien se implementò un ciclo anidado que es un for
dentro de un for y que tiene como finalidad realizar procesamientos un poco
màs complejos que los que realiza un ciclo simple.
