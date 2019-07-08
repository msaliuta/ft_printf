/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_non_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 04:25:17 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/08 13:36:20 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_first_dec(t_pf_env *e, char c)
{
	if (c == 0)
		write(e->fd, "[NUL]", 5);
	else if (c == 1)
		write(e->fd, "[SOH]", 5);
	else if (c == 2)
		write(e->fd, "[STX]", 5);
	else if (c == 3)
		write(e->fd, "[ETX]", 5);
	else if (c == 4)
		write(e->fd, "[EOT]", 5);
	else if (c == 5)
		write(e->fd, "[ENQ]", 5);
	else if (c == 6)
		write(e->fd, "[ACK]", 5);
	else if (c == 7)
		write(e->fd, "[BEL]", 5);
	else if (c == 8)
		write(e->fd, "[BS]", 4);
	else if (c == 9)
		write(e->fd, "[TAB]", 5);
	else if (c == 10)
		write(e->fd, "[LF]", 4);
}

void	print_second_dec(t_pf_env *e, char c)
{
	if (c == 11)
		write(e->fd, "[VT]", 5);
	else if (c == 12)
		write(e->fd, "[FF]", 4);
	else if (c == 13)
		write(e->fd, "[CR]", 4);
	else if (c == 14)
		write(e->fd, "[SO]", 4);
	else if (c == 15)
		write(e->fd, "[SI]", 4);
	else if (c == 16)
		write(e->fd, "[DLE]", 5);
	else if (c == 17)
		write(e->fd, "[DC1]", 5);
	else if (c == 18)
		write(e->fd, "[DC2]", 5);
	else if (c == 19)
		write(e->fd, "[DC3]", 5);
	else if (c == 20)
		write(e->fd, "[DC4]", 5);
}

void	print_thirtd_dec(t_pf_env *e, char c)
{
	if (c == 21)
		write(e->fd, "[NAK]", 5);
	else if (c == 22)
		write(e->fd, "[SYN]", 5);
	else if (c == 23)
		write(e->fd, "[ETB]", 5);
	else if (c == 24)
		write(e->fd, "[CAN]", 5);
	else if (c == 25)
		write(e->fd, "[EM]", 4);
	else if (c == 26)
		write(e->fd, "[SUB]", 5);
	else if (c == 27)
		write(e->fd, "[ESC]", 5);
	else if (c == 28)
		write(e->fd, "[FS]", 4);
	else if (c == 29)
		write(e->fd, "[GS]", 4);
	else if (c == 30)
		write(e->fd, "[RS]", 4);
	else if (c == 31)
		write(e->fd, "[US]", 4);
}
