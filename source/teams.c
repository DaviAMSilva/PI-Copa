#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>

#include "functions.h"
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
bool ler_teams(team_t *teams, FILE *arquivo)
{
    int i = 0;
    char buffer[LEN];

    while (i < NTEAMS)
    {
        // Lendo o arquivo uma linha por vez
        memset(buffer, 0, LEN);

        if (ler_linha(arquivo, buffer) == NULL)
        {
            return false;
        };

        // Se o nome começa por # ou está vazio ele é desconsiderado
        if (*buffer != '#' && *buffer != '\0')
        {
            // Salva o nome do time
            strncpy(teams[i].nome, buffer, LEN);

            // Zerando todos os atributos
            teams[i].golsMarcados = teams[i].golsRecebidos = teams[i].golsSaldo =
            teams[i].amarelos = teams[i].vermelhos = 
            teams[i].pontos = teams[i]._colocado = 0;

            // Esse cálculo é necessário para garantir que a tabela alinhe
            // corretamente pois caracteres UTF-8 ocupam mais de um byte
            teams[i]._len = LEN;
            for (int j = 0; j < LEN; j++)
                if ((*(teams[i].nome + j) & 0xc0) == 0x80)
                    teams[i]._len++;

            i++;
        }
    }

    return true;
}



/**
 * Salva todos os times na ordem
 * em que eles se encontram no vetor
 * no arquivo 'arquivo'
 */
void salvar_teams(team_t *teams, FILE* arquivo)
{
    fprintf(arquivo, "O campeão da Copa do Mundo da FIFA foi o time:\n> %s <\n\n", teams[0].nome);

    fprintf(arquivo, "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━┓\n");
    fprintf(arquivo, "┃            COPA DO MUNDO DA FIFA             ┃             Gols            ┃        Cartões       ┃\n");
    fprintf(arquivo, "┣━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┯━━━━━━━━╋━━━━━━━━━━┯━━━━━━━━━━┯━━━━━━━╋━━━━━━━━━━┯━━━━━━━━━━━┫\n");
    fprintf(arquivo, "┃ Nº ┃          Nome do Time          │ Pontos ┃ Marcados │ Sofridos │ Saldo ┃ Amarelos │ Vermelhos ┃\n");
    fprintf(arquivo, "┣━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┿━━━━━━━━╋━━━━━━━━━━┿━━━━━━━━━━┿━━━━━━━╋━━━━━━━━━━┿━━━━━━━━━━━┫\n");

    for (int i = 0; i < NTEAMS; i++)
    {
        fprintf(arquivo, "┃ %2.2d ┃ %-*s │ %-6d ┃ %-8d │ %-8d │ %+-5d ┃ %-8d │ %-9d ┃\n",
            i + 1,

            teams[i]._len,
            teams[i].nome,

            teams[i].pontos,

            teams[i].golsMarcados,
            teams[i].golsRecebidos,
            teams[i].golsSaldo,

            teams[i].amarelos,
            teams[i].vermelhos
        );
    }

    fprintf(arquivo, "┗━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┷━━━━━━━━┻━━━━━━━━━━┷━━━━━━━━━━┷━━━━━━━┻━━━━━━━━━━┷━━━━━━━━━━━┛\n");
}





/**
 * Imprime todos os times na ordem
 * em que eles se encontram no vetor
 */
void exibir_teams_todos(team_t *teams)
{
    printf("  ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("  ┃            COPA DO MUNDO DA FIFA             ┃             Gols            ┃        Cartões       ┃\n");
    printf("  ┣━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┯━━━━━━━━╋━━━━━━━━━━┯━━━━━━━━━━┯━━━━━━━╋━━━━━━━━━━┯━━━━━━━━━━━┫\n");
    printf("  ┃ Nº ┃          Nome do Time          │ Pontos ┃ Marcados │ Sofridos │ Saldo ┃ Amarelos │ Vermelhos ┃\n");
    printf("  ┣━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┿━━━━━━━━╋━━━━━━━━━━┿━━━━━━━━━━┿━━━━━━━╋━━━━━━━━━━┿━━━━━━━━━━━┫\n");

    for (int i = 0; i < NTEAMS; i++)
    {
        printf("  ┃ %2.2d ┃ %-*s │ %-6d ┃ %-8d │ %-8d │ %+-5d ┃ %-8d │ %-9d ┃\n",
            i + 1,
            teams[i]._len,
            teams[i].nome,

            teams[i].pontos,

            teams[i].golsMarcados,
            teams[i].golsRecebidos,
            teams[i].golsSaldo,

            teams[i].amarelos,
            teams[i].vermelhos
        );
    }

    printf("  ┗━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┷━━━━━━━━┻━━━━━━━━━━┷━━━━━━━━━━┷━━━━━━━┻━━━━━━━━━━┷━━━━━━━━━━━┛\n");
}





/**
 * Imprime a situação do grupo especificado na ordem
 * em que os times se encontram
 */
void exibir_teams_grupo(team_t *teams, int ngrupo)
{
    if (ngrupo < 0 || ngrupo > NGRPS - 1) return;

    printf("  ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("  ┃                   GRUPO: %-4c                ┃             Gols            ┃        Cartões       ┃\n", ngrupo + 'A');
    printf("  ┣━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┯━━━━━━━━╋━━━━━━━━━━┯━━━━━━━━━━┯━━━━━━━╋━━━━━━━━━━┯━━━━━━━━━━━┫\n");
    printf("  ┃ Nº ┃          Nome do Time          │ Pontos ┃ Marcados │ Sofridos │ Saldo ┃ Amarelos │ Vermelhos ┃\n");
    printf("  ┣━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┿━━━━━━━━╋━━━━━━━━━━┿━━━━━━━━━━┿━━━━━━━╋━━━━━━━━━━┿━━━━━━━━━━━┫\n");
    
    int index;
    for (int i = 0; i < TGRPS; i++)
    {
        index = ngrupo * TGRPS + i;

        printf("  ┃ %2.2d ┃ %-*s │ %-6d ┃ %-8d │ %-8d │ %+-5d ┃ %-8d │ %-9d ┃\n",
            i + 1,
            teams[index]._len,
            teams[index].nome,

            teams[index].pontos,

            teams[index].golsMarcados,
            teams[index].golsRecebidos,
            teams[index].golsSaldo,

            teams[index].amarelos,
            teams[index].vermelhos
        );
    }

    printf("  ┗━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┷━━━━━━━━┻━━━━━━━━━━┷━━━━━━━━━━┷━━━━━━━┻━━━━━━━━━━┷━━━━━━━━━━━┛\n");
}


/**
 * Compara dois times e retorna:
 * • -1 se A estiver melhor
 * • +1 se B estiver melhor
 * • 0 caso haja algum erro 
 */
int comparar_teams(const void *a, const void *b)
{
    team_t *teamA = (team_t *) a;
    team_t *teamB = (team_t *) b;

    /**
     * Critérios de desempate:
     ** 1. Pontos
     ** 2. Saldo de gols
     ** 3. Gols marcados
     *- 4. Confronto direto
     *! 5. Fair Play
     ** 6. Sorteio
     */

    // Classificação
    if (teamA->_colocado > teamB->_colocado)      return -1;
    else if (teamA->_colocado < teamB->_colocado) return +1;
    else
    {
        // Pontos
        if (teamA->pontos > teamB->pontos)      return -1;
        else if (teamA->pontos < teamB->pontos) return +1;
        else
        {
            // Saldo de gols
            if (teamA->golsSaldo > teamB->golsSaldo)      return -1;
            else if (teamA->golsSaldo < teamB->golsSaldo) return +1;
            else
            {
                // Gols marcados
                if (teamA->golsMarcados > teamB->golsMarcados)      return -1;
                else if (teamA->golsMarcados < teamB->golsMarcados) return +1;
                else
                {
                    // Cartões amarelos
                    if (teamA->amarelos < teamB->amarelos)      return -1;
                    else if (teamA->amarelos > teamB->amarelos) return +1;
                    else
                    {
                        // Cartões vermelhos
                        if (teamA->vermelhos < teamB->vermelhos)      return -1;
                        else if (teamA->vermelhos > teamB->vermelhos) return +1;
                        else
                        {
                            // Sorteio
                            if (rand() % 2) return -1;
                            else            return +1;
                        }
                    }
                }
            }
        }
    }

    return 0;
}