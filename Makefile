NAME = minishell

FLAGS =   -g -Wall -Wextra -Werror 

SRCS =  main.c \
		utils.c\
		\
		./parsing/parsing.c \
		./parsing/path_handler_utils.c \
		./parsing/path_handle.c \
		./parsing/tokens_jobs.c \
		./parsing/tokens_precursors.c \
		./parsing/token_typer.c \
		./parsing/token_loop.c \
		\
		./dblink/dblink.c \
		./dblink/dblink_utils.c \
		\
		./executing/env.c \
		./executing/export.c \
		./executing/exec.c \
		./executing/export_utils.c \
		./executing/unset.c \
		./executing/cd.c \
		./executing/pwd.c \
		./executing/echo.c \
		./executing/start_jobs.c \
		./executing/redir_handler.c \
		./executing/pipe.c \
		\
		./jobs/jobs_redir.c \
		./jobs/jobs_redir_links.c \
		./jobs/jobs.c \
		./jobs/jobs_links.c \
		./jobs/jobs_lst.c \
		\
		./eval/eval.c \
		./eval/eval_util.c \
		./eval/eval_redir.c \
		./eval/eval_cmd.c \

		
RM =  rm -rf 
.c.o:
	@gcc  ${FLAGS}  -c $< -o ${<:.c=.o}

OBJS = ${SRCS:.c=.o}

CC = gcc

all: ${NAME}

${NAME}:${OBJS}
		@echo "\033[0;33m Compiling..."
		@$(MAKE) -C libft
		@${CC} ${OBJS} ${FLAGS}  -lreadline -L./readline ./libft/libft.a  -lncurses  -L./ncurses/lib -o ${NAME}
		@echo "\033[0m"
		@echo "\n\033[32m\033[1m  Minishell Compiled\n\033[0m"
# @${CC} ${OBJS} ${FLAGS} -L./readline -lreadline  -L./libft -lft  -L./ncurses/lib -lncurses -o ${NAME}
run: all
		./$(NAME)

leak: all
		leaks --atExit -- ./$(NAME)
		./$(NAME)

val: all
	valgrind   --leak-check=full --track-origins=yes -s --trace-children=yes  ./$(NAME)
test: all
	valgrind   --leak-check=full --show-leak-kinds=all --track-origins=yes -s --trace-children=yes  ./$(NAME) "-c" 'cd .. cd ..'

clean:
		@echo "\033[0;31m Cleaning..."
	    ${RM} ${OBJS}
		@make -C libft/ clean
		@echo "\033[0m"

git:
		@git add ${SRCS} minishell.h Makefile  ./executing/executing.h \
		./executing/executing.h \
		./parsing/parsing.h \
		./jobs/jobs.h \
		./eval/eval.h

fclean: clean
		@echo "\033[0;31m Removing executable..."
		@${RM} ${NAME}
		@$(MAKE) -C libft fclean
		@echo "\033[0m"

re: fclean all

.PHONY: clean fclean re all

re: fclean all
	
.PHONY: clean fclean re all/

