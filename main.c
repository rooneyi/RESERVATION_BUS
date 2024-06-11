#include <stdio.h>
#include <stdlib.h>
#include "starter_bus.h"
#include <mysql/mysql.h>
#include <string.h>


typedef struct {
    char nom[50];
    int place;

}Trajet;
typedef  struct {
    char *nom;
    char *prenom;
    char *numtel;
    char *Destiation;
    char *dateReservation;
    char *genre;

}ReservationEffectuer;
typedef  struct {
    char *nom;
    char *prenom;
    char *numtel;
    char *Destination;
    char *dateReservation;
    char *genre;
    ReservationEffectuer *reservation;
    int nreservation;
}Client;

typedef  struct {
    char *name;
    char DestinationBus;
    int NSiegeDispo;
    int NSiege;
    int NBus;
    char *Destination;
    Client *client;
    int NClient;
}Bus;



/* -------Zon reservation --------*/
ReservationEffectuer* createReservation(){
    ReservationEffectuer* reservation=NULL;
    reservation = malloc(sizeof(ReservationEffectuer ));
    if (reservation==NULL){
        fprintf(stderr,"Erreur d'allocation de la memoire");
        exit(EXIT_FAILURE);
    }
    reservation->nom=NULL;
    reservation->prenom=NULL;
    reservation->numtel=NULL;
    reservation->genre=NULL;
    reservation->dateReservation=NULL;
    reservation->Destiation=NULL;

    return reservation;
}
void R_addNom(ReservationEffectuer *reservation,char* nom){
    reservation->nom= malloc(sizeof (char*));
    if (reservation->nom==NULL){
        fprintf(stderr,"Erreur d'allocation de la memoire pour l'ajout du nom");
        exit(EXIT_FAILURE);
    }
    strcpy(reservation->nom,nom);
    return;
}
void R_addDestination(ReservationEffectuer *reservation,char* Destination){
    reservation->Destiation= malloc(sizeof (char*));
    if (reservation->Destiation==NULL){
        fprintf(stderr,"Erreur d'allocation de la memoire pour l'ajout du nom");
        exit(EXIT_FAILURE);
    }
    strcpy(reservation->Destiation,Destination);
}
void R_addgenre(ReservationEffectuer *reservation,char* genre){
    reservation->genre= malloc(sizeof (char*));
    if (reservation->genre==NULL){
        fprintf(stderr,"Erreur d'allocation de la memoire pour l'ajout du nom");
        exit(EXIT_FAILURE);
    }
    strcpy(reservation->genre,genre);
    return;
}
void R_addPrenom(ReservationEffectuer *reservation,char* prenom){
    reservation->prenom= malloc(sizeof (char*));
    if (reservation->prenom==NULL){
        fprintf(stderr,"Erreur d'allocation de la memoire pour l'ajout du nom");
        exit(EXIT_FAILURE);
    }
    strcpy(reservation->prenom,prenom);
    return;
}
void R_addNumtel(ReservationEffectuer *reservation,char* numtel){
    reservation->numtel= malloc(sizeof (char*));
    if (reservation->numtel==NULL){
        fprintf(stderr,"Erreur d'allocation de la memoire pour l'ajout du nom");
        exit(EXIT_FAILURE);
    }
    strcpy(reservation->numtel,numtel);
    return;
}
void R_addDateReservation(ReservationEffectuer *reservation,char* datereservation){
    reservation->dateReservation= malloc(sizeof (char*));
    if (reservation->dateReservation==NULL){
        fprintf(stderr,"Erreur d'allocation de la memoire pour l'ajout du nom");
        exit(EXIT_FAILURE);
    }
    strcpy(reservation->dateReservation,datereservation);
    return;
}

//fonction pour liberer l'espace allouer
void clean_reservation(ReservationEffectuer *reservation){
    if (reservation->nom != NULL)
    {
        free(reservation->nom);
        reservation->nom=NULL;
    }
    if (reservation->prenom != NULL)
    {
        free(reservation->prenom);
        reservation->prenom=NULL;
    }
    if (reservation->genre != NULL)
    {
        free(reservation->genre);
        reservation->genre=NULL;
    }
    if (reservation->Destiation != NULL)
    {
        free(reservation->Destiation);
        reservation->Destiation=NULL;
    }
    if (reservation->dateReservation != NULL)
    {
        free(reservation->dateReservation);
        reservation->dateReservation=NULL;
    }
    if (reservation->numtel != NULL)
    {
        free(reservation->numtel);
        reservation->numtel=NULL;
    }



}
void AfficherReservation(ReservationEffectuer r){
    printf("%s %s %s %s %s %s a reserver \n",r.nom,r.prenom,r.Destiation,r.numtel,r.dateReservation,r.genre);

}

void AfficherTrajet(Trajet trajet){
    printf("%s %s %s %s %s %s a reserver \n",trajet.nom);

}
/*------zone client ----------*/
void AfficherClient(Client client){
    printf("%s %s %s %s %s %s a reserver \n",client.nom,client.prenom,client.reservation,client.genre,client.numtel,client.dateReservation);

}

void clean_Client(Client *client){
    int i=0;
    if (client->nom != NULL)
    {
        free(client->nom);
        client->nom=NULL;
    }
    if (client->prenom != NULL)
    {
        free(client->prenom);
        client->prenom=NULL;
    }
    if (client->genre != NULL)
    {
        free(client->genre);
        client->genre=NULL;
    }
    if (client->Destination != NULL)
    {
        free(client->Destination);
        client->Destination=NULL;
    }
    if (client->dateReservation != NULL)
    {
        free(client->dateReservation);
        client->dateReservation=NULL;
    }
    if (client->numtel != NULL)
    {
        free(client->numtel);
        client->numtel=NULL;
    }
    for (;i<client->nreservation; i++) {
        if (&client->reservation != NULL){
            clean_reservation(&client->reservation[i]);
        }
    }



}

void c_addReservation(Client* client,ReservationEffectuer reservation){
    client->reservation= realloc(client->reservation,sizeof (ReservationEffectuer)*(client->nreservation+1));
    if(client->reservation ==NULL){
        fprintf(stderr,"erreur d'allocation de la memoire");
        exit(EXIT_FAILURE);
    }
    client->reservation[client->nreservation]=reservation;
    client->nreservation++;
    return;
}
void c_addNom(Client* client,char* nom){
    client->nom= malloc(sizeof (char*));
    if (client->nom==NULL){
        fprintf(stderr,"Erreur d'allocation de la memoire pour l'ajout du nom");
        exit(EXIT_FAILURE);
    }
    strcpy(client->nom,nom);
    return;
}

void c_addDestination(Client* client,char* Destination){
    client->Destination= malloc(sizeof (char*));
    if (client->Destination==NULL){
        fprintf(stderr,"Erreur d'allocation de la memoire pour l'ajout du nom");
        exit(EXIT_FAILURE);
    }
    strcpy(client->Destination,Destination);
}
void c_addgenre(Client*client,char* genre){
    client->genre= malloc(sizeof (char*));
    if (client->genre==NULL){
        fprintf(stderr,"Erreur d'allocation de la memoire pour l'ajout du nom");
        exit(EXIT_FAILURE);
    }
    strcpy(client->genre,genre);
    return;
}
void c_addPrenom(Client*client,char* prenom){
    client->prenom= malloc(sizeof (char*));
    if (client->prenom==NULL){
        fprintf(stderr,"Erreur d'allocation de la memoire pour l'ajout du nom");
        exit(EXIT_FAILURE);
    }
    strcpy(client->prenom,prenom);
    return;
}
void c_addNumtel(Client*client,char* numtel){
    client->numtel= malloc(sizeof (char*));
    if (client->numtel==NULL){
        fprintf(stderr,"Erreur d'allocation de la memoire pour l'ajout du nom");
        exit(EXIT_FAILURE);
    }
    strcpy(client->numtel,numtel);
    return;
}
void c_addDateReservation(Client*client,char* datereservation) {
    client->dateReservation = malloc(sizeof(char *));
    if (client->dateReservation == NULL) {
        fprintf(stderr, "Erreur d'allocation de la memoire pour l'ajout du nom");
        exit(EXIT_FAILURE);
    }
    strcpy(client->dateReservation, datereservation);
    return;

}


Client* createClient(){
    Client* client=NULL;
    client =malloc(sizeof(Client));
    if (client==NULL){
        fprintf(stderr,"Erreur d'allocation de la memoire");
        exit(EXIT_FAILURE);
    }
    client->nom=NULL;
    client->prenom=NULL;
    client->numtel=NULL;
    client->genre=NULL;
    client->dateReservation=NULL;
    client->Destination=NULL;
    client->reservation=NULL;
    client->nreservation=0;

    return client;
}


/* -------Zon Bus --------*/
Bus *createBus(){
    Bus* bus=NULL;
    bus = malloc(sizeof(ReservationEffectuer ));
    if (bus==NULL){
        fprintf(stderr,"Erreur d'allocation de la memoire");
        exit(EXIT_FAILURE);
    }
    bus->name=NULL;
    bus->NSiege=0;
    bus->NBus=0;
    bus->client=NULL;
    bus->NClient=0;
    bus->Destination=NULL;
    bus->NSiegeDispo=0;

    return bus;
}
void bus_clean(Bus *bus){
    int i=0;
    if (bus->name!= NULL){
        free(bus->name);
        bus->name = NULL;
    }
    if (bus->client!=NULL)
    {
        free(bus->client);
        bus->client =NULL;
    }
    for (i=0; i<bus->NClient;i++) {
        if (bus->client != NULL){
            clean_Client(&bus->client[i]);
        }
    }
    if (bus!= NULL){
        free(bus);
        bus = NULL;
    }
    return;

}


/*---------------------------------------------*/
/*
int connectDatabase(){
    MYSQL *conn;
    MYSQL_RES *result;
    MYSQL_ROW row;

    // Initialiser la connexion
    conn = mysql_init(NULL);
    if (conn == NULL) {
        printf( "Failed to initialize MySQL connection\n");
        exit(1);
    }

    // Se connecter au serveur MySQL
    if (mysql_real_connect(conn, "localhost", "root", "root", "main", 3306,NULL,0) == NULL) {
        fprintf(stderr, "Failed to connect to MySQL: %s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }

    // Exécuter une requête SQL
    char query[] = "SELECT * FROM user";
    if (mysql_query(conn, query)){
        fprintf(stderr, "Failed to execute query: %s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }

    // Stocker le résultat de la requête
    result = mysql_store_result(conn);
    if (result == NULL) {
        fprintf(stderr, "Failed to store result set: %s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }

    // Traiter les résultats de la requête
    int num_fields = mysql_num_fields(result);
    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; i++) {
            printf("%s\t", row[i]);
        }
        printf("\n");
    }

    // Libérer les ressources
    mysql_free_result(result);
    mysql_close(conn);
    return 0;
}
 */

// Fonction principale du programme
int main()
{


    ReservationEffectuer r1={"rooney", "s", "0994644422", "kipushi", "67", "M"};
    Client *client;
    Trajet *trajet;

    ReservationEffectuer r;


    R_addPrenom(&r,"simplice");
    R_addgenre(&r,"F");
    R_addDestination(&r,"Lubumbashi");
    R_addNumtel(&r,"0994644242");
    R_addNom(&r,"rooney");
    R_addDateReservation(&r,"8906");
    AfficherReservation(r);

    client=createClient();
    c_addNom(client,"ROONEY");
    c_addPrenom(client,"45");
    c_addNumtel(client,"456666666");
    c_addgenre(client,"M");
    c_addDestination(client,"LUBUMBASHI");
    c_addDateReservation(client,"67");
    c_addReservation(client,r1);
    AfficherClient((*client));

    clean_reservation(&r);
    menu();



    // Retourne 0 pour indiquer que le programme s'est exécuté avec succès
    return 0;
}








