#include "sistema.h" //incluindo as funções

/*
Projeto de Estrutura de dados

Docente: Andesson dos Reis matos, Caio Alves
*/

/* O projeto consiste na criação de um sistema de turismo */
int main(void) {
  setlocale(LC_ALL, "Portuguese");

  //------ Iniciando o gerador de codigos -----//
  time_t seed = time(NULL);
  srand((int)seed);

  int opcao;
  Lista lista;
  //---------- Iniciando a lista ---------//
  criar_lista(&lista);

  // criar_arquivo();
  ler_arquivo(&lista);
  do {
    abertura();
    menu_inicial();
    scanf("%d", &opcao);
    getchar();
    limpar_tela();
    escolha_opcao(opcao, &lista);

  } while (opcao != 0);

  return 0;
}
