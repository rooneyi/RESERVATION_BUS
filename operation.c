#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// Structure pour stocker les informations d'une reseravtion
typedef struct {
    int id;             // Identifiant du ticket
    char nom[100];
    char prenom[100];
    char destination[100];
    char date_reservation[11];
    char genre[1];   // Date de reservation (format YYYY-MM-DD)
    int Payer;
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


// Fonction pour charger les reservation a partir du fichier reservation
void reservation_ticket() {
    FILE *file = fopen("reservation.txt", "r");
    if (file == NULL) {
        printf("Erreur d'ouverture du fichier des resrevation!\n");
        return;
    }
    compteur_reservation = 0;
    while (fscanf(file, "%d %s %s %s %s %d\n",
            &reservations[compteur_reservation].id,
            reservations[compteur_reservation].nom,
            reservations[compteur_reservation].prenom,
            reservations[compteur_reservation].date_reservation,
            reservations[compteur_reservation].genre,
            &reservations[compteur_reservation].Payer)){
            compteur_reservation++;
    }
    fclose(file);
}


//fonction pour rechercher un client grace a l'id ou au nom
void rechercher_client() {
    char nom[100];
    int id_entry;
    printf("Entrez le nom du client a rechercher ");
    scanf("%s", nom);
    printf("Entrez l'id a rechercher ");
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

void ajout_ticket_reser() {
    /*if (book_count >= MAX_BOOKS) {
        printf("Limite de livres atteinte!\n");
        return;
    }
    */
    reservations[compteur_reservation].id = compteur_reservation + 1;
    printf("Entrez le nom ");
    scanf("%s", reservations[compteur_reservation].nom);
    printf("Entrez le prenom ");
    scanf("%s", reservations[compteur_reservation].prenom);
    printf("Entrez le genre ");
    scanf("%s", reservations[compteur_reservation].genre);
    printf("Entrez la destination ");
    destination_posible();
    printf("Entrez la destination (en Toute lettre)");
    scanf("%s", reservations[compteur_reservation].destination);
    printf("Entrez la date de reservation ");
    scanf("%s", reservations[compteur_reservation].date_reservation);

    //printf("Entrez le numero de telephone ");
    //scanf("%s", reservations[compteur_reservation].tele);


    enregister_ticket();
    printf("Ticket Reserver avec succes \n");
}
