#include <stdio.h>
#include <stdlib.h>

#include "teams.h"
#include "functions.h"
#include "defaults.h"





/**
 * Função que realiza um jogo entre os times
 * nas posições 'teamA' e 'teamB'
 * 
 * Se 'aleatorio' for verdadeiro as estatísticas
 * serão escolhidas aleatoriamente
 */
void jogo_fase_grupo(team_t *teamA, team_t *teamB, int aleatorio, int grupo)
{
    int golsA = -1, amarA = -1, vermA = -1,
        golsB = -1, amarB = -1, vermB = -1;
    


    if (aleatorio)
    {
        golsA = RGOLS;
        golsB = RGOLS;

        teamA->golsMarcados += golsA;
        teamB->golsMarcados += golsB;

        teamA->golsRecebidos += golsB;
        teamB->golsRecebidos += golsA;

        teamA->amarelos += amarA = RAMARELOS;
        teamB->amarelos += amarB = RAMARELOS;

        teamA->vermelhos += vermA = RVERMELHOS;
        teamB->vermelhos += vermB = RVERMELHOS;
    }
    else
    {
        // Gols
        while (golsA < 0)
        {
            limpar_terminal();
            printf(MSG_INSIRA_QTD_GOLS, teamA->nome);
            limpar_buffer();
            scanf("%d", &golsA);
        }
        teamA->golsMarcados += golsA;
        teamB->golsRecebidos += golsA;

        while (golsB < 0)
        {
            limpar_terminal();
            printf(MSG_INSIRA_QTD_GOLS, teamB->nome);
            limpar_buffer();
            scanf("%d", &golsB);
        }
        teamB->golsMarcados += golsB;
        teamA->golsRecebidos += golsB;



        // Amarelos
        while (amarA < 0)
        {
            limpar_terminal();
            printf(MSG_INSIRA_QTD_AMARELOS, teamA->nome);
            limpar_buffer();
            scanf("%d", &amarA);
        }
        teamA->amarelos += amarA;

        while (amarB < 0)
        {
            limpar_terminal();
            printf(MSG_INSIRA_QTD_AMARELOS, teamB->nome);
            limpar_buffer();
            scanf("%d", &amarB);
        }
        teamB->amarelos += amarB;



        // Vermelhos
        while (vermA < 0)
        {
            limpar_terminal();
            printf(MSG_INSIRA_QTD_VERMELHOS, teamA->nome);
            limpar_buffer();
            scanf("%d", &vermA);
        }
        teamA->vermelhos += vermA;

        while (vermB < 0)
        {
            limpar_terminal();
            printf(MSG_INSIRA_QTD_VERMELHOS, teamB->nome);
            limpar_buffer();
            scanf("%d", &vermB);
        }
        teamB->vermelhos += vermB;
    }


    if (!aleatorio)
    {
        limpar_terminal();

        printf(MSG_RESULTADO_JOGO, teamA->nome, golsA, golsB, teamB->nome);

        if (golsA > golsB)
            printf(MSG_VENCEDOR, teamA->nome);
        else if (golsA < golsB)
            printf(MSG_VENCEDOR, teamB->nome);
        else 
            printf(MSG_EMPATE);

        printf(MSG_ENTER_CONTINUAR);
        limpar_buffer();
        getchar();
    }



    // Atualizando o saldo de gols
    teamA->golsSaldo = teamA->golsMarcados - teamA->golsRecebidos;
    teamB->golsSaldo = teamB->golsMarcados - teamB->golsRecebidos;



    // Atualizando a pontuação dos times
    if (golsA > golsB)
        teamA->pontos += 3;
    else if (golsA < golsB)
        teamB->pontos += 3;
    else
        teamA->pontos++, teamB->pontos++;
}







/**
 * Função que realiza um jogo entre os times
 * nas posições 'teamA' e 'teamB'
 * 
 * Se 'aleatorio' for verdadeiro as estatísticas
 * serão escolhidas aleatoriamente
 */
void jogo_mata_mata(team_t *teamA, team_t *teamB, int aleatorio, team_t **ganhador_ptr, team_t **perdedor_ptr)
{
    int golsA = -1, golsProrrogA = -1, amarA = -1, vermA = -1,
        golsB = -1, golsProrrogB = -1, amarB = -1, vermB = -1;
    
    team_t *ganhador = NULL;
    team_t *perdedor = NULL;



    if (!aleatorio)
    {
        // Gols
        while (golsA < 0)
        {
            limpar_terminal();
            printf(MSG_INSIRA_QTD_GOLS, teamA->nome);
            limpar_buffer();
            scanf("%d", &golsA);
        }
        teamA->golsMarcados  += golsA;
        teamB->golsRecebidos += golsA;

        while (golsB < 0)
        {
            limpar_terminal();
            printf(MSG_INSIRA_QTD_GOLS, teamB->nome);
            limpar_buffer();
            scanf("%d", &golsB);
        }
        teamB->golsMarcados  += golsB;
        teamA->golsRecebidos += golsB;



        // Amarelos
        while (amarA < 0)
        {
            limpar_terminal();
            printf(MSG_INSIRA_QTD_AMARELOS, teamA->nome);
            limpar_buffer();
            scanf("%d", &amarA);
        }
        teamA->amarelos += amarA;

        while (amarB < 0)
        {
            limpar_terminal();
            printf(MSG_INSIRA_QTD_AMARELOS, teamB->nome);
            limpar_buffer();
            scanf("%d", &amarB);
        }
        teamB->amarelos += amarB;



        // Vermelhos
        while (vermA < 0)
        {
            limpar_terminal();
            printf(MSG_INSIRA_QTD_VERMELHOS, teamA->nome);
            limpar_buffer();
            scanf("%d", &vermA);
        }
        teamA->vermelhos += vermA;

        while (vermB < 0)
        {
            limpar_terminal();
            printf(MSG_INSIRA_QTD_VERMELHOS, teamB->nome);
            limpar_buffer();
            scanf("%d", &vermB);
        }
        teamB->vermelhos += vermB;
    }
    else
    {
        golsA = RGOLS;
        golsB = RGOLS;

        teamA->golsMarcados += golsA;
        teamB->golsMarcados += golsB;

        teamA->golsRecebidos += golsB;
        teamB->golsRecebidos += golsA;

        teamA->amarelos += amarA = RAMARELOS;
        teamB->amarelos += amarB = RAMARELOS;

        teamA->vermelhos += vermA = RVERMELHOS;
        teamB->vermelhos += vermB = RVERMELHOS;
    }
    



    // Se estiverem empatados vai para a prorrogação
    if (golsA == golsB)
    {
        if (!aleatorio)
        {
            limpar_terminal();
            printf(MSG_JOGO_FOI_PRORROGADO);
            printf(MSG_ENTER_CONTINUAR);
            limpar_buffer();
            getchar();

            while (golsProrrogA < 0)
            {
                limpar_terminal();
                printf(MSG_INSIRA_QTD_GOLS_PRORROG, teamA->nome);
                limpar_buffer();
                scanf("%d", &golsProrrogA);
            }

            while (golsProrrogB < 0)
            {
                limpar_terminal();
                printf(MSG_INSIRA_QTD_GOLS_PRORROG, teamB->nome);
                limpar_buffer();
                scanf("%d", &golsProrrogB);
            }
        }
        else
        {
            golsProrrogA = RGOLS;
            golsProrrogB = RGOLS;
        }
        


        // Se estiverem empatados, ainda, vai para os penâltis
        if (golsProrrogA == golsProrrogB)
        {
            char op = '\0';

            if (!aleatorio)
            {
                limpar_terminal();
                printf(MSG_JOGO_FOI_PENALTIS);
                printf(MSG_ENTER_CONTINUAR);
                limpar_buffer();
                getchar();

                while (op != '1' && op != '2')
                {
                    limpar_terminal();
                    printf(MSG_GANHOU_PENALTIS, teamA->nome, teamB->nome);
                    limpar_buffer();
                    op = getchar();
                }
            }
            else
            {
                op = rand() % 2 ? '1' : '2';
            }
            

            if (op == '1')
            {
                ganhador = teamA;
                perdedor = teamB;
                teamA->pontos++;
            }
            else
            {
                ganhador = teamB;
                perdedor = teamA;
                teamB->pontos++;
            }
        }
        else if (golsProrrogA > golsProrrogB)
        {
            ganhador = teamA;
            perdedor = teamB;
            teamA->pontos += 3;
        }
        else
        {
            ganhador = teamB;
            perdedor = teamA;
            teamB->pontos += 3;
        }
    }
    else if (golsA > golsB)
    {
        ganhador = teamA;
        perdedor = teamB;
        teamA->pontos += 3;
    }
    else
    {
        ganhador = teamB;
        perdedor = teamA;
        teamB->pontos += 3;
    }




    limpar_terminal();

    printf(MSG_RESULTADO_JOGO, teamA->nome, golsA, golsB, teamB->nome);

    printf(MSG_VENCEDOR, ganhador->nome);

    printf(MSG_ENTER_CONTINUAR);
    limpar_buffer();
    getchar();




    // Atualizando o saldo de gols
    teamA->golsSaldo = teamA->golsMarcados - teamA->golsRecebidos;
    teamB->golsSaldo = teamB->golsMarcados - teamB->golsRecebidos;

    

    // Atualizando a colocação
    ganhador->_colocado += 2;
    perdedor->_colocado++;



    // Salvando os ponteiros
    if (ganhador_ptr != NULL) *ganhador_ptr = ganhador; 
    if (perdedor_ptr != NULL) *perdedor_ptr = perdedor; 
}