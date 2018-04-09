/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 15:11:16 by florenzo          #+#    #+#             */
/*   Updated: 2018/01/28 13:29:18 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include <limits.h>
# include <string.h>
# include "libft.h"
# define SIGN TRUE
# define NOSIGN FALSE
# define SPACE ' '
# define PLUS '+'
# define INIT 1
# define FLUSH 2
# define PRINTF_BUFF_SIZE 1024

/*
** Structures
*/

typedef int		t_flag;

typedef struct	s_out
{
	char		*buffer;
	int			fd;
}				t_out;

typedef enum	e_format
{
	CHAR,
	INT,
	UINT,
	WCHAR,
	VOIDPTR,
	CHARPTR,
	WCHARPTR,
	INTPTR
}				t_format;

typedef struct	s_info
{
	char		**fmt;
	void		(*show)(int flag, t_out *out, struct s_info *info, char c);
	size_t		max;
	uintmax_t	base;
	t_format	format;
	int			total;
	int			hash;
	int			leftjustify;
	int			zeroes;
	int			plus;
	int			space;
	int			field;
	int			precision;
	int			size;
	int			charlen;
	int			caps;
}				t_info;

/*
** stdout.c
*/

int				ft_printf(const char *fmt, ...);
int				ft_nprintf(size_t max, const char *fmt, ...);
int				ft_vprintf(const char *fmt, va_list args);
int				ft_vnprintf(size_t max, const char *fmt, va_list args);

/*
** fd.c
*/

int				ft_dprintf(int fd, const char *fmt, ...);
int				ft_dnprintf(int fd, size_t max, const char *fmt, ...);
int				ft_vdprintf(int fd, const char *fmt, va_list args);
int				ft_vdnprintf(int fd,
							size_t max, const char *fmt, va_list args);

/*
** buffer.c
*/

int				ft_sprintf(char *buffer, const char *fmt, ...);
int				ft_snprintf(char *buffer, size_t max, const char *fmt, ...);
int				ft_vsprintf(char *buffer, const char *fmt, va_list args);
int				ft_vsnprintf(char *buffer,
							size_t max, const char *fmt, va_list args);

/*
** asprintf.c
*/

int				ft_asprintf(char **strp, const char *fmt, ...);
int				ft_vasprintf(char **strp, const char *fmt, va_list ap);

/*
** printf_core.c
*/

void			mv_fmt(t_info *info);
void			parsechar(t_info *info, int n);
int				printf_core(t_out *out,
							size_t max, const char *fmt, va_list args);

/*
** adding.c
*/

void			addchar(t_info *info, char c);
void			put_nchars(t_info *info, int n, char c);
void			addmsg(t_info *info, char *str);
/*
** parsing.c
*/

void			init(t_out *out, size_t max, t_info *info, char **format);
void			add_buffer(int flag, t_out *out, t_info *info, char c);
void			add_fd(int flag, t_out *out, t_info *info, char c);
void			flush(t_out *out, t_info *info);
void			shitty_case(t_info *info, char c);

/*
** parse.c
*/

int				format_acquired(t_info *info, va_list args);
void			reinit(t_info *info);
int				fmt_to_num(t_info *info);
void			set_uint(t_info *info, char c);

/*
** get_stuff.c
*/

int				printf_get_flags(t_info *info, va_list args);
int				get_field(t_info *info, va_list args);
int				get_precision(t_info *info, va_list args);
int				get_sizemod(t_info *info);
int				get_spec(t_info *info);

/*
** ifs.c
*/

int				is_flag(char c);
int				is_sizemod(char c);
int				is_spec(char c);
int				is_uintspec(char c);

/*
** out.c
*/

void			ft_out(t_info *info, va_list args);

/*
** out_int.c && int_processing.c
*/

void			out_int(t_info *info, va_list args);
void			print_int(t_info *info, intmax_t n);
void			put_int(t_info *info, intmax_t n, int sign);
void			put_int_rec(t_info *info, intmax_t n);
void			process_int(t_info *info, intmax_t n);
void			put_int_sign(t_info *info, intmax_t n, char plussign);
int				int_len(t_info *info, intmax_t n);

/*
** out_str.c
*/

void			out_str(t_info *info, va_list args);
void			print_str(t_info *info, char *str);
int				charptrlen(t_info *info, char *str);

/*
** out_uint.c uint_tools.c && uint_processing.c
*/

void			out_uint(t_info *info, va_list args);
void			process_uint(t_info *info, uintmax_t n);
int				uint_digits(t_info *info, uintmax_t n);
void			uint_prefix(t_info *info);
int				prefix_len(t_info *info);
void			put_uint_base(t_info *info, uintmax_t n, char *base);
void			uint_base(t_info *info, uintmax_t n);

/*
** out_voidptr.c
*/

void			out_voidptr(t_info *info, va_list args);

/*
** out_char.c
*/

void			out_char(t_info *info, va_list args);

/*
** out_wchar.c
*/

void			out_wchar(t_info *info, va_list args);
void			add_wchar(t_info *info, wchar_t c, int len);
int				wchar_len(wchar_t c);

/*
** out_wstr.c
*/

void			out_wstr(t_info *info, va_list args);
void			add_wstr(t_info *info, wchar_t *ptr);
int				wstr_byte_len(wchar_t *ptr);
int				wstr_byte_nlen(wchar_t *ptr, int n);

/*
** set_count.c
*/

void			set_count(t_info *info, va_list args);

#endif
