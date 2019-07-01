/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 12:06:37 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/01 12:44:12 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	spec_base(t_pf_env *e, char type)
{
	long			tmp;
	unsigned long	val;

	val = 0;
	init_int_arg(e, &tmp);
	if (type == 'O' || e->mod == pf_z || e->mod == pf_t ||
		e->mod == pf_j || e->mod == pf_l || e->mod == pf_ll)
		val = (unsigned long)tmp;
	else if (e->mod == pf_hh)
		val = (unsigned char)tmp;
	else if (e->mod == pf_h)
		val = (unsigned short)tmp;
	else if (e->mod == pf_nomod)
		val = (unsigned int)tmp;
	(type == 'b' || type == 'B') ? e->out = ft_ultoa_base(val, 2) : 0;
	(type == 'o' || type == 'O') ? e->out = ft_ultoa_base(val, 8) : 0;
	(type == 'x' || type == 'X') ? e->out = ft_ultoa_base(val, 16) : 0;
	if (type == 'b' || type == 'o' || type == 'x')
		ft_strlower(e->out);
	e->flag.minus == 1 ? e->flag.zero = 0 : 0;
	print_base(e, type, (long)val);
}
