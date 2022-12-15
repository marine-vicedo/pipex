.PHONY : all test testb lldb lldbb bonus norm clean fclean re

NAME := pipex.a
NAME_BONUS := pipex_bonus.a
SOFT_NAME := pipex
SOFT_BONUS := pipex_bonus

CC := cc -g3
FLAGS := -Wall -Wextra -Werror -I includes/
OBJ_DIR := obj/
AR := ar rc
RM := rm
VAL := valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes

BLACK = \033[1;30m
REDBG = \033[30;41m
RED = \033[0;31m
GREEN = \033[0;32m
ORANGE = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
NC = \033[0m

SRCS = pipex.c files.c process.c get_paths.c free.c\

BONUS_SRCS =  pipex_bonus.c files_bonus.c process_bonus.c get_paths_bonus.c free_bonus.c \
get_next_line.c get_next_line_utils.c heredoc_bonus.c \

LIBFT := libft/libft.a
FCLIB := ${MAKE} fclean -C libft

OBJS = $(SRCS:%.c=%.o)
BOBJS = $(BONUS_SRCS:%.c=%.o)
NORM = $(wildcard *.c) $(wildcard *.h)

OBJ = $(addprefix $(OBJ_DIR),$(OBJS))
BOBJ = $(addprefix $(OBJ_DIR),$(BOBJS))

OBJF := .cache_exists

all : ${LIBFT} ${NAME} ${SOFT_NAME}

${LIBFT} :
		${MAKE} all -C libft
		cp ${LIBFT} ${NAME}

${NAME} : ${OBJ}
		@echo "${BLUE}###${NC}Update de l'archive ${NAME}${BLUE}###${MAGENTA}"
		${AR} ${NAME} ${OBJ}
		@echo "${NC}"

${OBJ_DIR}%.o : %.c | $(OBJF)
		@echo "${BLUE}###${NC}Creation du fichier ${@:%.c=%.o}${BLUE}###${ORANGE}"
		${CC} ${FLAGS} -c $< -o $@
		@echo "${NC}"

${SOFT_NAME} :
		@echo "${BLUE}###${NC}Creation du fichier ${SOFT_NAME}${BLUE}###${ORANGE}"
		${CC} ${NAME} ${FLAGS} ${LIBFT} -o ${SOFT_NAME}
		@echo "${NC}"

$(OBJF) :
		@mkdir -p ${OBJ_DIR}

bonus : ${LIBFT} ${BOBJ} ${NAME_BONUS} ${SOFT_BONUS}

${NAME_BONUS} : ${BOBJ}
		@echo "${BLUE}###${NC}Update de l'archive ${NAME_BONUS}${BLUE}###${MAGENTA}"
		${AR} ${NAME_BONUS} ${BOBJ}
		@echo "${NC}"

${SOFT_BONUS} :
		@echo "${BLUE}###${NC}Creation du fichier ${SOFT_BONUS}${BLUE}###${ORANGE}"
		${CC} ${NAME_BONUS} ${FLAGS} ${LIBFT} -o ${SOFT_BONUS}
		@echo "${NC}"

clean :
		${FCLIB}
		@echo "${RED}###${NC}Nettoyage des fichiers .o${RED}###"
		${RM} -rf ${OBJ_DIR}
		@echo "${GREEN}###${NC}Nettoyage OK${GREEN}###${NC}\n"

fclean : clean
		@echo "${RED}###${NC}Nettoyage d'archives et de Softs${RED}###"
		${RM} -f ${NAME} ${NAME_BONUS} ${SOFT_NAME} ${SOFT_BONUS}
		@echo "${GREEN}###${NC}Nettoyage OK${GREEN}###${NC}\n"

re : fclean all
