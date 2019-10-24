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
        v[i] = (int) rand() % 10000 + 1;

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

// Heap Sort
void maxHeaphy(int * A, int i, int tam) {
    int l, r, maior, aux;
    maior = i;
    l = 2 * i;     // left(i)
    r = 2 * i + 1; // right(i)
    
    if (l <= tam && A[l] > A[i])
        maior = l;

    if(r <= tam && A[r] > A[maior])
        maior = r;
    
    if(maior != i) {
        aux = A[maior];
        A[maior] = A[i];
        A[i] = aux;
        maxHeaphy(A, maior, tam);
    }
}

void heapSort(int * A, int tam) {
    int aux, i;

    // buildHeapMax
    for(i = tam/2; i >= 0; i--)
        maxHeaphy(A, i, tam);

    for(i = tam - 1; i >= 0; i--){
        aux = A[0];
        A[0] = A[i+1]; // tam-1 é o último elemento do vetor
        A[i+1] = aux;
        maxHeaphy(A, 0, i);
    }
}

// int main() {
//    srand(time(NULL));
//    int tamanho = 10;
//    int i, * v = gerarVetorOrdenadoInversamente(tamanho);
//    for (i = 0; i < tamanho; i++)
//        printf("%6d", v[i]);

//    printf("\n\n\n");
//    heapSort(v, tamanho);

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
        int * v = gerarVetorOrdenado(tamanho);
        start = tempo();
        heapSort(v, tamanho);
        fprintf(file, "%d,%f\n", tamanho, (tempo() - start));
        free(v);
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
        int * v = gerarVetorDesordenado(tamanho);
        start = tempo();
        heapSort(v, tamanho);
        fprintf(file, "%d,%f\n", tamanho, (tempo() - start));
        free(v);
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
        int * v = gerarVetorOrdenadoInversamente(tamanho);
        start = tempo();
        heapSort(v, tamanho);
        fprintf(file, "%d,%f\n", tamanho, (tempo() - start));
        free(v);
    }
    fclose(file);

    return 0;
}
