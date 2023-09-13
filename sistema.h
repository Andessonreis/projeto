//----------- Cabeçario ----------//

#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//---------- Estrutura do passageiro ----------//

typedef struct {

  int codigo_passageiro;
  char nome[50];
  long int telefone;

} Passageiro;

//---------- Estrutura do pacotes ----------//

typedef struct {

  int codigo_pacotes;
  float valor;
  char destino[40];
  Passageiro passageiro;

} Pacotes;

//---------- Estrutura do No ----------//

typedef struct No {

  Pacotes pacotes;
  struct No *proximo;
} No;

//---------- Estrutura da lista  ----------//

typedef struct {

  No *inicio;
  int tamanho;

} Lista;

//---------- Prototipos ----------//

//----------Prototipos Lista-----//

bool criar_lista(Lista *);
bool lista_vazia(Lista lista);
bool inserir_lista(Lista *, Pacotes);
void imprimir_lista(Lista *lista);
bool remover_lista(Lista *lista, int cod);
int editar_lista_de_pacotes(Lista *lista, int cod);
void criar_arquivo();
void salvar_arquivo(Lista* listas);
bool ler_arquivo(Lista* listas);

//--------Funçoes extras-----------//
//----------Andesson reis----------//
bool inserir_meio(Lista *lista, int, Pacotes );
//------------Caio Alves---------//
float retornar_media(Lista *lista);

//-------Prototipos pacotes------//

Pacotes cadastro_pacotes();
int inserir_codigo_de_busca_passageiro();
int inserir_codigo_de_busca_pacote();
int busca_cod_passageiro(Lista lista, int cod);
void busca_nome_passageiro(Lista lista);
void imprimir_pacotes(Pacotes pacotes);
void imprimir_passageiros(Passageiro passageiro);
Pacotes cadastro_pacotes_editar_lista(int cod1, int cod2);

//-------------Outros-----------//

void menu_inicial();
void escolha_opcao(int opcao, Lista *);
int busca_escolha(Lista lista);
void limpar_tela();
void abertura();
int gerar_codigo();
void tela();
void telaC(); 
