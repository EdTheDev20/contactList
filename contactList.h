struct contact
{
    char name[255];
    //char phone[20];
    struct numberList* phone;
    char email[255];
    char address[255];
    char company[255];
};

typedef struct contact Contact;
typedef struct contactList ContactList;
typedef struct numberList NumberList;

ContactList* listInit();
NumberList* numberListInit();

int listIsEmpty(ContactList*);

void printList(ContactList*);
void printNumberList(NumberList*);

int searchContact(ContactList*, char*);

ContactList* insertContact(ContactList*, Contact);
NumberList* insertNumber(NumberList*, char*);

ContactList* removeContact(ContactList*, char*);
NumberList* removeNumber(NumberList*, char*);

void replaceContact(ContactList*, char*, Contact);
void updateContact(ContactList*, char*, char, char*);
int companyContacts(ContactList*, char*);
int phoneNumbers(ContactList*);

void clearList(ContactList*);
void clearNumberList(NumberList*);
