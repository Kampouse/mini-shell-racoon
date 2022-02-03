NAME = minishell

FLAGS =   -g -Wall -Wextra -Werror
SRCS =  main.c \
		utils.c\
		list_operator.c\
		\
		./parsing/parsing.c \
		./parsing/prompt_eval.c \
		./parsing/signal_docc.c \
		./parsing/tokens_jobs.c \
		./parsing/tokens_precursors.c \
		./parsing/token_typer.c \
		./parsing/token_loop.c \
		./parsing/start_signal.c \
		\
		./dblink/dblink.c \
		./dblink/dblink_utils.c \
		\
		./bultin/env.c \
		./bultin/export.c \
		./bultin/export_utils.c \
		./bultin/unset.c \
		./bultin/cd.c \
		./bultin/pwd.c \
		./bultin/echo.c \
		./bultin/exit.c \
		\
		./executing/start_jobs.c \
		./executing/redir_handler.c \
		./executing/path_handler_utils.c \
		./executing/path_handle.c \
		./executing/find_part.c \
		./executing/command_not_found.c \
		./executing/pipe.c \
		./executing/fd.c \
		\
		./jobs/jobs_redir.c \
		./jobs/jobs_redir_links.c \
		./jobs/jobs.c \
		./jobs/jobs_links.c \
		./jobs/jobs_lst.c \
		./jobs/jobs_utils.c \
		\
		./eval/eval.c \
		./eval/eval_util.c \
		./eval/eval_redir.c \
		./eval/pre_eval_redir.c \
		./eval/eval_cmd.c \

		
RM =  rm -rf 
.c.o:
	@gcc  ${FLAGS}  -c $< -o ${<:.c=.o}

OBJS = ${SRCS:.c=.o}

CC = gcc

all: ${NAME}

DETECTED_OS := $(shell uname -s)
${NAME}:${OBJS}
		@make   -C libft > /tmp/out
ifeq ($(DETECTED_OS), Darwin)
	@${CC} ${OBJS} ${FLAGS} -L./readline -lreadline  ./libft/libft.a  -lncurses -o ${NAME}
endif
ifeq ($(DETECTED_OS), Linux)
	@${CC} ${OBJS} ${FLAGS} -L./readline -lreadline  -L./libft -lft  -L./ncurses/lib -lncurses -o ${NAME}  -L ./ncurses/lib 
endif
		@echo "\033[0m"
		@echo "\n\033[32m\033[1m  Minishell Compiled  for $(DETECTED_OS) \n\033[0m"
run: all
		./$(NAME)

leak: all
		leaks --atExit -- ./$(NAME)
		./$(NAME)

val: all
	valgrind   --leak-check=full --track-origins=yes -s --trace-children=yes  ./$(NAME)
test: all
	valgrind   --leak-check=full --show-leak-kinds=all --track-origins=yes -s --trace-children=yes --show-reachable=yes  ./$(NAME) -c "cat << this | cat << this | exit"
norm: 
	@norminette ${SRCS}  | grep "Error!"


clean:
		@echo "\033[0;31m Cleaning..."
	    @rm -rf ${OBJS} > /tmp/out
		@make -C libft/ clean > /tmp/out
		@echo "\033[0m"

git:
		@git add ${SRCS} minishell.h Makefile  ./executing/executing.h \
		./executing/executing.h \
		./parsing/parsing.h \
		./jobs/jobs.h \
		./eval/eval.h

fclean: 
		@echo "\033[0;31m NUKED everything and may our sanity rest..."
		@${RM} ${NAME} 
	    @rm -rf ${OBJS} > /tmp/out
		@make -C libft fclean > /tmp/out
		@echo "\033[0m"

re: fclean all

.PHONY: clean fclean re all

re: fclean all
	
.PHONY: clean fclean re all/

