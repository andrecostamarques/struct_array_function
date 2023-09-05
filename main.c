#include <stdio.h>
#include <stdlib.h>

typedef struct academia{
  int ra;
  float altura;
  float peso;
}alunos;

alunos* atribuir(int qnt){
  alunos *aux; //cria uma instancia da struct temporária pro ponteiro la embaixo apontar
  aux = (alunos*)malloc(qnt * sizeof(alunos)); //separa na memória um espaco pra criar a array de struct 
  
  for(int i =0; i < qnt; i++){ //faz um loop que percorre a array de struct

    fflush(stdin);
    
    printf("\nDigite o Ra do aluno:");
    fflush(stdin);
    scanf("%d",&aux[i].ra); //essa sintaxe basicamente ta falando a mesma coisa que isso aqui:
  // scanf("%d",*aux+i->ra)  <- automaticamente a linguagem faz essa conta pra vc e colocar como array.

    printf("\nDigite a altura do aluno:");
    fflush(stdin);
    scanf("%f",&aux[i].altura);

    printf("\nDigite o peso do aluno:");
    fflush(stdin);
    scanf("%f",&aux[i].peso);
    
  }
  return aux;
}

int maior_altura(int qnt, alunos vet[]){

  float aux;
  int aux2;
  
  aux = vet[0].altura;

  for (int i =0; i<qnt; i++){
    if(vet[i].altura >= aux){
      aux = vet[i].altura;
      aux2 = i;
    }
    
  }
  printf("\nA maior altura é: %.2f de ra: %d",aux,vet[aux2].ra);

  return 0;
}
int menor_peso(int qnt, alunos vet[]){

  float aux;
  int aux2;
  aux=vet[0].peso;

  for (int i =0; i<qnt; i++){
    if(vet[i].peso <= aux){
      aux = vet[i].peso;
      aux2 = i;
    }
    
  }
  printf("\nO menor peso é: %.2f de ra: %d",aux,vet[aux2].ra);

  return 0;
}

int main(void) {

  alunos *vet; //cria um ponteiro de struct
  int qntalun;  //quantida de alunos na academia
  printf("Quantos alunos terão na academia?:");
  scanf("%d",&qntalun);
  vet = atribuir(qntalun);  //executa a função que vai alocar dinamicamente a quantidade
  //memoria necessária para salvar a array de struct para a quantidade de alunos necessária
  //e vai retornar a posicao dessa memoria para ser salva em vet.

  for(int i = 0; i < qntalun; i++){
    printf("\n Ra: %d",vet[i].ra);
    printf("\n Altura: %.2f",vet[i].altura);
    printf("\n Peso: %.2f",vet[i].peso);
  }

  maior_altura(qntalun,vet);  //executa a funcao para percorrer as arrays e achar a maior altura e peso
  menor_peso(qntalun,vet);
  
  return 0;
}