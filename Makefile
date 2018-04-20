LIBFT = libft.a

# Compilation
CC = clang
CFLAGS = -Wall -Wextra -g \
		 -Wno-unused-parameter
# -Werror
NCURSE = -lncurses

# Directories
SRCDIR = ./src
OBJDIR = ./objects
LIBDIR = ./libft

ASM = asm
COREWAR = corewar
NAME = $(COREWAR) $(ASM)
COREWAR_SRC = champ_list_tools.c \
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
COREWAR_SRCS = $(addprefix $(SRCDIR)/, $(COREWAR_SRC))
COREWAR_OBJS = $(addprefix $(OBJDIR)/, $(COREWAR_SRC:.c=.o))

# Prefixes library
LIB = $(addprefix $(LIBDIR)/, $(LIBFT))

# Rules

all: $(NAME)
$(NAME): $(LIB)

$(COREWAR_OBJS): src/corewar.h libft/libft.h

$(COREWAR): $(OBJDIR) $(LIB) $(COREWAR_OBJS)
	$(CC) $(CFLAGS) -o $(COREWAR) $(COREWAR_OBJS) $(LIB) $(NCURSE)

# $(ASM): $(LIB)
	# $(CC) $(CFLAGS) -o $(ASM) $(ASM_OBJS) $(LIB)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIB):
	make -C $(LIBDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	make -C libft clean
	rm -rf $(LIB)
	rm -f $(COREWAR_OBJS)

fclean: clean
	make -C libft fclean
	rm -rf $(OBJDIR)

re: fclean all

.PHONY: fclean clean re
