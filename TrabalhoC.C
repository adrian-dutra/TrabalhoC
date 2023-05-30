#include<stdio.h>
#include<time.h>


void swap(int* a, int* b){

    int temp = *a;
    *a = *b;
    *b = temp;

}

void selectionSort(int n, int vet[]){

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
}

void incertionSort(int n, int vet[]){

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
}

//ESPAÇO RESERVADO PRO MERGESORT


void quickSort(int menor, int maior, int vet[]){
    if(menor < maior){
        int p = parte(menor, maior, vet);
        quickSort(vet, menor, p - 1);
        quickSort(vet, p + 1, maior);

    }
}

int parte(int vet[], int menor, int maior){
    
}