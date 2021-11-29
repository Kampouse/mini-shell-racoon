#ifndef PARSING_H
# define PARSING_H
#include "../minishell.h"

int		check_cashtoken(t_dlist *link);

char    *token_builder(char *str);
char    *find_single(char *str,size_t *len);
char    *find_dquoted(char *str, size_t *len);
char    *find_partner(char *str, size_t *len);
char    *line_no_string(char *str,size_t *len);
char    *line_handler(char *str, size_t *len);
int     token_bool(char *str, size_t *len);
char    *token_loop(char *result, char *str, size_t len, size_t offset);
int     is_quoted(char *str);
int     token_valid(char **tokens,char *trimed,int type);
int     token_scanner(char *str,size_t *token_size);
void tokens_peek(t_dlist *lst);
#endif
