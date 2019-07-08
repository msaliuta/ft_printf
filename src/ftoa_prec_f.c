/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa_prec_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 04:25:08 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/08 12:13:58 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_prec_f(t_pf_env *e, long double d)
{
	ftoa_f(e, d, 0);
	if (e->flag.minus)
	{
		if (d > 0 && (e->flag.plus || e->flag.sps))
			e->ret += (e->flag.plus == 1 ?
			write(e->fd, "+", 1) : write(e->fd, " ", 1));
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
		prec_width_print(e);
	}
	else
	{
		prec_width_print(e);
		if (d > 0 && (e->flag.plus || e->flag.sps))
			e->ret += (e->flag.plus == 1 ?
			write(e->fd, "+", 1) : write(e->fd, " ", 1));
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
	}
	++e->i;
	free(e->out);
}

long	get_prec_num_f(long double d, int prec)
{
	int		neg;
	int		i;

	i = -1;
	neg = (d < 0 ? -1 : 1);
	d *= neg;
	while (++i < prec)
		d *= 10;
	d += 0.5;
	d *= neg;
	return ((long)d);
}
