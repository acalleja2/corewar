/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <lorenzo.farnetani@student.42.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 20:47:14 by florenzo          #+#    #+#             */
/*   Updated: 2018/01/23 20:47:14 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		is_flag(char c)
{
	return (c == ' ' || c == '+' || c == '-' || c == '#' || c == '0');
}

int		is_sizemod(char c)
{
	return (c == 'h' || c == 'l' || c == 'z' || c == 'j');
}

int		is_spec(char c)
{
	return (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' ||
			c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' ||
			c == 'x' || c == 'X' || c == 'c' || c == 'C' || c == 'n' ||
			c == 'b' || c == 'B' || c == 'r');
}

int		is_uintspec(char c)
{
	return (c == 'u' || c == 'x' || c == 'X' || c == 'o' || c == 'b' ||
			c == 'B');
}
