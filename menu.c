#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "operation.h"

#define WIDTH 80  // Largeur de la fenêtre à 80 caractères

// Codes ANSI pour les couleurs et les styles
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"

// Fonction pour centrer le texte
void centerText(const char* text) {
    int len = strlen(text);
    int padding = (WIDTH - len) / 2;
    for (int i = 0; i < padding; i++) {
        printf(" ");
    }
    printf("%s\n", text);
}

// Fonction pour centrer et formater le texte avec des couleurs
void centerTextColored(const char* color, const char* text) {
    int len = strlen(text);
    int padding = (WIDTH - len) / 2;
    for (int i = 0; i < padding; i++) {
        printf(" ");
    }
    printf("%s%s%s\n", color, text, RESET);
}

// Fonction pour centrer et formater le texte avec des couleurs et des styles
void centerTextStyled(const char* color, const char* style, const char* text) {
    int len = strlen(text);
    int padding = (WIDTH - len) / 2;
    for (int i = 0; i < padding; i++) {
        printf(" ");
    }
    printf("%s%s%s%s\n", style, color, text, RESET);
}

// Fonction pour centrer le texte formaté
void centerTextFormatted(const char* format, ...) {
    char buffer[WIDTH + 1];
    va_list args;
    //va_start(args, format);
    vsnprintf(buffer, WIDTH + 1, format, args);
    //va_end(args);
    centerText(buffer);
}

void Menu_principal() {
    centerTextStyled(BLUE,BOLD,  "+------------------------ Bienvenu sur ReserTrans --------------------------+");
    centerTextStyled(BLUE,BOLD,  "|                                                                           |");
    centerTextStyled(BLUE,BOLD,  "|                      1.   Reserver votre Bus                              |");
    centerTextStyled(BLUE,BOLD,  "|                      2.   Tous les Ticket                                 |");
    centerTextStyled(BLUE,BOLD,  "|                      3.   Rechercher un client                            |");
    centerTextStyled(BLUE,BOLD,  "|                      4.   Payer Ticket                                    |");
    centerTextStyled(BLUE,BOLD,  "|                      5.   Quitter                                         |");
    centerTextStyled(BLUE,BOLD,  "|                                                                           |");
    centerTextStyled(BLUE,BOLD,  "|                                                                           |");
    centerTextStyled(BLUE,BOLD,  "+---------------------------------------------------------------------------+\n\n");
}

void Menu_principal_reser() {
    centerTextStyled(GREEN,BOLD,  "|+------------------------ Reservation -----------------------+ |");
    centerTextStyled(GREEN,BOLD,  "|                                                               |");
    centerTextStyled(GREEN,BOLD,  "|                      1.    trajet diponible                   |");
    centerTextStyled(GREEN,BOLD,  "|                      2.    Reserver votre Bus                 |");
    centerTextStyled(GREEN,BOLD,  "|                      3.    Payement avec Mobile Money         |");
    centerTextStyled(GREEN,BOLD,  "|                      4.    Quitter                            |");
    centerTextStyled(GREEN,BOLD,  "|                                                               |");
    centerTextStyled(GREEN,BOLD,  "+---------------------------------------------------------------+\n\n");

}

// Fonction permettant d'afficher le menu principal
void afficherMenu() {
    centerTextStyled(CYAN, BOLD, "|+------------------------ TRANSACTION AVEC  MOBILE MONEY  -----------------------+ |");
    centerText("|                                                                                   |");
    centerText("|                         0. Verifier le solde.                                     |");
    centerText("|                         1. Effectuer un depot.                                    |");
    centerText("|                         2. Effectuer un retrait.                                  |");
    centerText("|                         3. Afficher les transactions.                             |");
    centerText("|                         5.      Quitter                                           |");
    centerTextStyled(CYAN, BOLD, "|+----------------------------------------------------------------------------------+ \n\n");
}

// Fonction permettant d'afficher les options de devises
void afficherDevisesOptions() {
    centerText("\n Selectionnez une devise :\n\n");
    centerText("--> 0. USD.");
    centerText("--> 1. FC.\n\n");
}

// Fonction de gestion des soldes des comptes
void gererSoldes() {
    int devise;
    afficherMenu();
    system("clear");

    centerText("\t\t+------------Verifier votre solde------------------------+\n\n");
    afficherDevisesOptions();
    printf("Choisissez une option :");
    scanf("%d", &devise);

    switch(devise) {
        case 0:
            centerTextFormatted("\nVotre solde en USD est de %.2f USD\n\n\n", verifierSolde(devise));
            break;
        case 1:
            centerTextFormatted("\nVotre solde en FC est de %.2f FC\n\n\n", verifierSolde(devise));
            break;
    }
}

// Fonction permettant de traiter les opérations de dépôt
void gererDepot() {
    int devise, montantDepot;
    afficherMenu();
    system("cls");

    centerText("\t\tEffectuer un depot\n\n");
    afficherDevisesOptions();
    printf("Choisissez une option :");
    scanf("%d", &devise);

    printf("Saisir le montant :");
    scanf("%d", &montantDepot);

    effectuerDepot(devise, montantDepot);
}

// Fonction permettant de traiter les opérations de retrait
void gererRetrait() {
    int devise, montantRetrait;
    afficherMenu();
    system("clear");

    centerText("\t\tEffectuer un retrait\n\n");
    afficherDevisesOptions();
    printf("Choisissez une option :");
    scanf("%d", &devise);

    printf("Saisir le montant :");
    scanf("%d", &montantRetrait);

    effectuerRetrait(devise, montantRetrait);
}

// Fonction permettant d'afficher l'historique des transactions
void gererTransactions() {
    afficherMenu();
    system("clear");

    centerText("\t\tListe des transactions effectuees\n\n");
    afficherTransactions();
}




