//----------- Cabeçario ----------//
#ifndef SISTEMA_H_INCLUDED
#define SISTEMA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#endif // SISTEMA_H_INCLUDED


//---------- Estrutura do passageiro ----------//
typedef struct
{

    int codigo_passageiro;
    char nome[50];
    int telefone;

} Passageiro;

//---------- Estrutura do pacotes ----------//
typedef struct
{
    int codigo_pacotes;
    int valor;
    char destino[40];
    Passageiro passageiro;

} Pacotes;

//---------- Estrutura do No ----------//
typedef  struct no
{
    Pacotes *pacotes;
    struct no *proximo;
} No;

//---------- Estrutura da lista  ----------//
typedef struct
{
    No *inicio;
    int tamanho;

} Lista;


//---------- Prototipos ----------//
bool inserir_lista(Lista *, Pacotes*);
Pacotes *cadastro_pacotes(Lista *);
void imprimir_lista(Lista *);
char gerador_caractere();
int *gerador_de_codigo();



