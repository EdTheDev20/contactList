#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"contactList.h"

// Listas encadeadas simples
// Cada contacto
struct contactList
{
    Contact data;
    struct contactList* next;
};

// Cada número
struct numberList
{
    char number[20];
    struct numberList* next;
};


// Inicializar listas
ContactList* listInit()
{
    return NULL;
}

NumberList* numberListInit()
{
    return NULL;
}


// Verificar lista vazia
int listIsEmpty(ContactList* l)
{
    if(l==NULL){
        return 0;
    }
    return -1;
}

// Imprimir listas
void printList(ContactList* l)
{
    if(l!=NULL){
        for(ContactList* active = l; active != NULL; active = active->next){
            printf("\nNome: %s", active->data.name);
            //printf("\nTelefone: %s", active->data.phone);
            printf("\nQuantidade de nºs de telefone: %d", phoneNumbers(active));
            printNumberList(active->data.phone);
            printf("\nEmail: %s", active->data.email);
            printf("\nEndereço: %s", active->data.address);
            printf("\nEmpresa: %s", active->data.company);
            printf("\n\n-------------------------------\n");
        }
    }else{
        printf("\nNão existem contactos na lista...");
        printf("\n\n-------------------------------\n\n");
    }
}

void printNumberList(NumberList* nl)
{
    int i = 0;
    for(NumberList* active = nl; active != NULL; active = active->next){
        i++;
        printf("\nTelefone %d: %s", i, active->number);
    }
}


// Buscar contacto
int searchContact(ContactList* l, char* n)
{
    for(ContactList* active = l; active != NULL; active = active->next){
        if(strcmpi(n, active->data.name) == 0){
            printf("\nContacto\n");
            printf("\nNome: %s", active->data.name);
            //printf("\nTelefone: %s", active->data.phone);
            printNumberList(active->data.phone);
            printf("\nEmail: %s", active->data.email);
            printf("\nEndereço: %s", active->data.address);
            printf("\nEmpresa: %s\n\n", active->data.company);
            return 0;
        }
    }
    printf("\nNão foi encontrado nenhum contacto na lista com este nome...\n\n");
    return -1;
}

// Inserir no inicio das listas
ContactList* insertContact(ContactList* l, Contact c)
{
    ContactList* newContact = (ContactList*)malloc(sizeof(ContactList));

    strcpy(newContact->data.address, c.address);
    strcpy(newContact->data.company, c.company);
    strcpy(newContact->data.email, c.email);
    strcpy(newContact->data.name, c.name);
    //strcpy(newContact->data.phone, c.phone);
    newContact->data.phone = numberListInit();
    for(NumberList* aux = c.phone; aux != NULL; aux = aux->next){
        newContact->data.phone = insertNumber(newContact->data.phone, aux->number);
    }
    newContact->next = l;

    printf("\nO contacto foi inserido com sucesso.\n\n");

    return newContact;
}

NumberList* insertNumber(NumberList* nl, char* n)
{
    NumberList* newNumber = (NumberList*)malloc(sizeof(NumberList));

    strcpy(newNumber->number, n);
    newNumber->next = nl;

    return newNumber;
}


// Remover
ContactList* removeContact(ContactList* l, char* n)
{
    ContactList* prev;
    for(ContactList* active = l; active != NULL; active = active->next){
        for(NumberList* aux = active->data.phone; aux != NULL; aux = aux->next){
            if(strcmpi(n, aux->number) == 0){
                if(active == l){
                    l = active->next;
                }else{
                    prev->next = active->next;
                }

                clearNumberList(active->data.phone);

                free(active);
                printf("Contacto removido.\n\n");
                return l;
            }
        }
        prev = active;
    }
    printf("\nO contacto não foi encontrado...\n\n");
    return l;
}

NumberList* removeNumber(NumberList* nl, char* n)
{
    NumberList* prev;
    for(NumberList* active = nl; active != NULL; active = active->next){
        if(strcmpi(n, active->number) == 0){
            if(active == nl){
                nl = active->next;
            }else{
                prev->next = active->next;
            }

            free(active);
            printf("Número removido.\n\n");
            return nl;
        }
        prev = active;
    }
    printf("\nO número não foi encontrado...\n\n");
    return nl;
}

// Substituir contacto
void replaceContact(ContactList* l, char* n, Contact c)
{
    for(ContactList* active = l; active != NULL; active = active->next){
        if(strcmpi(n, active->data.name) == 0){
            strcpy(active->data.address, c.address);
            strcpy(active->data.company, c.company);
            strcpy(active->data.email, c.email);
            strcpy(active->data.name, c.name);
            //strcpy(active->data.phone, c.phone);
            clearNumberList(active->data.phone);
            active->data.phone = numberListInit();
            for(NumberList* aux = c.phone; aux != NULL; aux = aux->next){
                active->data.phone = insertNumber(active->data.phone, aux->number);
            }

            printf("\nContacto substituído com sucesso.\n\n");
            return;
        }
    }
    printf("\nNenhum contacto foi encontrado com este nome...\n\n");
}

// Actualizar contacto
void updateContact(ContactList* l, char* n, char opt, char* field)
{
    for(ContactList* active = l; active != NULL; active = active->next){
        if(strcmpi(n, active->data.name) == 0){
            switch(opt){
                case '1':{
                    strcpy(active->data.name, field);
                    printf("\nNome actualizado com sucesso.\n\n");
                }
                break;
                case '2':{
                    //strcpy(active->data.phone, field);
                    active->data.phone = insertNumber(active->data.phone, field);
                    printf("\Número adicionado com sucesso.\n\n");
                }
                break;
                case '3':{
                    active->data.phone = removeNumber(active->data.phone, field);
                }
                break;
                case '4':{
                    strcpy(active->data.email, field);
                    printf("\nEmail actualizado com sucesso.\n\n");
                }
                break;
                case '5':{
                    strcpy(active->data.address, field);
                    printf("\nEndereço actualizado com sucesso.\n\n");
                }
                break;
                case '6':{
                    strcpy(active->data.company, field);
                    printf("\nEmpresa actualizada com sucesso.\n\n");
                }
                break;
                default: {
                    return;
                }
            }

            return;
        }
    }
}

// Numero de contactos da mesma empresa
int companyContacts(ContactList* l, char* c)
{
    if(l == NULL)
        return 0;

    if(strcmpi(c, l->data.company) == 0)
        return 1 + companyContacts(l->next, c);
    else
        return 0 + companyContacts(l->next, c);
}

// Quantidade de números de telefone do contacto
int phoneNumbers(ContactList* c){
    int i = 0;

    for(NumberList* active = c->data.phone; active != NULL; active = active->next){
        i++;
    }

    return i;
}


// Limpar listas
void clearList(ContactList* l)
{
    if(l != NULL){
        ContactList *aux = l;
        while(aux != NULL){
            l = l->next;
            free(aux);
            aux = l;
        }
    }
}

void clearNumberList(NumberList* nl)
{
    if(nl != NULL){
        NumberList *aux = nl;
        while(aux != NULL){
            nl = nl->next;
            free(aux);
            aux = nl;
        }
    }
}



