#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 15

// Déclarations des tableaux
char names[MAX_CONTACTS][MAX_NAME_LEN];
char phones[MAX_CONTACTS][MAX_PHONE_LEN];
int contactCount = 0;

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

// Fonction principale
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