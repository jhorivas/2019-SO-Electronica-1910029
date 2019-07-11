Ejercicio-1.c

Inicialmente definimos una variable x=100 antes de hacer el llamado al sistema 
fork() una vez hacemos el llamado se crean dos procesos que habiamos visto
previamente, el proceso padre y el proceso hijo; preguntamos que si la llamada a
fork() es igual a cero entonces en nuestro programa se encuentra nuestro proceso 
hijo e igualmente hacemos lo mismo con el proceso padre pero para este item 
preguntamos si es mayor que cero. Una vez compilado el programa procedemos a 
ejecutarlo y podemos observar que el valor de x tanto para el padre como para el 
hijo es el mismo, luego dentro de cada if asignamos un valor nuevo de x tanto para
el padre como el hijo y podemos observar que independientemente de haber asignado
un valor de x por fuera de los condicionales los valores nuevos que toman tanto el 
padre como el hijo son los que les hemos asignando recientemente.

Ejercicio-2.c

Al ejecutar el programa Ejercicio-2, vemos que nos presenta un mensaje del padre 
donde nos dice que accede al descriptor del archivo y nos devuelve el número 3.
Paralelamente el hijo nos presenta el mismo mensaje accediendo al descriptor del
archivo y nos devuelve el número 3. Por lo que podemos deducir que tanto el hijo
como el padre pueden acceder al descriptor del archivo. Por otro lado al escribir
en el archivo al mismo tiempo, vemos que nos devuelve el mismo número devuelto
por open ().



Ejercicio-3.c

Inicialmente en nuestro int main() llamamos a la llamada al sistema fork() 
valga la redundancia para luego preguntar en nuestros condicionales si es 
igual a cero entonces es el proceso hijo, si es mayor que cero es el proceso
padre; simplemente cuando sea el proceso hijo imprimimos la cadena de 
caracteres Hola y cuando sea el proceso padre hacemos los propio pero
imprimiendo la palabra Adios. Podemos observar que si utilizamos el wait()
dentro del proceso padre siempre se garantiza que una vez conluya el hijo
el padre hara su proceso, pero una vez quitamos el wait() observamos que
no hay un orden y que casi siempre se ejecuta primero el proceso padre. Para
asegurarnos de que siempre se imprima primero el proceso hijo y luego el padre
sin utilizar el wait(), utilizamos el sleep() que pone a dormir al proceso
por un tiempo determinado, el tiempo que le dimos fue minimo pero siempre 
se asegura de que se imprima el hijo y luego el padre.

Ejercicio-4.c

Para este ejercicio tome como referencia el ejercicio anterior, simplemente se 
añadio las funciones exec() y sus variantes. Seguimos las intrucciones que nos
daba la pregunta y luego probamos cada una de las variantes obteniendo en cada
una de ellas practicamente lo mismo, lo que cambia son minimos detalles, por 
ejemplo para poder ejecutar el execle() toca agregarle un envp[] para que 
compile, las variantes execl(), execlp() con el argumento compilan y cuando se 
ejecutan estos tres programas nos arroja lo mismo. Para poder ejecutar las
variantes execv(), execvp() con la funcion (char * const argv[]) compilan y
cuando se ejecutan arrojan el mismo resultado que las anteriores; la variante 
execvpe() no se pudo compilar en nuestra terminal dandonos un error en declaracion
de funcion implicita

Ejercicio-5.c

Este ejercicio es lo mismo que hemos venido haciendo en los anteriores ejercicios
haciendo la llamada al sistema fork() para que en el programa tengamos un proceso
padre y un proceso hijo; lo que normalmente se hace en estos procesos es que el
hijo se ejecute primero haciendo un wait() en el proceso padre. Pero para efectos
del ejercicio se nos pide colocar este wait() en el proceso hijo ¿Que esperamos?
Pues simplemente haciendo un analisis si cuando ponemos en wait() en el proceso
padre este espera hasta que el proceso hijo termine, si invertimos los roles y
ponemos el wait() en el hijo lo que vamos a conseguir es que este espere hasta
que el proceso padre termine para luego el hacer su ejecucion. Por lo tanto
si usamos el wait() en el hijo esperariamos que tengamos un resultado de -1 ya
que no hay hijo de hijo pero no habria inconvenientes para ejecutar el programa 
es por esto que hay que esperar a que se cierre alguno de los procesos que tenemos
para que luego el hijo se ejecute.

Ejercicio-6.
Para este ejercicio usamos el mismo codigo del ejercicio anterior solo que en
vez de utilizar el wait(NULL), el ejercicio nos pide utilizar el waitpid().
Inicialmente lo unico que hicimos fue dejarlo en waitpid(NULL) y nos aparecio
un error diciendonos que para usar este comando habia que ponerle unos argumentos
investigando llegamos a la forma en que se utiliza el waitpid() el cual esta de
esta forma waitpid(pid_t pid, int *status, int options) una vez hicimos el proceso
como se muestra anteriormente nos aparecio nuevamente un error que no lograbamos
ver porque razon estaba ocurriendo luego mirando algunos ejemplos en internet de
como usaban el comando observamos que dentro antes de la variable creada colocaban
"&" luego procedimos a hacer lo propio con nuestro codigo y efectivamente nos
compilo pero sin entender el porque es necesario poner esto.
El waitpid() se deberia usar cuando queremos suspender la ejecucion de un proceso
en curso hasta que un proceso hijo especificado por el argumento pid haya terminado o
en su defecto hasta que se produzca una señal cuya accion sea finalizar el proceso
actual

Ejercicio-7.c
En este ultimo ejercicio se toma nuevamente el anterior como plantilla y el unico
cambio que se realiza es que dentro del proceso padre usamos el comando 
close(STDOUT_FILENO) en lugar de wait(NULL) lo que podemos observar en este programa
es que una vez compilado cuando lo vamos a ejecutar lo que vayamos a imprimir dentro
del proceso hijo nunca se imprime es decir que no entra a ese ciclo por lo tanto
lo que hace este comando es cerrar o eliminar el ciclo del proceso hijo y solo
imprimir lo que contenga el proceso padre.
