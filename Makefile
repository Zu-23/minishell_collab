####            Variables            #####

# Executables :
NAME		:=	minishell

#Compilation :
CC			:=	cc 
CFLAGS		:=	-g -O2

# Utils :
RM			:=	rm -f

#Directories :
INC_DIR		:=	inc/
PARS_DIR	=	$(SRC_DIR)parsing/
EXEC_DIR	=	$(SRC_DIR)executing/
BLTN_DIR	=	$(SRC_DIR)builtins/
MISC_DIR	=	$(SRC_DIR)misc/
SRC_DIR		:=	src/
LIBFT_DIR	:=	libft/

#Includes :
INCLUDES	:=	minishell.h parser.h execute.h
CINCPATH	:=	-I$(LIBFT_DIR) -I$(INC_DIR)

#Source Files :
PARS_SRC	:=	
EXEC_SRC	:= 	execute.c
BLTN_SRC	:=	export.c unset.c env.c 
MISC_SRC	:=	variables.c \
				utils.c env_utils.c var_utils.c 
SRC			:=	main.c minishell.c init.c setup.c
SRC			:=	$(addprefix $(SRC_DIR), $(SRC)) \
				$(addprefix $(PARS_DIR), $(PARS_SRC)) \
				$(addprefix $(EXEC_DIR), $(EXEC_SRC)) \
				$(addprefix $(BLTN_DIR), $(BLTN_SRC)) \
				$(addprefix $(MISC_DIR), $(MISC_SRC))


#Object Files :
OBJ			:=	$(SRC:.c=.o)

#Libraries :
LIBFT		:=	$(LIBFT_DIR)/libft.a
LINKLIBS	:=	-lft -lreadline
LIBSPATH	:=	-L$(LIBFT_DIR)


####            Rules            #####

libft	:
		@$(MAKE) --no-print-directory -s -C $(LIBFT_DIR)
		@$(MAKE) --no-print-directory all

all			:	$(NAME)

$(NAME)		:	$(OBJ) $(LIBFT)
		@echo
		@echo "$(RED)Linking...$(DEFAULT)"
		$(CC) $^ -o $(NAME) $(LIBSPATH) $(LINKLIBS)
		@echo
		@echo "$(LGREEN)$(NAME) has been created ! :)$(DEFAULT)"
		@echo

%.o		:	%.c $(addprefix $(INC_DIR), $(INCLUDES))
		$(CC) $(CFLAGS) $(CINCPATH) -c $< -o $@

clean 		:
		@$(RM) $(OBJ)
		@echo "$(COLOR01)$(NAME) :"\
		"$(YELLOW)object files have been deleted ! $(DEFAULT)"
		@echo

libclean	:
		@$(MAKE) --no-print-directory clean -s -C $(LIBFT_DIR)

execlean	:
		@$(RM) $(NAME)
		@echo "$(RED)$(NAME) has been deleted !$(DEFAULT)"
		@echo

fclean		:	libclean clean
		@$(MAKE) --no-print-directory execlean -s -C $(LIBFT_DIR)
		@-$(RM) $(NAME)
		@echo "$(RED)$(NAME) has been deleted !$(DEFAULT)"
		@echo

re			:	fclean libft

.PHONY		:	all clean fclean re bonus libft

#COLORS
RED		= \033[1;31m
LGREEN	= \033[1;32m
YELLOW	= \033[1;33m
CYAN	= \033[1;36m
DEFAULT = \033[0m
COLOR01	= \033[1;38;5;194m
COLOR02	= \033[1;38;5;38m
