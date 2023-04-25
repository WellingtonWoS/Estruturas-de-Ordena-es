#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "Projeto_P1.h"
#include "Ordenacoes.h"
#define RUN 2
//metodo de definicao

//Alocar vetor
int *aloca_vetor(tam){
    int *v= (int*)malloc(tam * sizeof(int));
    return v;
}
//Criar um vetor com numeros aleatorios
void criaale_vetor(int *v, int tam){
    int i;
        for(i = 0; i < tam; i++)
    //rand -> retorna um numero pseudo-aleatorio.
            *(v + i) = rand();

}
//Criar um vetor para a ordenacao crescente
void vetor_crescente(int *v,int n){
    int i;
    for(i=0;i<n;i++){
        v[i]=i;
    //gera vetor crescente
    }
    printf("\nVetor crescente e:");
    for(i=0;i<n;i++){
        printf("%d-",v[i]);
    }
    printf("\n");
}
//Criar um vetor para a ordenacao decrescente
void vetor_decrescente(int *v,int n){
    int i,x=n;
    for(i=0;i<n;i++){
        v[i]=x;
        x-=1;
        //gera vetor decrescente
    }
    printf("\nVetor decrescente e:");
    for(i=0;i<n;i++){
        printf("%d-",v[i]);
    }
    printf("\n");
}
//Criar funcao para medir o tempo de cada algoritmo de ordenacao
double tempo_duracao(int argum,int *v,int tam){
    struct timeval Tempo_antes,Tempo_depois;
    double deltaT,tempant,tempdep;
    // gettimeofday -> calcular o tempo decorrido em um bloco de codigo
    //tempo inicial
    gettimeofday(&Tempo_antes,NULL);
    //switch que gera vetor ordenado com o algoritmo escolhido
    switch (argum)
            {
            case 1:
                bubblesort(v,tam);
                break;

            case 2:
                insertion(v,tam);
                break;

            case 3:
                selectionSort(v,tam);
                break;

            case 4:
                shellsort(v,tam);;
                break;

            case 5:
                mergesort(v, tam);
                break;

            case 6:
                quick_sort(v,0,tam);
                break;
            case 7:
                heapsort(v,tam);
                break;
            case 8:
                radixsortLSD(v,tam);
                break;
            case 9:
                timSort(v,tam);
                break;
            case 10:
                countingsort(v,tam);
                break;
            }
    //termino da ordenacao
    gettimeofday(&Tempo_depois,NULL);

    //deltat -> tempo total
    deltaT = (Tempo_depois.tv_sec + Tempo_depois.tv_usec/1000000.0 ) - (Tempo_antes.tv_sec + Tempo_antes.tv_usec/1000000.0 );
    //tempant -> tempo antes
    tempant=Tempo_antes.tv_sec + Tempo_antes.tv_usec/1000000.0;
    //tempdep -> tempo depois
    tempdep=Tempo_depois.tv_sec + Tempo_depois.tv_usec/1000000.0;
    //printf("Tempo antes\n");
    //printf("%f\n", tempant);
    //printf("Tempo depois\n");
    //printf("%f\n", tempdep);
    //printf("tempo total\n");
    //printf("%f\n", deltaT);

    return deltaT;
}


