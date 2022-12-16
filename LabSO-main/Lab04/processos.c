#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int fibo(int);
int fatorial(int);
void TorreHanoi(int, int, int, int);

void processoPai();
void processoFilho();
void processoNeto();

int main()
{

    pid_t pid = fork();

    if (pid == 0)
    {
        pid_t pid2 = fork();
        if (pid2 == 0)
        {
            processoNeto();
            exit(0);
        }
        else
        {
            processoFilho();
            wait(NULL);
            exit(0);
        }
    }
    else
        processoPai();
}

int fibo(int n)
{
    if (n == 1)
        return 1;
    int a = 0, b = 1;
    long aux = 0;
    for (int i = 1; i < n; i++)
    {
        aux = a + b;
        a = b;
        b = aux;
    }
    return aux;
}

int fatorial(int n)
{
    if (n == 1)
        return 1;
    int fat = 1;
    for (int i = n; i != 1; i--)
        fat *= i;
    return fat;
}

void TorreHanoi(int origem, int destino, int auxiliar, int quantidade)
{
    int count = 0;
    if (quantidade == 1)
    {
        printf("Move de %d para %d \n ", origem, destino);
        count += 1;
    }
    else
    {
        TorreHanoi(origem, auxiliar, destino, quantidade - 1);
        TorreHanoi(origem, destino, auxiliar, 1);
        TorreHanoi(auxiliar, destino, origem, quantidade - 1);
    }
}

void processoPai()
{

    for (int i = 1; i <= 100; i++)
    {
        printf("pPai, pid = %d :\n\t%d° termo de fibonacci = %d: \n", getpid(), i, fibo(i));
    }
}
void processoFilho()
{
    printf("pFilho, pid = %d :\n\tFatorial de 5 = %d\n", getpid(), fatorial(5));
}
void processoNeto()
{
    printf("pNeto, pid = %d:\n", getpid());
    TorreHanoi(0, 2, 1, 6);
}