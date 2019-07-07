/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_functs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 04:25:11 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/07 20:40:56 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_long_argm(t_pf_env *e, long *tmp)
{
	if (e->tag.tag)
	{
		va_copy(e->ap[0], e->ap[1]);
		while (--e->tag.pos >= 0)
			*tmp = va_arg(e->ap[0], long);
		return ;
	}
	*tmp = va_arg(e->ap[0], long);
}

void	process_int(t_pf_env *e)
{
	long tmp;
	long i;

	init_long_argm(e, &tmp);
	i = (long long)tmp;
	if (e->flag.minus == 1)
		e->flag.zero = 0;
	if (e->flag.prec >= 0)
		e->flag.zero = 0;
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
	digit_print(e);
}

void	init_double_argm(t_pf_env *e, double *tmp)
{
	if (e->tag.tag)
	{
		va_copy(e->ap[0], e->ap[1]);
		while (--e->tag.pos >= 0)
			*tmp = va_arg(e->ap[0], double);
		return ;
	}
	*tmp = va_arg(e->ap[0], double);
}

void	process_unsint(t_pf_env *e, char type)
{
	long tmp;

	e->flag.sps = 0;
	e->flag.plus = 0;
	init_long_argm(e, &tmp);
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
	digit_print(e);
}
