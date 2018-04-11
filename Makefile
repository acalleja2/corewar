LIB = libft.a
PROGS = corewar

# Compilation
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

# Directories
SRCDIR = src
OBJDIR = Objects
INCDIR = includes
LIBDIR = .

INC = corewar.h
SRC = ft_error_parse.c \
	  ft_strisnumber.c \
	  init_t_args.c \
	  main.c \
	  parseargs.c \
	  parser.c \
	  corewar_engine.c \
	  error_file.c

# Prefixes sources
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
INCS = $(addprefix $(INCDIR)/, $(INC))

# Prefixes library
LIBS = $(addprefix $(LIBDIR)/, $(LIB))
LIBS_DIRS = $(sort $(dir $(LIBS)))

OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
OBJS_DIRS = $(sort $(dir $(OBJS)))

.PHONY: clean fclean $(NAME)

# Rules

all: $(PROGS)

$(PROGS): build $(OBJS)
	@make -C libft
	@mv libft/$(LIB) ./
	@$(CC) $(CFLAGS) -o $(PROGS) $(OBJS) $(LIBS)

build:
	@mkdir -p $(OBJDIR)

clean:
	@make -C libft clean
	@rm -rf $(LIB)
	@rm -rf $(OBJDIR)

.PHONY:fclean
fclean: clean
	@make -C libft fclean
	@rm -rf $(LIB)
	@rm -rf $(OBJDIR)
	@rm -rf $(PROGS)

.PHONY:re
re: fclean all

$(LIBDIR)/%.a:
	@make -s -C $(@D)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) -c -o $@ $< -I$(INCDIR) $(CFLAGS)
