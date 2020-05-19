/**
 * Função que realiza um jogo entre os times
 * nas posições 'teamA' e 'teamB'
 * 
 * Se 'aleatorio' for verdadeiro as estatísticas
 * serão escolhidas aleatoriamente
 */
void jogo_fase_grupo(team_t *teamA, team_t *teamB, int aleatorio, int grupo);

/**
 * Função que realiza um jogo entre os times
 * nas posições 'teamA' e 'teamB'
 * 
 * Se 'aleatorio' for verdadeiro as estatísticas
 * serão escolhidas aleatoriamente
 */
void jogo_mata_mata(team_t *teamA, team_t *teamB, int aleatorio, team_t **ganhador_ptr, team_t **perdedor_ptr);