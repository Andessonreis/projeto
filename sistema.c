#include "sistema.h" //incluindo as structs;

//----------Funcao para limpar a tela---------//
void limpar_tela(){
    system("cls");
}

//---------CRIAR LISTA--------//
bool criar_lista(){
    Lista *lista = malloc(sizeof(Lista));
    lista->inicio = NULL;
    return true;
}
//----------MENU INICIAL----------//
void menu_inicial(){
    limpar_tela();
        printf("\t\nMENU INICIAL\n");
        printf("\n<1> Iniciar cadastro de pacotes de viagem\n"
                    "<2> Lista todos os pacotes cadastrado\n");
}

//---------ESCOLHA DE OPCOES---------//
void escolha_opcao(int opcao,Lista *lista){
            switch(opcao)
        {
        case 1:
            inserir_lista(&lista, cadastro_pacotes(lista));
            break;
        case 2:
            imprimir_lista(&lista);
        }
}
//----------Cadastro de pacotes----------//
Pacotes* cadastro_pacotes(Lista *lista)
{
    Pacotes *pacotes = malloc(sizeof(Pacotes));
     if(pacotes == NULL){
        printf("Erro"); exit(1);
     }
    printf("\t\nMENU DE CADASTRO DE PACOTES\n\n");
    fflush(stdin);
    printf("Digite o destino da viagem: ");
    fgets(pacotes->destino, 40, stdin); setbuf(stdin, NULL);
    fflush(stdin);
    printf("Digite valor: ");
    scanf("%f", &pacotes->valor); fflush(stdin);

//---------Cadastro passageiro----------//
    printf("Digite o nome do passageiro: ");
    fgets(pacotes->passageiro.nome, 50, stdin);
    setbuf(stdin, NULL);
    printf("Telefone: ");
    scanf("%d", &pacotes->passageiro.telefone);
    fflush(stdin);
    limpar_tela();

        printf("cadastro realizado com sucesso\n");
        inserir_lista(lista, pacotes);
        return true;
    //system("cls");
    return pacotes;
}
    //gera segundo a tabela ascii e 65 e A
char gerador_caractere(){
    return (rand()%26 + 65);
}
int *gerador_de_codigo(){
    char *codigo = (char *)malloc(sizeof(char));

    codigo[0] = gerador_caractere();
    codigo[1] = 48 + rand()%10;
    codigo[2] = gerador_caractere();
    codigo[3] = gerador_caractere();
    codigo[4] = 48 + rand()%10;
    codigo[5] = 48 + rand()%10;
    codigo[6] = gerador_caractere();
    codigo[7] = 48 + rand()%10;
}

Pacotes *codigos(Pacotes *pacotes){
     char cod_pacotes = gerador_de_codigo(), cod_passageiro = gerador_de_codigo();

   strcpy(pacotes->codigo_pacotes, cod_pacotes);
   strcpy(pacotes->passageiro.codigo_passageiro, cod_passageiro);
}

//---------- inserção no inicio da lista ----------//
bool inserir_lista(Lista *lista, Pacotes *pacotes)
{
    No *novo = (No*)malloc(sizeof(No));
    if(!novo)return false;
    else{
            novo->pacotes  = pacotes;
            novo->proximo = lista->inicio;
            lista->inicio = novo;

    }
    return true;
}

//---------- Imprimindo Lista ----------//

void imprimir_lista(Lista *lista){
    No *novo;

    for(int i = 0; lista != NULL; i++){
        printf("%d\n", novo->pacotes->valor);
        novo = novo->proximo; 
    }

 }



