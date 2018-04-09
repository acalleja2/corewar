/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_wchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <lorenzo.farnetani@student.42.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 17:07:57 by florenzo          #+#    #+#             */
/*   Updated: 2018/01/28 13:47:18 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
** UTF-8 encoding
**           an X is a significant bit
** 11110XXX 10XXXXXX 10XXXXXX 10XXXXXX 21 bits
**          1110XXXX 10XXXXXX 10XXXXXX 16 bits
**                   110XXXXX 10XXXXXX 11 bits
**                            0XXXXXXX  7 bits
**
** wchar_len() explanation
** mask 1 : check 16 < bits <= 21
**          --> 0X1F0000
**          aka 0B 00011111 00000000 00000000
**
** mask 2 : check 11 < bits <= 16
**          --> 0X00F800
**          aka 0B 00000000 11111000 00000000
**
** mask 3 : check  7 < bits <= 11
**          --> 0X000780
**          aka 0B 00000000 00000111 10000000
**
** mask 4 : check  0 < bits <=  7
**          --> 0X00007F
**          aka 0B 00000000 00000000 01111111
*/

int				wchar_len(wchar_t c)
{
	if (0X1F0000 & c)
		return (4);
	else if (0X00F800 & c)
		return (3);
	else if (0X000780 & c)
		return (2);
	else if (0X00007F & c)
		return (1);
	else if (c == 0)
		return (1);
	return (0);
}

/*
** add_wchar() explanation
**
** if (len == 1)
**     addchar() as it is (thanks to ASCII compatibility)
** if (len == 2)
**     need to convert c = 00000ABC DEFGHIJK
**                      to 110ABCDE 10FGHIJK
** if (len == 3)
**     need to convert c = 00000000 ABCDEFGH IJKLMNOP
**                      to 1110ABCD 10EFGHIJ 10KLMNOP
** if (len == 4)
**     need to convert c = 00000000 000ABCDE FGHIJKLM NOPQRSTU
**                      to 11110ABC 10DEFGHI 10JKLMNO 10PQRSTU
*/

static void		four_width(t_info *info, wchar_t c)
{
	addchar(info, (char)((unsigned char)
				((0XF0000000 | ((c << 6) & 0X07000000)) >> 24)));
	addchar(info, (char)((unsigned char)
				((0X800000 | ((c << 4) & 0X3F0000)) >> 16)));
	addchar(info, (char)((unsigned char)
				((0X8000 | ((c << 2) & 0X3F00)) >> 8)));
	addchar(info, (char)((unsigned char)(0X80 | (c & 0X3F))));
}

void			add_wchar(t_info *info, wchar_t c, int width)
{
	if (width == 1)
		addchar(info, (char)c);
	if (width == 2)
	{
		addchar(info, (char)((unsigned char)
					((0XC000 | ((c << 2) & 0X1F00)) >> 8)));
		addchar(info, (char)((unsigned char)(0X80 | (c & 0X3F))));
	}
	else if (width == 3)
	{
		addchar(info, (char)((unsigned char)
					((0XE00000 | ((c << 4) & 0X0F0000)) >> 16)));
		addchar(info, (char)((unsigned char)
					((0X8000 | ((c << 2) & 0X3F00)) >> 8)));
		addchar(info, (char)((unsigned char)(0X80 | (c & 0X3F))));
	}
	else if (width == 4)
		four_width(info, c);
}

void			out_wchar(t_info *info, va_list args)
{
	wchar_t		c;

	c = (wchar_t)va_arg(args, wint_t);
	info->charlen = wchar_len(c);
	if (info->leftjustify)
	{
		add_wchar(info, c, info->charlen);
		put_nchars(info, info->field - info->charlen,
				info->zeroes ? '0' : SPACE);
	}
	else
	{
		put_nchars(info, info->field - info->charlen,
				info->zeroes ? '0' : SPACE);
		add_wchar(info, c, info->charlen);
	}
}
