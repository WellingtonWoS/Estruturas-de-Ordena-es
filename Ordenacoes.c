#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define RUN 2

//1 Bubblesort
int bubblesort(int *v,int tam)
{
    int i,continua,aux,fim=tam;
    do{
        continua=0;
    for(i=0;i<fim-1;i++)
            if(v[i]>v[i+1])   /* Se você deseja classificar em ordem decrescente, altere> para <apenas aqui. */
            {
                aux=v[i];
                v[i]=v[i+1];
                v[i+1]=aux;
                continua=i;
            }
        fim--;

    }while(continua !=0);
}
// 7Heapsort
void heapsort(int *v, int n)
{
    setlocale(LC_ALL, "");
    int i, aux;

    for (i = (n - 1) / 2; i >= 0; i--) //cria heap a partir dos dados
    {                                  //metade do vetor até a primeira posição e analisar para criar heap
        criaHeap(v, i, n - 1);
    }

    for (i = n-1; i >= 1; i--) //reconstruir heap
    {
        aux = v[0];       //pega o maior elemento da heap e coloca na sua posição correspondente no array (quando no topo, tirando ele da heap)
        v[0] = v[i];
        v[i] = aux;
        criaHeap(v, 0, i - 1);
    }
}

void criaHeap (int *v, int i, int f)
{
    int aux = v[i]; //auxiliar primeira posição da partição
    int j = i * 2 + 1; //primeiro filho dele

    while (j <= f){ //enquanto filho menor do que o final do vetor
        if (j < f){
            if(v[j] < v [j+1]){ //pai tem 2 filhos? quem é o maior?
                j = j +1;
            }
        }
        if (aux < v[j]){  //filho maior que o pai?
            v[i] = v[j]; //filho se torna o pai!
            i = j;           //repetir o processo
            j = 2 * i + 1;
        }else{
            j = f + 1;
        }
    }
    v[i] = aux; //antigo pai ocupa lugar o último filho analisado
}
//8RadixsortLSD
// Essa função retornará o maior elemento do Array
int pega_Valor_Max(int *v, int n) {
  int max = v[0];   //max irá receber o vetor da posição zero
  for (int i = 1; i < n; i++)
    if (v[i] > max){    //Aqui o programa irá verificar
                            //se o vetor passado possui um
                            //valor maior q max
        max = v[i];     //assim a variavel max irá receber
                            //o valor mais alto ate o programa
                            // rodar todo o vetor
      }
  return max;
}

// Usando counting sort para classificar os elementos com base
// em lugares significativos
void contador(int *v, int tamanho, int divisor) {
  int resultado[tamanho + 1]; //Declarando a varivel resultado com o tamanho + 1
  int max = (v[0] / divisor) % 10;//Declarando a variavel max com
                                        //o array na primeira posição divido pelo
                                        // o divisor
                                      // que possui a finalidade de transitar entre
                                      // as casas

  for (int i = 1; i < tamanho; i++){
    if (((v[i] / divisor) % 10) > max)
      max = v[i];
  }// um laço de repetição para contar a frenquencias dos digitos
  // e para descobrir o valor max

  int count[max + 1];

  for (int i = 0; i < max; ++i){
    count[i] = 0;
    }// laço de repetição para zerar as casas
    // do vetor e guardar o valor max

  // Calculando a quantidade de elementos
  for (int i = 0; i < tamanho; i++){
    count[(v[i] / divisor) % 10]++;
  }

  // Calculando a soma acumulativa
  for (int i = 1; i < 10; i++){
    count[i] += count[i - 1];
  }

  // Coloca os elementos em ordem no vetor resultado,
  // para passar para o array
  // ou seja, salvando os valores ordenados em
  //array para depois ordena o array
  for (int i = tamanho - 1; i >= 0; i--) {
    resultado[count[(v[i] / divisor) % 10] - 1] = v[i];
    count[(v[i] / divisor) % 10]--;
  }
    // laço de repetição que copia o array ordenado
  for (int i = 0; i < tamanho; i++){
    v[i] = resultado[i];
  }
}

// Função principal para implementação do Radix
void radixsortLSD(int *v, int tamanho) {
  // Pegando o elemento maximo
  int max = pega_Valor_Max(v, tamanho);

  // Aplicando o contador para classificar elementos com base no valor
  // posicional ou seja verificando sua casa "unidade,dezena,centena...".

    for (int lugar = 1; max / lugar > 0; lugar *= 10){
    contador(v, tamanho, lugar);
    }
}
//5 Mergesort
/*
  Dado um vetor de inteiros v e um inteiro n >= 0, ordena o vetor v[0..n-1] em ordem crescente.
*/
void mergesort(int *v, int n) {
  int *c = malloc(sizeof(int) * n);
  sort(v, c, 0, n - 1);
  free(c);
}

/*
  Dado um vetor de inteiros v e dois inteiros i e f, ordena o vetor v[i..f] em ordem crescente.
  O vetor c é utilizado internamente durante a ordenação.
*/
void sort(int *v, int *c, int i, int f) {
  if (i >= f) return;

  int m = (i + f) / 2;

  sort(v, c, i, m);
  sort(v, c, m + 1, f);

  /* Se v[m] <= v[m + 1], então v[i..f] já está ordenado. */
  if (v[m] <= v[m + 1]) return;

  merge(v, c, i, m, f);
}


/*
  Dado um vetor v e três inteiros i, m e f, sendo v[i..m] e v[m+1..f] vetores ordenados,
  coloca os elementos destes vetores, em ordem crescente, no vetor em v[i..f].
*/
void merge(int *v, int *c, int i, int m, int f) {
  int z,
      iv = i, ic = m + 1;

  for (z = i; z <= f; z++) c[z] = v[z];

  z = i;

  while (iv <= m && ic <= f) {
    /* Invariante: v[i..z] possui os valores de v[iv..m] e v[ic..f] em ordem crescente. */

    if (c[iv] <= c[ic]) v[z++] = c[iv++];
    else v[z++] = c[ic++];
  }

  while (iv <= m) v[z++] = c[iv++];

  while (ic <= f) v[z++] = c[ic++];
}
//10Countingsort
int countingsort(int *v, int tam)
{
    //int vet[7] = {1,4,5,2,7,5,0};
    int maior, indice, j, quantidade,i;
    maior = v[0];
    for(i=0; i<tam; i++){
        if( v[i]>maior){
            maior = v[i];
            }
    }
    int vet_counting_sort[maior+1];
    for(i=0; i<maior+1;i++){
        vet_counting_sort[i]=0;
    }
    for( i=0; i<tam;i++){
    indice = v[i];
    vet_counting_sort[indice]++;
    }
    return 0;

}
//4shellsort

// Funcao de ordenacao de algoritmos: ShellSort.
// Sao passados 2 parametros para a funcao: o endereco
// da vetor e seu tamanho definido na constante;
void shellsort(int *v, int N){

    // Declaracao de variáveis.
    // i, j: Servem para referenciar as posicoes/indices do vetor.
    // aux: variavel auxiliar que ira guardar o elemento das comparacoes
    // h: o coeficiente que irá determinar a distancia do salto entre os
    // vetores para melhor performar a ordenacao.
    int i, j, h, aux;

    // Antes de efetuar leituras no vetor, o programa primeiro precisa
    // identificar qual o melhor salto que pode ser feito entre os
    // elementos para entao serem ordenados mais rapidamente. Para isso,
    // o programa atribui um novo valor para h até que este valor seja
    // menor que o numero de elementos do vetor dividido poor tres
    h = 1;
    while(h < N/3){
        h = 3 * h + 1;
    }


    // Apos definir o h, o programa ira comecar a comparar os elementos
    // em h posicoes até que o vetor chege ao fim. Porem, ainda irao
    // existir elementos que nao foram comparados entre si, isso implica
    // na reducao do valor de h para que posicoes que nao foram comparadas
    // passem a ser, e isso se repete ate que o h seja reduzido para o valor
    // 1. Neste ponto, o programa ira funcionar com o sistema de ordenacao
    // do insertion sort, que compara elementos de 1 posicao de distancia.
    // Assim que a ultima passada no vetor for efetuada comparando elementos
    // de 1 posicao de distancia, o h sera reduzido a um valor menor que 1 no
    // final do laço, mas neste ponto, o vetor ja estara ordenado, e e por isso
    // que criamos um laco que so executa a ordenacao enquanto h for maior que 0.
    while(h > 0){

        // Aqui comecamos a comparacao ate que o vetor termine.
        // i vai receber o valor de h, e o valor auxiliar sera
        // aquele na posicao i do vetor, exemplo:

        //  v = {110, 104, 123, 91, 2, 44, 901, 84, 10, 78};
        //  i = 4;
        //      aux = 2
        //      j = 4
        for(i = h; i < N; i++){
            aux = v[i];
            j = i;

            // Em seguida, entramo no laco para verificar se o elemento
            // da posicao j e maior que o elemento na posicao h:

            // 4 >= 4 && 2 < 110? TRUE

            // Em caso positivo, o elemento de indice j recebe o valor
            // da posicao j-h, enquanto o j é decrementado em h unidades:

            // v[4] = v[0]
            // j = 4-4 = 0

            // Dessa forma, os elementos vao sempre ser comparados assim:

            // v[4] com v[0]
            // v[5] com v[1]
            // v[6] com v[2]
            // v[7] com v[3]
            // v[8] com v[4]
            // v[9] com v[5]


            while(j >= h && aux < v[j - h]){
                v[j] = v[j - h];
                j = j - h;

            }

            // O valor auxiliar so e recuperado e reordenado da variavel aux
            // no final das comparacoes do laco while anterior. Isto e importante
            // pois, eventualmente, o valor de h sera igual a 1, e mais de uma
            // comparacao pode ser feita no laco while anterior, e mais elementos
            // devem ser ordenados para que assim a insercao do valor na variavel
            // auxiliar ocorra de forma ordenada.
            v[j] = aux;


        }

        // Depois que todas as comparacoes sao feitas com o intervalo de h posicoes,
        // o valor e reajustado da melhor forma atraves da formula abaixo, e mais uma
        // vez os valores sao comparados entre o novo valor de h posicoes de distancia
        // no vetor ate que o resultado dessa formula para h seja menor que 0, onde a
        // ordenacao e encerrada.

        // h = (4-1)/3
        // h = 1
        h = (h-1)/3;

    }

}
//9Timsort

// =============== Funcoes auxiliares ===============(Nao retirar e deixar como subtitulo)
//Abaixo esta uma funcao auxiliar que pode ordenar um array por ordenacao por insercao.
//Nome: insertionSort
// Input(s):
//(1)'arr' e um ponteiro para um endereco inteiro.
//Este e o inicio de algum 'bloco de memoria contiguo' que vamos classificar.
//(2) 'l' e 'r' sao inteiros, que sao o primeiro indice e o ultimo indice de 'arr' respectivamente.
//Output: Nenhum valor e retornado, mas 'arr' deve ser modificado para armazenar uma matriz ordenada de numeros.

void insertionSort(int arr[], int l, int r) { // funcao e declarada com o vetor, o valor de i do for na funcao timsort e o retorno de arg1 ou arg2 da funcao min
    if (arr == NULL || l>=r) return; // se o vetor for nulo ou l(i do for da funcao timsort) for maior ou igual a r(resultado da funcao min) entao returna nada

    int key;
    int i, j; // variaveis locais criadas para o for da funcao
    for (i=l+1; i<=r; i++) { // repeticao comparando a sentenca de i sendo menor ou igual a r
        key = arr[i]; // enquanto verdadeiro variavel key recebe valor do indice do vetor onde o indice e igual a i da funcao
        j = i-1; // variavel j recebe o valor de i - 1 ficando assim com o indice anterior ao de i
        while (j>=l && arr[j]>key) { //enquanto o j for maior e igual a l e o valor do vetor no indice j for maior que key
            arr[j+1] = arr[j]; // indice j+1 no vetor recebe valor do indice j do vetor
            j--; //j e decrementado
        }
        arr[j+1] = key; // apos terminar o while o vetor no indice j+1 recebe o valor de key
    }

}

//==============funcao de mesclagem.=============(Fazer como subtitulo)
//Nome: merge
//Input(s):
//(1)'arr' e um ponteiro para um endereco inteiro.
//Este e o inicio 'bloco de memoria contiguo' que vamos classificar.
//(2) 'temp' e um ponteiro para um endereco inteiro.

//Isso ajuda a armazenar temporariamente o subarray classificado.
//(3) 'l', 'm' e 'r' sao inteiros, que sao o primeiro indice, o meio e o ultimo indice de 'array' respectivamente.
//Output: Nenhum valor e retornado, mas 'array' deve ser modificado para armazenar um array ordenado de numeros.
void merge_timsort(int arr[], int temp[], int l, int m, int r){// funcao e declarada com vetor principal, vetor temporario, l que e o valor de for da funcao timsort, m tambem da funcao timsort e r da funcao timsort
    if (arr == NULL || temp == NULL) return; // comparativo onde vetor caso nulo ou vetor temporario caso nulo retorna nada
    if (l > m || m+1 > r) return; // se l for maior que m ou m+1 for maior que r returna nada

    int i = l; // i recebe l
    int j = m + 1; // j recebe m mais 1
    int start = l; // start recebe l // variaveis locais criadas para while

    while (i <= m && j <= r){ //enquanto i for menor ou igual a m  e j for menor ou igual a r
	if (arr[i] < arr[j]){ // se indice i do vetor for menor a indice j do vetor entao
	    temp[start++] = arr[i++];// indice start incrementado do vetor temporario receber valor do indice i incrementado do vetor principal
	} else if (arr[i] == arr[j]){ // se nao for verdadeiro e indice i do vetor for igual a indice j do vetor
	    temp[start++] = arr[i++]; // indice start incrementado do vetor temporario receber valor do indice i incrementado do vetor principal

	    temp[start++] = arr[j++]; //indice start incrementado do vetor temporario receber valor do indice j incrementado do vetor principal
	}
	else{ // se nenhuma das comparacoes for verdadeira
	    temp[start++] = arr[j++];//indice start incrementado do vetor temporario receber valor do indice j incrementado do vetor principal
	}

    }

    while (i <= m){ // enquanto i for menor ou igual a m
	    temp[start++] = arr[i++]; // indice start incrementado do vetor temporario receber valor do indice i incrementado do vetor principal
    }


    while (j <= r){ //enquanto j menor ou igual a r
	    temp[start++] = arr[j++]; // indice start incrementado do vetor temporario receber valor do indice j incrementado do vetor principal
    }

    for (i = l; i <= r; i++){ // repeticao ocorre enquanto i for menor ou  igual a r
	    arr[i] = temp[i]; // indice i do vetor principal receber valor do indice i do vetor temporario
    }
}

//===============funcao min=============(subtitulo)
//Nome: min
//Input(s):
//(1) 'arg1' and 'arg2' sao dois inteiros para comparar.
//Output:o menor inteiro.

//Resumo: funcao que divide em subvetores.

int min(int arg1, int arg2){ // funcao que foi chamada para o comparativo de dois valores arg1(entra o valor de i+RUN-1) e arg2 (Valor de size-1)
    if (arg1 <= arg2){ // comparativo entre arg1 sendo menor ou igual a arg2
        return arg1; // se verdadeiro retorna o valor arg1
    } else {
        return arg2;// se falso retorna valor de arg2
    }
}

//==============funcao de classificacao.=========(subtitulo)
//Name: timSort
//Input(s):
//(1) 'arr' e um ponteiro para um endereco inteiro
//Este e o inicio de 'bloco de memoria contiguo' que iremos sort.
//(2)'size' nos diz o tamanho do array de dados que estamos classificando.
// Output: Nenhum valor e retornado, mas 'arr' deve ser modificado para armazenar uma matriz ordenada de numeros.
//Comece a mesclar a partir do tamanho RUN. Ele sera mesclado no tamanho 2*RUN, depois 4*RUN, e assim por diante.
//'l', 'm' e 'r' sao os indices esquerdo, medio e direito de dois subarranjos contiguos.
//'n' e o tamanho de um subarray.
// Resumo : Mesclagem em varios tempo de respostas

void timSort(int arr[], unsigned int size){ //funcao e declarada com o vetor e o tamanho do vetor em variavel sem sinal
    if (arr == NULL || size <= 1) return; //comparacao para ver se o vetor e nulo ou o tamanho dele e menor que 1, se sim retorna nada
    for (int i=0; i < size; i+=RUN){ //caso nao inicia o for para iniciar uma repeticao baseado no tamanho de run
        insertionSort(arr, i, min(i+RUN-1, size-1)); // a repeticao serve para chamar nova funcao chamada insertionsort que fara a ordenacao dos vetores, ela e declarada com o vetor, o valor de i sendo essa uma variavel auxiliar e uma funcao chamada min
    }

    int* temp = (int*)malloc(sizeof(int)*size);// e criado um vetor temporario e alocado em memoria


    int l, m, r, n; // criacao de variaveis locais para utilizacao em for
    for (n=RUN; n < size; n*=2){// repeticao acontece durante n for menor que size(tamanho do vetor), n recebe n vezes 2
        for (l=0; l < size; l+=2*n){ //repeticao acontece durante l for menor que size e l recebe a soma de l mais duas vezes o valor de n
            m = l+n-1; // m recebe valor de l mais n menos 1
            r = min(l+2*n-1, size-1); // recebe valor da funcao min correspondente ao arg1 sendo l+2*n-1 e arg2 size-1, o resultado que a funcao der esse e o valor inserido em r
            if (m<r){ // comparativo do valor obtido de m sendo menor que o resultado de r
                merge(arr, temp, l, m, r);// caso verdadeiro chama a funcao merge
            }
        }
    }
    free(temp); // libera valor allocado de temp
}

//=============funcao de impressao==============(subtitulo)
// Name: printIntArray
// Input(s):
//(1) 'arr' e um ponteiro para um endereco inteiro.
//(2)'size' nos diz o quao grande e o array de dados.
//Output: Nenhum valor e retornado, apenas imprime 'arr'.


//6Quicksort

// Função de Ordenação por Seleção
// Quick sort function
void quick_sort(int *v, int left, int right) {
    int i, j, x, y;

    i = left;
    j = right;
    x = v[(left + right) / 2];

    while(i <= j) {
        while(v[i] < x && i < right) {
            i++;
        }
        while(v[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = v[i];
            v[i] = v[j];
            v[j] = y;
            i++;
            j--;
        }
    }

    if(j > left) {
        quick_sort(v, left, j);
    }
    if(i < right) {
        quick_sort(v, i, right);
    }
}

//3selectionsort

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int *v, int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (v[j] < v[min_idx])
            min_idx = j;

        // Swap the found minimum element with the first element
        if(min_idx != i)
            swap(&v[min_idx], &v[i]);
    }
}

//2insertion_sort


// Função de Ordenação por Inserção
// Insertion sort function
void insertion(int *v,int tam)
{
 int i, j, tmp;

 for(i = 1; i < tam; i++)
 {
  tmp = v[i];
  for(j = i-1; j >= 0 && tmp < v[j]; j--)
  {
   v[j+1] = v[j];
  }
  v[j+1] = tmp;
 }
}
