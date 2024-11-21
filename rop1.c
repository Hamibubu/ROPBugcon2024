#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int variable=0;

void salto1() 
{
    printf("Lograste llegar al primer salto\n");
    variable++;
}

void salto2() {
    printf("Lograste el salto 2!\n");
    variable++;
}

void salto3() {
    printf("Llegaste al salto 3, vamos a comprobar si lo hiciste bien...\n");
    if(variable==2){
        system("/bin/bash");
    }else{
    	printf("Al parecer no lo estas haciedo bien...");
    }
}

void vulnerable(char* string) 
{
    char buffer[100];
    strcpy(buffer, string);
}

int main(int argc, char** argv) 
{
    vulnerable(argv[1]);
    return 0;
}
