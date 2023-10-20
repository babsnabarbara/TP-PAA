#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void criarArquivoComLinhas(int n) {
    char nomeArquivo[50];
    sprintf(nomeArquivo, "arquivo_%d.txt", n);
    
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo %s.\n", nomeArquivo);
        exit(1);
    }
    
    // Escreve a primeira linha com o valor 100
    fprintf(arquivo, "100\n");
    
    // Escreve as linhas seguintes com valores aleatórios
    srand(time(NULL));  // Inicializa a semente para números aleatórios
    for (int i = 1; i <= n; i++) {
        int valor1 = rand() % 20 + 1;
        int valor2 = rand() % 100 + 1;
        fprintf(arquivo, "%d\t%d\n", valor1, valor2);
    }
    
    fclose(arquivo);
}

int main() {
    for (int i = 0; i < 20; i++) {
        criarArquivoComLinhas(pow(2,i) * 100);
    }
    
    printf("Arquivos criados com sucesso!\n");
    
    return 0;
}