/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prec_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 04:25:19 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/08 10:09:40 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ftoa(long double d)
{
	char	*s;
	long	tmp;
	int		len;
	int		neg;

	neg = (d < 0 ? -1 : 1);
	len = (d < 0 ? 1 : 0);
	d *= neg;
	tmp = (long)d;
	while (tmp > 0 && len++ >= 0)
		tmp /= 10;
	while (d - (long)d != 0 && len++ >= 0)
		d *= 10;
	s = ft_strnew(len);
	while (--len >= 0)
	{
		s[len] = (long)d % 10 + '0';
		d /= 10;
		if (neg == -1 && len == 1)
		{
			s[0] = '-';
			break ;
		}
	}
	return (s);
}

void	nan_inf(t_pf_env *e, char type, double var)
{
	if (var != var)
	{
		if (type == 'e' || type == 'f' || type == 'g')
			e->ret += write(e->fd, "nan", 3);
		else
			e->ret += write(e->fd, "NAN", 3);
	}
	else if (var * 2 == var && var != 0)
	{
		if (type == 'e' || type == 'f' || type == 'g')
			e->ret += write(e->fd, "inf", 3);
		else
			e->ret += write(e->fd, "INF", 3);
	}
	++e->i;
}
