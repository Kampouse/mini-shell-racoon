
NAME = minishell

FLAGS =  -g -Wall -Wextra -Werror 

SRCS =  main.c \
		utils.c\
		./parsing/token_analyzer.c \
		./parsing/parsing.c \
		./parsing/path_handler_utils.c \
		./parsing/path_handle.c \
		./parsing/tokens_jobs.c \
		./parsing/tokens_precursors.c \
		./parsing/token_typer.c \
		./parsing/token_loop.c \
		./dblink/dblink.c \
		./dblink/dblink_utils.c \
		./executing/env.c \
		./executing/export.c \
 		./executing/variable.c \
		./executing/exec.c \
		./executing/check_bultin.c \
		./executing/export_valider.c \
		./jobs/jobs_redir.c \
		./jobs/jobs.c \
		./jobs/jobs_links.c \
		
RM =  rm -rf 
.c.o:
	@gcc ${FLAGS}  -c $< -o ${<:.c=.o}

OBJS = ${SRCS:.c=.o}
CC = gcc
all: ${NAME}
${NAME}:${OBJS}

		@$(MAKE) -C libft
		@${CC} ${OBJS} ${FLAGS} -L./lib -lreadline  ./libft/libft.a  -lncurses -o ${NAME}

run: all
		./$(NAME)
leak: all
		leaks --atExit -- ./$(NAME)
		./$(NAME)
val: all
	valgrind ./$(NAME)


clean:

	    ${RM} ${OBJS}
		@make -C libft/ clean

git:
		@git add ${SRCS} minishell.h Makefile  ./executing/executing.h \
		./executing/executing.h \
		./parsing/parsing.h \
		./jobs/jobs.h


fclean: clean
	@${RM} ${NAME}
	@$(MAKE) -C libft fclean
re: fclean all

.PHONY: clean fclean re all


re: fclean all
	
.PHONY: clean fclean re all
