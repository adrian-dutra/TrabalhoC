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
        quickSort(menor, p - 1, vet);
        quickSort(p + 1, maior, vet);
    }
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