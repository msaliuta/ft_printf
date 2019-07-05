/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 04:25:24 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/03 04:25:24 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	spec_precision(t_pf_env *e, char type)
{
	long double	ld;
	double		d;

	if (e->mod == pf_L)
	{
		init_long_double(e, &ld);
		if (ld != ld || (ld * 2 == ld && ld != 0))
			return (nan_inf(e, type, ld));
	}
	else
	{
		init_prec_arg(e, &d);
		if (d != d || (d * 2 == d && d != 0))
			return (nan_inf(e, type, d));
		ld = (long double)d;
	}
	if (type == 'e' || type == 'E')
		return (print_prec_e(e, ld, type));
	if (type == 'f' || type == 'F')
		return (print_prec_f(e, ld));
	if (type == 'g' || type == 'G')
		return (print_prec_g(e, ld, type));
	if (type == 'a' || type == 'A')
		return (print_prec_a(e, ld, type));
}
