#include <stdio.h>
#include <stdlib.h>
#include <time.h>

clock_t start, end;
double tempo_insertion, tempo_merge, tempo_quick;
double tempo_selection_Crescente, tempo_selection_Decrescente, tempo_selection_Desordenado, tempo_selection_Aleatorio;
double tempo_inserction_Crescente, tempo_insertion_Decrescente, tempo_insertion_Desordenado, tempo_insertion_Aleatorio;
double tempo_merge_Crescente, tempo_merge_Decrescente, tempo_merge_Desordenado, tempo_merge_Aleatorio;

int menuEscolhas();
void criaVetorCrescente(int n, int *vet);
void criaVetorDecrescente(int n, int *vet);
void criaVetorLevementeDesordenado(int n, int *vet);
void criaVetorAleatorio(int n, int *vet);
void swap(int *a, int *b);
void selectionSort(int n, int vet[]);
void insertionSort(int n, int vet[]);
void merge(int l, int m, int r, int vet[]);
void mergeSort(int l, int r, int vet[]);
void quickSort(int menor, int maior, int vet[]);
int parte(int menor, int maior, int vet[]);

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
                printf("TEMPO DO SELECTION SORT VETOR ALEATORIO: %lf\n", tempo_selection_Aleatorio);
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

        case 3:
            if (vetCrescente != NULL)
            {
                start = clock();
                insertionSort(tamanho, vetCrescente);
                end = clock();
                tempo_inserction_Crescente = ((double)(end - start)) / CLOCKS_PER_SEC;
                /*for (int i = 0; i < tamanho; i++)
                {
                    printf("%d\n", vetCrescente[i]);
                }*/
                printf("\n");
                printf("-----------------------------------------------------------------");
                printf("\n");
                printf("\n");
                printf("TEMPO DO INSERTION SORT VETOR CRESCENTE ORDENADO: %lf\n", tempo_inserction_Crescente);
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
                insertionSort(tamanho, vetDecrescente);
                end = clock();
                tempo_insertion_Decrescente = ((double)(end - start)) / CLOCKS_PER_SEC;
                /*for (int i = 0; i < tamanho; i++)
                {
                    printf("%d\n", vetDecrescente[i]);
                }*/
                printf("\n");
                printf("-----------------------------------------------------------------");
                printf("\n");
                printf("\n");
                printf("TEMPO DO INSERTION SORT VETOR DECRESCENTE ORDENADO: %lf\n", tempo_insertion_Decrescente);
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
                insertionSort(tamanho, vetDesordenado);
                end = clock();
                tempo_insertion_Desordenado = ((double)(end - start)) / CLOCKS_PER_SEC;
                /*for (int i = 0; i < tamanho; i++)
                {
                    printf("%d\n", vetDesordenado[i]);
                }*/
                printf("\n");
                printf("-----------------------------------------------------------------");
                printf("\n");
                printf("\n");
                printf("TEMPO DO INSERTION SORT VETOR LEVEMENTE DESORDENADO: %lf\n", tempo_insertion_Desordenado);
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
                insertionSort(tamanho, vetAleatorio);
                end = clock();
                tempo_insertion_Aleatorio = ((double)(end - start)) / CLOCKS_PER_SEC;
                /* for (int i = 0; i < tamanho; i++)
                 {
                     printf("%d\n", vetAleatorio[i]);
                 }*/
                printf("\n");
                printf("-----------------------------------------------------------------");
                printf("\n");
                printf("\n");
                printf("TEMPO DO INSERTION SORT VETOR ALEATORIO: %lf\n", tempo_insertion_Aleatorio);
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

        case 4:
            if (vetCrescente != NULL)
            {
                start = clock();
                mergeSort(0, tamanho - 1, vetCrescente);
                end = clock();
                tempo_merge_Crescente = ((double)(end - start)) / CLOCKS_PER_SEC;
                /*for (int i = 0; i < tamanho; i++)
                {
                    printf("%d\n", vetCrescente[i]);
                }*/
                printf("\n");
                printf("-----------------------------------------------------------------");
                printf("\n");
                printf("\n");
                printf("TEMPO DO MERGE SORT VETOR CRESCENTE ORDENADO: %lf\n", tempo_merge_Crescente);
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
                mergeSort(0, tamanho - 1, vetDecrescente);
                end = clock();
                tempo_merge_Decrescente = ((double)(end - start)) / CLOCKS_PER_SEC;
                /*for (int i = 0; i < tamanho; i++)
                {
                    printf("%d\n", vetDecrescente[i]);
                }*/
                printf("\n");
                printf("-----------------------------------------------------------------");
                printf("\n");
                printf("\n");
                printf("TEMPO DO MERGE SORT VETOR DECRESCENTE ORDENADO: %lf\n", tempo_merge_Decrescente);
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
                mergeSort(0, tamanho - 1, vetDesordenado);
                end = clock();
                tempo_merge_Desordenado = ((double)(end - start)) / CLOCKS_PER_SEC;
                /*for (int i = 0; i < tamanho; i++)
                {
                    printf("%d\n", vetDesordenado[i]);
                }*/
                printf("\n");
                printf("-----------------------------------------------------------------");
                printf("\n");
                printf("\n");
                printf("TEMPO DO MERGE SORT VETOR LEVEMENTE DESORDENADO: %lf\n", tempo_merge_Desordenado);
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
                mergeSort(0, tamanho - 1, vetAleatorio);
                end = clock();
                tempo_merge_Aleatorio = ((double)(end - start)) / CLOCKS_PER_SEC;
                /*for (int i = 0; i < tamanho; i++)
                 {
                     printf("%d\n", vetAleatorio[i]);
                 }*/
                printf("\n");
                printf("-----------------------------------------------------------------");
                printf("\n");
                printf("\n");
                printf("TEMPO DO MERGE SORT VETOR ALEATORIO: %lf\n", tempo_merge_Aleatorio);
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
        case 5:
            if (vetCrescente != NULL)
            {
                start = clock();
                quickSort(0, tamanho - 1, vetCrescente);
                end = clock();
                tempo_merge_Crescente = ((double)(end - start)) / CLOCKS_PER_SEC;
                /*for (int i = 0; i < tamanho; i++)
                {
                    printf("%d\n", vetCrescente[i]);
                }*/
                printf("\n");
                printf("-----------------------------------------------------------------");
                printf("\n");
                printf("\n");
                printf("TEMPO DO QUICKSORT VETOR CRESCENTE ORDENADO: %lf\n", tempo_merge_Crescente);
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
                quickSort(0, tamanho - 1, vetDecrescente);
                end = clock();
                tempo_merge_Decrescente = ((double)(end - start)) / CLOCKS_PER_SEC;
                /*for (int i = 0; i < tamanho; i++)
                {
                    printf("%d\n", vetDecrescente[i]);
                }*/
                printf("\n");
                printf("-----------------------------------------------------------------");
                printf("\n");
                printf("\n");
                printf("TEMPO DO QUICKSORT VETOR DECRESCENTE ORDENADO: %lf\n", tempo_merge_Decrescente);
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
                quickSort(0, tamanho - 1, vetDesordenado);
                end = clock();
                tempo_merge_Desordenado = ((double)(end - start)) / CLOCKS_PER_SEC;
                /*for (int i = 0; i < tamanho; i++)
                {
                    printf("%d\n", vetDesordenado[i]);
                }*/
                printf("\n");
                printf("-----------------------------------------------------------------");
                printf("\n");
                printf("\n");
                printf("TEMPO DO QUICKSORT VETOR LEVEMENTE DESORDENADO: %lf\n", tempo_merge_Desordenado);
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
                quickSort(0, tamanho - 1, vetAleatorio);
                end = clock();
                tempo_merge_Aleatorio = ((double)(end - start)) / CLOCKS_PER_SEC;
                /*for (int i = 0; i < tamanho; i++)
                 {
                     printf("%d\n", vetAleatorio[i]);
                 }*/
                printf("\n");
                printf("-----------------------------------------------------------------");
                printf("\n");
                printf("\n");
                printf("TEMPO DO QUICKSORT VETOR ALEATORIO: %lf\n", tempo_merge_Aleatorio);
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
    printf("1  - 1000\n");
    printf("2  - 3000\n");
    printf("3  - 5000\n");
    printf("4  - 7000\n");
    printf("5  - 10000\n");
    printf("6  - 13000\n");
    printf("7  - 15000\n");
    printf("8  - 18000\n");
    printf("9  - 20000\n");
    printf("10 - 22000\n");
    scanf("%d", &escolha);

    switch (escolha)
    {
    case 1:
        n = 1000;
        break;
    case 2:
        n = 3000;
        break;
    case 3:
        n = 5000;
        break;
    case 4:
    n = 7000;
    break;
    case 5:
    n = 10000;
    break;
     case 6:
    n = 13000;
    break;
     case 7:
    n = 15000;
    break;
     case 8:
    n = 18000;
    break;
     case 9:
    n = 20000;
    break;
     case 10:
    n = 22000;
    break;
    default:
        printf("Você deve escolher entre 1 e 10!\n");
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

void insertionSort(int n, int vet[])
{

    int i, chave, j;
    for (i = 1; i < n; i++)
    {
        chave = vet[i];
        j = i - 1;
        while (j >= 0 && vet[j] > chave)
        {
            vet[j + 1] = vet[j];
            j = j - 1;
        }
        vet[j + 1] = chave;
    }
}

void merge(int l, int m, int r, int vet[])
{

    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = vet[l + i];
    for (j = 0; j < n2; j++)
        R[j] = vet[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            vet[k] = L[i];
            i++;
        }
        else
        {
            vet[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        vet[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        vet[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int l, int r, int vet[])
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(l, m, vet);
        mergeSort(m + 1, r, vet);

        merge(l, m, r, vet);
    }
}
void quickSort(int menor, int maior, int vet[])
{
    if (menor < maior)
    {
        int p = parte(menor, maior, vet);
        quickSort(menor, p - 1, vet);
        quickSort(p + 1, maior, vet);
    }
}
int parte(int menor, int maior, int vet[])
{
    int pi = vet[maior];
    int i = (menor - 1);
    for (int j = menor; j <= maior - 1; j++)
    {
        if (vet[j] < pi)
        {
            i++;
            swap(&vet[i], &vet[j]);
        }
    }
    swap(&vet[i + 1], &vet[maior]);
    return (i + 1);
}
