#include <stdio.h>
#include <string.h>
#include "contact.h"

// Vérifie si une chaîne est vide ou uniquement composée d'espaces
int isBlank(const char *str) {
    while (*str) {
        if (!(*str == ' ' || *str == '\n')) {
            return 0; // Pas vide
        }
        str++;
    }
    return 1; // Vide
}

// Ajouter un contact
void addContact(Contact contacts[], int *contactCount) {
    if (*contactCount >= MAX_CONTACTS) {
        printf("La liste de contacts est pleine.\n");
        return;
    }

    char name[NAME_LENGTH], phone[PHONE_LENGTH];
   
    printf("Entrez le nom: ");
    fgets(name, NAME_LENGTH, stdin);
    if (isBlank(name)) {
        printf("Le nom ne peut pas être vide.\n");
        return;
    }
    name[strcspn(name, "\n")] = '\0'; // Retirer le \n

    printf("Entrez le numéro de téléphone: ");
    fgets(phone, PHONE_LENGTH, stdin);
    if (isBlank(phone)) {
        printf("Le numéro de téléphone ne peut pas être vide.\n");
        return;
    }
    phone[strcspn(phone, "\n")] = '\0'; // Retirer le \n

    strcpy(contacts[*contactCount].name, name);
    strcpy(contacts[*contactCount].phone, phone);
    (*contactCount)++;
    printf("Contact ajouté avec succès !\n");
}

// Rechercher un contact par nom
void searchContact(Contact contacts[], int contactCount) {
    char searchName[NAME_LENGTH];
    printf("Entrez le nom à rechercher: ");
    fgets(searchName, NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; // Retirer le \n

    for (int i = 0; i < contactCount; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            printf("Contact trouvé: %s - %s\n", contacts[i].name, contacts[i].phone);
            return;
        }
    }
    printf("Contact non trouvé.\n");
}

// Afficher tous les contacts
void displayContacts(Contact contacts[], int contactCount) {
    if (contactCount == 0) {
        printf("Aucun contact à afficher.\n");
        return;
    }

    printf("Liste des contacts:\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%d. %s - %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

// Supprimer un contact par nom
void deleteContact(Contact contacts[], int *contactCount) {
    char deleteName[NAME_LENGTH];
    printf("Entrez le nom du contact à supprimer: ");
    fgets(deleteName, NAME_LENGTH, stdin);
    deleteName[strcspn(deleteName, "\n")] = '\0'; // Retirer le \n

    for (int i = 0; i < *contactCount; i++) {
        if (strcmp(contacts[i].name, deleteName) == 0) {
            // Déplacer tous les contacts suivants vers l'avant
            for (int j = i; j < *contactCount - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*contactCount)--;
            printf("Contact supprimé avec succès.\n");
            return;
        }
    }
    printf("Contact non trouvé.\n");
}

