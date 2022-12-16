#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#define MAX_COUNT 200
void ChildProcess(void);
void ParentProcess(void);
void main(void)
{
    pid_t pid;

    pid = fork();
    if (pid == 0)
        ChildProcess();
    wait();
    ParentProcess();
    
    exit(0);
}
void ChildProcess(void)
{
    int i;
    for (i = 1; i <= MAX_COUNT; i++)
        printf(" Processo FILHO, valor = %d\n", i);
    printf(" *** Processo FILHO finalizado ***\n");
    exit(0);
}
void ParentProcess(void)
{
    int i;
    for (i = 1; i <= MAX_COUNT; i++)
        printf("Processo PAI, valor = %d\n", i);
    printf("*** Processo PAI finalizado ***\n");
    exit(0);
}