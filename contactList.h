/*
struct PhoneNumber{
    char number[20];
}Phone;
*/

struct ContactData
{
    char name[255];
    char phone[20];
    //Phone* phone;
    char email[255];
    char address[255];
    char company[255];
};

typedef struct ContactData Contact;
typedef struct ContactList ContactList;
//typedef struct NumberList Number;

ContactList* listInit();
bool listIsEmpty(ContactList*);
ContactList* insertContact(ContactList*, Contact);
ContactList* removeContact(ContactList*, char*);
void replaceContact(ContactList*); // !?
void updateContact(ContactList*, char*);
int companyContacts(ContactList*, char*);
