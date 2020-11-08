#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"contactList.h"

// Lista encadeada simples
// Cada contacto
struct ContactList
{
    Contact data;
    struct ContactList *next;
};

// Lista encadeada de números
/*struct NumberList{
    Phone phone;
    struct NumberList* next;
};*/

// Inicializar lista
ContactList* listInit()
{
    return NULL;
}

// Verificar lista vazia
bool listIsEmpty(ContactList* l)
{
    return (l == NULL ? true : false);
}

// Inserir no inicio da lista
ContactList* insertContact(ContactList* l, Contact c)
{
    ContactList* newContact = (ContactList*)malloc(sizeof(ContactList));

    newContact->data->address = c->address;
    newContact->data->company = c->company;
    newContact->data->email = c->email;
    newContact->data->name = c->name;
    newContact->data->phone = c->phone;
    newContact->next = l;

    return newContact;
}

// Remover contacto
ContactList* removeContact(ContactList* l, char* p)
{
    if(l!=NULL){
        ContactList* prev;
        for(ContactList* active = l; active != NULL; active = active->next){
            if(strcmpi(p, active->data->phone) == 0){
                if(active == l){
                    l = active->next
                }else{
                    prev->next = active->next;
                }
                free(active);
                printf("Contacto removido.\n");
                return l;
            }
            prev = active;
        }
        printf("O contacto não foi encontrado\n");
    }else{
        printf("Não existem contactos na lista.\n");
    }

    return l;
}

// Numero de contactos da mesma empresa **************************************************************** TROCAR PARA RECURSIVA
int companyContacts(ContactList* l, char* c)
{
    int n = 0;

    //FAZER DE MODO RECURSIVO ***************************************************
    for(ContactList* active = l; active != NULL; active = active->next){
        if(strcmpi(c, active->data->company) == 0){
            n++;
        }
    }

    /*
    if(l == NULL){
        return n;
    }else{
        if(strcmpi(c, l->data->company) == 0){
            n++;
        }
        companyContacts(l->next, c);
    }
    */

    return n;
}






