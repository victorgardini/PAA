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

// MergeSort
void merge(int * vetor, int comeco, int meio, int fim) {
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int * vetAux;

    vetAux = (int*)malloc(tam * sizeof(int));

    while(com1 <= meio && com2 <= fim){
        if(vetor[com1] < vetor[com2]) {
            vetAux[comAux] = vetor[com1];
            com1++;
        }
        else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }


    while(com1 <= meio){  //Caso ainda haja elementos na primeira metade
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }


    while(com2 <= fim) {   //Caso ainda haja elementos na segunda metade
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){    //Move os elementos de volta para o vetor original
        vetor[comAux] = vetAux[comAux-comeco];
    }
    free(vetAux);
}


void mergeSort(int * vetor, int comeco, int fim){
    if (comeco < fim) {
        int meio = (fim+comeco)/2;
        mergeSort(vetor, comeco, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, comeco, meio, fim);
    }
}

//int main() {
//    srand(time(NULL));
//    int tamanho = 10;
//    int i, * v = gerarVetorDesordenado(tamanho);
//    for (i = 0; i < tamanho; i++)
//        printf("%6d", v[i]);
//
//    printf("\n\n\n");
//    mergeSort(v, 0, tamanho-1);
//
//    for (i = 0; i < tamanho; i++)
//        printf("%6d", v[i]);
//
//    printf("\n\n\n");
//    return 0;
//}

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
        mergeSort(v, 0, tamanho-1);
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
        mergeSort(v, 0, tamanho-1);
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
        mergeSort(v, 0, tamanho-1);
        fprintf(file, "%d,%f\n", tamanho, (tempo() - start));
    }
    fclose(file);

    return 0;
}
