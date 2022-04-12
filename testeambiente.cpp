#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
 
using namespace std;
int main()
{
    void *var = 0;
 
    time_t timer;
    time_t timer2;
    struct tm y2k = { 0 };
    double seconds;
    string msgret;
 
 	printf("/////////////////////////////////////////////////////////////////////////////////////// \n");
 	printf("//	                           ______ _____ _______ _____ 	                     // \n");
 	printf("//	                         |  ____|_   _|__   __|_   _|	                     // \n");
 	printf("//	                         | |__    | |    | |    | |  	                     // \n");
 	printf("//	                         |  __|   | |    | |    | |  	                     // \n");
 	printf("//	                         | |____ _| |_   | |   _| |_ 	                     // \n");
 	printf("//	                         |______|_____|  |_|  |_____|	                     // \n");
 	printf("/////////////////////////////////////////////////////////////////////////////////////// \n");
	printf("//     _   _   _   _   _     _   _     _   _   _   _   _   _   _   _   _   _   _     // \n");
	printf("//    / \ / \ / \ / \ / \   / \ / \   / \ / \ / \ / \ / \ / \ / \ / \ / \ / \ / \    // \n");
	printf("//   ( T | E | S | T | E ) ( D | E ) ( P | E | R | F | O | R | M | A | N | C | E )   // \n");
	printf("//    \_/ \_/ \_/ \_/ \_/   \_/ \_/   \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/    // \n");
    printf("//                                                                                   // \n");
    printf("/////////////////////////////////////////////////////////////////////////////////////// \n");

 	printf(" \n");

    printf("TESTE 1\n");
    printf("ALOCANDO BLOCO DE MEMORIA\n");
 
    y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
    y2k.tm_year = 100; y2k.tm_mon = 0; y2k.tm_mday = 1;
    timer = time(NULL);
 
    for (int i = 0; i < 300000000; i++)
    {
        var = malloc(100);
        free(var);
    }
 
    timer2 = time(NULL);
    seconds = timer2 - timer;
 
    printf("TEMPO LEVADO PARA ALOCAR MEMORIA: %f segundos\n", seconds);
    printf(" \n");
    if (seconds <= 10) {
        printf("RESULTADO DO TESTE: Otimo -> RECOMENDADO PARA O PROTHEUS\n");
    }
    else if (seconds > 10 && seconds <= 15) {
        printf("RESULTADO DO TESTE: Bom -> NAO recomendado para o Protheus\n");
    }
    else if (seconds > 15 && seconds <= 25) {
        printf("RESULTADO DO TESTE: Ruim -> NAO recomendado para o Protheus\n");
    }
    else {
        printf("RESULTADO DO TESTE: Pessimo -> NAO recomendado para o Protheus\n");
    }
 
    printf(" \n");
    printf(" \n");
    printf("TESTE 2\n");
    printf("LEITURA EM DISCO\n");
 
    y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
    y2k.tm_year = 100; y2k.tm_mon = 0; y2k.tm_mday = 1;
    timer = time(NULL);
 
    char * buffer;
    FILE *pFile = fopen("teste.txt", "rb");
    long lSize = ftell(pFile);
    size_t result;
    buffer = (char*)malloc(sizeof(char)*lSize);
    for (int i = 0; i < 7000000; i++)
    {
        fseek(pFile, 0, SEEK_END);
        result = fread(buffer, 1, lSize, pFile);
    }
    fclose(pFile);
    free(buffer);
    timer2 = time(NULL);
    seconds = timer2 - timer;
 
    printf("TEMPO LEVADO PARA REALIZAR A LEITURA EM DISCO: %f segundos\n", seconds);
    printf(" \n");
    if (seconds <= 10) {
        printf("RESULTADO DO TESTE: Otimo -> RECOMENDADO PARA O PROTHEUS\n");
    }
    else if (seconds > 10 && seconds <= 25) {
        printf("RESULTADO DO TESTE: Bom -> NAO recomendado para o Protheus\n");
    }
    else if (seconds > 25 && seconds <= 26) {
        printf("RESULTADO DO TESTE: Ruim -> NAO recomendado para o Protheus\n");
    }
    else {
        printf("RESULTADO DO TESTE: Pessimo -> NAO recomendado para o Protheus\n");
    }
 
    printf(" \n");
    printf(" \n");
    printf(" ***********************************************************************\n");
    printf(" \n");
    printf(" TABELA DE REFERENCIA - ALOCAR BLOCO DE MEMORIA\n");
    printf(" \n");
    printf("Otimo   - ate 10.000000 segundos (RECOMENDADO PARA O PROTHEUS)\n");
    printf("Bom     - ate 15.000000 segundos (NAO recomendado para o Protheus)\n");
    printf("Ruim    - ate 25.000000 segundos (NAO recomendado para o Protheus)\n");
    printf("Pessimo -   + 25.000000 segundos (NAO recomendado para o Protheus)\n");
    printf(" \n");
 
    printf(" TABELA DE REFERENCIA - LEITURA EM DISCO\n");
    printf(" \n");
    printf("Otimo   - ate 10.000000 segundos (RECOMENDADO PARA O PROTHEUS)\n");
    printf("Bom     - ate 25.000000 segundos (NAO recomendado para o Protheus)\n");
    printf("Ruim    - ate 26.000000 segundos (NAO recomendado para o Protheus)\n");
    printf("Pessimo -   + 26.000000 segundos (NAO recomendado para o Protheus)\n");
    printf(" \n");
}
