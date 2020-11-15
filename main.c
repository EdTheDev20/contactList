#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include"contactList.c"

int main()
{
    setlocale(LC_ALL, "Portuguese");

    //Declaracao de variaveis
    int m; // para o menu
    int listEmpty;
    char name[255];
    char phone[20];
    char email[255];
    char address[255];
    char company[255];
    char contactToReplace[255];
    char updateField[255];
    Contact contactData;
    ContactList *contacts;

    //Inicializando as listas
    contacts = listInit();

    do{
        system("cls");
        printf("1 - Verificar lista vazia\n");
        printf("2 - Inserir contacto\n");
        printf("3 - Remover contacto\n");
        printf("4 - Substituir contacto *\n");
        printf("5 - Actualizar contacto\n");
        printf("6 - Contactos da empresa\n");
        printf("7 - Quantidade de números do contacto**\n");
        printf("8 - Listar Contactos\n");
        printf("0 - Sair...\n\n");
        printf("Escolha uma opcao: ");

        fflush(stdin);
        scanf("%d", &m);

        switch(m)
        {
            case 1:{ // Verificar se a lista está vazia
                system("cls");
                printf("----- Verificar lista -----\n\n");
                if(listIsEmpty(contacts)==0)
                    printf("Lista vazia.\n\n");
                else
                    printf("A lista não está vazia.\n\n");
                system("pause");
                system("cls");
            }
            break;
            case 2:{ // Inserir contacto
                system("cls");
                printf("----- Adicionar contacto -----\n\n");
                printf(" ------------ \n| 0 - Voltar |\n ------------ \n");
                printf("\nNome: ");
                fflush(stdin);
                gets(contactData.name);
                if(strcmp(contactData.name, "0")==0)
                   break;
                printf("Telefone: ");
                fflush(stdin);
                gets(contactData.phone);
                if(strcmp(contactData.phone, "0")==0)
                    break;
                printf("Email: ");
                fflush(stdin);
                gets(contactData.email);
                if(strcmp(contactData.email, "0")==0)
                    break;
                printf("Endereço: ");
                fflush(stdin);
                gets(contactData.address);
                if(strcmp(contactData.address, "0")==0)
                    break;
                printf("Empresa: ");
                fflush(stdin);
                gets(contactData.company);
                if(strcmp(contactData.company, "0")==0)
                    break;

                contacts = insertContact(contacts, contactData);
                fflush(stdin);
                system("pause");
                system("cls");
            }
            break;
            case 3:{// Remover contacto
                system("cls");
                printf("----- Remover contacto -----\n\n");
                printf(" ------------ \n| 0 - Voltar |\n ------------ \n");
                printf("\nDigite o numero do contacto que pretende remover:\n");
                fflush(stdin);
                gets(contactData.phone);
                if(strcmp(contactData.phone, "0")==0)
                    break;

                contacts = removeContact(contacts, contactData.phone);
                system("pause");
                system("cls");
            }
            break;
            case 4:{ // Substituir contacto
                system("cls");
                printf("----- Substituir contacto -----\n\n");
                printf("------------ \n| 0 - Voltar |\n ------------ \n");
                printf("\nInforme os novos dados.\n");
                printf("\nNome: ");
                fflush(stdin);
                gets(contactData.name);
                if(strcmp(contactData.name, "0")==0)
                   break;
                printf("Telefone: ");
                fflush(stdin);
                gets(contactData.phone);
                if(strcmp(contactData.phone, "0")==0)
                    break;
                printf("Email: ");
                fflush(stdin);
                gets(contactData.email);
                if(strcmp(contactData.email, "0")==0)
                    break;
                printf("Endereço: ");
                fflush(stdin);
                gets(contactData.address);
                if(strcmp(contactData.address, "0")==0)
                    break;
                printf("Empresa: ");
                fflush(stdin);
                gets(contactData.company);
                if(strcmp(contactData.company, "0")==0)
                    break;


                printf("\n\nInforme o nome do contacto que pretende substituir:\n");
                fflush(stdin);
                gets(contactToReplace);
                if(strcmp(contactToReplace, "0")==0)
                    break;

                replaceContact(contacts, contactToReplace , contactData);

                system("pause");
                system("cls");
            }
            break;
            case 5:{ // Actualizar contacto
                system("cls");
                printf("----- Actualizar da contacto -----\n\n");
                printf(" ------------ \n| 0 - Voltar |\n ------------ \n");
                printf("\nDigite o nome do contacto que pretende actualizar:\n");
                fflush(stdin);
                gets(contactData.name);
                if(strcmp(contactData.name, "0")==0)
                    break;

                if(searchContact(contacts, contactData.name) == 0){
                    printf("\n(1) Actualizar nome");
                    printf("\n(2) Actualizar número");
                    printf("\n(3) Actualizar email");
                    printf("\n(4) Actualizar endereço");
                    printf("\n(5) Actualizar empresa\n");
                    printf("\nEscolha a opção: ");

                    scanf("%d", &m);
                    fflush(stdin);

                    switch (m){
                        case 1:{
                            printf("\nInforme o novo nome: ");
                        }
                        break;
                        case 2:{
                            printf("\nInforme o novo número: ");
                        }
                        break;
                        case 3:{
                            printf("\nInforme o novo email: ");
                        }
                        break;
                        case 4:{
                            printf("\nInforme o novo endereço: ");
                        }
                        break;
                        case 5:{
                            printf("\nInforme a nova empresa: ");
                        }
                        break;
                        default: {
                            printf("\nERRO! Opcção inválida...");
                        }
                        break;
                    }

                    gets(updateField);
                    updateContact(contacts, contactData.name, m, updateField);
                }

                fflush(stdin);
                system("pause");
                system("cls");
            }
            break;
            case 6:{ // Contactos da empresa
                system("cls");
                printf("Busca - Viagens efectuadas num ano por um amigo\n\n");
                printf(" ------------ \n| 0 - Voltar |\n ------------ \n");
                printf("\nInforme a empresa: ");
                fflush(stdin);
                gets(contactData.company);
                if(strcmp(contactData.company, "0")==0)
                    break;
                printf("Número de contactos: %d\n\n", companyContacts(contacts, contactData.company));

                fflush(stdin);
                system("pause");
                system("cls");
            }
            break;
            case 7:{ // Quantidade de números do contacto
                system("cls");
                printf("Quantidade de números em um contacto\n\n");
                printf(" ------------ \n| 0 - Voltar |\n ------------ \n");
                printf("\n-------------------------------\n");
                /*
                */
                system("pause");
                system("cls");
            }
            break;
            case 8:{ // Listar contactos
                system("cls");
                printf("Lista de contactos\n\n");
                printf("\n-------------------------------\n");
                printList(contacts);
                system("pause");
                system("cls");
            }
            break;
            case 0:{ // Fechar programa
                system("cls");

                // Limpando as listas
                clearList(contacts);

            }
            break;
        }

    }while(m!=0);

    return 0;
}
