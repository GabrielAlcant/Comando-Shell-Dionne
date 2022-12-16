#!/bin/bash
#crontab = 
# * * * * * echo "ola $(whoami)" > /dev/pts/0
# */2 * * * * (diretorio do script) > /dev/pts/0
#variaveis com diretórios (pode ser alterado para a localização atual dos arquivos)
Site=/home/$(whoami)/Documentos/Site/
Modelo=/home/$(whoami)/Documentos/Modelo/

cd $Modelo
keyModelo=$(cat chave.txt)

cd $Site
#criando arquivo tar do site para gerar chave
tar -cvf backup.tar.gz ./*
keySite=$(sha256sum backup.tar.gz | awk '{print $1}')
#gerar arquivo chave.txt para comparação
sha256sum backup.tar.gz | awk '{print $1}' > ${Site}chave.txt
#remover o arquivo tar
rm backup.tar.gz
#atribuindo variavel com chave do modelo
dif=$(diff ${Modelo}chave.txt ${Site}chave.txt)
#remover chave.txt do diretório site
rm ${site}chave.txt

if [ -s $dif ];
then
	echo "São iguais"
	echo "Chave Site: $keySite"
	echo "Chave modelo: $keyModelo"
else
	echo "Os arquivos foram modificados, aplicando correções"
	sendemail -f ronald.andrade@icen.ufpa.br -t ronald.andrade.02@gmail.com -u "Alteração dos Arquivos"  -m "Foi detectado uma alteração nos arquivos, e as medidas de conteção foram tomadas!" -s cupijo.ufpa.br:587  -xu ronald.andrade@icen.ufpa.br -xp *****
	#apagar arquivos modificados
	rm $Site./*
	#extraindo modelo para o diretório do site
	cd $Modelo
	unzip backup.zip -d $Site
	#zipando e gerando nova chave para futuras comparações
	cd $Site
	tar -cvf backup.tar.gz ./*
	sha256sum backup.tar.gz | awk '{print $1}' > ${Modelo}chave.txt
	rm -rf backup.tar.gz
fi
