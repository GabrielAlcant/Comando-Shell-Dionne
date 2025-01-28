#!/bin/bash
#crontab = 
# * * * * * echo "ola $(whoami)" > /dev/pts/0
# */2 * * * * (diretorio do script) > /dev/pts/0
#variaveis com diretórios (pode ser alterado para a localização atual dos arquivos)
Site=/home/gabriel/Documentos/LAB/www
Modelo=/home/gabriel/Documentos/LAB/backup

cd $Modelo
keyModelo=$(cat chave.txt)

cd $Site
#criando arquivo tar do site para gerar chave
tar -cvf backup.tar.gz ./*
keySite=$(sha256sum backup.tar.gz | awk '{print $1}')
#gerar arquivo chave.txt para comparação
sha256sum backup.tar.gz | awk '{print $1}' > ${Site}/chave.txt
#remover o arquivo tar
rm backup.tar.gz
#atribuindo variavel com chave do modelo
dif=$(diff ${Modelo}/chave.txt ${Site}/chave.txt)
#remover chave.txt do diretório site
rm ${Site}/chave.txt

if [ -s $dif ];
then
	echo "São iguais"
	echo "Chave Site: $keySite"
	echo "Chave modelo: $keyModelo"
else
	echo "Os arquivos foram modificados, aplicando correções"
	sendEmail -f gabrielribeiro969@outlook.com \
  -t gabrielalcantara722@gmail.com \
  -s smtp-mail.outlook.com:587 \
  -u "Site Burlado" \
  -m "Foram encontradas alteraçoes no site, aplicando correções" \
  -xu gabrielribeiro969@outlook.com \
  -xp 'Yuri@rafael123' \
  -o tls=yes
	#apagar arquivos modificados
	rm $Site/*
	#extraindo modelo para o diretório do site
	cd $Modelo
	unzip backup.zip -d $Site
	#zipando e gerando nova chave para futuras comparações
	cd $Site
	tar -cvf backup.tar.gz ./*
	sha256sum backup.tar.gz | awk '{print $1}' > ${Modelo}/chave.txt
	rm -rf backup.tar.gz
fi
