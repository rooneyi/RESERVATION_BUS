#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

#include <stdlib.h>

#include "operation.h"

void Menu_principal(){
    printf("|+------------------------ Bienvenu sur ReserTrans -----------------------+ |\n");
    printf("|                                                                           |\n");
    printf("|                         1.   Reserver votre Bus                           |\n");
    printf("|                         2.   Getsion des Utilisateur                      |\n");
    printf("|                         3.    Rechercher un client                        |\n");
    printf("|                         4.    Payement avec Mobile Money                  |\n");
    printf("|                         5.      Quitter                                   |\n");
    printf("|+--------------------------------------------------------------------------+ \n\n");

}

void Menu_principal_reser(){
    printf("|+------------------------ Reservation -----------------------+ |\n");
    printf("|                                                               |\n");
    printf("|                         1.    trajet diponible                |\n");
    printf("|                         3.    Reserver votre Bus              |\n");
    printf("|                         4.    Payement avec Mobile Money      |\n");
    printf("|                         5.      Quitter                       |\n");
    printf("|+--------------------------------------------------------------+ \n\n");

}



// Fonction permettant d'afficher le menu principal

void afficherMenu()
{
    // Imprimer le message de bienvenue et les options

    printf("|+------------------------ TRANSACTION AVEC  MOBILE MONEY  -----------------------+ |\n");
    printf("|                                                                                   |\n");
    printf("|                         0. Verifier le solde.                                     |\n");
    printf("|                         1. Effectuer un depot.                                    |\n");
    printf("|                         2. Effectuer un retrait.                                  |\n");
    printf("|                         3. Afficher les transactions.                             |\n");
    printf("|                         5.      Quitter                                           |\n");
    printf("|+----------------------------------------------------------------------------------+ \n\n");
}

// Fonction permettant d'afficher les options de devises

void afficherDevisesOptions()
{
    // Imprimer les options devises

    printf("\n Selectionnez une devise :\n\n");
    printf("--> 0. USD.\n");
    printf("--> 1. FC.\n\n");
}

// Fonction de gestion des soldes des comptes

void gererSoldes()
{
    // Variable permettant de stocker le choix de la devise de l'utilisateur
    int devise;

    // Afficher le menu
    afficherMenu();

    // Effacer la console
    system("cls");

    printf("\t\t+------------Verifier votre solde------------------------+\n\n");

    // Afficher option devise
    afficherDevisesOptions();

    // Invite l'utilisateur � choisir une devise
    printf("Choisissez une option :");

    // R�cup�rer le choix de l'utilisateur
    scanf("%d", &devise);

    // G�rer le choix de l'utilisateur
    switch(devise)
    {
        case 0:
            // Si l'utilisateur a choisi USD, imprimer le solde en USD
            printf("\nVotre solde en USD est de %.2f USD\n\n\n", verifierSolde(devise));
            break;
        case 1:
            // Si l'utilisateur a choisi FC, imprimer le solde en FC
            printf("\nVotre solde en FC est de %.2f FC\n\n\n", verifierSolde(devise));
            break;
    }
}

// Fonction permettant de traiter les op�rations de d�p�t

void gererDepot()
{
    // Variables pour stocker le choix de la devise et le montant du d�p�t de l'utilisateur
    int devise, montantDepot;

    // Afficher le menu
    afficherMenu();

    // Effacer la console
    system("cls");

    printf("\t\tEffectuer un depot\n\n");

    // Afficher option devise
    afficherDevisesOptions();

    // Inviter l'utilisateur � choisir une devise
    printf("Choisissez une option :");

     // R�cup�rer le choix de l'utilisateur
    scanf("%d", &devise);

    // Invite l'utilisateur � saisir le montant du d�p�t
    printf("Saisir le montant :");

    // R�cup�rer le montant du d�p�t
    scanf("%d", &montantDepot);

    // Effectuer l'op�ration de d�p�t
    effectuerDepot(devise,montantDepot);
}

// Fonction permettant de traiter les op�rations de retrait

void gererRetrait()
{
    // Variables pour stocker le choix de la devise de l'utilisateur et le montant du retrait
    int devise, montantRetrait;

    // Afficher le menu
    afficherMenu();

    // Effacer la console
    system("cls");

    printf("\t\tEffectuer un retrait\n\n");

    // Afficher option devise
    afficherDevisesOptions();

    // Inviter l'utilisateur � choisir une devise
    printf("Choisissez une option :");

    // R�cup�rer le choix de l'utilisateur
    scanf("%d", &devise);

    // Invite l'utilisateur � saisir le montant du retrait
    printf("Saisir le montant :");

   // R�cup�rer le montant du retrait
    scanf("%d", &montantRetrait);

    // Effectuer l'op�ration de retrait
    effectuerRetrait(devise,montantRetrait);
}

// Fonction permettant d'afficher l'historique des transactions

void gererTransactions()
{

    // Afficher le menu
    afficherMenu();

    // Effacer la console
    system("cls");

    printf("\t\tListe des trasanctions effectuees\n\n");

    afficherTransactions();
}
