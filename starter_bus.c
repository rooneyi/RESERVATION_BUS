#include <stdio.h>

#include <stdlib.h>

#include "menu.h"

#include "operation_bus.h"

// Fonction permettant d'afficher le menu et de g�rer les choix de l'utilisateur
void menu()
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

                // Si l'utilisateur a choisi l'option 0, g�rer reserver le ticket
                reserverTicket();

                // Si l'utilisateur a choisi l'option 0, g�rer les soldes des comptes
                break;
            case 1:
                // Si l'utilisateur a choisi l'option 1, traiter les transactions de d�p�t
                //gererDepot();
                break;
            case 2:
                // Si l'utilisateur a choisi l'option 2, traiter les transactions de retrait
                //gererRetrait();
                break;
            case 3:
                 // Si l'utilisateur a choisi l'option 3, afficher l'historique des transactions
                //gererTransactions();
                break;
            default:
                // Si l'utilisateur a choisi une autre option, dire au revoir et sortir
                printf("\n Au revoir !\n");

            }

        } while (choix != 4);
    }


