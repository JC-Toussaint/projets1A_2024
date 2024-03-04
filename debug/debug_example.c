#include <stdio.h>
#include <string.h>

#include "debug.h"


int main(){
int var;

PRINT_MESG_DBG(" = numero de la ligne de code du PRINT_MESG_DBG\n"); 

var=255;
PRINT_MESG_DBG("var = %d\n", var);
}
