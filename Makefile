# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luguimar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/21 15:59:38 by luguimar          #+#    #+#              #
#    Updated: 2023/10/14 17:28:25 by luguimar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = main.c

BONUS_SRC = main_bonus.c utils_bonus.c

OBJS = ${SRC:.c=.o}

BONUS_OBJS = ${BONUS_SRC:.c=.o}

CC = cc -g
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I .
MAKE = make -C
LIBFT_PATH = libft
LIBFT = ${LIBFT_PATH}/libft.a

.c.o:
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

BONUS_FILES_EXIST = $(shell ls $(BONUS_OBJS) 2>/dev/null | grep -c . | awk '{print ($$1 == '$(words $(BONUS_OBJS))') ? "yes" : "no"}')

ifeq ($(BONUS_FILES_EXIST),yes)
all: clean ${NAME}
else
all: ${NAME}
endif

SRC_FILES_EXIST = $(shell ls $(OBJS) 2>/dev/null | grep -c . | awk '{print ($$1 == '$(words $(OBJS))') ? "yes" : "no"}')

ifneq ($(BONUS_FILES_EXIST),yes)
bonus: clean ${BONUS_OBJS} ${LIBFT}
		${CC} ${BONUS_OBJS} ${LIBFT} -o ${NAME}
endif

ifneq ($(shell test -f ${NAME} && echo yes),yes)
bonus: clean ${BONUS_OBJS} ${LIBFT}
		${CC} ${BONUS_OBJS} ${LIBFT} -o ${NAME}
endif

ifeq ($(BONUS_FILES_EXIST),yes)
ifeq ($(shell test -f ${NAME} && echo yes),yes)
bonus:
endif
endif

$(NAME): ${OBJS} ${LIBFT}
		${CC} ${OBJS} ${LIBFT} -o ${NAME}

$(LIBFT):
		${MAKE} ${LIBFT_PATH}

clean:
		${MAKE} ${LIBFT_PATH} clean
		${RM} ${OBJS} ${BONUS_OBJS}

fclean: clean
		${MAKE} ${LIBFT_PATH} fclean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
