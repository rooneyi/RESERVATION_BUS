#include <stdlib.h>

// Les types de devises

typedef enum Devise { USD, FC }Devise;


// Structure qui represente une date

struct Date
{
    int jour;
    int mois;
    int annee;
};

// Les types de transactions

typedef enum TypeTransaction { DEPOT, RETRAIT } TypeTransaction;

// Structure qui represente une trasanction

struct Transaction
{
    struct Date date;
    double montant;
    Devise devise;
    TypeTransaction type;

};

// Tableau contenant les soldes pour chaque devise
double soldes[] = {0.0, 0.0};

// Tableau contenant les transactions pour toutes les devises
struct Transaction* transactions = NULL;


