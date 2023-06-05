#include <stdio.h>
#include "algoritmos.h"
int main(){
       int escolha;
       do
       {
            printf("===============menu===============\n");
            printf("1 - opção\n");
            printf("2 - opção\n");
            printf("3 - opção\n");
            printf("4 - opção\n");
            printf("0 - sair\n");
            printf("==================================\n");
            printf("escolha qual algoritmo quer rodar:\n");
            scanf("%d", escolha);
       
       switch (escolha)
       {
            case 1:
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
            default:
            printf("Erro sua escolha deve ser entre 1 e 4 !");    
            break;
       }
       } while (escolha!=0);
}