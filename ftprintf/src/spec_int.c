/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 12:06:40 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/01 15:00:52 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
