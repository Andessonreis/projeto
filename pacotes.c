#include "sistema.h"

//----------Cadastro de pacotes----------//
Pacotes cadastro_pacotes() {
  Pacotes pacotes;

  telaC();

  printf("Digite o destino da viagem: ");
  scanf("%39[^\n]", pacotes.destino);
  getchar();

  printf("Digite valor: ");
  scanf("%f", &pacotes.valor);
  getchar();

  printf("Digite o nome do passageiro: ");
  scanf("%49[^\n]", pacotes.passageiro.nome);
  getchar();

  printf("Telefone do passageiro: ");
  scanf("%ld", &pacotes.passageiro.telefone);
  getchar();

  return pacotes;
}

Pacotes cadastro_pacotes_editar_lista(int cod1, int cod2) {
  Pacotes pacotes;

  pacotes.codigo_pacotes = cod1;
  pacotes.passageiro.codigo_passageiro = cod2;

  printf("Digite o destino da viagem: ");
  scanf("%39[^\n]", pacotes.destino);
  getchar();

  printf("Digite valor: ");
  scanf("%f", &pacotes.valor);
  getchar();

  printf("Digite o nome do passageiro: ");
  scanf("%49[^\n]", pacotes.passageiro.nome);
  getchar();

  printf("Telefone do passageiro: ");
  scanf("%ld", &pacotes.passageiro.telefone);
  getchar();

  return pacotes;
}

//---------Imprimir pacotes---------//
void imprimir_pacotes(Pacotes pacotes) {
  // criar tbm uma funcao de cabe�ario

  printf("\nDestino: %s\nCodigo do pacote: [%d]\nValor: $%.3f\n", pacotes.destino,
         pacotes.codigo_pacotes, pacotes.valor);
  imprimir_passageiros(pacotes.passageiro);
  printf("\n------------------------->\n");
}

//---------Imprimir passageiro---------//
void imprimir_passageiros(Passageiro passageiro) {
  printf("\nNome do passageiro: %s\nCodigo do passageiro: [%d]\nTelefone: %d\n",
         passageiro.nome, passageiro.codigo_passageiro, passageiro.telefone);
}

//---------Busca passageiro ---------//
int busca_cod_passageiro(Lista lista, int cod) {
  if (lista_vazia(lista) == true)
    return EXIT_FAILURE;
  else {
    while (lista.inicio &&
           lista.inicio->pacotes.passageiro.codigo_passageiro != cod)
      lista.inicio = lista.inicio->proximo;

    if (lista.inicio == NULL)
      return EXIT_FAILURE;

    imprimir_pacotes(lista.inicio->pacotes);
    printf("\nDIgite enter para retornar ao menu\n");
    getchar();
    limpar_tela();
    return EXIT_SUCCESS;
  }
}
//---------busca pelo nome passageiro---------//
void busca_nome_passageiro(Lista lista) {
  char busca_nome[40];
  No *aux = lista.inicio;

  printf("\nDigite  o nome do passageiro: ");
  scanf("%39[^\n]", busca_nome);

  if (lista_vazia(lista) == true)
    return;
  else {
    while (aux && strcmp(aux->pacotes.passageiro.nome, busca_nome) != 0)
      aux = aux->proximo;

    if (aux) 
      imprimir_pacotes(aux->pacotes);
     else
      printf("\nNome nao econtrado");
  }
}

//----------Inserir cod passageiro---------//
int inserir_codigo_de_busca_passageiro() {
  int num;
  printf("Digite o codigo do passageiro: ");
  scanf("%d", &num);
  getchar();

  return num;
}

//----------Inserir cod passageiro---------//
int inserir_codigo_de_busca_pacote() {
  int num;
  printf("Digite o codigo do pacote: ");
  scanf("%d", &num);
  getchar();

  return num;
}