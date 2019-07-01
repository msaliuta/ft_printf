/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_unsint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 12:06:44 by msaliuta          #+#    #+#             */
/*   Updated: 2019/06/30 18:33:16 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	spec_unsint(t_pf_env *e, char type)
{
	long tmp;

	e->flag.sp = 0;
	e->flag.plus = 0;
	init_int_arg(e, &tmp);
	if (tmp == LLONG_MIN || tmp == LONG_MIN)
		e->out = ft_strdup("-9223372036854775808");
	else if (type == 'D' || type == 'U' || e->mod == pf_l ||
			e->mod == pf_t || e->mod == pf_j || e->mod == pf_ll)
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
