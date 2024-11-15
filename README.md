# Numeri Primi

**"Numeri Primi"** è un repository che raccoglie due progetti distinti per il calcolo, la generazione e la verifica di numeri primi. Entrambi i progetti sono scritti in linguaggio C e si concentrano su algoritmi e metodi efficienti per lavorare con numeri primi e coppie di numeri primi gemelli.


## Progetti Inclusi

### 1. **Progetto Numeri Primi Gemelli**

Il progetto si focalizza sull'identificazione di **numeri primi gemelli**, ovvero coppie di numeri primi che differiscono di 2 (ad esempio, 11 e 13). Include l'implementazione di algoritmi basati su formule matematiche che generano e verificano tali coppie.

#### Caratteristiche principali:
- Generazione di sequenze basate sulle formule:
  - `(6*x - 1) * (6*y - 1)`
  - `(6*x + 1) * (6*y + 1)`
  - `(6*x - 1) * (6*y + 1)`
- Identificazione e memorizzazione delle coppie gemelle trovate.
- Output dei risultati in formato leggibile.

#### Come eseguire:
1. Compila il programma con:
   ```sh
   gcc -o prime main.c
   ```
2. Esegui il programma:
   ```sh
   ./prime
   ```
3. I risultati saranno visibili sul terminale e salvati in `output.txt`.

### 2. **Algoritmo Numeri Primi**

Un progetto più generico che implementa un algoritmo per il calcolo dei numeri primi tramite cicli e sottrazioni. È progettato per essere flessibile e consente di configurare il numero di cicli di calcolo tramite argomenti da riga di comando.

#### Caratteristiche principali:
- Generazione iterativa di numeri primi con ottimizzazione tramite array dinamici.
- Salvataggio dei numeri primi trovati in un file di output (`output.txt`).
- Supporto per personalizzare il numero di cicli da eseguire.

#### Come eseguire:
1. Usa il file `Makefile` per compilare:
   ```sh
   make
   ```
2. Esegui il programma:
   ```sh
   make start
   ```
   Oppure specifica il numero di cicli:
   ```sh
   make start-10
   ```
3. Pulisci i file compilati con:
   ```sh
   make clean
   ```


## Struttura del Repository

Il repository è organizzato in due cartelle principali, una per ciascun progetto:

- `primi-gemelli`: Contiene i file per il progetto **Numeri Primi Gemelli**.
- `algoritmo-primi`: Contiene i file per il progetto **Algoritmo Numeri Primi**.

Ogni cartella include:
- Codice sorgente (`.c` e `.h`).
- File di output (`output.txt`) per salvare i risultati.
- Un file `README` specifico con ulteriori dettagli.

## Requisiti

- **Compilatore GCC**: Assicurati di avere GCC installato sul tuo sistema.
- **Sistema operativo Unix-like** (Linux, macOS) consigliato, ma compatibile con Windows tramite WSL o MinGW.

## Contributi

Contributi al miglioramento del codice o all'ottimizzazione degli algoritmi sono sempre benvenuti! Segui questi passi per contribuire:

1. Effettua un fork del repository.
2. Crea un branch per le modifiche:
   ```sh
   git checkout -b miglioramenti
   ```
3. Effettua il commit delle modifiche:
   ```sh
   git commit -m "Miglioramenti agli algoritmi"
   ```
4. Pusha il branch:
   ```sh
   git push origin miglioramenti
   ```
5. Apri una **Pull Request** per la revisione.


## Licenza

Questo progetto è distribuito sotto la licenza **GPLv3**. Per ulteriori dettagli, consulta il file `LICENSE`.