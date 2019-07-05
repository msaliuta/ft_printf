/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 04:25:15 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/03 04:25:15 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_dice(t_pf_env *e)
{
	long	ran;
	char	nb;
	double	d;
	int		i;

	init_int_arg(e, &ran);
	i = 0;
	d = (double)ran * 1.23456;
	while (i++ < 10)
	{
		d /= 12.34;
		d += ((long)d % 6 == 2 ? 1 : -1);
		d = (long)d;
		d += ((long)d % 6 == 4 ? 1 : -1);
		d *= 21.43;
		d += ((long)d % 6 == 0 ? 1 : -1);
	}
	nb = ((long)d % 6) + 49;
	e->ret += write(e->fd, &nb, 1);
	++e->i;
}
