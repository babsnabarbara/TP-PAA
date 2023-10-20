#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <sys/time.h>

// Estruturas e algoritmos definidos aqui

double getElapsedTime(struct timeval start, struct timeval end) {
    return (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
}

int main() {
    int n_values[] = {100, 200, 400, 800, 1600, 3200, 6400, 12800, 25600};
    int num_instances = 20;

    double execution_times[3][9]; // 3 algoritmos, 9 tamanhos de instâncias

    for (int i = 0; i < num_instances; i++) {
        for (int j = 0; j < sizeof(n_values) / sizeof(n_values[0]); j++) {
            struct timeval start, end;
            gettimeofday(&start, NULL);

            // Execute seu algoritmo de mochila 0-1 aqui

            gettimeofday(&end, NULL);
            double elapsed_time = getElapsedTime(start, end);

            // Calcule a média de tempo aqui
            execution_times[0][j] += elapsed_time; // Algoritmo 1
            // execution_times[1][j] += elapsed_time; // Algoritmo 2
            // execution_times[2][j] += elapsed_time; // Algoritmo 3
        }
    }

    // Calcule as médias de tempo dividindo pelo número de instâncias
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 9; j++) {
            execution_times[i][j] /= num_instances;
        }
    }

    // Gere um arquivo de dados para o Gnuplot
    FILE *gnuplot_data = fopen("gnuplot_data.txt", "w");
    for (int j = 0; j < 9; j++) {
        fprintf(gnuplot_data, "%d %f\n", n_values[j], execution_times[0][j]);
    }
    fclose(gnuplot_data);

    // Use o Gnuplot para criar um gráfico de barras
    FILE *gnuplot_script = popen("gnuplot -persist", "w");
    fprintf(gnuplot_script, "set terminal png\n");
    fprintf(gnuplot_script, "set output 'execution_times.png'\n");
    fprintf(gnuplot_script, "set title 'Tempo Médio de Execução'\n");
    fprintf(gnuplot_script, "set xlabel 'Tamanho da Instância'\n");
    fprintf(gnuplot_script, "set ylabel 'Tempo (s)'\n");
    fprintf(gnuplot_script, "set style data histograms\n");
    fprintf(gnuplot_script, "plot 'gnuplot_data.txt' using 2:xtic(1) title 'Algoritmo 1'\n");
    fclose(gnuplot_script);

    return 0;
}
