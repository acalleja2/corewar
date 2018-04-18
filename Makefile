LIB = libft.a
PROGS = corewar

# Compilation
CC = gcc
CFLAGS = -Wall -Wextra -g \
		 -Wno-unused-parameter
		 # -Werror

# Directories
SRCDIR = src
OBJDIR = objects
INCDIR = includes
LIBDIR = ./libft
BUILDDIR = ./build
NCURSE = -lncurses

INC = corewar.h
SRC = champ_list_tools.c \
	  champion_initialization.c \
	  check_alive.c \
	  free_args.c \
	  ft_error_parse.c \
	  ft_strisnumber.c \
	  get_stuff.c \
	  increment_pc.c \
	  init_t_args.c \
	  ins_add.c \
	  ins_aff.c \
	  ins_and.c \
	  ins_fork.c \
	  ins_ld.c \
	  ins_ldi.c \
	  ins_lfork.c \
	  ins_live.c \
	  ins_lld.c \
	  ins_lldi.c \
	  ins_or.c \
	  ins_st.c \
	  ins_sti.c \
	  ins_sub.c \
	  ins_xor.c \
	  ins_zjmp.c \
	  main.c \
	  mem_load.c \
	  mem_tools.c \
	  ncurse.c \
	  ncurses_tools.c \
	  ncurses_tools2.c \
	  ocp_getters.c \
	  ocp_ifs.c \
	  parse_binary_output_mode.c\
	  parse_n.c \
	  parse_name.c \
	  parse_talk.c \
	  parse_text_output_mode.c \
	  parse_utilities.c \
	  parseargs.c \
	  print_winner.c \
	  proc_list_tools.c \
	  process_parameters.c \
	  setup_champs.c \
	  stupid.c \
	  switch_instruction.c \
	  vm_loop.c \
	  ncurse_colors.c \
	  ncurses_tools3.c \
	  ncurse_tools4.c \
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
	$(CC) $(CFLAGS) -o $(PROGS) $(OBJS) $(LIBS) $(NCURSE)

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
