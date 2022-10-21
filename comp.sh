cd /home/aluno/Downloads/Comando-Shell-Dionne-main/
path=index.html
cd /home/aluno/Downloads/Comando-Shell-Dionne-main/
path2=backup.html

#Verificando se os arquivos foram modificados
cd 
comp1=$(zip -r principal.zip $path)
comp2=$(zip -r  backup.zip $path2)

#Chave Hash
chave1=$(sha256sum $comp1 | awk '{print$1}' )
chave2=$(sha256sum $comp2 | awk '{print$1}' )


if [ $chave1 = $chave2 ]; then
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
