#include<stdio.h>
#include<time.h>
#include "algoritmos.h"
clock_t start, end;
double tempo_selection, tempo_insertion, tempo_merge, tempo_quick;

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




void incertionSort(int n, int vet[]){
    start = clock();

    int i, chave, j;
    for(i = 1; i < n; i++){
        chave = vet[i];
        j = i - 1;
        while(j >= 0 && vet[j] > chave){
            vet[j + 1] = vet[j];
            j = j -1;
        }
        vet[j + 1] = chave;
    }
    end = clock();
    tempo_insertion = ((double) (end - start)) / CLOCKS_PER_SEC;
}



void merge(int l, int m, int r, int vet[]){

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

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vet[k] = L[i];
            i++;
        }
        else {
            vet[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vet[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        vet[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int l, int r, int vet[]) {
    start = clock();

    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(l, m, vet);
        mergeSort(m + 1, r, vet);

        merge(l, m, r, vet);
    }
    end = clock();
    tempo_merge = ((double) (end - start)) / CLOCKS_PER_SEC;
}


void quickSort(int menor, int maior, int vet[]){
    start = clock();

    if(menor < maior){
        int p = parte(menor, maior, vet);
        quickSort(menor, p - 1, vet);
        quickSort(p + 1, maior, vet);
    }
    end = clock();
    tempo_quick = ((double) (end - start)) / CLOCKS_PER_SEC;
}
int parte(int menor, int maior, int vet[]){

    int pi = vet[maior];
    int i = (menor - 1);
    for(int j = menor; j <= maior - 1; j++){
        if(vet[j] < pi){
            i++;
            swap(&vet[i], &vet[j]);
        }
    }
    swap(&vet[i + 1], &vet[maior]);
    return(i + 1);
}


void criaVetorCrescente(int n, int* vet) {
    int i = 0;
    int num = 1;
    do {
        vet[i] = num;
        num++;
        i++;
    } while (i != n);
}

int* criaVetorDecrescente(int n){

int i = 0;
    int* vet = (int*)malloc(n * sizeof(int));
    int num = n;
    do {
        vet[i] = num;
        num--;
        i++;
    } while (num >= 1);
    return vet;

}

int* criaVetorDesordenado(int n) {
    int i = 0;
    int* vet = (int*)malloc(n * sizeof(int));
    int num = 1;
    do {
        vet[i] = num;
        num++;
        i++;
    } while (i != n);
    
    int metade = n/2;
    int aux = 0;

    for(int i = 0; i < metade; i = i + 1 + i ){
        aux = vet[i];
        vet[i] = vet[i+1];
        vet[i+1] = aux;

    }
    
    return vet;

}

int menuEscolhas(){
    int escolha;
    int n;
    printf("Escolha com quantos numeros o vetor sera criado:");
    printf("1 - 100");
    printf("2 - 1000");
    printf("3 - 10000");
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
        n =10000;
        break; 
    default:
        printf("voce deve esolher entre 1 e 3 !!!");
        break;
    }
    
    return n

}

