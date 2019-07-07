/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_persent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 04:25:24 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/07 14:29:04 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	spec_percent(t_pf_env *e)
{
	if (e->flag.minus)
	{
		e->ret += write(e->fd, "%", 1);
		while (e->flag.width-- > 1)
			e->ret += write(e->fd, " ", 1);
	}
	else
	{
		while (e->flag.width-- > 1)
		{
			if (e->flag.zero)
				e->ret += write(e->fd, "0", 1);
			else
				e->ret += write(e->fd, " ", 1);
		}
		e->ret += write(e->fd, "%", 1);
	}
	++e->i;
}

void	spec_int(t_pf_env *e)
{
	long tmp;
	long i;

	init_int_arg(e, &tmp);
	i = (long long)tmp;
	e->flag.minus == 1 ? e->flag.zero = 0 : 0;
	e->flag.prec >= 0 ? e->flag.zero = 0 : 0;
	if (tmp == LLONG_MIN || tmp == LONG_MIN)
		e->out = ft_strdup("-9223372036854775808");
	else if (e->mod == pf_z)
		e->out = ft_itoa((size_t)i);
	else if (e->mod == pf_hh)
		e->out = ft_itoa((char)i);
	else if (e->mod == pf_h)
		e->out = ft_itoa((short)i);
	else if (e->mod == pf_nomod)
		e->out = ft_itoa((int)i);
	else if (e->mod == pf_l || e->mod == pf_t ||
			e->mod == pf_ll || e->mod == pf_j)
		e->out = ft_ltoa((long)i);
	else if (e->mod == pf_L)
		e->out = ft_itoa((unsigned long)i);
	print_digit(e);
}

void	spec_unsint(t_pf_env *e, char type)
{
	long tmp;

	e->flag.sps = 0;
	e->flag.plus = 0;
	init_int_arg(e, &tmp);
	if (tmp == LLONG_MIN || tmp == LONG_MIN)
		e->out = ft_strdup("-9223372036854775808");
	else if (type == 'D' || type == 'U' || e->mod == pf_l ||
			e->mod == pf_t || e->mod == pf_j || e->mod == pf_ll
			|| e->mod == pf_L)
		e->out = ft_ultoa((unsigned long)tmp);
	else if (e->mod == pf_z)
		e->out = ft_ltoa((long)tmp);
	else if (e->mod == pf_h)
		e->out = ft_ltoa((unsigned short)tmp);
	else if (e->mod == pf_hh)
		e->out = ft_ultoa((unsigned char)tmp);
	else if (e->mod == pf_nomod && type != 'U')
		e->out = ft_ultoa((unsigned int)tmp);
	print_digit(e);
}
