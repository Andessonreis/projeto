#include "sistema.h"

bool ler_arquivo(Lista* listas){
  FILE *file = fopen("TURISMO.bin", "rb");

  if(file != NULL){
    No *no = malloc(sizeof(No));
    
    while(fread(&no->pacotes,sizeof(Pacotes),1,file))
      inserir_lista(listas, no->pacotes);
  } else
      return false;
  return true;

  fclose(file);
}

void salvar_arquivo(Lista* listas){
  FILE *file;
  file = fopen("TURISMO.bin","wb");
  No *no = listas->inicio;

  if(file == NULL)
    printf("ERRO AO ABRIR O ARQUIVO\n");
  else{
    while(no){
      fwrite(&no->pacotes, sizeof(Pacotes),1,file); 
      no = no->proximo; 
    }
    fclose(file);
  }
}