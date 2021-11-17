
NAME = minishell

FLAGS = -Wall -Wextra -Werror

SRCS =  main.c \
		utils.c\
		env.c \
		./parsing/path_handler_utils.c \
		./parsing/path_handle.c \
		
RM =  rm -rf 
.c.o:
	@gcc ${FLAGS}  -c $< -o ${<:.c=.o}

OBJS = ${SRCS:.c=.o}
CC = gcc 
all: ${NAME}
${NAME}:${OBJS} 
		@$(MAKE) -C libft
		@${CC} ${OBJS} ${FLAGS} -L./lib -lreadline  -L./libft -lft -lcurses -o ${NAME}
	
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
# @$(MAKE) -C ft_printf fclean
	@$(MAKE) -C libft fclean
re: fclean all
	
.PHONY: clean fclean re all