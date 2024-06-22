#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "operation.h"

void payement(){
    menuMobile();
}
void menu(){
    int choix;
    do{

        Menu_principal();
        printf("Selectionner une option :");
        scanf("%d",&choix);
        switch (choix){
            case 1:
                system("clear");
                do{
                            system("clear");
                            Menu_principal_reser();
                            printf("Selectionner une option :");
                            scanf("%d",&choix);
                            switch (choix){
                                case 1:
                                    system("clear");
                                    do{
                                      printf("\n   +-------------------------------------------------------------------------+\n\n");
                                      printf("\n   |                               1.Destination possible                    |  \n");
                                      printf("\n   |                               2.Precedant                               |  \n");
                                      printf("\n   +-------------------------------------------------------------------------+\n\n");
                                      printf("\n   Selectionner une option :\n\n");
                                      scanf("%d",&choix);
                                      switch(choix){
                                          case 1:
                                                system("clear");
                                                destination_posible();
                                                break;
                                         default:
                                                system("clear");
                                                printf("\n Au revoir\n\n");
                                                break;
                                            }
                                      }while(choix != 2);

                                    break;
                                case 2:
                                    system("clear");
                                    ajout_ticket_reser();
                                    break;
                                case 3:
                                    system("clear");
                                    payement();
                                    break;
                                default:
                                    printf("\n    ******* Menu Precedant ********\n\n");
                                    break;
                            }

                        }while(choix != 4);

                break;
            case 2:
                system("clear");
                display_reservations_all();
                break;
            case 3:
                system("clear");
                rechercher_client();
                break;
            case 4:
                system("clear");
                payer_ticket();
                break;
            case 5:
                system("clear");
                printf("\n\n+--------------------Merci d'utiser notre Servicer----------------------+\n\n");

                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }

    }while(choix != 5);

}


// Fonction permettant d'afficher le menu et de g�rer les choix de l'utilisateur
void menuMobile()
{
    // Variable pour stocker le choix de l'utilisateur
    int choix;

    // Boucle jusqu'� ce que l'utilisateur choisisse de sortir (option 3)
    do {
        // Afficher le menu
        afficherMenu();

        // Inviter l'utilisateur � choisir une option
        printf("Choisissez une option :");

        // Lire le choix de l'utilisateur
        scanf("%d", &choix);

        // Effacer la console
        system("clear");

        // G�rer le choix de l'utilisateur
        switch (choix) {
            case 0:
                // Si l'utilisateur a choisi l'option 0, g�rer les soldes des comptes
                gererSoldes();
                //
                break;
            case 1:
                // Si l'utilisateur a choisi l'option 1, traiter les transactions de d�p�t
                gererDepot();
                break;
            case 2:
                // Si l'utilisateur a choisi l'option 2, traiter les transactions de retrait
                gererRetrait();
                break;
            case 3:
                 // Si l'utilisateur a choisi l'option 3, afficher l'historique des transactions
                gererTransactions();
                break;
            default:
                // Si l'utilisateur a choisi une autre option, dire au revoir et sortir
                printf("\n Au revoir !\n");
        }
    } while (choix != 4);
}
