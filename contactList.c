#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"contactList.h"

// Lista encadeada simples
struct ContactList{
    contact contact;
    struct l_amigo *prox;
};
