#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("pPai: %d\n", (int)getpid());

    pid_t pid = fork();

    if (pid != 0 ) printf("pFilho criado: %d\n", (int)pid);

    if (pid == 0)
    { 
        pid_t pid2 = fork();
        if (pid2 != 0 ) printf("pNeto criado: %d\n", (int)pid2);
        if (pid2 == 0){
            printf("pNeto em execucao\n");
            printf("pNeto terminado\n");
            exit(0);
        }
        printf("pFilho esperando pNeto\n");
        wait(NULL);
        printf("pfilho em execucao\n");
        printf("pFilho terminado\n");
        exit(0);
    }

    printf("pPai esperando o filho terminar\n");
    wait(NULL);
    printf("pPai terminado\n");
    return (0);
}