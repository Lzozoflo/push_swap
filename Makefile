.PHONY: all clean fclean re f fclear c clear lib

NAME			=		push_swap
NAME_LIB		=		./libft/libft.a
CC				=		cc
FLAGS			=		-Wall -Wextra -Werror -MMD -MP
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


D_INC_LIBFT		=		./libft/inc/


#############################################################################################
#																							#
#										// SOURCE											#
#																							#
#############################################################################################


INC				=		libft.h


SRC		=		ft_parting.c


#############################################################################################
#																							#
#										// OBJECT											#
#																							#
#############################################################################################


# All src in his Src Directories
SRCS			=		$(addprefix $(D_SRC), $(SRC))

# Changing all source directories to object directories
OBJS			=		$(subst $(D_SRC), $(D_OBJ), $(SRCS:.c=.o))
D_OBJS			=		$(subst $(D_SRC), $(D_OBJ), $(SRCS))
DEPS			=		$(SRCS:%.c=%.d)

INCS			=		$(addprefix $(D_INC), $(INC))


#############################################################################################
#																							#
#										// COMPILATION										#
#																							#
#############################################################################################


all				:	$(NAME) $(D_OBJ)


$(NAME)			:	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(NAME_LIB) -o $(NAME)


$(D_OBJ)%.o		: 	 $(D_SRC)%.c Makefile lib
			@mkdir -p $(D_OBJ)
			$(CC) $(CFLAGS) -c $< -o $@ -I $(D_INC_LIBFT)

lib			:
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
