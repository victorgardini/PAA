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

// Método de ordenação por inserção, v = vetor a ser ordenado, n = tamanho do vetor
int * bubbleSort (int * v, int n){
    int i, j, aux;
    for (i = 0; i < n; i++) {
        for (j = n-1; j > i; j--) {
            if (v[j] < v[j-1]) {
                aux = v[j-1];
                v[j-1] = v[j];
                v[j] = aux;
            }
        }
    }
    return v;
}

/*int main() {
    srand(time(NULL));
    int i, * v = gerarVetorDesordenado(5);
    for (i = 0; i < 5; i++)
        printf("%6d", v[i]);

    printf("\n\n\n");    
    v = bubbleSort(v, 5);

    for (i = 0; i < 5; i++)
        printf("%6d", v[i]);
    
    printf("\n\n\n");
    return 0;
}*/

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
        v = bubbleSort(v, tamanho);
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
        v = bubbleSort(v, tamanho);
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
        v = bubbleSort(v, tamanho);
        fprintf(file, "%d,%f\n", tamanho, (tempo() - start));
    }
    fclose(file);


    return 0;
}
