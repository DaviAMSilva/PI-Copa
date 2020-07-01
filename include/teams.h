#pragma once

#include <stdio.h>
#include <stdbool.h>

#include "defaults.h"


// Estrutura que guarda as informações sobre os times
typedef struct Team
{
    char nome[LEN];

    int pontos;

    int golsMarcados;
    int golsRecebidos;
    int golsSaldo;

    int amarelos;
    int vermelhos;

    int _colocado;
    int _len;
} team_t;


/**
 * Lê os times a partir do arquivo 'arquivo'
 * e os salva no vetor 'teams'
 */
bool ler_teams(team_t *teams, FILE *arquivo);

/**
 * Salva todos os times na ordem
 * em que eles se encontram no vetor
 * no arquivo 'arquivo'
 */
void salvar_teams(team_t *teams, FILE* arquivo);

/**
 * Imprime todos os times na ordem
 * em que eles se encontram no vetor
 */
void exibir_teams_todos(team_t *teams);

/**
 * Imprime a situação do grupo especificado na ordem
 * em que os times se encontram
 */
void exibir_teams_grupo(team_t *teams, int grupo);

/**
 * Compara dois times e retorna:
 * • -1 se A estiver melhor
 * • +1 se B estiver melhor
 * • 0 caso haja algum erro 
 */
int comparar_teams(const void *a, const void *b);