
NAME = minishell

FLAGS =  -g -Wall -Wextra -Werror 

SRCS =  main.c \
		utils.c\
		./executing/env.c \
		./executing/export.c \
		./parsing/path_handler_utils.c \
		./parsing/path_handle.c \
		./parsing/tokens_jobs.c \
		./parsing/token_typer.c \
		./dblink/dblink.c \
		./dblink/dblink_utils.c \

		
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

clean:

	    ${RM} ${OBJS}
		@make -C libft/ clean

git:
		@git add ${SRCS} minishell.h Makefile

fclean: clean
	@${RM} ${NAME}
	@$(MAKE) -C libft fclean
re: fclean all

.PHONY: clean fclean re all


re: fclean all
	
.PHONY: clean fclean re all
