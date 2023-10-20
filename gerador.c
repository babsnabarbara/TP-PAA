#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomInstance(int n, int W) {
    FILE *file = fopen("input.txt", "w");
    if (file == NULL) {
        printf("Erro ao criar o arquivo de entrada.\n");
        return;
    }

    fprintf(file, "%d\n", W);

    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        int weight = 1 + (rand() % 30);
        int value = 1 + (rand() % 100);
        fprintf(file, "%d %d\n", weight, value);
    }

    fclose(file);
}

int main() {
    int n_values[] = {100, 200, 400, 800, 1600, 3200, 6400, 12800, 25600};
    int W_values[] = {100, 200, 400, 800, 1600, 3200, 6400, 12800, 25600};
    int num_instances = 20;

    // Loop para gerar as instâncias aleatórias
    for (int i = 0; i < num_instances; i++) {
        for (int j = 0; j < sizeof(n_values) / sizeof(n_values[0]); j++) {
            generateRandomInstance(n_values[j], W_values[j]);
        }
    }

    return 0;
}
