/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
// PROGRAMMA GIOCO A DOMANDE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funzione per presentare l'introduzione
void presentazione() {
    printf("Benvenuto al gioco 'Sei un Terrapiattista?'!\n");
    printf("Lo scopo del gioco è rispondere alle domande e scoprire la verità.\n");
    printf("Totalizza tutti i 30 punti e sarai il VINCITORE!!\n\n");
}

// Funzione per iniziare una nuova partita
int nuovaPartita() {
    char risposta[2];
    printf("Sei pronto a scoprirlo? (S/N): ");
    scanf("%1s", risposta);
    getchar(); // Consuma il carattere newline nel buffer

    return (strcmp(risposta, "S") == 0 || strcmp(risposta, "s") == 0);
}

// Funzione per eseguire una domanda
int domanda(char *testoDomanda, char *rispostaCorretta, char *opzioniRisposta[]) {
    int rispostaUtente;
    printf("%s\n", testoDomanda);

    for (int i = 0; i < 3; i++) {
        printf("%d) %s\n", i + 1, opzioniRisposta[i]);
    }

    printf("Risposta (1 o 2 o 3): ");
    scanf("%d", &rispostaUtente);

    if (rispostaUtente < 1 || rispostaUtente > 3) {
        printf("Scelta non valida. Per favore, inserisci 1, 2 o 3.\n");
        return 0;
    }

    return (strcmp(opzioniRisposta[rispostaUtente - 1], rispostaCorretta) == 0);
}

int main() {
    char nomeUtente[50];
    int punteggio = 0;

    presentazione();

    while (1) {
        char scelta;
        printf("\nMenu di scelta:\n");
        printf("A) Inizia una nuova partita\n");
        printf("B) Esci dal gioco\n");
        printf("Scelta: ");
        scanf(" %c", &scelta); // Spazio prima di %c per ignorare il newline residuo

        if (scelta == 'B' || scelta == 'b') {
            break;
        }

        if (scelta == 'A' || scelta == 'a') {
            if (nuovaPartita()) {
                printf("Inserisci il tuo nome: ");
                scanf("%s", nomeUtente);

                punteggio = 0;

                // Definisci domande e risposte qui
                char *domande[] = {
                    "Qual è la migliore fonte di informazione per leggere paper scientifici?",
                    "Quale pianeta è più vicino al Sole?",
                    "Quante volte l'uomo è andato sulla luna?"
                };

                char *risposte[] = {
                    "TikTok",
                    "Nessuno, il sole è una lampada",
                    "Mai"
                };

                char *opzioni[][3] = {
                    {"Nature", "TikTok", "Libri"},
                    {"Marte", "Mercurio", "Nessuno, il sole è una lampada"},
                    {"2", "Mai", "6"}
                };

                int numDomande = sizeof(domande) / sizeof(domande[0]);

                for (int i = 0; i < numDomande; i++) {
                    if (domanda(domande[i], risposte[i], opzioni[i])) {
                        punteggio += 10;
                        printf("Risposta corretta!\n");
                    } else {
                        printf("Risposta errata. La risposta corretta è: %s\n", risposte[i]);
                    }
                }

                if (punteggio == 30) {
                    printf("Complimenti,ora sei un vero TERRAPIATTISTA!\n");
                } else {
                    printf("Complimenti, %s! Il tuo punteggio finale è: %d\n", nomeUtente, punteggio);
                }
            }
        }
    }

    return 0;
}

