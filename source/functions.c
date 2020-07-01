#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>

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

FILE *abrir_arquivo(const char *msg)
{
    OPENFILENAME ofn = {0};
    char buffer[100] = {0};

    ofn.lStructSize  = sizeof(OPENFILENAME);
    ofn.lpstrFilter  = "Arquivo de Texto\0*.txt\0";
    ofn.nMaxFile     = 100;
    ofn.lpstrTitle   = msg;
    ofn.lpstrFile    = buffer;
    ofn.lpstrDefExt  = "txt";
    ofn.Flags        = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST;

    if (GetOpenFileName(&ofn))
        return fopen(ofn.lpstrFile, "r");
    else
        return NULL;
}

FILE *salvar_arquivo(const char *msg)
{
    OPENFILENAME ofn = {0};
    char buffer[100] = {0};

    ofn.lStructSize  = sizeof(OPENFILENAME);
    ofn.lpstrFilter  = "Arquivo de Texto\0*.txt\0";
    ofn.nMaxFile     = 100;
    ofn.lpstrTitle   = msg;
    ofn.lpstrFile    = buffer;
    ofn.lpstrDefExt  = "txt";
    ofn.Flags        = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT;

    if (GetSaveFileName(&ofn))
        return fopen(ofn.lpstrFile, "w");
    else
        return NULL;
}

bool confirmar_sair(HWND window_handler)
{
    if (MessageBoxW(window_handler, L"Deseja mesmo sair do programa?", L"Confimar saída", MB_ICONWARNING | MB_YESNO | MB_DEFBUTTON2) == IDYES)
        return true;
    else
        return false;
}