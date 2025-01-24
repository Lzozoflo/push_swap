.PHONY: all clean fclean re f fclear c clear lib run

NAME			=		push_swap
CC				=		cc
CFLAGS			=		-Wall -Wextra -Werror -MMD -MP -O3
CFLAGSS			=		-Weverything
NPD				=		--no-print-directory
MAKE			:=		$(MAKE) -j $(NPD)
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
D_OBJ			=		1object/
D_INC			=		inc/

# Source Directories
D_INSTRUC		=		instructions/
D_UTILIS		=		utils/
D_SORT			=		sort/


#############################################################################################
#																							#
#										// SOURCE											#
#																							#
#############################################################################################


INC				=		push_swap.h

SRC				=		main.c

SRC_INSTRUC		=		ft_push.c					\
						ft_reverse_rotate.c			\
						ft_rotate.c					\
						ft_swap.c					\
						ft_while_reverse_rotate.c	\
						ft_while_rotate.c

SRC_SORT		=		ft_first_last_move.c		\
						ft_three_and_more.c			\
						ft_turc_sort.c

SRC_UTILIS		=		ft_count_sort.c				\
						ft_creat_data.c				\
						ft_creat_stack.c			\
						ft_final_index.c			\
						ft_free.c					\
						ft_head_index.c				\
						ft_turc_sort_utils.c


#############################################################################################
#																							#
#										// OBJECT											#
#																							#
#############################################################################################


# All src in his Src Directories
SRCS			=		$(addprefix $(D_SRC), $(SRC))						\
						$(addprefix $(D_SRC)$(D_INSTRUC), $(SRC_INSTRUC))	\
						$(addprefix $(D_SRC)$(D_UTILIS), $(SRC_UTILIS))		\
						$(addprefix $(D_SRC)$(D_SORT), $(SRC_SORT))


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


NAME_LIB		=		./libft/libft.a


#############################################################################################
#																							#
#										// COMPILATION										#
#																							#
#############################################################################################


all				:	lib
			$(MAKE) $(NAME)
			$(MAKE) $(D_OBJ)

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
			$(MAKE) -C libft clean


fclean 			:
			$(RM) $(NAME)
			$(RM) $(D_OBJ)
			$(MAKE) -C libft fclean


re 				:	 fclean all


#############################################################################################
#																							#
#										Allias												#
#																							#
#############################################################################################


c				:	clear
clear			:	clean

f				:	fclean
fclear			:	fclean

 -include $(DEPS)
