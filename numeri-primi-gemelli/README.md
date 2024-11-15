# Progetto Numeri Primi Gemelli

## Descrizione

Questo progetto ha lo scopo di generare e verificare numeri primi gemelli utilizzando un algoritmo che si basa su specifiche sequenze numeriche. I numeri primi gemelli sono coppie di numeri primi che differiscono tra loro di 2 (ad esempio, 11 e 13). Le sequenze utilizzate nel progetto sono derivate dalle formule `(6*x - 1) * (6*y - 1)`, `(6*x + 1) * (6*y + 1)` e `(6*x - 1) * (6*y + 1)`.

Il progetto comprende diverse funzioni per generare queste sequenze, verificare la presenza dei numeri non primi, e visualizzare i risultati. L'obiettivo è di identificare coppie di numeri che possono essere candidati a numeri primi gemelli e visualizzare questi risultati in un formato leggibile.

## Struttura del Progetto

- `prime.h`: Contiene le dichiarazioni delle funzioni e delle macro utilizzate nel progetto.
- `main.c`: Contiene la funzione `main` e l'implementazione delle funzioni necessarie per il funzionamento del programma.

## Funzioni Principali

### Macro e Funzioni di Utilità

- **`CEIL_DIV(x, y)`**: Macro per calcolare la divisione tra due numeri arrotondando per eccesso.
- **`insert_number(uint64_t **array, uint64_t *dimension, uint64_t number)`**: Inserisce un numero in un array dinamico di `uint64_t`.
- **`is_contain(uint64_t *array, uint64_t size, uint64_t number)`**: Verifica se un numero è contenuto in un array.
- **`insert_numbers(uint64_t ***array, uint64_t *dimension, uint64_t number1, uint64_t number2)`**: Inserisce due numeri in un array dinamico di array di `uint64_t`.
- **`view_the_client(uint64_t **array, uint64_t dimension, int print)`**: Visualizza i numeri presenti in un array dinamico di `uint64_t`.
- **`start_timer()`**: Avvia il timer per misurare il tempo di esecuzione.
- **`stop_timer(clock_t start_time)`**: Ferma il timer e restituisce il tempo trascorso in secondi.

### Generazione delle Sequenze

- **`generate_s1(uint64_t ***array, uint64_t *size, uint64_t max_k, uint64_t max_n)`**: Genera e inserisce i valori della sequenza S1 in un array dinamico di array dinamici.
- **`generate_s2(uint64_t ***array, uint64_t *size, uint64_t max_k, uint64_t max_n)`**: Genera e inserisce i valori della sequenza S2 in un array dinamico di array dinamici.
- **`generate_s3(uint64_t ***array, uint64_t *size, uint64_t max_k, uint64_t max_n)`**: Genera e inserisce i valori della sequenza S3 in un array dinamico di array dinamici.

## Come Eseguire il Progetto

1. **Compilazione del progetto:**
   Apri il terminale nella directory del progetto e compila il programma utilizzando il comando:

   ```sh
   gcc -o prime main.c
   ```

2. **Esecuzione del programma:**
   Esegui il programma appena compilato con il comando:

   ```sh
   ./prime
   ```

3. **Risultati:**
   - I risultati dell'esecuzione verranno visualizzati sullo schermo e salvati in un file chiamato `output.txt`.

## Dettagli Tecnici

- **Librerie Utilizzate:**
  - `stdio.h`: Per la gestione dell'input e output.
  - `stdint.h`: Per definizioni di tipi di dati con larghezza fissa.
  - `stdlib.h`: Per la gestione della memoria dinamica.
  - `string.h`: Per la manipolazione delle stringhe.
  - `time.h`: Per la gestione del tempo e misurazioni temporali.

- **Costanti:**
  - `MAX_NUMBER`: Definisce il limite massimo dei numeri generati.
  - `MAX_K`: Calcolata come `CEIL_DIV(MAX_NUMBER, 6)`, rappresenta il massimo valore per le variabili `x` e `y` nelle formule delle sequenze.

## Note Aggiuntive

- La costante `MAX_NUMBER` può essere modificata nel codice per cambiare il limite massimo dei numeri generati. Questo può influenzare il tempo di esecuzione e la dimensione degli array.
- Il file di output `output.txt` verrà creato nella directory in cui viene eseguito il programma e conterrà l'elenco dei numeri gemelli trovati.