LIB = libft.a
PROGS = corewar

# Compilation
CC = gcc
CFLAGS = -Wall -Wextra -g \
		 # -Werror

# Directories
SRCDIR = src
OBJDIR = objects
INCDIR = includes
LIBDIR = ./libft
BUILDDIR = ./build

INC = corewar.h
SRC = ft_error_parse.c \
	  ft_strisnumber.c \
	  init_t_args.c \
	  main.c \
	  parseargs.c \
	  parser.c \
	  parse_n.c \
	  parse_binary_output_mode.c\
	  parse_name.c \
	  parse_text_output_mode.c \
	  parse_utilities.c \
	  setup_champs.c \
	  champion_initialization.c \
	  champ_list_tools.c \
	  get_stuff.c \
	  mem_load.c \
	  mem_tools.c \
	  proc_list_tools.c \
	  free_args.c \
	  vm_loop.c \
	  check_alive.c \
	  parse_talk.c \
	  print_winner.c \
	  ins_live.c \
	  ins_ld.c \
	  ins_st.c \
	  ins_add.c \
	  ins_sub.c \
	  ins_and.c \
	  ins_or.c \
	  ins_xor.c \
	  ins_zjmp.c \
	  ins_ldi.c \
	  ins_sti.c \
	  ins_fork.c \
	  ins_lld.c \
	  ins_lldi.c \
	  ins_lfork.c \
	  ins_aff.c
# error_file.c

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
$(OBJS): src/corewar.h
$(PROGS): $(OBJDIR) $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) -o $(PROGS) $(OBJS) $(LIBS)

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	make -C libft clean
	rm -rf $(LIB)
	rm -rf $(OBJDIR)

.PHONY:fclean
fclean: clean
	make -C libft fclean
	rm -rf $(LIB)
	rm -rf $(OBJDIR)
	rm -rf $(PROGS)

.PHONY:re
re: fclean all

$(LIBDIR)/%.a:
	make -s -C $(@D)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c -o $@ $< -I$(INCDIR) $(CFLAGS)
