#ifndef CONTACTS_H
#define CONTACTS_H

#define MAX_CONTACTS 100
#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 15

// Déclare les fonctions
void addContact(char name[], char phone[]);
void searchContact(char name[]);
void displayContacts();
void deleteContact(char name[]);

#endif // CONTACTS_H