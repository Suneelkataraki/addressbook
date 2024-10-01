#ifndef CONTACT_H
#define CONTACT_H
#define _GNU_SOURCE
#define MAX_CONTACTS 100

#include <stdio.h>
#include <string.h>


typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;

void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);

void loadContactsFromFile( AddressBook *addressBook);
void saveAndExits(AddressBook *addressBook);
void saveContactsToFile(AddressBook *addressBook);

void print_equalto();
void red();
void green();
void bule();
void yellow();
void reset ();
char *validate_name(char *str);
char *validate_phone(char *str,AddressBook *addressBook);
char *validate_email(char *str,AddressBook *addressBook);
#endif
