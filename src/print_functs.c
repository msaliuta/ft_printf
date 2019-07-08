/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 04:25:15 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/08 09:48:59 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	digit_sign_print(t_pf_env *e)
{
	if (e->flag.plus || e->flag.sps)
	{
		if (e->flag.plus == 1)
			e->ret += write(e->fd, "+", 1);
		else
			e->ret += write(e->fd, " ", 1);
	}
	else if (e->flag.neg)
		e->ret += write(e->fd, "-", 1);
}

void	digit_print(t_pf_env *e)
{
	process_dgt_prec(e);
	if (e->flag.zero)
	{
		digit_sign_print(e);
		digit_width_print(e);
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
	}
	else if (e->flag.minus)
	{
		digit_sign_print(e);
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
		digit_width_print(e);
	}
	else
	{
		digit_width_print(e);
		digit_sign_print(e);
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
	}
	++e->i;
	free(e->out);
}

void	base_pre_print(t_pf_env *e, char type, long val)
{
	if (e->flag.hash && e->out[0] != '\0' && val != 0)
		bpp_check(e, type, 1);
	else if ((type == 'o' || type == 'O') && e->flag.hash && e->flag.prec >= 0)
		e->ret += write(e->fd, "0", 1);
	else if (type == 'a' || type == 'A')
	{
		if (e->flag.plus || e->flag.sps)
		{
			bpp_check(e, type, 2);
		}
		if (type == 'a')
		{
			e->ret += type;
			write(e->fd, "0x", 2);
		}
		else
		{
			e->ret += type;
			write(e->fd, "0X", 2);
		}
		e->flag.width -= 2;
	}
}

void	bpp_check(t_pf_env *e, char type, int n)
{
	if (n == 1)
	{
		if (type == 'o' || type == 'O')
			e->ret += write(e->fd, "0", 1);
		if (type == 'x')
			e->ret += write(e->fd, "0x", 2);
		if (type == 'X')
			e->ret += write(e->fd, "0X", 2);
		if (type == 'a' || type == 'A')
			e->flag.width -= 2;
	}
	else
	{
		if (e->flag.sps)
		{
			e->ret += e->flag.sps;
			write(1, " ", 1);
		}
		else
		{
			e->ret += e->flag.sps;
			write(1, "+", 1);
		}
	}
}

void	base_print(t_pf_env *e, char type, long val)
{
	check_prec_base(e, type);
	if (e->flag.zero)
	{
		base_pre_print(e, type, val);
		base_width_print(e, type);
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
	}
	else if (e->flag.minus)
	{
		base_pre_print(e, type, val);
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
		base_width_print(e, type);
	}
	else
	{
		base_width_print(e, type);
		base_pre_print(e, type, val);
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
	}
	++e->i;
	free(e->out);
}
