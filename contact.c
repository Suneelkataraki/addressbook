#include "contact.h"
#include<strings.h>
#include<stdlib.h>

//extern Contact dummyContacts[11];
void red()
{
    printf("\033[1;31m");
}

void bule ()
{
    printf("\033[0;34m");
}

void green ()
{
    printf("\033[0;32m");
}
void yellow()
{
    printf("\033[0;33m");
}

void reset()
{
    printf("\033[0m");
}
void print_equalto()
{
    for(int i=0;i<MAX_CONTACTS;i++)
    {
        printf("=");
    }
}
/*list the all contacts in the file*/
void listContacts(AddressBook *addressBook) 
{
    print_equalto();
    printf("\n");
    yellow();
    printf("%-10s: %-30s: %-30s: %-20s\n","S.No","Name","Phone No","Email ID");
    reset();
    print_equalto();
    printf("\n");
    int i;
    /*printing the all list contacts*/
    for( i=0;i<addressBook->contactCount;i++)
    {
        printf("%-10d: %-30s: %-30s: %-20s\n",i+1,addressBook->contacts[i].name,
        addressBook->contacts[i].phone,addressBook->contacts[i].email);
        printf("\n");
    }
    print_equalto();
    printf("\n");

    char ch;
    bule ();
    printf("Do you want to continue Y/N : ");
    reset();
    scanf(" %c",&ch);
    if(ch=='N' || ch=='n')
    {
        /*program terminted*/
        exit(0);
    }
}
void initialize(AddressBook *addressBook) 
{
    /*function calling*/
    loadContactsFromFile(addressBook);
}

void loadContactsFromFile( AddressBook *addressBook)
{
    /*open the file in read mode*/
    FILE *fptr=fopen("data.txt","r");
    if(fptr==NULL)
    {
        printf("File Not Exits\n");
        return;
    }
    /*read the contactcount file*/
    fscanf(fptr,"%d\n",&addressBook->contactCount);
    int i;
    for(i=0;i<addressBook->contactCount;i++)
    {
        /*read upto , in the list contacts*/
        fscanf(fptr,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name,
              addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
}

void saveAndExits(AddressBook *addressBook)
{
    /*save to file function call*/
    saveContactsToFile(addressBook);
    exit(EXIT_SUCCESS);
}

void saveContactsToFile(AddressBook *addressBook)
{
    /*open file in  the write mode*/
    FILE *fptr=fopen("data.txt","w");
    fprintf(fptr,"%d\n",addressBook->contactCount);
    int i;
    for(i=0;i<addressBook->contactCount;i++)
    {
        fprintf(fptr,"%s,%s,%s\n",addressBook->contacts[i].name,
              addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    /*file closeing*/
    fclose(fptr);
}

void createContact(AddressBook *addressBook) 
{
    char str[100];
        
        bule ();
    p1: printf("Enter the name : ");
        reset();
        scanf(" %[^\n]",str);

        for(int i=0;str[i];i++)
        {
            /*checking for alphabets in the user name */
            if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z') || str[i]==' ')
            {

            }
            else
            {
                red();
                printf("Entered name is incorrect!\n");
                reset();
                goto p1;
            }
        }

        for(int i=0;i<addressBook->contactCount;i++)
        {
            /*comparing the user name and enter the name should be unique*/
            if(strcasecmp(str, addressBook->contacts[i].name) == 0)
            {
                red();
                printf("Enter name is already exits pls enter valid name\n");
                reset();
                goto p1;
            }
        }
        /*copy to the name in the addressbook*/
        strcpy(addressBook->contacts[addressBook->contactCount].name,str);
        
        bule ();
    p2: printf("Enter the Mobile Number : ");
        reset();
        scanf(" %[^\n]",str);

        int count=0;
        for(int i=0;str[i]!='\0';i++)
        {
            /*checking digits min 10 number*/
            if(str[i]>='0' && str[i]<='9')
            {
                count++;
            }
        }
        if(count != 10)
        {
            red();
            printf(" Invalid please enter correct number\n");
            reset();
            goto p2;
        }

        for(int i=0;i<addressBook->contactCount;i++)
        {
            /*checking for unique number*/
            if(strcmp(str, addressBook->contacts[i].phone) == 0)
            {
                red();
                printf("Enter number  is already exits pls enter valid number\n");
                reset();
                goto p2;
            }
        }
       /*copy phone number to the addressbook*/
       strcpy(addressBook->contacts[addressBook->contactCount].phone,str);
        
        bule ();
    p3: printf("Enter the Email Id :\n");
        reset();
        scanf(" %[^\n]",str);
        char *p;

        /*checking for user email should be @ contains*/
        if((p=(strchr(str,'@'))) == 0)
        {
            red();
            printf("please enter the correct Email.Id\n");
            reset();
            goto p3;
        }

        /*checking for user email @ after the one letter should contains*/
        if((*(p+1)>='a' && *(p+1)<='z')==0)
        {
            red();
            printf("please enter the correct Email Id\n");
            reset();
            goto p3;
        }
        /*checking for user email should be .com contains*/
        if((strstr(str, ".com" )) == 0)
        {
            red();
            printf("please enter the correct Email Id\n");
            reset();
            goto p3;
        }

        /*copy email to the addressbook*/
        for(int i=0; i<addressBook->contactCount; i++)
        {
            /*checking user email id unique or not */
            if(strcmp(str, addressBook->contacts[i].email)== 0)
            {
                red();
                printf("Your Email Id already exits please Enter  another Email id\n");
                reset();
                goto p3;
            }
        }
        
        /*copy email in the addressbook*/
        strcpy(addressBook->contacts[addressBook->contactCount].email,str);
        addressBook->contactCount++;

        green ();
        printf("\n");
        printf("creatcontact updated successfully\n");
        reset();

        char ch;
        bule ();
        printf("Do you want to continue Y/N : ");
        reset();
        scanf(" %c",&ch);
        if(ch=='N' || ch=='n')
        {
           exit(0);
        }
}

void searchContact(AddressBook *addressBook) 
{
   
    int i;
    char str[100];
    int count=0;
    int add[100];
         
         bule ();
    p4:  printf("Enter the Name or number: ");
         reset();
         scanf(" %[^\n]",str);

       printf("\n");
       yellow();
       printf("%-10s: %-30s: %-30s: %-30s\n","S.No","Name","Phone No","Email ID");
       reset();
       printf("\n");
       for(int i=0; i<addressBook->contactCount; i++)
       {
           /*checking user name in the addressbook */
           if((strcasestr(addressBook->contacts[i].name,str)) || (strstr(addressBook->contacts[i].phone, str) != 0 ))
           {
              printf("%-10d : %-30s %-20s : %-30s\n",count+1,addressBook->contacts[i].name,
              addressBook->contacts[i].phone,addressBook->contacts[i].email);
              printf("\n");
              add[count++]=i;
            }

        }


        if(count==0)
            {
               red();
               printf("Your name is not found pls enter the correct name:\n");
               reset();
               goto p4;
            }
        else if(count>1)
        {

           int slt;
           bule ();
           printf("Multiple names is found:\n ");
     p10:  printf("select specific contact serial number:\n");
           reset();
           printf("\n");
           scanf(" %d",&slt);

           if(slt>count)
            {
              red();
              printf("Invalid serial number pls correct serial number:\n");
              reset();
              goto p10;
            }

        
            printf("\n");
            yellow();
            printf("%-10s: %-30s: %-30s: %-30s\n","S.No","Name","Phone No","Email ID");
            reset();
            printf("\n");

            i=add[slt-1];
            /*printing only user details*/
            printf("%-10d : %-30s %-20s : %-30s\n",1,addressBook->contacts[i].name,
            addressBook->contacts[i].phone,addressBook->contacts[i].email);
            printf("\n");
        }
        char ch;
        bule ();
        printf("Do you want to continue Y/N : ");
        reset();
        scanf(" %c",&ch);
        if(ch=='N' || ch=='n')
        {
            exit(0);
        }
}

char *validate_name(char *str)
{
       bule ();
   p1: printf("Enter the new name:\n");
       reset();
       scanf(" %[^\n]",str);

       for(int i=0;str[i];i++)
        {
            if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z') || str[i]==' ')
            {

            }
            else
            {
                red();
                printf("Entered name is incorrect!\n");
                reset();
                goto p1;
            }
        }
        return str;

}

char *validate_phone(char *str,AddressBook *addressBook)
{
        bule ();
    p2: printf("Enter the Mobile Number : ");
        reset();
        scanf(" %[^\n]",str);

        int count=0;
        for(int i=0;str[i]!='\0';i++)
        {
            if(str[i]>='0' && str[i]<='9')
            {
                count++;
            }
        }
        if(count != 10)
        {
            red();
            printf("please enter correct number\n");
            reset();
            goto p2;
        }

        for(int i=0;i<addressBook->contactCount;i++)
        {
            if(strcmp(str, addressBook->contacts[i].phone) == 0)
            {
                red();
                printf("Enter number  is already exits pls enter valid number\n");
                reset();
                goto p2;
            }
        }
        return str;
}

char *validate_email(char *str, AddressBook *addressBook)
{
        bule ();
    p3: printf("Enter the Email Id :\n");
        reset();
        scanf(" %[^\n]",str);
        char *p;

        if((p=(strchr(str,'@'))) == 0)
        {
            red();
            printf("please enter the correct Email.Id\n");
            reset();
            goto p3;
        }

        
        if((*(p+1)>='a' && *(p+1)<='z')==0)
        {
            red();
            printf("please enter the correct Email Id\n");
            reset();
            goto p3;
        }

        if((strstr(str, ".com" )) == 0)
        {
            red();
            printf("please enter the correct Email Id\n");
            reset();
            goto p3;
        }


        for(int i=0; i<addressBook->contactCount; i++)
        {
            if(strcmp(str, addressBook->contacts[i].email)== 0)
            {
                red();
                printf("Your Email Id already exits please Enter  another Email id\n");
                reset();
                goto p3;
            }
        }
        return str;
}

void editContact(AddressBook *addressBook) 
{
    char edit[100];
    int index = -1; 
    int count=0; 
    int a=0,N=1;
    int add[100];
       
       bule ();
   p5: printf("Enter the name, phone number, or email of the contact to edit: ");
       reset();
       scanf(" %[^\n]", edit);  

       for (int i = 0; i < addressBook->contactCount; i++) 
       {
        /*checking for the user name is thrre or not in the addressbook*/
          if ((strcasestr(addressBook->contacts[i].name,edit) != 0 ) || (strstr(addressBook->contacts[i].phone, edit) != 0 ))
          {
              index = i; 
              count++;
              printf("%d Name: %-30s Mob No: %-30s\n",count,addressBook->contacts[index].name,
              addressBook->contacts[index].phone);
              printf("\n");
              add[a++]= i;
              N++;
            }
        }

       if(count==0)
       {  
           red();
           printf("No contact found pls try again correct Name or phone number and email : %s\n", edit);
           reset();
           goto p5;
           printf("\n");
        }

        int slt;
        bule ();
    p9: printf("Select the serial number : ");
        reset();
        scanf("%d",&slt);

       if(slt>count)
        {
           red();
           printf("Invalid serial number pls correct serial number:\n");
           reset();
           goto p9;
        }

    if (index != -1) 
    {
        index=add[slt-1];
        printf("%-10d : %-30s %-20s : %-30s\n",1,addressBook->contacts[index].name,
        addressBook->contacts[index].phone,addressBook->contacts[index].email);
        printf("\n");
        int choice;
        char *ret;
            printf("Contact found. \n");
            printf("1. Name\n");
            printf("2. Phone Number\n");
            printf("3. Email\n");
            bule ();
     p11:   printf("Enter your choice : ");
            reset();
            scanf(" %d", &choice); 
            /*user enter less then choice*/
            if(choice>3)
            {
              red();
              printf("Invalid choice again re Enter:\n");
              reset();
              goto p11;
            }


        switch (choice) 
        {
            case 1:
                /*function calling in the validate name checking*/
                ret=validate_name(edit);
                /*copy to the addressbook in the name*/
                strcpy(addressBook->contacts[index].name,ret);
                break;
            case 2:
                /*function calling in the validate number checking*/
                ret=validate_phone(edit,addressBook);
                /*copy to the addressbook in the number*/
                strcpy(addressBook->contacts[index].phone,ret);
                break;
            case 3:
                /*function calling in the validate email checking*/
                ret=validate_email(edit,addressBook);
                /*copy to the addressbook in the mail*/
                strcpy(addressBook->contacts[index].email,ret);
                break;
            default:
                printf("Invalid choice. \n");
                return;
        }
        green ();
        printf("Contact updated successfully. \n");
        reset();

        char ch;
        bule ();
        printf("Do you want to continue Y/N : ");
        reset();
        scanf(" %c",&ch);
        if(ch=='N' || ch=='n')
        {
           exit(0);
        }
    } 
    
}

void deleteContact(AddressBook *addressBook) 
{
    
   char search[100];
   int found[100];
   int count=0;

   int a=0,N=1;
   int add[100];
    bule ();
    printf("Enter the name or number:\n");
    reset();
    scanf(" %[^\n]", search);  

    for (int i = 0; i < addressBook->contactCount; i++) 
    {
        /*checks the user name in the adressbook in the there or not*/
        if ((strcasestr(addressBook->contacts[i].name,search) != 0 ) || (strstr(addressBook->contacts[i].phone, search) != 0 ))
        {
            count++;
            /*printing the all found in the addressbook*/
            printf("%d Name: %-30s Mob No: %-30s\n",N,addressBook->contacts[i].name,
            addressBook->contacts[i].phone);
            printf("\n");
            add[a++]= i;
            N++;
        }
    }

    if(count==0)
    {
        red();
        printf("contact is Not found pls enter valid name: %s\n",search);
        reset();
        return;
    }

       int choice;
       bule ();
   p6: printf("Enter the S.No number if you want to delete ");
       reset();
       scanf("%d",&choice);
       /*user enter should be choice in between count*/
       if(choice < 1 || choice > count)
       {
          red();
          printf("Invalid choice, pls enter correct choice\n");
          reset();
          goto p6;
        }

        int delete=add[choice-1];
        /*only printing the user specify details*/
        for (int i = delete; i <addressBook->contactCount-1; i++)
        {
            addressBook->contacts[i]=addressBook->contacts[i+1];
        }
        /*after contactcount decresing*/
         addressBook->contactCount--;
         
         green ();
         printf("deleted contact successfully.\n");
         reset();

         char ch;
         bule ();
         printf("Do you want to continue Y/N : ");
         reset();
         scanf(" %c",&ch);
         if(ch=='N' || ch=='n')
         {
            exit(0);
            /*program terminted*/
         }
    

}
