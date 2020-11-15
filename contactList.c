#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"contactList.h"

// Listas encadeadas simples
// Cada contacto
struct contactList
{
    Contact data;
    struct contactList *next;
};

// Cada número
struct numberList{
    Phone phone;
    struct numberList* next;
};


// Inicializar listas
// Lista de contactos
ContactList* listInit()
{
    return NULL;
}

// Lista de números
NumberList* numberListInit(){
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
// Imprimir lista de contactos
void printList(ContactList* l){
    if(l!=NULL){
        for(ContactList* active = l; active != NULL; active = active->next){
            printf("\nNome: %s", active->data.name);
            printf("\nTelefone: %s", active->data.phone);
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

// Imprimir lista de números
void printNumberList(NumberList* l){
    if(l!=NULL){
        for(ContactList* active = l; active != NULL; active = active->next){
            printf("\nNome: %s", active->data.name);
            printf("\nTelefone: %s", active->data.phone);
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

// Buscar contacto
int searchContact(ContactList* l, char* n){
    for(ContactList* active = l; active != NULL; active = active->next){
        if(strcmpi(n, active->data.name) == 0){
            printf("\nContacto\n");
            printf("\nNome: %s", active->data.name);
            printf("\nTelefone: %s", active->data.phone);
            printf("\nEmail: %s", active->data.email);
            printf("\nEndereço: %s", active->data.address);
            printf("\nEmpresa: %s\n\n", active->data.company);
            return 0;
        }
    }
    printf("\nNão foi encontrado nenhum contacto na lista com este nome...\n\n");
    return -1;
}

// Inserir no inicio da lista
ContactList* insertContact(ContactList* l, Contact c)
{
    ContactList* newContact = (ContactList*)malloc(sizeof(ContactList));

    strcpy(newContact->data.address, c.address);
    strcpy(newContact->data.company, c.company);
    strcpy(newContact->data.email, c.email);
    strcpy(newContact->data.name, c.name);
    strcpy(newContact->data.phone, c.phone);
    newContact->next = l;

    printf("\nO contacto foi inserido com sucesso.\n\n");

    return newContact;
}

// Remover contacto
ContactList* removeContact(ContactList* l, char* p)
{
    if(l!=NULL){
        ContactList* prev;
        for(ContactList* active = l; active != NULL; active = active->next){
            if(strcmpi(p, active->data.phone) == 0){
                if(active == l){
                    l = active->next;
                }else{
                    prev->next = active->next;
                }
                free(active);
                printf("Contacto removido.\n\n");
                return l;
            }
            prev = active;
        }
        printf("\nO contacto não foi encontrado...\n\n");
    }else{
        printf("\nNão existem contactos na lista...\n\n");
    }

    return l;
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
            strcpy(active->data.phone, c.phone);

            printf("\nContacto actualizado com sucesso.\n\n");
            return;
        }
    }
    printf("\nNenhum contacto foi encontrado com este nome...\n\n");
}

// Actualizar contacto
void updateContact(ContactList* l, char* n, int opt, char* field)
{
    for(ContactList* active = l; active != NULL; active = active->next){
        if(strcmpi(n, active->data.name) == 0){
            switch(opt){
                case 1:{
                    strcpy(active->data.name, field);
                }
                break;
                case 2:{
                    strcpy(active->data.phone, field);
                }
                break;
                case 3:{
                    strcpy(active->data.email, field);
                }
                break;
                case 4:{
                    strcpy(active->data.address, field);
                }
                break;
                case 5:{
                    strcpy(active->data.company, field);
                }
                break;
                default: {
                    return;
                }
            }

            printf("\nContacto actualizado com sucesso.\n\n");
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

// Limpar lista
void clearList(ContactList *l){
    if(l != NULL){
        ContactList *aux = l;
        while(aux != NULL){
            l = l->next;
            free(aux);
            aux = l;
        }
    }
}






