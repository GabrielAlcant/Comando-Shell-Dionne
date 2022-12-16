#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
typedef struct
{
    int Prioridade;
    int id;
    float Tempo;
} Processo;

typedef struct
{
    int Primeiro, Ultimo;
    int aux;
    Processo processos[3];
} Escalonador;


void FLVazia(Escalonador *escalonador)
{
    escalonador->Primeiro = 0;
    escalonador->Ultimo = escalonador->Primeiro;
    escalonador->aux = 1;
}

int Vazia(Escalonador escalonador)
{
    return (escalonador.Primeiro == escalonador.Ultimo);
}

void Insere(Processo x, Escalonador *escalonador)
{
    if (escalonador->Ultimo > 2)
        printf("ERRO LISTA CHEIA\n");
    else
    {
        escalonador->processos[escalonador->Ultimo] = x;
        escalonador->processos[escalonador->Ultimo].id = escalonador->aux;
        escalonador->aux++;
        escalonador->Ultimo++;
    }
}

void Retira(int posicao, Escalonador *escalonador, Processo *Item)
{
    int Aux;

    if (Vazia(*escalonador) || posicao >= escalonador->Ultimo)
    {
        printf(" ERRO POSIÇÃO NÃO EXISTE\n");
        return;
    }
    *Item = escalonador->processos[posicao];
    escalonador->Ultimo--;
    for (Aux = posicao; Aux < escalonador->Ultimo; Aux++)
        escalonador->processos[Aux] = escalonador->processos[Aux + 1];
}

void BubbleSort(Processo arr[], int n) {
    int i,j;
    Processo aux;
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - i - 1; j++){
            if (arr[j].Prioridade > arr[j+1].Prioridade){
                aux = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = aux;
            }
        }
    }
}

void round_robin(Escalonador escalonador,float time_slice){
    Processo p;

    p.Prioridade = 4;
    p.Tempo = 200;
    Insere(p, &escalonador);
    p.Prioridade = 1;
    p.Tempo = 300;
    Insere(p, &escalonador);
    p.Prioridade = 2;
    p.Tempo = 25;
    Insere(p, &escalonador);


    while(!Vazia(escalonador)){
        for (int i = escalonador.Primeiro; i < escalonador.Ultimo; i++){
            if ((escalonador.processos[i].Tempo) - time_slice <= 0){
            printf("P%d, %0.2f*\n",escalonador.processos[i].id, escalonador.processos[i].Tempo );
            Retira(i,&escalonador,&p);
            }
            else{
            printf("P%d, %0.2f\n",escalonador.processos[i].id, escalonador.processos[i].Tempo);
            escalonador.processos[i].Tempo -= time_slice;
            }
        }
    }
}

void prioridade(Escalonador escalonador,float time_slice){
    Processo p;

    p.Prioridade = 4;
    p.Tempo = 200;
    Insere(p, &escalonador);
    p.Prioridade = 1;
    p.Tempo = 300;
    Insere(p, &escalonador);
    p.Prioridade = 2;
    p.Tempo = 25;
    Insere(p, &escalonador);

    //Ordenar por prioridade
    BubbleSort(escalonador.processos,3);
    while(!Vazia(escalonador)){
        for (int i = escalonador.Primeiro; i < escalonador.Ultimo; i++){
            if ((escalonador.processos[i].Tempo) - time_slice <= 0){
            printf("P%d, %0.2f*\n",escalonador.processos[i].id, escalonador.processos[i].Tempo );
            Retira(i,&escalonador,&p);
            }
            else{
            printf("P%d, %0.2f\n",escalonador.processos[i].id, escalonador.processos[i].Tempo);
            escalonador.processos[i].Tempo -= time_slice;
            }
        }
    }

}