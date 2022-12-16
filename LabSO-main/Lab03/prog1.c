#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define STRSIZE 100

void flush_in();

int main(){
	/*
	Laboratório 03 de sistemas operacionais
	*/
	//ponteiro com dados do buffer e variável para o nome do arquivo
	char buff[STRSIZE], fn[10];
	int fd, n;

	printf("Entre com o nome de um arquivo novo:\n");
	scanf("%s",&fn);
	
	//limpar stdin
	flush_in();

	printf("\nEntre com um texto qualquer:");
	//ler o texto com o input pelo teclado
	fgets(buff, STRSIZE, stdin); 
	
	//criar o arquivo caso não exista em modo de escrita, O nome do arquivo no código será o fn
	fd = open(fn,O_CREAT|O_WRONLY, 0444);
	//chamada de sistema para escrita, parâmetros: (descritor de arquivo, dados do buffer, numero de contagem de dados do buffer)
	n = write(fd,buff,strlen(buff));

	close(fd);

	printf("\n\nVeja o conteúdo do arquivo criado\n");
}

void flush_in()
{
   int ch;
   //EOF significa fim da linha e possui um valor -1;
   //fgetc atribui os chars do stdin à variável ch;
   //quando ch utilizar todos os chars de stdin retorna -1;
   //esse processo limpará stdin;
   while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}
