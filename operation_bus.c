#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mysql/mysql.h>
/*void connectDB()
{
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
*/

void NewTicket(char nom[],char prenom[],char sexe,int age,char numtel[],char DateReservation[],char VilleDestination)
{
    //recupere les infos de l'utilisateur lors de la reservation du ticket


}


//fonction pour reserver le ticket avec un parametre
void reserverTicket()
{
    char nom[50];
    char prenom[50];
    char sexe;
    int age;
    char numtel[10];
    char DateReservation[50];
    char VilleDestination[50];
    printf("Entrez votre nom :");
    scanf("%s",nom);
    printf("Entrez votre Prenom :");
    scanf("%s",prenom);
    printf("Entrez votre age :");
    scanf("%d",&age);
    printf("Entrez votre Numero de telephone :");
    scanf("%s",numtel);
    printf("Date de reservation :");
    scanf("%s",DateReservation);
    printf("ENtrez votre destination ");
    scanf("%s",VilleDestination);


}

//fonction pour afficher les transaction des ticket effectuer
int transactionEffectuerTicketParticulier(int ID_ticket)
{

}

//fonction pour

