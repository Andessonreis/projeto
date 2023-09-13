#include "sistema.h" //incluindo as structs;

void tela() {
  printf("\n\n"
         "\t|******************************************************|\n"
         "\t|*                                                    *|\n"
         "\t|*                 SISTEMA DE TURISMO                 *|\n"
         "\t|*                                                    *|\n"
         "\t|******************************************************|\n\n");
}

void telaC() {
  printf("\n\n"
         "\t|******************************************************|\n"
         "\t|*                                                    *|\n"
         "\t|*                  Cadastrar Pacotes                 *|\n"
         "\t|*                                                    *|\n"
         "\t|******************************************************|\n\n");
}

//---------->Funcao para limpar a tela<---------//
void limpar_tela() {
  system("cls");
  system("clear");
}
//--------->Time<---------//
void abertura() {
  tela();
  time_t horaEmC;
    time(&horaEmC);
    struct tm *horaLocal = localtime(&horaEmC);
    int horas = horaLocal->tm_hour - 3;
    int minutos = horaLocal->tm_min;
    int dia = horaLocal->tm_mday;
    int mes = horaLocal->tm_mon + 1;
    int ano = horaLocal->tm_year + 1900;
    printf("\nData: %02d/%02d/%02d\n", dia, mes, ano);
    printf("Hora: %02d:%02d\n", horas, minutos);
}

//---------->MENU INICIAL<----------//
void menu_inicial() {

  printf("\t\nMENU INICIAL\n");
  printf("\n<0> Encerrar\n"
         "<1> Iniciar cadastro de pacotes de viagem\n"
         "<2> Lista todos os pacotes cadastrados\n"
         "<3> Consulta\n"
         "<4> Editar pacote\n"
         "<5> Excluir pacote\n"
         "<6> Salva em arquivo\n"
         "<7> Inserir no meio(função extra)\n"
         "<8> Retornar a media dos valores da lista(função extra)\n");
}

//--------->ESCOLHA DE OPCOES<---------//
void escolha_opcao(int opcao, Lista *lista) {
  Pacotes pacotes; 
  int cod;
  switch (opcao) {
  case 0:
    printf("Saindo e salvando em arquivo\n");
    salvar_arquivo(lista);
    break;
  case 1:
    pacotes = cadastro_pacotes(lista);
    limpar_tela();
    if (inserir_lista(lista, pacotes) == true)
      printf("Pacote adicionado com sucesso! :)\n");
    break;
  case 2:
    imprimir_lista(lista);
    break;
  case 3:
    if (lista_vazia(*lista) == true) {
      printf("A lista de pacotes esta vazia :(\n");
      return;
    }
    busca_escolha(*lista);
    break;
  case 4:
    if (lista_vazia(*lista) == true) {
      printf("A lista de pacotes esta vazia :(\n");
      return;
    }
    cod = inserir_codigo_de_busca_pacote();
    editar_lista_de_pacotes(lista, cod);
    break;
  case 5:
    if (lista_vazia(*lista) == true) {
      printf("A lista de pacotes esta vazia :(\n");
      return;
    }
    cod = inserir_codigo_de_busca_pacote();
    if (remover_lista(lista, cod) == true)
      printf("Pacotes de turismo removido com sucesso!\n");
    else
      printf("Pacote nao encontado :(\n");
    break;
  case 6:
    if (lista_vazia(*lista) == true) {
      printf("A lista de pacotes esta vazia :(\n");
      return;
    }
   salvar_arquivo(lista);
    break;
  case 7:
    if(lista_vazia(*lista) == true){
      printf("A lista esta vazia!!");
      return;
    }else{
      cod = inserir_codigo_de_busca_pacote();
      pacotes = cadastro_pacotes(lista);
      inserir_meio(lista, cod, pacotes);
    }
    break;
    case 8:
   printf("A media do preçoes eh: %.2f", retornar_media(lista));
    break;
  default:
    printf("Opção invalida :(\n");
    break;
  }
}
//---------Escolha da busca----------//
int busca_escolha(Lista lista) {
  int busca, cod;
  char nome;

  limpar_tela();
  printf("\n<1> Consultar pelo CODIGO do passagerio:\n"
         "<2> Consultar pelo NOME do passageiro:\n ");
  scanf("%d", &busca);
  getchar();
  limpar_tela();

  switch (busca) {
  case 1:
    cod = inserir_codigo_de_busca_passageiro();
    if (busca_cod_passageiro(lista, cod) == EXIT_FAILURE)
      printf("Pacotes pacote não encontado\n\n");
    break;
  case 2:
    busca_nome_passageiro(lista);
    break;
    default:
      printf("Opção invalida!");
    break;
  }
  return true;
}
