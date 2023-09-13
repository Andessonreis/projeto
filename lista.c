#include "sistema.h"

//---------CRIAR LISTA--------//
bool criar_lista(Lista *lista) {
  lista->inicio = NULL;
  return true;
}

//--------Lista vazia--------//
bool lista_vazia(Lista lista) {
  if (lista.inicio)
    return false;
  return true;
}

//--------Gerando codigo aleatoriamente--------//
int gerar_codigo() {
  int cod;
  return cod = rand() % 10000;
}

//---------- Imprimindo Lista ----------//

void imprimir_lista(Lista *lista) {

  Pacotes pacotes;
  Passageiro passageiro;
  No *aux2 = lista->inicio;
  if (lista->inicio == NULL)
    printf("\nLista vazia :(");
  else {
    int aux = 0;
    while (aux2) {
      aux++;
      printf("\n------------------------->\n");
      printf("Pacotes cadastrados: %d\n", aux);
      imprimir_pacotes(aux2->pacotes);
      aux2 = aux2->proximo;
    }
  }
    printf("\nPressione enter para retornar ao menu\n");
    getchar();
    limpar_tela();
}

//---------- inserção no inicio da lista ----------//
bool inserir_lista(Lista *lista, Pacotes pacotes) {
  No *aux, *novo = (No *)malloc(sizeof(No));
  if (novo) {
    novo->pacotes = pacotes;
    novo->pacotes.codigo_pacotes = gerar_codigo();
    novo->pacotes.passageiro.codigo_passageiro = gerar_codigo();
    if (lista->inicio == NULL) {
      novo->proximo = lista->inicio;
      lista->inicio = novo;
    } else {
      aux = lista->inicio;
      while (aux->proximo)
        aux = aux->proximo;
      novo->proximo = NULL;
      aux->proximo = novo;
    }
  } else {
    printf("Erro na alocação de memoria");
    return false;
  }
  return true;
}
//---------Edita a lista de pacotes---------//
int editar_lista_de_pacotes(Lista *lista, int cod) {
  No *aux = lista->inicio;
  if (aux == NULL)
    return EXIT_FAILURE;
  else {
    while (aux && cod != aux->pacotes.codigo_pacotes)
      aux = aux->proximo;
    if (aux) {
      printf("\nCodigo de pacote de turismo encontrado! :)\n");
      aux->pacotes = cadastro_pacotes_editar_lista(aux->pacotes.codigo_pacotes, aux->pacotes.passageiro.codigo_passageiro);
    } else
      printf("codigo não encontado :(");
  }
  return EXIT_SUCCESS;
}

//---------Remover da lista--------//

bool remover_lista(Lista *lista, int cod){

  No *aux = lista->inicio, *remover = malloc(sizeof(No));

  if(lista->inicio->pacotes.codigo_pacotes == cod){
      remover = lista->inicio;
      lista->inicio = lista->inicio->proximo;
  } else{
       while (aux->proximo && aux->proximo->pacotes.codigo_pacotes != cod)
          aux = aux->proximo;

      if (aux->proximo){
            remover = aux->proximo;
            aux->proximo = remover->proximo;
        }else  return false;
  }
    free(remover);
    return true;
}

//----------Função extra Andesson dos reis----------//
 
bool inserir_meio(Lista *lista, int cod, Pacotes pacotes){
  No *novo = malloc(sizeof(No)), *aux;
  if(novo == NULL){
    printf("Erro ao alocar novo no\n");
    return false;
    }
  else{
    novo->pacotes = pacotes;
    novo->pacotes.codigo_pacotes = gerar_codigo();
    novo->pacotes.passageiro.codigo_passageiro = gerar_codigo();
    
    if(lista->inicio == NULL){
      novo->proximo = NULL;
      lista->inicio = novo;

      }else{
       aux = lista->inicio;
        while(aux->proximo && aux->pacotes.codigo_pacotes != cod)
          aux = aux->proximo;
      
        novo->proximo = aux->proximo;
        aux->proximo = novo;
      if(novo->proximo == NULL)
        printf("\n\nCodigo não encontrado! inserindo no fim\n");
      }
  }
  return true;
}
//---------------------Fim---------------------//

//---------- Função extra Caio Alves ----------//

float retornar_media(Lista *lista){
  float media,soma=0;
  
  int cont=0;
  
  No *no = lista->inicio;

  while(no){
    soma = soma + no->pacotes.valor;
    no = no->proximo;
    cont = cont +1;
  } 

  media = soma/cont;
  
  return media;
}

//------------------------FIM-----------------------//


