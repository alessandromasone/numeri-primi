//1kk Tempo di esecuzione: 258.249486 secondi
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Enumerazione per le posizioni dei nomi nell'array di numeri
enum NamesPositions {
    plus_1 = 0,
    minus_1 = 1,
    twins = 2,
    composite = 3
};

// Definizione di costanti
#define MAX_NUMBER 1000
#define MAX_K CEIL_DIV(MAX_NUMBER, 6)

#include "prime.h" // Inclusione del file header "prime.h" che contiene le dichiarazioni delle funzioni


int main() {

    clock_t start_time = start_timer();

    // Inizializzazione di un array per i numeri non primi
    uint64_t *array_not_primes = NULL;
    uint64_t size_not_primes = 0;

    // Ricerca per i numeri da non considerare primi
    generate_s1(&array_not_primes, &size_not_primes, MAX_K, MAX_NUMBER);
    generate_s2(&array_not_primes, &size_not_primes, MAX_K, MAX_NUMBER);
    generate_s3(&array_not_primes, &size_not_primes, MAX_K, MAX_NUMBER);

    // Inizializzazione dell'array dei candidati ai numeri primi gemelli
    uint64_t **array_candidates = NULL;
    uint64_t size_candidates = 0;

    // Ciclo per calcolare i candidati ai numeri primi gemelli e verificarne la primalità
    for (uint64_t k = 1; k < MAX_K; k++) {

        // Calcolo dei numeri 6k-1 e 6k+1
        int64_t s_minus_1 = (6 * k) - 1;
        int64_t s_plus_1 = (6 * k) + 1;

        // Inserimento dei numeri 6k-1 e 6k+1 nell'array dei candidati
        insert_numbers(&array_candidates, &size_candidates, s_minus_1, s_plus_1);

        // Verifica se i numeri 6k-1 e 6k+1 sono presenti nell'array dei non primi
        int present_minus_1 = is_contain(array_not_primes, size_not_primes, s_minus_1);
        int present_plus_1 = is_contain(array_not_primes, size_not_primes, s_plus_1);

        // Impostazione del flag gemelli e del flag composizione
        array_candidates[k - 1][twins] = (present_minus_1 || present_plus_1) ? true : false;

        if (present_minus_1 && present_plus_1) {
            array_candidates[k - 1][composite] = 2;
        } else {
            array_candidates[k - 1][composite] = present_minus_1 ? false : true;
        }

    }

    printf("Tempo di esecuzione: %f secondi\n", stop_timer(start_time));

    // Visualizzazione dei risultati
    view_the_client(array_candidates, size_candidates, true);

    return 0;
}
