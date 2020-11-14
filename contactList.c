#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"contactList.h"

// Lista encadeada simples
// Cada contacto
struct contactList
{
    Contact data;
    struct contactList *next;
};

// Lista encadeada de números
/*
struct NumberList{
    Phone phone;
    struct NumberList* next;
};
*/

// Inicializar lista
ContactList* listInit()
{
    return NULL;
}

// Verificar lista vazia
int listIsEmpty(ContactList* l)
{
    //return (l == NULL ? true : false);
    if(l==NULL){
        return 0;
    }
    return -1;
}

// Imprimir lista
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
        printf("\nNão existem contactos na lista");
        printf("\n\n-------------------------------\n\n");
    }
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
        printf("O contacto não foi encontrado\n\n");
    }else{
        printf("Não existem contactos na lista.\n\n");
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

            printf("\nContacto actualizado com sucesso\n\n");
            return;
        }
    }
    printf("\nNenhum contacto foi encontrado com este nome\n\n");
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
                    printf("ERRO...");
                    return;
                }
            }

            printf("\nContacto actualizado com sucesso\n\n");
            return;
        }
    }
    printf("\nNenhum contacto foi encontrado com este nome\n\n");
}

// Numero de contactos da mesma empresa **************************************************************** TROCAR PARA RECURSIVA
int companyContacts(ContactList* l, char* c)
{
    int n = 0;

    //FAZER DE MODO RECURSIVO ***************************************************
    for(ContactList* active = l; active != NULL; active = active->next){
        if(strcmpi(c, active->data.company) == 0){
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






