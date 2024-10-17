#include <stdio.h>
#include <string.h>
#include "contacts.h"

// Déclarations des tableaux statiques ici (portée locale à contacts.c)
static char names[MAX_CONTACTS][MAX_NAME_LEN];
static char phones[MAX_CONTACTS][MAX_PHONE_LEN];
static int contactCount = 0; // Nombre actuel de contacts

// Fonction pour ajouter un contact (vérifie les doublons)
void addContact(char name[], char phone[]) {
    // Vérification des doublons
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(names[i], name) == 0) {
            printf("Erreur: le contact existe déjà.\n");
            return;
        }
    }
    // Ajout du nouveau contact
    strcpy(names[contactCount], name);
    strcpy(phones[contactCount], phone);
    contactCount++;
    printf("Contact ajouté avec succès.\n");
}

// Fonction pour rechercher un contact par nom
void searchContact(char name[]) {
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(names[i], name) == 0) {
            printf("Contact trouvé: %s - %s\n", names[i], phones[i]);
            return;
        }
    }
    printf("Contact non trouvé.\n");
}

// Fonction pour afficher tous les contacts
void displayContacts() {
    if (contactCount == 0) {
        printf("Aucun contact à afficher.\n");
        return;
    }
    for (int i = 0; i < contactCount; i++) {
        printf("%d. %s - %s\n", i + 1, names[i], phones[i]);
    }
}

// Fonction pour supprimer un contact
void deleteContact(char name[]) {
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(names[i], name) == 0) {
            for (int j = i; j < contactCount - 1; j++) {
                strcpy(names[j], names[j + 1]);
                strcpy(phones[j], phones[j + 1]);
            }
            contactCount--;
            printf("Contact supprimé avec succès.\n");
            return;
        }
    }
    printf("Contact non trouvé.\n");
}