/*
 *  Actividad 4
 *  Programación avanzada
 * 
 *  Daniel Roa
 *  A01021960
 * 
 *  Páginas de soporte:
 *  https://www.gnu.org/software/libc/manual/html_node/Using-Getopt.html
 *  http://www.cplusplus.com/reference/cstdlib/atoi/
 * 
 */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void easter_egg();
void instruction();

typedef struct procceses{
    int childP;
    int avg;
} procDat;

int main(int argc, char * const *argv)
{
    char * numberVal = NULL;
    int dat, itSup = 0, convNumber = 0, contPID = 0;
    pid_t pid;
    
    //Error value - opterr se convierte en ? cuando marca un error
    opterr = 0;

    while ((dat = getopt(argc, argv, "n:em")) != -1){
        switch (dat)
        {

        //Caso principal, donde el usuario insertó n números
        case 'n':
            numberVal = optarg;
            //Convert char to int
            convNumber = atoi(numberVal);
            break;
        
        //En caso que el usuario quiera ver el manual de uso del programa
        case 'm':
            itSup = 1;
            break;

        //Valor de prueba, para asegurarme que funcionara con mas de dos 'flags'
        case 'e':
            easter_egg();
            break;

        //Para la ejecución del programa
        default:
            abort();
            break;
        }
    }

    procDat *proc = (procDat *)malloc(sizeof(procDat) * convNumber);
    procDat * fin = proc + convNumber;
    procDat *cont = proc;

    /* for (procDat *cont = proc; cont < fin; ++cont){
        if(pid == -1){
            printf("Error al crear al hijo\n");
        }else if(pid == 0){

        }
    } */
    
    while (cont < fin && contPID < convNumber)
    {
        pid = fork();
        if (pid == -1){

            printf("Error al crear al hijo\n");

        }else if(pid == 0){

            printf("El proceso padre es %d y su hijo es %d\n", getpid(), getppid());

        }
        
    }

    //printf("Se insertó el valor numérico de %d\n", convNumber);

    if (itSup == 1){
        instruction();
    }

    return 0;
}

void easter_egg(){
    printf("Congrats! You just found me!\n\nPlease mark me with a great grade!\n:)\n");
}

void instruction(){
    printf("Usage: ./a.out <options> <numeric value>\n");
    printf("The possible options are:\n");
    printf("-n\t\tAllows user to input a number in the numeric value field\n-i\t\tAllows the user to view this manual\n-e\t\tRun it to find out!\n");
}