#include <windows.h>
#include <stdio.h>

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