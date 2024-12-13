.PHONY: all clean fclean re f fclear c clear lib

NAME			=		push_swap
NAME_LIB		=		./libft/libft.a
CC				=		cc
CFLAGS			=		-Wall -Wextra -Werror -MMD -MP
RM				=		rm -fr
AR				=		ar -rcs


# Color
GREEN			=		\033[0;32m
BLUE			=		\033[0;34m
RED				=		\033[0;31m
YELLOW			=		\033[0;33m
RESET			=		\033[0m


#############################################################################################
#																							#
#										// Directories										#
#																							#
#############################################################################################


# Directories
D_SRC			=		src/
D_OBJ			=		object/
D_INC			=		inc/

# Source Directories
D_INSTRUC		=		instructions/


#############################################################################################
#																							#
#										// SOURCE											#
#																							#
#############################################################################################


INC				=		push_swap.h


SRC				=		main.c						\
						ft_creat_stack_utils.c


SRC_INSTRUC		=		ft_swap.c					\
						ft_push.c					\
						ft_rotate.c					\
						ft_reverse_rotate.c


#############################################################################################
#																							#
#										// OBJECT											#
#																							#
#############################################################################################


# All src in his Src Directories
SRCS			=		$(addprefix $(D_SRC), $(SRC))						\
						$(addprefix $(D_SRC)$(D_INSTRUC), $(SRC_INSTRUC))


# Changing all source directories to object directories
OBJS			=		$(subst $(D_SRC), $(D_OBJ), $(SRCS:.c=.o))
D_OBJS			=		$(subst $(D_SRC), $(D_OBJ), $(SRCS))
DEPS			=		$(SRCS:%.c=%.d)

INCS			=		$(addprefix $(D_INC), $(INC))


#############################################################################################
#																							#
#										// LIBFT											#
#																							#
#############################################################################################

D_INC_LIBFT		=		./libft/inc/

INC_LIBFT		=		libft.h


#############################################################################################
#																							#
#										// COMPILATION										#
#																							#
#############################################################################################


all				:	lib $(NAME) $(D_OBJ)


$(NAME)			:	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(NAME_LIB) -o $(NAME)


$(D_OBJ)%.o		:	$(D_SRC)%.c $(INCS) Makefile
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS) -c $< -o $@ -I $(D_INC) -I $(D_INC_LIBFT)


lib				:
			$(MAKE) -C libft


#############################################################################################
#																							#
#								    // CLEAN  FCLEAN  RE									#
#																							#
#############################################################################################


clean 			:
			$(RM) $(D_OBJ)


fclean 			:	clean
			$(RM) $(NAME)


re 				:	 fclean all


#############################################################################################
#																							#
#										Allias									#
#																							#
#############################################################################################


c				:	clear
clear			:	clean

f				:	fclean
fclear			:	fclean


#to see what variables did
debug			:
	@echo "Debug: $(all)"
 -include $(DEPS)
