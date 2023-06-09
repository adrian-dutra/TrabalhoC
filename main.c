#include <stdio.h>
#include <stdlib.h>
#include <time.h>

clock_t start, end;
double tempo_insertion, tempo_merge, tempo_quick;
double tempo_selection_Crescente, tempo_selection_Decrescente, tempo_selection_Desordenado,tempo_selection_Aleatorio;

int menuEscolhas();
void criaVetorCrescente(int n, int *vet);
void criaVetorDecrescente(int n, int *vet);
void criaVetorLevementeDesordenado(int n, int *vet);
void criaVetorAleatorio(int n, int *vet);
void swap(int *a, int *b);
void selectionSort(int n, int vet[]);

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
            if (vetCrescente != NULL)
            {
                start = clock();
                selectionSort(tamanho, vetCrescente);
                end = clock();
                tempo_selection_Crescente = ((double)(end - start)) / CLOCKS_PER_SEC;
                /*for (int i = 0; i < tamanho; i++)
                {
                    printf("%d\n", vetCrescente[i]);
                }*/
                printf("\n");
                printf("-----------------------------------------------------------------");
                printf("\n");
                printf("\n");
                printf("TEMPO DO SELECTION SORT VETOR CRESCENTE ORDENADO: %lf\n", tempo_selection_Crescente);
                printf("\n");
                printf("-----------------------------------------------------------------");
                printf("\n");
                printf("\n");
            }
            else
            {
                printf("Erro: o vetor não foi criado! Use a opcao 1 do menu !\n");
            }
            if (vetDecrescente != NULL)
            {
                start = clock();
                selectionSort(tamanho, vetDecrescente);
                end = clock();
                tempo_selection_Decrescente = ((double)(end - start)) / CLOCKS_PER_SEC;
                /*for (int i = 0; i < tamanho; i++)
                {
                    printf("%d\n", vetDecrescente[i]);
                }*/
                printf("\n");
                printf("-----------------------------------------------------------------");
                printf("\n");
                printf("\n");
                printf("TEMPO DO SELECTION SORT VETOR DECRESCENTE ORDENADO: %lf\n", tempo_selection_Decrescente);
                printf("\n");
                printf("-----------------------------------------------------------------");
                printf("\n");
                printf("\n");
            }
            else
            {
                printf("Erro: o vetor não foi criado! Use a opcao 1 do menu !\n");
            }
            if (vetDesordenado != NULL)
            {
                start = clock();
                selectionSort(tamanho, vetDesordenado);
                end = clock();
                tempo_selection_Desordenado = ((double)(end - start)) / CLOCKS_PER_SEC;
                /*for (int i = 0; i < tamanho; i++)
                {
                    printf("%d\n", vetDesordenado[i]);
                }*/
                printf("\n");
                printf("-----------------------------------------------------------------");
                printf("\n");
                printf("\n");
                printf("TEMPO DO SELECTION SORT VETOR LEVEMENTE DESORDENADO: %lf\n", tempo_selection_Desordenado);
                printf("\n");
                printf("-----------------------------------------------------------------");
                printf("\n");
                printf("\n");
            }
            else
            {
                printf("Erro: o vetor não foi criado! Use a opcao 1 do menu !\n");
            }
             if (vetAleatorio != NULL)
            {
                start = clock();
                selectionSort(tamanho, vetAleatorio);
                end = clock();
                tempo_selection_Aleatorio = ((double)(end - start)) / CLOCKS_PER_SEC;
               /* for (int i = 0; i < tamanho; i++)
                {
                    printf("%d\n", vetAleatorio[i]);
                }*/
                printf("\n");
                printf("-----------------------------------------------------------------");
                printf("\n");
                printf("\n");
                printf("TEMPO DO SELECTION SORT VETOR LEVEMENTE DESORDENADO: %lf\n", tempo_selection_Aleatorio);
                printf("\n");
                printf("-----------------------------------------------------------------");
                printf("\n");
                printf("\n");
            }
            else
            {
                printf("Erro: o vetor não foi criado! Use a opcao 1 do menu !\n");
            }
            break;
        default:
            printf("Erro: sua escolha deve ser entre 0 e 4!\n");
            break;
        }
    } while (escolha != 0);

    // Liberando a memória alocada para os vetores
    free(vetCrescente);
    free(vetDecrescente);
    free(vetDesordenado);
    free(vetAleatorio);

    return 0;
}

int menuEscolhas()
{
    int escolha;
    int n;

    printf("Escolha com quantos numeros o vetor será criado:\n");
    printf("1 - 1000\n");
    printf("2 - 5000\n");
    printf("3 - 10000\n");
    scanf("%d", &escolha);

    switch (escolha)
    {
    case 1:
        n = 1000;
        break;
    case 2:
        n = 5000;
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
    criaVetorCrescente(n, vet);

    srand(time(NULL));

    for (int i = 0; i < n / 2; i++)
    {
        int j = rand() % n;
        swap(&vet[i], &vet[j]);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int n, int vet[])
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (vet[j] < vet[min_idx])
            {
                min_idx = j;
            }
        }
        swap(&vet[min_idx], &vet[i]);
    }
}