# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adnajja <adnajja@student.42belgium.be>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/09 19:57:54 by tilogie           #+#    #+#              #
#    Updated: 2026/08/04 15:29:45 by adnajja          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ════════════════════════════════════════════════════════════════════════════ #
#                                  CONFIG                                      #
# ════════════════════════════════════════════════════════════════════════════ #

NAME		= libft.a
INCLUDE		= .
SRC_DIR		= src/
OBJ_DIR		= obj/

CC			= cc
CFLAGS		= -Wall -Werror -Wextra -I $(INCLUDE)
RM			= rm -f
AR			= ar rcs

# ════════════════════════════════════════════════════════════════════════════ #
#                                  COLORS                                      #
# ════════════════════════════════════════════════════════════════════════════ #

DEF_COLOR	= \e[0;39m
GRAY		= \e[0;90m
RED			= \e[0;91m
GREEN		= \e[0;92m
YELLOW		= \e[0;93m
BLUE		= \e[0;94m
MAGENTA		= \e[0;95m
CYAN		= \e[0;96m
WHITE		= \e[0;97m

# ════════════════════════════════════════════════════════════════════════════ #
#                                  SOURCES                                     #
# ════════════════════════════════════════════════════════════════════════════ #

FTIS_DIR		=	ft_is/
FTIS			=	ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint

FTMEM_DIR		=	ft_mem/
FTMEM			=	ft_bzero ft_calloc ft_memchr ft_memcmp ft_memmove ft_memset ft_memcpy

FTPUT_DIR		=	ft_put/
FTPUT			=	ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd ft_putnstr_fd

FTTO_DIR		=	ft_to/
FTTO			=	ft_atoi ft_itoa ft_tolower ft_toupper

FTSTR_DIR		=	ft_str/
FTSTR			=	ft_split ft_strchr ft_strcmp ft_strdup ft_striteri ft_strjoin \
					ft_strlcat ft_strlcpy ft_strlen ft_strmapi ft_strncmp \
					ft_strnstr ft_strrchr ft_strtrim ft_substr ft_strdup_array \
					ft_array_free ft_strjoin_three ft_strstr

FTLST_DIR		=	ft_lst/
FTLST			=	ft_lstadd_back ft_lstadd_front ft_lstclear ft_lstdelone \
					ft_lstiter ft_lstlast ft_lstmap ft_lstnew ft_lstsize

FTPRINTF_DIR	=	ft_printf/
FTPRINTF		=	ft_hex_printf ft_printf ft_ptr_printf ft_unsigned_printf \
					ft_utils_printf

GNL_DIR			=	gnl/
GNL				=	get_next_line_utils get_next_line

SRC_FILES+=$(addprefix $(FTIS_DIR),$(FTIS))
SRC_FILES+=$(addprefix $(FTMEM_DIR),$(FTMEM))
SRC_FILES+=$(addprefix $(FTPUT_DIR),$(FTPUT))
SRC_FILES+=$(addprefix $(FTTO_DIR),$(FTTO))
SRC_FILES+=$(addprefix $(FTSTR_DIR),$(FTSTR))
SRC_FILES+=$(addprefix $(FTLST_DIR),$(FTLST))
SRC_FILES+=$(addprefix $(FTPRINTF_DIR),$(FTPRINTF))
SRC_FILES+=$(addprefix $(GNL_DIR),$(GNL))

SRC			= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJF		= obj/.cache_exists

# ════════════════════════════════════════════════════════════════════════════ #
#                                  RULES                                       #
# ════════════════════════════════════════════════════════════════════════════ #

all:		$(NAME)

$(NAME):	$(OBJ)
			@$(AR) $(NAME) $(OBJ)
			@ranlib $(NAME)
			@echo "$(GREEN)✓ libft.a compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@echo "$(YELLOW)  Compiling: $<$(DEF_COLOR)"
			@$(CC) $(CFLAGS) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)
			@mkdir -p $(OBJ_DIR)$(FTIS_DIR)
			@mkdir -p $(OBJ_DIR)$(FTMEM_DIR)
			@mkdir -p $(OBJ_DIR)$(FTPUT_DIR)
			@mkdir -p $(OBJ_DIR)$(FTTO_DIR)
			@mkdir -p $(OBJ_DIR)$(FTSTR_DIR)
			@mkdir -p $(OBJ_DIR)$(FTLST_DIR)
			@mkdir -p $(OBJ_DIR)$(FTPRINTF_DIR)
			@mkdir -p $(OBJ_DIR)$(GNL_DIR)
			@touch $(OBJF)

clean:
			@$(RM) -rf $(OBJ_DIR)
			@$(RM) -f $(OBJF)
			@echo "$(BLUE)✓ libft object files cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) -f $(NAME)
			@echo "$(CYAN)✓ libft library files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(GREEN)✓ libft recompiled!$(DEF_COLOR)"

norm:
			@echo "$(MAGENTA)Running norminette...$(DEF_COLOR)"
			@norminette $(INCLUDE) $(SRC_DIR) 2>/dev/null | grep -v "OK!" || true

.PHONY:		all clean fclean re norm
