/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 04:25:15 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/07 20:52:44 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	digit_sign_print(t_pf_env *e)
{
	if (e->flag.plus || e->flag.sps)
		e->ret += (e->flag.plus == 1 ?
		write(e->fd, "+", 1) : write(e->fd, " ", 1));
	else if (e->flag.neg)
		e->ret += write(e->fd, "-", 1);
}

void	digit_print(t_pf_env *e)
{
	process_dgt_prec(e);
	if (e->flag.zero)
	{
		digit_sign_print(e);
		print_digit_width(e);
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
	}
	else if (e->flag.minus)
	{
		digit_sign_print(e);
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
		print_digit_width(e);
	}
	else
	{
		print_digit_width(e);
		digit_sign_print(e);
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
	}
	++e->i;
	free(e->out);
}

void	base_pre_print(t_pf_env *e, char type, long val)
{
	if (e->flag.hash && e->out[0] != '\0' && val != 0)
	{
		e->ret += (type == 'o' || type == 'O') ? write(e->fd, "0", 1) : 0;
		e->ret += (type == 'x') ? write(e->fd, "0x", 2) : 0;
		e->ret += (type == 'X') ? write(e->fd, "0X", 2) : 0;
		type == 'a' || type == 'A' ? e->flag.width -= 2 : 0;
	}
	else if ((type == 'o' || type == 'O') && e->flag.hash && e->flag.prec >= 0)
		e->ret += write(e->fd, "0", 1);
	else if (type == 'a' || type == 'A')
	{
		if (e->flag.plus || e->flag.sps)
		{
			e->ret += e->flag.sps ? write(1, " ", 1) : write(1, "+", 1);
			e->flag.width--;
		}
		e->ret += type == 'a' ? write(e->fd, "0x", 2) : write(e->fd, "0X", 2);
		e->flag.width -= 2;
	}
}

void	base_print(t_pf_env *e, char type, long val)
{
	check_base_prec(e, type);
	if (e->flag.zero)
	{
		base_pre_print(e, type, val);
		print_base_width(e, type);
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
	}
	else if (e->flag.minus)
	{
		base_pre_print(e, type, val);
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
		print_base_width(e, type);
	}
	else
	{
		print_base_width(e, type);
		base_pre_print(e, type, val);
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
	}
	++e->i;
	free(e->out);
}
