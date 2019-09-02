#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// retorna quanto tempo se foi desde que o programa foi inicializado
double tempo(){
    return (double) clock () / CLOCKS_PER_SEC;
}

// retorna um vetor de tamanho n gerado aleatóriamente (desordenado)
int * gerarVetorDesordenado(int tamanho) {
    int i, * v;

    // alocando o vetor
    v = (int *) malloc(tamanho * sizeof(int));

    // preenchendo o vetor com números de 0 a 100
    for (i = 0; i < tamanho; i++)
        v[i] = (int) rand() % 100 + 1;

    return v;
}

// melhor caso
int * gerarVetorOrdenado(int tamanho) {
    int i, * v;

    // alocando o vetor
    v = (int *) malloc(tamanho * sizeof(int));

    // preechendo o vetor
    for (i = 0; i < tamanho; i++)
        v[i] = i;

    return v;    
}

// pior caso
int * gerarVetorOrdenadoInversamente(int tamanho) {
    int i, j=0, * v;
    v = (int *) malloc(tamanho * sizeof(int));

    for (i=tamanho-1; i>0; i--, j++)
        v[j] = i;
    
    return v;
}

// Método de ordenação por inserção, v = vetor a ser ordenado, n = tamanho do vetor
int * insertionsort (int * v, int n){
    int i, j, x;

    for (i = 1; i < n; i++){
        x = v[i];
        j = i - 1;
        while (j >=0 && v[j] > x) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = x;
    }
    return v;
}

int main() {
    int i;

    // FILE * file = fopen("desordenado.csv", "w");
    FILE * file = fopen("ordenado.csv", "w");
    // FILE * file = fopen("ordenadoInversamente.csv", "w");

    if (file == NULL) {
        printf("\n >>> Erro ao criar arquivo!");
        return 0;
    }

    double start, stop, elapsed;
    srand(time(NULL));

    int tamanho = 10000, * v;
    fprintf(file, "tamanho,tempo\n");


    for (i = 1; i <= 8; i++, tamanho+=20000) { // repetir 5 vezes
        
        // v = gerarVetorDesordenado(tamanho);
        v = gerarVetorOrdenado(tamanho);
        // v = gerarVetorOrdenadoInversamente(tamanho);
        
        start = tempo();

        v = insertionsort(v, tamanho);

        fprintf(file, "%d,%f\n", tamanho, (tempo() - start));
    }

    fclose(file);

    return 0;
}