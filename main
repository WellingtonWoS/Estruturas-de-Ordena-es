#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "Projeto_P1.h"
#include "Ordenacoes.h"
#define RUN 2
//bibliotecas
/* <sys/time.h> -> definir a estrutura de timeval que inclui pelo menos o
       seguintes membros: -time_t          tv_sec       Segundos.
              		  -suseconds_t     tv_usec Microssegundos */

int main(){
    int arg,teste,qtd,i,j,nesc;
    double result,soma[10],som_media,media,tempo_crescente,tempo_decrescente;
    do
    {
        //Menu -> Escolher o algoritmo de ordenacao
        printf("======================Escolha um algoritmo abaixo:============================\n\n");
        printf("\t 1    - BubbleSort\n");
        printf("\t 2    - InsertionSort\n");
        printf("\t 3    - SelectionSort\n");
        printf("\t 4    - ShellSort\n");
        printf("\t 5    - MergeSort\n");
        printf("\t 6    - QuickSort\n");
        printf("\t 7    - HeapSort\n");
        printf("\t 8    - RadixSort LSD\n");
        printf("\t 9    - TimSort\n");
        printf("\t 10   - CountingSort\n");
        scanf("%d", &arg);
        //Menu -> Escolher a quantidade de elementos
        printf("=====================Escolha uma quantidade de elementos:=====================\n\n");
        printf("\t 1    - mil\n");
        printf("\t 2    - 5mil\n");
        printf("\t 3    - 10mil\n");
        printf("\t 4    - 20mil\n");
        printf("\t 5    - 50mil\n");
        printf("\t 6    - 100mil\n");
        scanf("%d", &nesc);
        //switch que insere valor de elementos escolhidos no menu
        switch (nesc)
            {
            case 1:
                qtd=1000;
                break;

            case 2:
                qtd=5000;
                break;

            case 3:
                qtd=10000;
                break;

            case 4:
                qtd=20000;
                break;

            case 5:
                qtd=50000;
                break;

            case 6:
                qtd=100000;
                break;
            }

            int *v;//criacao de ponteiro
                for(i=0;i<10;i++){
                        //for para armazenar o tempo de duracao de cada algoritmo
                    v= aloca_vetor(qtd);//alocacao de vetor
                    criaale_vetor(v, qtd);//cria vetor aleatorio
                    //printf("\ntempo %d\n",i+1);
                    result = tempo_duracao(arg,v,qtd);//traz resultado de tempo de duracao
                    som_media=result+som_media;//faz o armazenamento dos valores de duracao
                    free(v);//desaloca vetor
                }
                media=som_media/10;//media da duracao dos algoritmos
                v= aloca_vetor(qtd);
                vetor_crescente(v,qtd);//vetor crescente sequenciado
                tempo_crescente = tempo_duracao(arg,v,qtd);//tempo de duracao para ordenacao
                vetor_decrescente(v,qtd);//vetor decrescente sequenciado
                tempo_decrescente = tempo_duracao(arg,v,qtd);//tempo de duracao para ordenacao
                printf("\nEsta e a media %f\n\n",media);
                printf("O tempo de execucao do vetor crescente e de: %f",tempo_crescente);
                printf("\nO tempo de execucao do vetor decrescente e de: %f",tempo_decrescente);
        printf("\nNovo teste?\n sim=1 nao=2\n");//loop para utilizacao do menu
        scanf("%d", &teste);
        free(v);//desaloca vetor
    }while (teste == 1);
}
