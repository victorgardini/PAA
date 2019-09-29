#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define incremento 20000
#define tamanho_inicial 10000

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

// QuickSort
int partition(int * A, int p, int r) {
    int j, aux;
    int x = A[r-1];
    int i = p-1;
    for (j = p; j < r-1; j++){
        if (A[j] <= x) {
            i++;
            aux = A[i];
            A[i] = A[j];
            A[j] = aux;
        }
    }
    aux = A[i+1];
    A[i+1] = A[r-1];
    A[r-1] = aux;
    
    return i+1;
}

void quicksort(int * A, int p, int r){
    if (p < r){
        int q = partition(A, p, r);
        quicksort(A, p, q);
        quicksort(A, q+1, r);
    }
}

// int main() {
//    srand(time(NULL));
//    int tamanho = 10;
//    int i, * v = gerarVetorDesordenado(tamanho);
//    for (i = 0; i < tamanho; i++)
//        printf("%6d", v[i]);

//    printf("\n\n\n");
//    quicksort(v, 0, tamanho);

//    for (i = 0; i < tamanho; i++)
//        printf("%6d", v[i]);

//    printf("\n\n\n");
//    return 0;
// }

int main() {
    int i, tamanho, * v = NULL;
    double start;
    FILE * file = NULL;
    srand(time(NULL));


    // 1: melhor caso --> ordenado
    printf("1 caso: ordenado...\n");
    file = fopen("ordenado.csv", "w");
    if (file == NULL) {
        printf("\n >>> Erro ao criar arquivo!");
        return 0;
    }
    fprintf(file, "tamanho,tempo\n");
    for (tamanho = tamanho_inicial, i = 1; i <= 8; i++, tamanho+=incremento) {
        v = gerarVetorOrdenado(tamanho);
        start = tempo();
        quicksort(v, 0, tamanho);
        fprintf(file, "%d,%f\n", tamanho, (tempo() - start));
    }
    fclose(file);

    // 2: caso intermediário --> desordenado
    printf("2 caso: desordenado...\n");
    file = fopen("desordenado.csv", "w");
    if (file == NULL) {
        printf("\n >>> Erro ao criar arquivo!");
        return 0;
    }
    fprintf(file, "tamanho,tempo\n");
    for (tamanho = tamanho_inicial, i = 1; i <= 8; i++, tamanho+=incremento) {
        v = gerarVetorDesordenado(tamanho);
        start = tempo();
        quicksort(v, 0, tamanho);
        fprintf(file, "%d,%f\n", tamanho, (tempo() - start));
    }
    fclose(file);

    // 3: caso pior caso --> inversamente ordenado
    printf("3 caso: inversamente ordenado...\n");
    file = fopen("ordenadoInversamente.csv", "w");
    if (file == NULL) {
        printf("\n >>> Erro ao criar arquivo!");
        return 0;
    }
    fprintf(file, "tamanho,tempo\n");
    for (tamanho = tamanho_inicial, i = 1; i <= 8; i++, tamanho+=incremento) {
        v = gerarVetorOrdenadoInversamente(tamanho);
        start = tempo();
        quicksort(v, 0, tamanho);
        fprintf(file, "%d,%f\n", tamanho, (tempo() - start));
    }
    fclose(file);

    return 0;
}
