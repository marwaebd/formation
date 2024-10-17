#include <stdio.h>
#include <string.h>
#include "contacts.h"

int main() {
    int choix;
    char name[MAX_NAME_LEN], phone[MAX_PHONE_LEN];

    do {
        printf("\nMenu:\n");
        printf("1. Ajouter un contact\n");
        printf("2. Rechercher un contact\n");
        printf("3. Afficher tous les contacts\n");
        printf("4. Supprimer un contact\n");
        printf("5. Quitter\n");
        printf("Votre choix: ");
        scanf("%d", &choix);
        getchar(); // Pour consommer le '\n' après l'entrée du choix

        switch (choix) {
            case 1:
                printf("Entrez le nom: ");
                fgets(name, MAX_NAME_LEN, stdin);
                name[strcspn(name, "\n")] = '\0'; // Retirer le '\n'
                printf("Entrez le numéro de téléphone: ");
                fgets(phone, MAX_PHONE_LEN, stdin);
                phone[strcspn(phone, "\n")] = '\0'; // Retirer le '\n'
                addContact(name, phone);
                break;
            case 2:
                printf("Entrez le nom à rechercher: ");
                fgets(name, MAX_NAME_LEN, stdin);
                name[strcspn(name, "\n")] = '\0';
                searchContact(name);
                break;
            case 3:
                displayContacts();
                break;
            case 4:
                printf("Entrez le nom à supprimer: ");
                fgets(name, MAX_NAME_LEN, stdin);
                name[strcspn(name, "\n")] = '\0';
                deleteContact(name);
                break;
            case 5:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide, essayez encore.\n");
        }
    } while (choix != 5);

    return 0;
}
