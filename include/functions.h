#pragma once

#include <stdio.h>
#include <windows.h>
#include <stdbool.h>

#include "defaults.h"

FILE *abrir_arquivo (const char *msg);
FILE *salvar_arquivo(const char *msg);

/**
 * Ler uma linha de um arquivo até achar
 * uma quebra de linha ou o fim do arquivo.
 * 
 * Retorna um ponteiro para o buffer usado
 */
char *ler_linha(FILE *arquivo, char buffer[]);

/**
 * Função para limpar o terminal,
 */
void limpar_terminal(void);

/**
 * Função para limpar o buffer
 */
void limpar_buffer(void);

/**
 * Fecha o programa com uma mensagem de despedida
 */
void sair(void);


bool confirmar_sair(HWND window_handler);