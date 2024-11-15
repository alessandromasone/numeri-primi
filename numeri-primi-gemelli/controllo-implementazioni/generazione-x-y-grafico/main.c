#include <stdint.h>
#include <stdio.h>

#define MAX_K 1000
#define MAX_N 10000

// Funzioni di calcolo
uint64_t calculate_s1(uint64_t x, uint64_t y) {
    return (6 * x - 1) * (6 * y - 1);
}

uint64_t calculate_s2(uint64_t x, uint64_t y) {
    return (6 * x + 1) * (6 * y + 1);
}

uint64_t calculate_s3(uint64_t x, uint64_t y) {
    return (6 * x - 1) * (6 * y + 1);
}

// Funzione per generare i dati e salvarli in un file in formato tabellare
void generate_data(const char* filename, uint64_t (*func)(uint64_t, uint64_t), uint64_t max_k, uint64_t max_n, int half) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("Cannot open file");
        return;
    }

    // Stampa i valori delle funzioni con la prima colonna (valori di y)
    for (uint64_t y = 1; y <= max_k; ++y) {
        uint64_t temp = func(1, y);
        for (uint64_t x = 1; x <= max_k; ++x) {
            fprintf(file, "%ld ", (long)func(x, y)); // Utilizziamo %ld per stampare numeri negativi
            if ((long)func(x, y) > max_n) break;
            if (x >= y && half) break;
        }
        if ((long)func(1, y) > max_n) break;
        fprintf(file, "\n");
    }

    fclose(file);
}

int main() {

    generate_data("data_s1.txt", calculate_s1, MAX_K, MAX_N, 1);
    generate_data("data_s2.txt", calculate_s2, MAX_K, MAX_N, 1);
    generate_data("data_s3.txt", calculate_s3, MAX_K, MAX_N, 0);

    return 0;
}
