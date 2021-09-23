#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void pall(char *string);
int main(int argc, char **argv)
	//posible edge cases si no existe el file oh si el file no tiene nada
{
	//crear espacio para link usando malloc
	FILE *file;
	char string[1000];
	int lidx;

	file = fopen(argv[1], "r");

	while (fgets(string, sizeof(string), file))
	{
		lidx = (strlen(string) -1);
		string[lidx] = '\0';
		pall(string);
	}
	return (0);
}

void pall(char *string)
{
	printf("%s\n", string);
}

//nop: No va a imprimir nada; lo vas a crear prototipo tipo void; esta funcion tiene que estar creada en el proyecto
//pero no se va a utilizar para nada;

// primer paso para monty; crear el sourcecode que pueda recibir argumentos utilizando argc argv; limitar la cantidad de
// argumentos; luego seria poder abrir ese archivo; luego de abrir ese archivo probablemente entraria un edge case para 
// confirmar lo que recibio cuando intento abrir el archivo; lo que reciba no deberia ser NULL si es NULL entoces deberias
// utilizar exit failured pero antes deberias imprimir un error; Luego de el edge case utilizarias una varriable tipo character
// pointer*; luego utilzas malloc para alocar memoria a esa variable por default utilizas 1024;

// 


