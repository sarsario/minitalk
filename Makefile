# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/10 13:37:24 by osarsari          #+#    #+#              #
#    Updated: 2023/08/26 17:20:46 by osarsari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================================ VARIABLES ================================= #

# The name of the executables
CLIENT	= client
SERVER	= server

# Compiler and compiling flags
CC	= gcc
CFLAGS	= -Wall -Werror -Wextra

# Debug, use with`make DEBUG=1`
ifeq ($(DEBUG),1)
CFLAGS	+= -g3 -fsanitize=address
endif

# Folder names
SRCDIR	= src/
INCDIR	= includes/
OBJDIR	= obj/
LIB_DIR	= lib/

# Add include folders
# CFLAGS	+= -I $(INCDIR) -I $(INCDIR)lib -I $(INCDIR)mlx

# Linking stage flags
LDFLAGS	= -L$(LIB_DIR) -lft
# LDFLAGS = -framework OpenGL -framework AppKit -L$(INCDIR)lib -lft\
	-L$(INCDIR)mlx -lmlx

# List of source files (add your *.c files here)

CLI_SRCS	=\
	$(SRCDIR)client.c \

SER_SRCS	=\
	$(SRCDIR)server.c \

# List of header files (add your *.h files here)

CLI_HEADERS	=\
	$(INCDIR)client.h \
	$(LIB_DIR)libft.h \

SER_HEADERS	=\
	$(INCDIR)server.h \
	$(LIB_DIR)libft.h \

# String manipulation magic
# SRC		:= $(notdir $(SRCS))
CLI_SRC		:= $(notdir $(CLI_SRCS))
SER_SRC		:= $(notdir $(SER_SRCS))
CLI_OBJ		:= $(CLI_SRC:.c=.o)
SER_OBJ		:= $(SER_SRC:.c=.o)
CLI_OBJS	:= $(addprefix $(OBJDIR), $(CLI_OBJ))
SER_OBJS	:= $(addprefix $(OBJDIR), $(SER_OBJ))
# OBJ		:= $(SRC:.c=.o)
# OBJS	:= $(addprefix $(OBJDIR), $(OBJ))

# Colors
GR	= \033[32;1m
RE	= \033[31;1m
YE	= \033[33;1m
CY	= \033[36;1m
RC	= \033[0m

# Implicit rules
VPATH := $(SRCDIR) $(OBJDIR) $(shell find $(SRCDIR) -type d)

# ================================== RULES =================================== #

all : $(OBJDIR) $(CLIENT) $(SERVER)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Compiling
$(OBJDIR)%.o : %.c $(HEADERS)
	@mkdir -p $(OBJDIR)
	@printf "$(GR)+$(RC)"
	@$(CC) $(CFLAGS) -c $< -o $@


# Linking

$(CLIENT) : $(CLI_OBJS) $(LIB_DIR)libft.a
	@printf "$(GR)$(CLIENT)$(RC)"
	@$(CC) $(CFLAGS) $(CLI_OBJS) $(LDFLAGS) -o $(CLIENT)

$(SERVER) : $(SER_OBJS) $(LIB_DIR)libft.a
	@printf "$(GR)$(SERVER)$(RC)"
	@$(CC) $(CFLAGS) $(SER_OBJS) $(LDFLAGS) -o $(SERVER)

$(LIB_DIR)libft.a:
	@make -C $(LIB_DIR)

bonus : all

# Cleaning
clean :
	@make -C $(LIB_DIR) clean
	@printf "$(RE)--- Removing $(OBJDIR)$(RC)\n"
	@rm -rf $(OBJDIR)

fclean : clean
	@make -C $(LIB_DIR) fclean
	@printf "$(RE)--- Removing $(CLIENT) + $(SERVER)$(RC)\n"
	@rm -f $(CLIENT) $(SERVER)

# Special rule to force to remake everything
re : fclean all

# This specifies the rules that does not correspond to any filename
.PHONY: all run clean fclean re $(CLIENT) $(SERVER) bonus