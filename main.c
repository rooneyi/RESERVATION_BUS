#include <stdio.h>
#include <stdlib.h>
int main (int argc , const char* agrv[]){

    int choix = 0;
    int prix = 0;

    printf("1.VIP\n2. Moyen\n3. Standard\n Votre choix\n");
    scanf("%d" ,&choix);

    while(choix !=1 && choix != 2 && choix != 3){
        printf("Erreur choix incorrect !\n");
        printf("1.VIP\n2. Moyen\n3. Standard\n Votre choix\n");
        scanf("%d" ,&choix);
    }



         switch(choix) {
        case 1:
            printf("vous avez choisi le siege VIP\n");

            afficherLesPrix(0,0);

            break;
        case 2:
            printf("vous avez choisi le siege MOyen\n");
            afficherLesPrix(1,1);
            break;
        case 3:
            printf("vous avez choisi le siege  Standard\n");
            afficherLesPrix(2,2);
            break;
    }


    return 0;

}

void afficherLesPrix(int USD, int FC)
{
    const float MIN_PRIX_SIEGE_FC[]={50000,30000,20000};
    const float MIN_PRIX_SIEGE_USD[]={25.0,15.0,10.0};

    printf("Prix en Franc : %f, Prix en Dollar : %f", MIN_PRIX_SIEGE_FC[FC], MIN_PRIX_SIEGE_USD[USD]);
}

