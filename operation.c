#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "constants.h"
#include "dataStores.h"




#define MAX_USERS 2

typedef struct {
    char username[50];
    char password[50];
} User;

User users[MAX_USERS];
int user_count = 0;






void ajouter_utilisateur(const char *username, const char *password) {
    if (user_count < MAX_USERS) {
        strcpy(users[user_count].username, username);
        strcpy(users[user_count].password, password);
        user_count++;
    } else {
        printf("Limite d'utilisateurs atteinte!\n");
    }
}

// Fonction pour vérifier l'authentification
int verifier_utilisateur(const char *username, const char *password) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return 1;
        }
    }
    return 0;
}

// Fonction pour charger les utilisateurs à partir d'un fichier
void charger_utilisateurs() {
    FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        printf("Erreur d'ouverture du fichier des utilisateurs!\n");
        return;
    }
    user_count = 0;
    while (fscanf(file, "%s %s", users[user_count].username, users[user_count].password) != EOF) {
        user_count++;
    }
    fclose(file);
}

// Fonction pour enregistrer les utilisateurs dans un fichier
void enregistrer_utilisateurs() {
    FILE *file = fopen("users.txt", "w");
    if (file == NULL) {
        printf("Erreur d'ouverture du fichier des utilisateurs!\n");
        return;
    }
    for (int i = 0; i < user_count; i++) {
        fprintf(file, "%s %s\n", users[i].username, users[i].password);
    }
    fclose(file);
}

// Structure pour stocker les informations d'une reseravtion
typedef struct {
    int id;             // Identifiant du ticket
    char nom[100];
    char prenom[100];
    char destination[100];
    char date_reservation[11];
    char genre[1];   // Date de reservation (format YYYY-MM-DD)
    int siege;
    int siegeDispo;
    int payer;
    Devise devise; // Devise utilisée pour le paiement


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



int compteur_reservation = 0;       // Compteur de reservation
int ticket_reserver = 0;   // compteur pour savoir combien de ticket reserver
int prixBus[][4]={15000,20000,30000,40000};
int siegeDispo=0;




// Fonction pour payer un ticket
void payer_ticket() {
    int id_ticket;
    printf("Entrez l'ID du ticket à payer :\n--> ");
    scanf("%d", &id_ticket);
    for (int i = 0; i < compteur_reservation; i++) {
        if (reservations[i].id == id_ticket) {
            double montantDepot;
            int deviseChoix;
            //char username[50], password[50];
            //printf("Authentification requise pour le paiement.\n");
//            printf("Nom d'utilisateur : ");
//            scanf("%s", username);
//            printf("Mot de passe : ");
//            scanf("%s", password);
//
//            if (verifier_utilisateur(username, password)) {
               // printf("Authentification réussie.\n");
                printf("Choisissez la devise pour le paiement (1 pour USD, 2 pour FC) :\n--> ");
                scanf("%d", &deviseChoix);
                Devise devise = (deviseChoix == 1) ? USD : FC;
                printf("Entrez le montant à déposer pour le paiement du ticket :\n--> ");
                scanf("%lf", &montantDepot);
                effectuerDepot(devise, montantDepot); // Utilisation de la devise choisie
                reservations[i].payer = 1; // Marquer comme payé
                reservations[i].devise = devise; // Enregistrer la devise utilisée
                enregister_ticket(); // Sauvegarde après paiement
                printf("Ticket payé avec succès!\n");
//            } else {
//                printf("Authentification échouée. Paiement annulé.\n");
//            }
            return;
        }
    }
    printf("Ticket non trouvé.\n");
}


// Fonction pour charger les reservation a partir du fichier reservation
void charger_reservation_ticket() {
    FILE *file = fopen("reservation_ticket.txt", "r");
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
            reservations[compteur_reservation].genre,
            &reservations[compteur_reservation].payer,
            (int*)&reservations[compteur_reservation].devise,
            &reservations[compteur_reservation].siege
            ) !=EOF){
            compteur_reservation++;
    }
    fclose(file);
}


void display_reservations_all() {
    for (int i = 0; i < compteur_reservation; i++) {
        printf("ID: %d \n NOM: %s \n PRENOM: %s \n DATE RESERVATION: %s \n DESTINATION: %s \n GENRE:%s\n",
                    reservations[i].id,
                    reservations[i].nom,
                    reservations[i].prenom,
                    reservations[i].date_reservation,
                    reservations[i].destination,
                    reservations[i].genre);
        if (reservations[i].siegeDispo == 1) {
            printf("Siège attribué : Oui\n");
        } else {
            printf("Siège attribué : Non\n");
        }
        if (reservations[i].payer == 1) {
            printf("Paiement effectué : Oui\n");
        } else {
            printf("Paiement effectué : Non\n");
        }
        printf("Devise utilisée : %s\n", reservations[i].devise == USD ? "USD" : "FC");
        printf("\n");
    }
}



//fonction pour rechercher un client grace a l'id ou au nom
void rechercher_client() {
    char nom[100];
    int id_entry;
    printf("Entrez le nom du client a rechercher :");
    scanf("%s", nom);
    //printf("Entrez l'id a rechercher :");
    //scanf("%d",&id_entry);
    for (int i = 0; i < compteur_reservation; i++) {
        if (strstr(reservations[i].nom, nom) /*|| strstr(reservations[i].id, id_entry)*/) {
            printf("ID: %d \n NOM: %s \n PRENOM: %s \n DATE RESERVATION: %s \n DESTINATION: %s \n GENRE:%s\n SIEGE: %d\n MONTANT: %f",
                    reservations[i].id,
                    reservations[i].nom,
                    reservations[i].prenom,
                    reservations[i].date_reservation,
                    reservations[i].destination,
                    reservations[i].genre,
                    reservations[i].siege,
                    reservations[i].payer);
        }
    }
}






void enregister_ticket() {
    FILE *file = fopen("reservation_ticket.txt","w");
    if (file == NULL) {
        printf("Erreur d'ouverture du fichier des reservations!\n");
        return;
    }
    for (int i = 0; i < compteur_reservation; i++) {
        fprintf(file, "%d %s %s %s %s \n",
            reservations[i].id,
            reservations[i].nom,
            reservations[i].prenom,
            reservations[i].date_reservation,
            reservations[i].genre,
            reservations[i].payer,
            reservations[i].devise,
            reservations[i].siege
            );
    }
    fclose(file);
}
//afficher le trajet disponible
void destination_posible(){
    int i = 0;
    char ville[][100]={"1.Likasi","2.Lubumbashi","3.kolwezi","4.Kasumbalesa"};

     printf("\n\n                         +-------------------------------+\n\n");
    //afficher toute les destination
    for(;i<=3;i++){
        printf("                          %s \n",ville[i]);
    }
    printf("\n\n                          +-------------------------------+\n\n");

}



void siegeDisponible() {
    int siegesTotal = 30;
    int sieges[siegesTotal];
    for (int i = 0; i < siegesTotal; i++) {
        sieges[i] = 1; // Marquer tous les sièges comme disponibles
    }
    for (int i = 0; i < compteur_reservation; i++) {
        if (reservations[i].siegeDispo == 1) {
            sieges[reservations[i].siege - 1] = 0; // Marquer les sièges réservés comme indisponibles
        }
    }
    printf("Sièges disponibles :\n");
    for (int i = 0; i < siegesTotal; i++) {
        if (sieges[i] == 1) {
            printf("%d ", i + 1);
        }
    }
    printf("\nChoisissez un siège : ");
    int choixSiege;
    scanf("%d", &choixSiege);
    reservations[compteur_reservation].siege = choixSiege;
    reservations[compteur_reservation].siegeDispo = 1; // Marquer le siège comme réservé
}

void ajout_ticket_reser() {

    reservations[compteur_reservation].id = compteur_reservation + 1;
    printf(" Entrez le nom :\n");
    printf("--> :");
    scanf("%s", reservations[compteur_reservation].nom);
    printf("Entrez le prenom :\n");
    printf("--> ");
    scanf("%s", reservations[compteur_reservation].prenom);
    printf("Entrez le genre \n");
    printf("--> ");
    scanf("%s", reservations[compteur_reservation].genre);

    destination_posible();
    printf("Entrez la destination (saisissez le numéro) :\n--> ");
    int choix_destination;
    printf("--> ");
    scanf("%d", &choix_destination);
    switch (choix_destination) {
        case 1:
            strcpy(reservations[compteur_reservation].destination, "Likasi");
            break;
        case 2:
            strcpy(reservations[compteur_reservation].destination, "Lubumbashi");
            break;
        case 3:
            strcpy(reservations[compteur_reservation].destination, "Kolwezi");
            break;
        case 4:
            strcpy(reservations[compteur_reservation].destination, "Kasumbalesa");
            break;
        default:
            strcpy(reservations[compteur_reservation].destination, "Inconnue");
            break;
    }

    siegeDisponible();
    printf("Entrez la date de reservation (YYYY-MM-DD) :\n--> ");
    printf("--> ");

    scanf("%s", reservations[compteur_reservation].date_reservation);
    reservations[compteur_reservation].payer = 0;
    compteur_reservation++;

    enregister_ticket();
    printf("Ticket Reserver avec succes \n");
     // Paiement immédiat après réservation
    double montantDepot;
    int deviseChoix;
    char username[50], password[50];
    printf("Authentification requise pour le paiement.\n");
    printf("Nom d'utilisateur : ");
    scanf("%s", username);
    printf("Mot de passe : ");
    scanf("%s", password);

    //if (verifier_utilisateur(username, password)) {
        printf("Authentification réussie.\n");
        printf("Choisissez la devise pour le paiement (1 pour USD, 2 pour FC) :\n--> ");
        scanf("%d", &deviseChoix);
        Devise devise = (deviseChoix == 1) ? USD : FC;
        printf("Entrez le montant à déposer pour le paiement du ticket :\n--> ");
        scanf("%lf", &montantDepot);
        effectuerDepot(devise, montantDepot); // Utilisation de la devise choisie
        reservations[compteur_reservation - 1].payer = 1; // Marquer comme payé
        reservations[compteur_reservation - 1].devise = devise; // Enregistrer la devise utilisée
        enregister_ticket(); // Sauvegarde après paiement
        printf("Ticket payé avec succès!\n");
    //} else {
       // printf("Authentification échouée. Paiement annulé.\n");
    //}
}
/*
void payer_ticket() {
    int id_ticket;
    printf("Entrez l'ID du ticket à payer :\n--> ");
    scanf("%d", &id_ticket);
    for (int i = 0; i < compteur_reservation; i++) {
        if (reservations[i].id == id_ticket) {
            reservations[i].paye = 1;
            printf("Paiement effectué avec succès pour le ticket ID : %d\n", id_ticket);
            enregister_ticket(); // Sauvegarde des modifications après le paiement
            return;
        }
    }
    printf("Aucun ticket trouvé avec l'ID : %d\n", id_ticket);
}
*/





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

    /*printf("payer le bus");
    scanf("%d",reservations[compteur_reservation].montant);
    soldes[devise] -= montantRetrait;

    reservations.payer =0;
    payer = montantRetrait;
    //payer = montantRetrait - prixBus
    */
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

