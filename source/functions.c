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

void imprimir_ganhador(const char *ganhador, HWND console_handler, WORD modo_cor)
{
    WORD amarelo  = (modo_cor == 0xF0) ? 0xF6 : 0x0E;
    WORD vermelho = (modo_cor == 0xF0) ? 0xF4 : 0x0C;
    WORD azul     = (modo_cor == 0xF0) ? 0xF3 : 0x0B;
    WORD verde    = (modo_cor == 0xF0) ? 0xF2 : 0x0A;

     SetConsoleTextAttribute(console_handler, amarelo);
     printf("\n\
            ___________\n\
       .---'::'        `---.\n\
      (::::::'              )\n\
    __|`-----._______.-----'|__\n\
   /  |              :::::::|  \\\n\
  |   |               ::::::|   |\n\
  |   |                :::::|   |\n\
   \\  |               ::::::|  /\n\
    \\ |"); SetConsoleTextAttribute(console_handler, vermelho); printf("    Copa do Mundo   "); SetConsoleTextAttribute(console_handler, amarelo); printf(":| /\n\
     \\|"); SetConsoleTextAttribute(console_handler, vermelho); printf("       da FIFA   "); SetConsoleTextAttribute(console_handler, amarelo); printf("::::|/\n\
      |               ::::::|\n\
      |              .::::::|\n\
      \\             :::::::|\n\
       \\            ::::::/\n\
        `.        .:::::::'\n\
          `-._  .::::::-'\n\
              |  \"\"\"|\"\n\
              |  :::|\n\
              |   ::|\n\
             /     ::\\\n\
        __.-'      :::`-.__\n\
       (_           ::::::_)\n\
         `\"\"\"---------\"\"\"'\n\
\n");

    SetConsoleTextAttribute(console_handler, verde);
    printf("\n      GANHADOR:      ");

    SetConsoleTextAttribute(console_handler, azul);
    printf("\n      %s\n", ganhador);

    SetConsoleTextAttribute(console_handler, modo_cor);
}