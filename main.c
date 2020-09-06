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

void easter_egg();
void instruction();

int main(int argc, char * const *argv)
{
    char * numberVal = NULL;
    int dat, itSup = 0, convNumber;

    opterr = 0;

    while ((dat = getopt(argc, argv, "n:em")) != -1){
        switch (dat)
        {
        case 'n':
            numberVal = optarg;

            convNumber = atoi(numberVal);

            break;
        
        case 'm':
            itSup = 1;
            break;

        case 'e':
            easter_egg();
            break;

        //En caso que opterr marque un error
        case '?':
            if (/* condition */)
            {
                /* code */
            }
            
            break;

        default:
            abort();
            break;
        }
    }

    if(itSup == 1){
        instruction();
    }

    printf("Se insertó el valor numérico de %d\n", convNumber);

    return 0;
}

void easter_egg(){
    printf("Congrats! You just found me!\n\n\nPlease mark me with a great grade!\n:)\n");
}

void instruction(){
    printf("Usage: ./a.out <options> <numeric value>\n");
    printf("The possible options are:\n");
    printf("-n\t\tAllows user to input a number in the numeric value field\n-i\t\tAllows the user to view this manual\n-e\t\tRun it to find out!\n");
}