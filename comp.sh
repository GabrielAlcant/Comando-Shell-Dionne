path=/home/sedepti/Documentos/GabrielR/index.html
path2=/home/sedepti/Documentos/GabrielR/backup.html
#Verificando se os arquivos foram modificados
if (cmp -s $path $path2); then
    echo "Os arquivos não foram modificados"

else
   echo "Os arquivos foram modificados"
   echo "Enviando email..."
# Enviando Email Caso tenha sido modificado
  sendEmail -f gabriel.alcantara@icen.ufpa.br -t gabrielribeiro969@outlook.com -s cupijo.ufpa.br:587 -u "Verificação de Modificação de Arquivos" -m "Seus arquivos principais foram alterados.Possivel invasão" -xu gabriel.alcantara@icen.ufpa.br -xp 'yurirafael123'
  #-a /arquivo.txt \
  #-xu gabriel.alcantara@icen.ufpa.br\
  #-xp 'yurirafael'\
  #-o tls=yes
   echo "Email enviado com sucesso"
# Copiando os arquvivos de backup e removendo o modificado

rm -r $path

cp -r $path2 $path

fi
