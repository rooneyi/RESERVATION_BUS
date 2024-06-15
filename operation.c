#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "constants.h"
#include "dataStores.h"



// Structure pour stocker les informations d'une reseravtion
typedef struct {
    int id;             // Identifiant du ticket
    char nom[100];
    char prenom[100];
    char destination[100];
    char date_reservation[11];
    char genre[1];   // Date de reservation (format YYYY-MM-DD)
    int siegeDispo;
} TicketReservation;

//creation de 1000 structure de reservation
TicketReservation reservations[1000];

/*-------structure pour stocker les infos du client ------*/
typedef struct {
    char nom[50];
    char prenom[50];

    char numero_client[14];
    int id_Client;
} client;

/*-------structure pour stocker les infos du client qui a reserver ------*/
typedef struct {
    int id;             // Identifiant de l'emprunteur
    char name[100];     // Nom de l'emprunteur
} Reserver_Decision;


int compteur_reservation = 0;       // Compteur de reservation
int ticket_reserver = 0;   // compteur pour savoir combien de ticket reserver
#define MAX_SIEGE 30;
int siegeDispo=0;


void display_reservations_all() {
    for (int i = 0; i < compteur_reservation; i++) {
        printf("ID: %d \n NOM: %s \n PRENOM: %s \n DATE RESERVATION: %s \n DESTINATION: %s \n GENRE:%s\n",
                    reservations[i].id,
                    reservations[i].nom,
                    reservations[i].prenom,
                    reservations[i].date_reservation,
                    reservations[i].destination,
                    reservations[i].genre);
    }
}


// Fonction pour charger les reservation a partir du fichier reservation
void charger_reservation_ticket() {
    FILE *file = fopen("reservation.txt", "r");
    if (file == NULL) {
        printf("Erreur d'ouverture du fichier des resrevation!\n");
        return;
    }
    compteur_reservation = 0;
    while (fscanf(file, "%d %s %s %s %s \n",
            &reservations[compteur_reservation].id,
            reservations[compteur_reservation].nom,
            reservations[compteur_reservation].prenom,
            reservations[compteur_reservation].date_reservation,
            reservations[compteur_reservation].genre
            ) !=EOF){
            compteur_reservation++;
    }
    fclose(file);
}


//fonction pour rechercher un client grace a l'id ou au nom
void rechercher_client() {
    char nom[100];
    int id_entry;
    printf("Entrez le nom du client a rechercher :");
    scanf("%s", nom);
    printf("Entrez l'id a rechercher :");
    scanf("%d",id_entry);
    for (int i = 0; i < compteur_reservation; i++) {
        if (strstr(reservations[i].nom, nom) || strstr(reservations[i].id, id_entry)) {
            printf("ID: %d \n NOM: %s \n PRENOM: %s \n DATE RESERVATION: %s \n DESTINATION: %s \n GENRE:%s\n",
                    reservations[i].id,
                    reservations[i].nom,
                    reservations[i].prenom,
                    reservations[i].date_reservation,
                    reservations[i].destination,
                    reservations[i].genre);
        }
    }
}






void enregister_ticket() {
    FILE *file = fopen("reservation.txt", "w");
    if (file == NULL) {
        printf("Erreur d'ouverture du fichier des reservations!\n");
        return;
    }
    for (int i = 0; i < compteur_reservation; i++) {
        (fscanf(file, "%d %s %s %s %s %d\n",
            &reservations[compteur_reservation].id,
            reservations[compteur_reservation].nom,
            reservations[compteur_reservation].prenom,
            reservations[compteur_reservation].date_reservation,
            reservations[compteur_reservation].genre
            ));
    }
    fclose(file);
}



void destination_posible(){
    int i = 0;
    char ville[][100]={"1.Likasi","2.Lubumbashi","3.kolwezi","4.Kasumbalesa"};

     printf("\n\n+-------------------------------+\n\n");
    //afficher toute les destination
    for(;i<=3;i++){
        printf("%s \n",ville[i]);
    }
    printf("\n\n+-------------------------------+\n\n");

}



void siegeDisponible(){
    int siegeDispoDis[][20]={1,2,3,4,5,6,7,8,9,10};
    for (int i=0;i<=9;i++){
        printf(" ** siege disponible * \n ");
        printf(" \n %d",siegeDispoDis[i]);
    }
    printf("Selectionner un siege :");
    scanf("%d",reservations[compteur_reservation].siegeDispo);
    //siegeDispo = MAX_SIEGE - siegeDispoDis[i];
}

void ajout_ticket_reser() {

    reservations[compteur_reservation].id = compteur_reservation + 1;
    printf("Entrez le nom :");
    scanf("--> %s", reservations[compteur_reservation].nom);
    printf("Entrez le prenom :");
    scanf("--> %s", reservations[compteur_reservation].prenom);
    printf("Entrez le genre ");
    scanf("--> %s", reservations[compteur_reservation].genre);
    printf("Entrez la destination :");
    destination_posible();
    siegeDisponible();

    printf("--> Entrez la destination (en Toute lettre) :");
    scanf("%s", reservations[compteur_reservation].destination);
    printf("--> Entrez la date de reservation :");
    scanf("%s", reservations[compteur_reservation].date_reservation);

    //printf("Entrez le numero de telephone ");
    //scanf("%s", reservations[compteur_reservation].tele);


    enregister_ticket();
    printf("Ticket Reserver avec succes \n");
}



int taille = 0;

// Fonction permettant d'enregistrer toutes les transactions effectuees

struct Transaction* enregistrerTransaction(struct Transaction* transactions, int* taille,struct Transaction n_transaction)
{
    (*taille)++;

    transactions = realloc(transactions, (*taille)* sizeof(struct Transaction));

    transactions[(*taille) - 1] = n_transaction;

    return transactions;
}

// Fonction permettant d'afficher toutes les transactions effectuees

void afficherTransactions()
{
    for (int i = 0; i < taille; i++) {
        printf("Transaction %d:\n", i + 1);
        printf("Date: %d/%d/%d\n", transactions[i].date.jour, transactions[i].date.mois, transactions[i].date.annee);
        printf("Montant: %.2f\n", transactions[i].montant);
        printf("Devise: %s\n", transactions[i].devise == USD ? "USD" : "FC");
        printf("Type: %s\n", transactions[i].type == DEPOT ? "DEPOT" : "RETRAIT");
        printf("\n");
    }
}


// Fonction permettant d'obtenir le solde dans une devise sp�cifique

double getSolde(Devise devise) {
    // S'assurer que la devise est comprise dans les limites du tableau des soldes.
    int nombreDevises = sizeof(soldes) / sizeof(soldes[0]);
    if (devise >= 0 && devise < nombreDevises) {
        return soldes[devise];
    }
    return 0.0; // Renvoie une valeur par d�faut si la devise n'est pas trouv�e
}

// Fonction permettant de v�rifier le solde dans une devise sp�cifique

double verifierSolde(Devise devise)
{
    return getSolde(devise);// Retourne le solde de la devise donn�e.

}

// Fonction permettant de calculer le nouveau solde apr�s un d�p�t dans une devise sp�cifique

double depotMontant(Devise devise, double montantDepot)
{
    // Obtenir l'heure actuelle
    time_t now = time(NULL);

    struct tm *local = localtime(&now);

    struct Transaction transaction;

    transaction.date.jour = local->tm_mday;
    transaction.date.mois = local->tm_mon + 1;
    transaction.date.annee = local->tm_year + 1900;
    transaction.montant = montantDepot;
    transaction.devise = devise;
    transaction.type= DEPOT;

    transactions = enregistrerTransaction(transactions, &taille, transaction);

    soldes[devise] += montantDepot;

    return verifierSolde(devise);
}

// Fonction permettant d'effectuer une op�ration de d�p�t dans une devise sp�cifique

void effectuerDepot(Devise devise, double montantDepot)
{
    double minDepot = (devise == USD) ? MIN_DEPOT_USD : MIN_DEPOT_FC;
    char *deviseCode = (devise == USD) ? "USD" : "FC";

    if (montantDepot > minDepot)
    {
        printf("\nLe depot du montant %.2f %s a ete effectue avec succes. Votre nouveau solde est de %.2f %s\n\n",
               montantDepot, deviseCode, depotMontant(devise, montantDepot), deviseCode);
    }
    else
    {
        printf("\nLe montant %.2f %s est insuffisant pour effectuer cette operation.\n\n",
               montantDepot, deviseCode);
    }
}

// Fonction permettant de calculer le nouveau solde apr�s un retrait dans une devise sp�cifique

double retraitMontant(Devise devise, double montantRetrait)
{
    // Obtenir l'heure actuelle
    time_t now = time(NULL);

    struct tm *local = localtime(&now);

    struct Transaction transaction;

    transaction.date.jour = local->tm_mday;
    transaction.date.mois = local->tm_mon + 1;
    transaction.date.annee = local->tm_year + 1900;
    transaction.montant = montantRetrait;
    transaction.devise = devise;
    transaction.type= RETRAIT;

    transactions = enregistrerTransaction(transactions, &taille, transaction);

    soldes[devise] -= montantRetrait;

    return verifierSolde(devise);
}

// Fonction permettant d'effectuer une op�ration de retrait dans une devise sp�cifique

void effectuerRetrait(Devise devise, double montantRetrait)
{
    double nouveauSolde;
    char *deviseCode = (devise == USD) ? "USD" : "FC";

    if (verifierSolde(devise) > 0) {
        nouveauSolde = retraitMontant(devise, montantRetrait);
        printf("\nLe retrait du montant %.2f %s a ete effectue avec succes. Votre nouveau solde est de %.2f %s\n\n",
                montantRetrait, deviseCode, nouveauSolde, deviseCode);
    } else {
        printf("\nVotre solde est insuffisant pour effectuer cette operation.\n\n");
    }
}

