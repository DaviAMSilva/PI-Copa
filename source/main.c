#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#include "teams.h"
#include "functions.h"
#include "defaults.h"
#include "jogos.h"

int main(int argc, char const *argv[])
{
    // Inicializando algumas coisas
    srand(time(NULL));
    SetConsoleOutputCP(CP_UTF8);




    // Vetor com todos os times da fase de grupo
    team_t teams_fase_grupo[NTEAMS] = {0};



    // Arquivo com os nomes dos times
    FILE *input_teams;



    // Decidir se a escolha é aleatória
    int aleatorio = 0;





    //////////##########==========--------- INTRODUÇÃO ----------==========##########//////////





    // Apresentação inicial
    limpar_terminal();
    printf(MSG_INICIO, argc > 1 ? argv[1] : INPUT_PDR);
    limpar_buffer();
    getchar();



    // Abrindo o arquivo com os times
    if (argc > 1)
        input_teams = fopen(argv[1], "r");
    else
        input_teams = fopen(INPUT_PDR, "r");



    // O arquivo falhou na abertura?
    if (input_teams == NULL)
    {
        limpar_terminal();
        printf(MSG_ERRO_ABRIR_ARQUIVO);
        printf(MSG_ENTER_SAIR);
        limpar_buffer();
        getchar();
        limpar_terminal();
        return 1;
    }



    // Ler o arquivo e salva os times
    ler_teams(teams_fase_grupo, input_teams);
    fclose(input_teams);
    


    // Exibe o status atual de cada grupo
    limpar_terminal();
    printf(MSG_EXIBIR_TEAMS_TODOS);
    for (int i = 0; i < NGRPS; i++)
    {
        putchar('\n');
        exibir_teams_grupo(teams_fase_grupo, i);
    }
    printf(MSG_ENTER_CONTINUAR);
    limpar_buffer();
    getchar();





    //////////##########==========--------- FASE DE GRUPOS ----------==========##########//////////





    // Começa a fase de grupos
    limpar_terminal();
    printf(MSG_INICIO_FASE_GRUPOS);
    printf(MSG_ENTER_CONTINUAR);
    limpar_buffer();
    getchar();





    // Os 2 laços exteriores são responsáveis pelos jogos
    for (int njogoA = 0; njogoA < TGRPS - 1; njogoA++)
    {
        for (int njogoB = njogoA + 1; njogoB < TGRPS; njogoB++)
        {
            // Quando apenas aceitamos A < B usamos
            // apenas o caso AB e eliminamos o caso BA
            if (njogoA >= njogoB) continue;



            limpar_terminal();

            // O laço interior trata os jogos para cada grupo
            for (int ngrupo = 0; ngrupo < NGRPS; ngrupo++)
            {
                if (!aleatorio)
                {
                    // Dá opções ao usuário
                    printf(MSG_OPCOES_FASE_GRUPOS, (teams_fase_grupo + ngrupo * TGRPS + njogoA)->nome, (teams_fase_grupo + ngrupo * TGRPS + njogoB)->nome);
                    limpar_buffer();


                    // Ler a opção do usuário
                    switch (getchar())
                    {
                    // Faz o programa aleatorizar todos os jogos
                    case 'a': case 'A':
                        aleatorio = 1;
                        break;
                    
                    // Finaliza o programa
                    case 's': case 'S':
                        sair();
                        return 0;
                    }
                }


                // Realiza um jogo entre dois times
                jogo_fase_grupo(teams_fase_grupo + ngrupo * TGRPS + njogoA, teams_fase_grupo + ngrupo * TGRPS + njogoB, aleatorio, ngrupo);

                // Ordenando os times em cada grupo
                qsort(teams_fase_grupo + ngrupo * TGRPS, TGRPS, sizeof(team_t), comparar_teams);



                if (!aleatorio)
                {
                    // Exibe o status atual do grupo em que estão
                    // os times que acabaram de jogar
                    limpar_terminal();
                    printf(MSG_EXIBIR_TEAMS_GRUPO, ngrupo + 'A');
                    exibir_teams_grupo(teams_fase_grupo, ngrupo);
                }
            }
        }
    }



    // Exibe o status atual de cada grupo
    limpar_terminal();
    printf(MSG_EXIBIR_TEAMS_TODOS);
    for (int i = 0; i < NGRPS; i++)
    {
        putchar('\n');
        exibir_teams_grupo(teams_fase_grupo, i);
    }
    printf(MSG_ENTER_CONTINUAR);
    limpar_buffer();
    getchar();





    //////////##########==========--------- MATA-MATA ----------==========##########//////////





    // Guarda os ponteiros pro times do mata-mata
    team_t *teams_mata_mata[16] =
    {
        teams_fase_grupo +  0, teams_fase_grupo +  5, // 1A ( 0) x 2B ( 5)
        teams_fase_grupo +  8, teams_fase_grupo + 13, // 1C ( 8) x 2D (13)
        teams_fase_grupo +  4, teams_fase_grupo +  1, // 1B ( 4) x 2A ( 1)
        teams_fase_grupo + 12, teams_fase_grupo +  9, // 1D (12) x 2C ( 9)
        teams_fase_grupo + 16, teams_fase_grupo + 21, // 1E (16) x 2F (21)
        teams_fase_grupo + 24, teams_fase_grupo + 29, // 1G (24) x 2H (29)
        teams_fase_grupo + 20, teams_fase_grupo + 17, // 1F (20) x 2E (17)
        teams_fase_grupo + 28, teams_fase_grupo + 25, // 1H (28) x 2G (25)
    };





    //////////##########==========--------- OITAVAS DE FINAL ATÉ AS SEMIFINAIS ----------==========##########//////////




    // O loop gera: j = 1, 2, 4
    // 1: (Oitavas)   Faz duplas com todos os times que passaram para o mata-mata
    // 2: (Quartas)   Faz duplas com os times que ganharam as oitavas
    // 4: (Semifinal) Faz duplas com os times que ganharam as quartas
    for (int j = 1; j <= 4; j *= 2)
    {
        limpar_terminal();

        // Imprime a inicio da etapa
        switch (j)
        {
        case 1:
            printf(MSG_INICIO_OITAVAS);
            break;
        case 2:
            printf(MSG_INICIO_QUARTAS);
            break;
        case 4:
            printf(MSG_INICIO_SEMIFINAIS);
            break;
        }
        printf(MSG_ENTER_CONTINUAR);
        limpar_buffer();
        getchar();


    
        aleatorio = 0;
        for (int i = 0; i < 8; i += j)
        {
            limpar_terminal();



            if (!aleatorio)
            {
                // Dá opções ao usuário
                printf(MSG_OPCOES_MATA_MATA, teams_mata_mata[i * 2]->nome, teams_mata_mata[i * 2 + j]->nome);
                limpar_buffer();



                // Lê a opção do usuário
                switch (getchar())
                {
                // Faz o programa aleatorizar o próximo jogo
                case 'a': case 'A':
                    aleatorio = 1;
                    break;
                
                // Finaliza o programa
                case 's': case 'S':
                    sair();
                    return 0;
                }
            }


            // Realiza um jogo entre dois times do tipo mata-mata
            jogo_mata_mata(teams_mata_mata[i * 2], teams_mata_mata[i * 2 + j], aleatorio, &teams_mata_mata[i * 2], &teams_mata_mata[i * 2 + j]);
        }
    }





    //////////##########==========--------- TERCEIRO LUGAR ----------==========##########//////////





    // Início do jogo pelo terceiro lugar
    limpar_terminal();
    printf(MSG_INICIO_TERCEIRO_LUGAR);
    printf(MSG_ENTER_CONTINUAR);
    limpar_buffer();
    getchar();



    // Dá opções ao usuário
    aleatorio = 0;
    limpar_terminal();
    printf(MSG_OPCOES_MATA_MATA, teams_mata_mata[4]->nome, teams_mata_mata[12]->nome);
    limpar_buffer();



    // Lê a opção do usuário
    switch (getchar())
    {
    // Faz o programa aleatorizar o próximo jogo
    case 'a': case 'A':
        aleatorio = 1;
        break;
    
    // Finaliza o programa
    case 's': case 'S':
        sair();
        return 0;
    }



    // Realiza o jogo pelo 3º lugar
    jogo_mata_mata(teams_mata_mata[4], teams_mata_mata[12], aleatorio, &teams_mata_mata[4], &teams_mata_mata[12]);





    //////////##########==========--------- FINAL ----------==========##########//////////




    // Início da final
    limpar_terminal();
    printf(MSG_INICIO_FINAIS);
    printf(MSG_ENTER_CONTINUAR);
    limpar_buffer();
    getchar();


    // Dá opções ao usuário
    aleatorio = 0;
    limpar_terminal();
    printf(MSG_OPCOES_MATA_MATA, teams_mata_mata[0]->nome, teams_mata_mata[8]->nome);
    limpar_buffer();


    // Lê a opção do usuário
    switch (getchar())
    {
    // Faz o programa aleatorizar o próximo jogo
    case 'a': case 'A':
        aleatorio = 1;
        break;
    
    // Finaliza o programa
    case 's': case 'S':
        sair();
        return 0;
    }



    // Realiza o jogo da final
    jogo_mata_mata(teams_mata_mata[0], teams_mata_mata[8], aleatorio, &teams_mata_mata[0], &teams_mata_mata[8]);


    // Aumenta a colocação do 1º e 3º lugar para que haja uma ordenação correta
    teams_mata_mata[0]->_colocado++;
    teams_mata_mata[8]->_colocado++;



    // Ordena todos os times de acordo com as regras de desempate e colocação no campeonato
    qsort(teams_fase_grupo, NTEAMS, sizeof(team_t), comparar_teams);





    //////////##########==========--------- FIM DO CAMPEONATO ----------==========##########//////////





    // Exibe o fim do campeonato
    limpar_terminal();
    printf(MSG_EXIBIR_FIM, teams_fase_grupo[0].nome);
    exibir_teams_todos(teams_fase_grupo);
    printf(MSG_ENTER_CONTINUAR);
    limpar_buffer();
    getchar();



    // Fala que vai salvar o resultado
    limpar_terminal();
    printf(MSG_SALVAR_RESULTADO, argc > 2 ? argv[2] : OUTPUT_PDR);
    printf(MSG_ENTER_CONTINUAR);
    limpar_buffer();
    getchar();



    // Arquivo para salvar o resultado
    FILE* output_teams;



    // Abrindo o arquivo que salvará o resultado
    if (argc > 2)
        output_teams = fopen(argv[2], "w");
    else
        output_teams = fopen(OUTPUT_PDR, "w");



    // O arquivo falhou na abertura?
    if (output_teams == NULL)
    {
        printf(MSG_ERRO_SALVAR_ARQUIVO);
        printf(MSG_ENTER_CONTINUAR);
        limpar_buffer();
        getchar();
        limpar_terminal();
    }
    else
    {
        salvar_teams(teams_fase_grupo, output_teams);
    }



    // Fim do programa
    limpar_terminal();
    printf(MSG_FIM);
    printf(MSG_ENTER_SAIR);
    limpar_buffer();
    getchar();
    limpar_terminal();



    return 0;
}