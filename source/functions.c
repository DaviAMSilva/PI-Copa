#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "defaults.h"



/**
 * Ler uma linha de um arquivo até achar
 * uma quebra de linha ou o fim do arquivo.
 * 
 * Retorna um ponteiro para o buffer usado
 */
char *ler_linha(FILE *arquivo, char *buffer)
{
    int n = 0, ch = 0;

    while ((ch = getc(arquivo)) != '\n' && ch != EOF)
        if (n < LEN)
            buffer[n++] = ch;

    if (ch == EOF) return NULL;

    return buffer;
}



/**
 * Função para limpar o terminal,
 */
void limpar_terminal(void) {
    system("cls");
}



/**
 * Função para limpar o buffer
 */
void limpar_buffer(void) {
    fflush(stdin);
}



/**
 * Fecha o programa com uma mensagem de despedida
 */
void sair(void)
{
    limpar_terminal();
    printf(MSG_SAIR);
    printf(MSG_ENTER_SAIR);
    limpar_buffer();
    getchar();
    limpar_terminal();
}