#ifndef PRIME_H
#define PRIME_H

#define true 1
#define false 0

/**
 * Calcola la divisione tra due numeri arrotondando per eccesso.
 * @param x Il dividendo.
 * @param y Il divisore.
 * @return Il risultato della divisione arrotondato per eccesso.
 */
#define CEIL_DIV(x, y) (((x) + (y) - 1) / (y))

/**
 * Inserisce un numero in un array dinamico di uint64_t.
 * @param array Puntatore all'array.
 * @param dimension Puntatore alla dimensione dell'array.
 * @param number Il numero da inserire.
 */
void insert_number(uint64_t **array, uint64_t *dimension, uint64_t number) {
    (*dimension)++; // Incrementa la dimensione dell'array

    // Rialloca la memoria per l'array con la nuova dimensione
    *array = (uint64_t*)realloc(*array, (*dimension) * sizeof(uint64_t));
    
    if (*array == NULL) { // Verifica se c'è stato un errore durante la riallocazione
        printf("Errore durante la riallocazione della memoria.");
        exit(1);
    }

    // Inserisce il numero nella posizione corretta dell'array
    (*array)[(*dimension) - 1] = number;
}

/**
 * Verifica se un numero è contenuto in un array.
 * @param array L'array in cui cercare.
 * @param size La dimensione dell'array.
 * @param number Il numero da cercare.
 * @return true se il numero è presente, altrimenti false.
 */
int is_contain(uint64_t *array, uint64_t size, uint64_t number) {
    for (uint64_t i = 0; i < size; i++) { // Scorre l'array
        if (array[i] == number) { // Verifica se il numero è presente
            return true; // Restituisce true se il numero è presente
        }
    }
    return false; // Restituisce false se il numero non è presente
}


/**
 * Inserisce due numeri in un array dinamico di array dinamici di uint64_t.
 * @param array Puntatore all'array di array.
 * @param dimension Puntatore alla dimensione dell'array di array.
 * @param number1 Il primo numero da inserire.
 * @param number2 Il secondo numero da inserire.
 */
void insert_numbers(uint64_t ***array, uint64_t *dimension, uint64_t number1, uint64_t number2) {
    (*dimension)++; // Incrementa la dimensione dell'array

    // Rialloca la memoria per l'array di array con la nuova dimensione
    *array = (uint64_t**)realloc(*array, (*dimension) * sizeof(uint64_t*));
    
    if (*array == NULL) { // Verifica se c'è stato un errore durante la riallocazione
        printf("Errore durante la riallocazione della memoria.");
        exit(1);
    }

    // Alloca memoria per l'array di uint64_t all'interno dell'array di array
    (*array)[(*dimension) - 1] = (uint64_t*)malloc(4 * sizeof(uint64_t));
    if ((*array)[(*dimension) - 1] == NULL) { // Verifica se c'è stato un errore durante l'allocazione
        printf("Errore durante l'allocazione della memoria.");
        exit(1);
    }

    // Inserisce i due numeri nell'array di uint64_t
    (*array)[(*dimension) - 1][plus_1] = number1;
    (*array)[(*dimension) - 1][minus_1] = number2;
}

/**
 * Visualizza i numeri presenti in un array dinamico di uint64_t.
 * @param array L'array da visualizzare.
 * @param dimension La dimensione dell'array.
 * @param print Flag che indica se stampare l'output su file (true) o su stdout (false).
 */
void view_the_client(uint64_t **array, uint64_t dimension, int print) {
    FILE *output_file; // Puntatore al file di output
    char buffer[20];
    char buffer2[20];
    char rowBuffer[100];

    // Apertura del file di output se richiesto
    if (print) {
        output_file = fopen("output.txt", "w"); // Apre il file in modalità scrittura ("w")
        if (output_file == NULL) { // Verifica se c'è stato un errore nell'apertura del file
            printf("Impossibile aprire il file output.txt");
            return; // Esce dalla funzione in caso di errore
        }
    }

    // Stampa l'intestazione
    if (print) fprintf(output_file, "k    | 6k-1         | 6k+1         | Twins*\n");
    else printf("k    | 6k-1         | 6k+1         | Twins*\n");
    if (print) fprintf(output_file, "-----------------------------------------------\n");
    else printf("-----------------------------------------------\n");

    // Itera attraverso l'array e formatta ogni riga
    for (uint64_t i = 0; i < dimension; i++) {
        char number1[20];
        char number2[20];

        if (array[i][twins] == true) {
            if (array[i][composite] == 2) {
                sprintf(number1, "%lluc", array[i][0]);
                sprintf(number2, "%lluc", array[i][1]);
            } else if (array[i][composite] == false) {
                sprintf(number1, "%lluc", array[i][0]);
                sprintf(number2, "%llu", array[i][1]);
            } else {
                sprintf(number1, "%llu", array[i][0]);
                sprintf(number2, "%lluc", array[i][1]);
            }
        } else {
            sprintf(number1, "%llu", array[i][plus_1]);
            sprintf(number2, "%llu", array[i][minus_1]);
        }

        sprintf(rowBuffer, "%-4llu | %-12s | %-12s | ", i+1, number1, number2);

        if (array[i][twins] != true) strcat(rowBuffer, "*"); // Aggiunge un asterisco se non sono gemelli

        if (print) fprintf(output_file, "%s\n", rowBuffer); // Stampa la riga su file se richiesto
        else printf("%s\n", rowBuffer); // Altrimenti stampa la riga su stdout
    }

    // Chiude il file di output se è stato aperto
    if (print) fclose(output_file);
}

/**
 * Genera e inserisce i valori della sequenza S1 in un array dinamico di array dinamici.
 * La sequenza S1 è definita come (6*x - 1) * (6*y - 1),
 * dove x e y sono compresi tra 1 e max.
 * @param array Puntatore all'array di array in cui inserire i valori generati.
 * @param size Puntatore alla dimensione dell'array principale.
 * @param max_k Il valore massimo per x e y.
 * @param max_n Il numero massimo su cui si punta ad arrivare
 */
void generate_s1(uint64_t ***array, uint64_t *size, uint64_t max_k, uint64_t max_n) {
    // Itera attraverso i valori di y da 1 a max_k
    for (uint64_t y = 1; y <= max_k; ++y) {
        // Itera attraverso i valori di x da 1 a max_k
        for (uint64_t x = 1; x <= max_k; ++x) {
            // Garantisce che x sia maggiore o uguale a y per evitare duplicati
            if (x >= y) {
                uint64_t result = (6 * x - 1) * (6 * y - 1);
                // Calcola e inserisce il valore della sequenza S1 nell'array
                insert_number(array, size, result);

                // Stop per non generare numeri maggiori di quello desiderato
                if (result > max_n) break;
            }
        }
        // Stop per non generare numeri maggiori di quello desiderato
        if ((6 * 1 - 1) * (6 * y - 1) > max_n) break;
    }
}

/**
 * Genera e inserisce i valori della sequenza S2 in un array dinamico di array dinamici.
 * La sequenza S2 è definita come (6*x + 1) * (6*y + 1),
 * dove x e y sono compresi tra 1 e max.
 * @param array Puntatore all'array di array in cui inserire i valori generati.
 * @param size Puntatore alla dimensione dell'array principale.
 * @param max_k Il valore massimo per x e y.
 * @param max_n Il numero massimo su cui si punta ad arrivare
 */
void generate_s2(uint64_t ***array, uint64_t *size, uint64_t max_k, uint64_t max_n) {
    // Itera attraverso i valori di y da 1 a max_k
    for (uint64_t y = 1; y <= max_k; ++y) {
        // Itera attraverso i valori di x da 1 a max_k
        for (uint64_t x = 1; x <= max_k; ++x) {
            // Garantisce che x sia maggiore o uguale a y per evitare duplicati
            if (x >= y) {
                uint64_t result = (6 * x + 1) * (6 * y + 1);
                // Calcola e inserisce il valore della sequenza S2 nell'array
                insert_number(array, size, result);

                // Stop per non generare numeri maggiori di quello desiderato
                if (result > max_n) break;
            }
        }
        // Stop per non generare numeri maggiori di quello desiderato
        if ((6 * 1 + 1) * (6 * y + 1) > max_n) break;
    }
}

/**
 * Genera e inserisce i valori della sequenza S3 in un array dinamico di array dinamici.
 * La sequenza S3 è definita come (6*x - 1) * (6*y + 1), dove x e y sono compresi tra 1 e max.
 * @param array Puntatore all'array di array in cui inserire i valori generati.
 * @param size Puntatore alla dimensione dell'array principale.
 * @param max_k Il valore massimo per x e y.
 * @param max_n Il numero massimo su cui si punta ad arrivare
 */
void generate_s3(uint64_t ***array, uint64_t *size, uint64_t max_k, uint64_t max_n) {
    // Itera attraverso i valori di y da 1 a max
    for (uint64_t y = 1; y <= max_k; ++y) {
        // Itera attraverso i valori di x da 1 a max
        for (uint64_t x = 1; x <= max_k; ++x) {
            uint64_t result = (6 * x - 1) * (6 * y + 1);
            // Calcola e inserisce il valore della sequenza S3 nell'array
            insert_number(array, size, result);

            // Stop per non generare numeri maggiori di quello desiderato
            if (result > max_n) break;
        }
        // Stop per non generare numeri maggiori di quello desiderato
        if ((6 * 1 - 1) * (6 * y + 1) > max_n) break;
    }
}

// Funzione per avviare il timer
clock_t start_timer() {
    return clock();
}

// Funzione per fermare il timer e restituire il tempo trascorso in secondi
double stop_timer(clock_t start_time) {
    return (double)(clock() - start_time) / CLOCKS_PER_SEC;
}

#endif