#include <stdio.h>
#include "algoritmos.h"
int main(){
       int escolha;
       do
       {
            printf("===============menu===============\n");
            printf("1 - Método de ordenação SelectionSort\n");
            printf("2 - Método de ordenação InsertionSort\n");
            printf("3 - Método de ordenação MergeSort\n");
            printf("4 - Método de ordenação QuickSort\n");
            printf("0 - sair\n");
            printf("==================================\n");
            printf("escolha qual algoritmo quer rodar:\n");
            scanf("%d", &escolha);
       
       switch (escolha)
       {
            case 1:
   
               int tamanho = menuEscolhas();
               int vetCrescente[tamanho];
               criaVetorCrescente(tamanho, vetCrescente);
            
            for (int i = 0; i < tamanho; i++)
            {
               printf("%d", vetCrescente[i]);
            }
            
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