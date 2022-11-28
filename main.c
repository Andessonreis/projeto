#include "sistema.h" //incluindo as funções

int main()
{
    //---Inciando o gerador de codigos---//
    time_t seed = time(NULL);
    srand((int)seed);

    int opcao; Lista lista; Pacotes *p;
    //---------Iniciando a lista--------//
    criar_lista();

    do
    {
        menu_inicial();
        scanf("%d", &opcao);
        limpar_tela();
        escolha_opcao(opcao, lista);
    }while(opcao != 0);

    return 0;
}
