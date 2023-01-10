# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eelhasni <eelhasni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 16:32:10 by eelhasni          #+#    #+#              #
#    Updated: 2022/08/27 14:55:35 by eelhasni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=		libft.a

CC 		=		cc

CFLAGS 	=		-Wall -Werror -Wextra

AR		=		ar rcs

RM 		=		rm -f

INC		=		libft.h

SRC		=		ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
				ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
				ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
				ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_putchar.c \
				ft_putendl.c ft_putnbr.c ft_putstr.c ft_split.c  \
				ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
				ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
				ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
				ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstiter.c \
				ft_lstdelone.c ft_lstclear.c ft_lstmap.c ft_lstadd_back.c

OBJ		= 	$(SRC:.c=.o)

all 	:		$(NAME)
	
$(NAME) :		$(OBJ)
		@echo
		@echo "$(COLOR02)Creating libft archive...$(DEFAULT)"
		$(AR) $@ $^
		@echo
		@echo "$(LGREEN)$(NAME) has been created ! :)$(DEFAULT)"
		@echo
		
%.o		:		%.c $(INC)
		$(CC) $(CFLAGS) -c $< -o $@

clean	:
		@$(RM) $(OBJ)
		@echo "$(COLOR01)$(NAME) :"\
		"$(YELLOW)object files have been deleted ! $(DEFAULT)"
		@echo

execlean:
		@$(RM) $(NAME)
		@echo "$(RED)$(NAME) has been deleted !$(DEFAULT)"
		@echo

fclean	:	clean execlean

re		:		fclean all

.PHONY	: 		all clean fclean re

#COLORS
RED		= \033[1;31m
LGREEN	= \033[1;32m
YELLOW	= \033[1;33m
CYAN	= \033[1;36m
DEFAULT = \033[0m
COLOR01	= \033[1;38;5;194m
COLOR02	= \033[1;38;5;38m
