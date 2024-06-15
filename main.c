#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<windows.h>

int clean ()
{
    system("cls");
}

void classe_bus()
{
    clean ();
    int classe;
    char classe1[100]={"vous avez paye votre billet de 50$: la premi�re classe\n "};
    char classe2[100] = "vous avez paye votre billet de 25$: la deuxi�me classe\n";
    char classe3[100] = "vous avez paye votre billet de 12$: la troixieme classe\n";
    char classe4[100]="Solde insuffisant\n";
    printf("\n\n\t\t\t\t -------=====^^^^ DEPOT BILLET DU BUS ^^^^=====-------\n\n\n\n\n\n");
    printf("\t\t\t Effectuer votre d�pot : ");

    scanf("%d",&classe);

    switch(classe)
    {
        case 50 : printf("%s",classe1);
           // printf("%s",&classe1);
                  printf("Bon Depart.\n");Sleep(10000); break;

        case 25 :  printf("%s",classe2);
        printf("Bon Depart\n");Sleep(10000);break;

        case 12 :  printf("%s",classe3);
        printf("Bon Depart\n");Sleep(10000);break;

        default:printf("%s",classe4);
        printf("Veuillez recharger\n");Sleep(10000);break;

    }

}

void identite()
{
    char nom;
    char postnom;
    char prenom;
    int num[10];

    printf("veuillez saisire votre nom : ");
    scanf("%s", & nom);
    printf("veuillez saisire votre postnom : ");
    scanf("%s", & postnom);
    printf("veuillez saisire votre prenom : ");
    scanf("%s", & prenom);
    printf("veuillez saisire votre num�ro mobile : ");
    scanf("%s", & num);
    classe_bus();

}

int option1()
{
        int classe;
        int mulli;
        clean();
        printf("1. LE BUS DE MULLIKUP\n");
        printf("---------------------\n");
        printf("1. Pr�mi�re Classe: 50$\n");
        printf("2. Deuxi�me Classe: 25$\n");
        printf("3. Troisi�me Classe: 7.5$\n");
        identite();

        clean();
}
int option2()
{
        int KKS;
        clean();
        printf("1. LE BUS DE KKS\n");
        printf("------------------------------------------------------------\n");
        printf("1. Pr�mi�re Classe: 50$\n");
        printf("2. Deuxi�me Classe: 25$\n");
        printf("3. Troisi�me Classe: 7.5$\n");
        identite();
        clean();
        scanf("%d",KKS);
        switch(KKS)
        {
            case 50:printf("vous avez pay� votre billet de la premi�re classe\n");
                     printf("Bon D�part\n"); break;

            case 25:  printf("vous avez pay� votre billet de la deuxi�me classe\n");
                     printf("Bon D�part\n"); break;

            case 3:   printf("vous avez pay� votre billet de la premi�re classe\n");
                      printf("Bon D�part\n"); break;
            default:  printf("veuillez saisire l'un des option");
        }
}
int option3()
{
        int KAR;
        clean();
        printf("1. LE BUS DE KAR\n");
        printf("------------------------------------------------------------\n");
        printf("1. Pr�mi�re Classe: 50$\n");
        printf("2. Deuxi�me Classe: 25$\n");
        printf("3. Troisi�me Classe: 12.5$\n");
        identite();
        clean();
           clean();

        switch(KAR)
        {
            case 1:  clean;
                     printf("vous avez pay� votre billet de la premi�re classe\n");
                     printf("Bon D�part\n"); break;

            case 2:  printf("vous avez pay� votre billet de la deuxi�me classe\n");
                     printf("Bon D�part\n"); break;

            case 3:   printf("vous avez pay� votre billet de la premi�re classe\n");
                      printf("Bon D�part\n"); break;
            default:  printf("veuillez saisire l'un des option");

        }
       // printf("1. LE BUS DE KAR\n");
        //printf("------------------------------------------------------------\n");
        //printf("1. Pr�mi�re Classe: 40$\n");
        //printf("2. Deuxi�me Classe: 20$\n");
        //printf("3. Troisi�me Classe: 10$\n");
        //printf("Choisissez votre classe et tout en effectuant votre d�pot:");
        //scanf("%d",& KAR);
}

