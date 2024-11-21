#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

char executed[50];
int can_execute=0;

void rop(){
    printf("HOLA\n");
    fflush(stdout);
}

void execute_system(){
    if(can_execute){
	printf("Lo lograste, aqui esta tu shell...\n");
	fflush(stdout);
	setuid(0);
        system(executed);
    }else{
    	printf("No puedes ejecutar %s\n", executed);
    }
}

void bin(int required) {
    if(required == 0xdeadc0de){
	printf("Codigo 1 corecto!\n");
	fflush(stdout);
    	strcat(executed, "/bin");
    }else{
    	printf("Buen intento, pero no!\n");
	fflush(stdout);
    }
}

void bash(int req1, int req2) {
    if(req1 == 0xc0dec0de){
        strcat(executed, "/bash -p");
	printf("Cadena /bash concatenada\n");
	fflush(stdout);
    }else{
	printf("Hay problemas con el primer argumento!\n");
	fflush(stdout);
	return;
    }
    if(req2 == 0xc0ffeeee){
	printf("Codigo correcto, ahora puedes ejecutar\n");
	fflush(stdout);
        can_execute=1;
    }else{
    	printf("Parece que no estas pasando bien tu segundo argumento...\n");
	fflush(stdout);
	return;
    }
    return;
}

void format_data(const char *input, char *output) {
    int j = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (isalpha((unsigned char)input[i])) {
            output[j++] = toupper((unsigned char)input[i]);
        }
    }
    output[j] = '\0';
}

// Función vulnerable (buffer overflow)
void vulnerable(char *string) {
    char buffer[150];
    char formatted[150];
    
    printf("Procesando datos...\n");
    strcpy(buffer, string); // Aquí está la vulnerabilidad
    format_data(buffer, formatted);
    printf("Datos formateados: %s\n", formatted);
}

int main(int argc, char **argv) {
    printf("Bienvenido al software de copiado y formateo seguro de datos...\n");
    printf("Uso: %s <input>\n", argv[0]);

    if (argc < 2) {
        printf("Error: Se requiere un argumento de entrada.\n");
        return 1;
    }

    printf("Iniciando el procesamiento de datos...\n");
    vulnerable(argv[1]);
    printf("Proceso completo.\n");

    return 0;
}
