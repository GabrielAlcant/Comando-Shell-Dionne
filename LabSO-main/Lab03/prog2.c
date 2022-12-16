#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    char d[10];
    DIR *p; //Ponteiro para o fluxo de diretório
    struct dirent *d1; // Ponteiro para strucr de diretório

    printf("Entre com um nome de um diretório:\n");
    scanf("%s",d);

    //armazenda o diretório informado pelo usuário no ponteiro
    p = opendir(d);
    //se o diretório não existe...
    if( p==NULL ){ 
        perror("Diretório não encontrado");
        exit(-1);
    }
    //    A função readdir () retorna um ponteiro para uma estrutura direta
    //    representando a próxima entrada de diretório no fluxo de diretório
    //    apontado por p . Retorna NULL ao chegar ao final do
    //    fluxo de diretório ou se ocorreu um erro.
    while( d1 = readdir(p) )
    printf("%s\n",d1->d_name);
}
