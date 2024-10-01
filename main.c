#include "contact.h"
#include<string.h>
#include<stdlib.h>


int main()
{
    //all function calls should be inside the main
    int choice;
    AddressBook addressBook;
    
    initialize(&addressBook); // Initialize the address book

    do {
        printf("\n***Address Book Menu***:\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
        printf("6. save contacts\n");	
        printf("7. Exit\n");
        p: printf("\e[1;34m Enter your choice: \e[0;m\n");
          scanf("%d", &choice);
        
          switch (choice) {
            case 1:
                createContact(&addressBook);
                break;
            case 2:
                searchContact(&addressBook);
                break;
            case 3:
                editContact(&addressBook);
                break;
            case 4:
                deleteContact(&addressBook);
                break;
            case 5:          
                listContacts(&addressBook);
                break;
            case 6:
                printf("Saving and exitsing...\n");
                saveContactsToFile(&addressBook);
                saveAndExits(&addressBook);
                break;
            case 7:
                printf("Exits.....\n");
                break;
            default:
                printf("\e[1;31m Invalid choice. Please try again.\e[0;m\n");
                goto p;
        }
        
    } while (choice !=7);
    
       return 0;
}

