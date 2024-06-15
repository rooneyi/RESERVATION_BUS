#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "operation.h"

void menu(){
    int choix;
    do{

        Menu_principal();
        printf("Selectionner une option :");
        scanf("%d",&choix);
        switch (choix){
            case 1:
                ajout_ticket_reser();
                break;
            case 2:
                break;
            case 3:
                rechercher_client();
                break;
            case 4:
                break;
            default:
                printf("Au revoir");
                break;
        }

    }while(choix != 5);

}
