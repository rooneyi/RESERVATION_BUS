#include <stdio.h>
#include <stdlib.h>

int main(){



    int choix_menu;
    int choix_sous_menu;
    int numero_ticket;
    int numero_bus;

  do{

        printf("=== menu principal===\n");
         printf("1. bus\n");
          printf("2. siege\n");
           printf("0. quitter\n");
        printf("choisissez un menu : ");
        scanf("%d", &choix_menu);

        switch (choix_menu) {
            case 1:
                printf("=== menu bus ===\n");
                break ;
            case 2 :
                printf("=== menu siege ===\n");
                break ;
            case 0:
                printf(" === revenir au menu precedent ===");
                break ;
            default :
                printf("choix invalide. veuillez reessayer.\n");
                break ;
                }
        printf("=== Menu bus ===\n");
        printf("1. Likasi\n");
        printf("2. Kolwezi\n");
        printf("3. Lubumbashi\n");
        printf("0. Quitter\n");
        printf("Choisissez un menu : ");
        scanf("%d", &choix_menu);

        switch (choix_menu) {
            case 1:
                printf("=== Menu Likasi ===\n");
                // Traiter les actions du menu Likasi

                printf("Entrez votre num�ro de ticket : ");
                scanf("%d", &numero_ticket);

                // Calculer le num�ro de bus en fonction du num�ro de ticket
                numero_bus = (numero_ticket % 10) + 1;

                printf("Vous �tes dans le bus num�ro %d\n", numero_bus);
                break;
            case 2:
                printf("=== Menu Kolwezi ===\n");
                // Traiter les actions du menu Kolwezi

                printf("Entrez votre num�ro de ticket : ");
                scanf("%d", &numero_ticket);

                // Calculer le num�ro de bus en fonction du num�ro de ticket
                numero_bus = (numero_ticket % 10) + 1;

                printf("Vous �tes dans le bus num�ro %d\n", numero_bus);
                break;
            case 3:
                printf("=== Menu Lubumbashi ===\n");
                printf("Entrez votre num�ro de ticket : ");
                scanf("%d", &numero_ticket);

                // Calculer le num�ro de bus en fonction du num�ro de ticket
                numero_bus = (numero_ticket % 10) + 1;

                printf("Vous �tes dans le bus num�ro %d\n", numero_bus);

                break;
            case 0:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide. Veuillez r�essayer.\n");
                break;
        }
    }
    while(choix_menu != 0);

    return 0;
}

