/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 11:58:12 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/12 20:38:45 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	error_label(void)
{
	ft_printf("Invalid Label Syntaxe.\n");
	exit(0);
}

void	error_opcode(char *str)
{
	ft_printf("Invalid Opcode '%s'.\n", str);
	exit(0);
}

void	error_param(char *str)
{
	ft_printf("Invalid Parametres '%s'.\n", str);
	exit(0);
}
