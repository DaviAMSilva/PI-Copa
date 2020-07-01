#pragma once

// Grupos
#define TGRPS 4
#define NGRPS 8
#define NTEAMS NGRPS * TGRPS



// Texto
#define LEN 30
#define TITULO "Sistema de gerenciamento da Copa do Mundo da FIFA"



// Aleatorio
#define RGOLS      (rand() % 8)
#define RAMARELOS  (rand() % 5 + 3)
#define RVERMELHOS (rand() % 2)



// Mensagens
#define MSG_INICIO                  "\n  Bem vindo ao sistema de gerenciamento da Copa do Mundo da FIFA.\n  Primeiramente vamos abrir e ler os nomes dos times que irão participar.\n"
#define MSG_INICIO_FASE_GRUPOS      "\n  Começa agora a fase de grupos!\n"
#define MSG_INICIO_OITAVAS          "\n  Começa agora as oitavas de final!\n"
#define MSG_INICIO_QUARTAS          "\n  Começa agora as quartas de final!\n"
#define MSG_INICIO_SEMIFINAIS       "\n  Começa agora as semifinais!\n"
#define MSG_INICIO_TERCEIRO_LUGAR   "\n  Começa agora o jogo pelo terceiro lugar!\n"
#define MSG_INICIO_FINAIS           "\n  Começa agora a final da Copa do Mundo da FIFA!\n"

#define MSG_ERRO_LER_ARQUIVO        L"Algo deu errado ao tentar ler os times.\nPor favor, tenha certeza que todos os times estejam corretos e tente novamente."
#define MSG_ERRO_ABRIR_ARQUIVO      L"Algo deu errado ao tentar abrir o arquivo.\nPor favor, tente novamente."
#define MSG_ERRO_SALVAR_ARQUIVO     L"Algo deu errado ao tentar criar o arquivo para salvar o resultado."

#define MSG_OPCOES_FASE_GRUPOS      "\n  Agora você tem algumas opções:\n\n  'A' - Aletorizar a fase de grupos    \n  'S' - Sair do programa\n  'R' - Realizar o próximo jogo\n  \n  Próximo jogo: | %s | x | %s |  \n  >>> "
#define MSG_OPCOES_MATA_MATA        "\n  Agora você tem algumas opções:\n\n  'A' - Aletorizar os jogos dessa etapa\n  'S' - Sair do programa\n  'R' - Realizar o próximo jogo\n  \n  Próximo jogo: | %s | x | %s |  \n  >>> "

#define MSG_EXIBIR_TEAMS_TODOS      "\n  Status atual do campeonato:\n"
#define MSG_EXIBIR_TEAMS_GRUPO      "\n  Status atual do grupo %c:\n\n"

#define MSG_SALVAR_RESULTADO        "\n  O resultado do campeonato será salvo no em um arquivo de texto.\n"
#define MSG_RESULTADO_FINAL         "\n  Resultado final do campeonato:\n\n"

#define MSG_ENTER_CONTINUAR         "\n  Aperte ENTER para continuar..."
#define MSG_ENTER_SAIR              "\n  Aperte ENTER para sair..."

#define MSG_INSIRA_QTD_GOLS         "\n  Por favor, insira a quantidade de gols marcados pelo time: | %s |\n  >>> "
#define MSG_INSIRA_QTD_GOLS_PRORROG "\n  Por favor, insira a quantidade de gols marcados durante a prorrogação pelo time: %s\n  >>> "
#define MSG_INSIRA_QTD_AMARELOS     "\n  Por favor, insira a quantidade de cartões amarelos do time: | %s |\n  >>> "
#define MSG_INSIRA_QTD_VERMELHOS    "\n  Por favor, insira a quantidade de cartões vermelhos do time: | %s |\n  >>> "

#define MSG_RESULTADO_JOGO          "\n  O resultado final do jogo foi:\n  | %s - %d | x | %d - %s |\n"
#define MSG_VENCEDOR                "\n  O vencedor do jogo foi o time: | %s |\n"
#define MSG_EMPATE                  "\n  O jogo terminou em empate\n"

#define MSG_JOGO_FOI_PRORROGADO     "\n  O jogo foi para a prorrogação\n"
#define MSG_JOGO_FOI_PENALTIS       "\n  O jogo foi para os penâltis\n"
#define MSG_GANHOU_PENALTIS         "\n  Quais dos times ganhou os penâltis?\n  1 - %s\n  2 - %s\n  >>> "

#define MSG_ABRIR_ARQUIVO          "Selecione o arquivo com os nomes dos times:"
#define MSG_SALVAR_ARQUIVO          "Escolha onde quer salvar o resultado:"