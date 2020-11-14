/*
struct PhoneNumber{
    char number[20];
}Phone;
*/

struct contact
{
    char name[255];
    char phone[20];
    //Phone* phone;
    char email[255];
    char address[255];
    char company[255];
};

typedef struct contact Contact;
typedef struct contactList ContactList;
//typedef struct NumberList Number;

ContactList* listInit();
int listIsEmpty(ContactList*);
void printList(ContactList*);
ContactList* insertContact(ContactList*, Contact);
ContactList* removeContact(ContactList*, char*);
void replaceContact(ContactList*, char*, Contact);
void updateContact(ContactList*, char*, int, char*);
int companyContacts(ContactList*, char*);
void clearList(ContactList *);
