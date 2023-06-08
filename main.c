#include <stdio.h>
#include <stdlib.h>
#include <time.h>
clock_t start, end;
double tempo_selection, tempo_insertion, tempo_merge, tempo_quick;
int menuEscolhas();
void criaVetorCrescente(int n, int *vet);
void criaVetorDecrescente(int n, int *vet);
void criaVetorLevementeDesordenado(int n, int *vet);
void criaVetorAleatorio(int n, int *vet);
void swap(int* a, int* b);
void selectionSort(int n, int vet[])
int main()
{
    int escolha;
    int tamanho;
    int *vetCrescente = NULL;
    int *vetDecrescente = NULL;
    int *vetDesordenado = NULL;
    int *vetAleatorio = NULL;
    do
    {
        printf("===============menu===============\n");
        printf("1 - Criar vetores\n");
        printf("2 - Método de ordenação SelectionSort\n");
        printf("3 - Método de ordenação InsertionSort\n");
        printf("4 - Método de ordenação MergeSort\n");
        printf("5 - Método de ordenação QuickSort\n");
        printf("0 - sair\n");
        printf("==================================\n");
        printf("Escolha qual algoritmo quer rodar:\n");
        scanf("%d", &escolha);
        switch (escolha)
        {
        case 0:
            printf("Fim do programa\n");
            break;
        case 1:
            tamanho = menuEscolhas();
            printf("%d\n", tamanho);
            vetCrescente = malloc(tamanho * sizeof(int));
            criaVetorCrescente(tamanho, vetCrescente);
            vetDecrescente = malloc(tamanho * sizeof(int));
            criaVetorDecrescente(tamanho, vetDecrescente);
            vetDesordenado = malloc(tamanho * sizeof(int));
            criaVetorLevementeDesordenado(tamanho, vetDesordenado);
            vetAleatorio = malloc(tamanho * sizeof(int));
            criaVetorAleatorio(tamanho, vetAleatorio);
            break;
        case 2:

            break;
        default:
            printf("Erro: sua escolha deve ser entre 0 e 4!\n");
            break;
        }
    } while (escolha != 00);
    return 0;
}
int menuEscolhas()
{
    int escolha;
    int n;
    printf("Escolha com quantos numeros o vetor será criado:\n");
    printf("1 - 100\n");
    printf("2 - 1000\n");
    printf("3 - 10000\n");
    scanf("%d", &escolha);
    switch (escolha)
    {
    case 1:
        n = 100;
        break;
    case 2:
        n = 1000;
        break;
    case 3:
        n = 10000;
        break;
    default:
        printf("Você deve escolher entre 1 e 3!\n");
        break;
    }
    return n;
}
void criaVetorCrescente(int n, int *vet)
{
    for (int i = 0; i < n; i++)
    {
        vet[i] = i + 1;
    }
}
void criaVetorDecrescente(int n, int *vet)
{
    for (int i = 0; i < n; i++)
    {
        vet[i] = n - i;
    }
}
void criaVetorAleatorio(int n, int *vet)
{
    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        vet[i] = rand();
    }
}
void criaVetorLevementeDesordenado(int n, int *vet)
{
    for (int i = 0; i < n; i++)
    {
        vet[i] = i + 1;
    }
    srand(time(NULL));
    for (int i = 0; i < n / 2; i++)
    {
        int j = rand() % n;
        int temp = vet[i];
        vet[i] = vet[j];
        vet[j] = temp;
    }
}
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selectionSort(int n, int vet[]){
    start = clock();

    int i, j, menorn;
    for(i = 0; i < n; i++){
        menorn = i;
        for(j = i+1; j < n; j++){
            if(vet[j] < vet[menorn]){
                menorn = j;
            }
            swap(&vet[menorn], &vet[i]);
        }
    }
    end = clock();
    tempo_selection = ((double) (end - start)) / CLOCKS_PER_SEC;
}

