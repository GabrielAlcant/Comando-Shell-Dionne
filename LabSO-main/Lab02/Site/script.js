function soma(){
   let n1 =  parseInt(document.getElementById("n1").value);
   let n2 = parseInt(document.getElementById("n2").value);
   let soma = n1 + n2;
   console.log(soma)
   document.getElementById("soma").value =  "A soma dos números é " + soma;
}
