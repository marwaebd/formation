#include <stdio.h>
#include "contactstruct.h"

int main() {
    Contact contacts[MAX_CONTACTS]; // Tableau de contacts
    int contactCount = 0; // Nombre de contacts dans la liste
    int choix;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Ajouter un contact\n");
        printf("2. Rechercher un contact\n");
        printf("3. Afficher tous les contacts\n");
        printf("4. Supprimer un contact\n");
        printf("5. Quitter\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);
        getchar(); // Pour consommer le \n après scanf

        switch (choix) {
            case 1:
                addContact(contacts, &contactCount);
                break;
            case 2:
                searchContact(contacts, contactCount);
                break;
            case 3:
                displayContacts(contacts, contactCount);
                break;
            case 4:
                deleteContact(contacts, &contactCount);
                break;
            case 5:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 5);

    return 0;
}

