/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prec_e.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 04:25:18 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/08 12:15:32 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_exponent(long double d, char type, char **expo)
{
	char	*tmp1;
	char	*tmp2;
	int		ex;

	d < 0 ? d *= -1 : 0;
	ex = 0;
	while (d >= 10)
	{
		d /= 10;
		ex++;
	}
	while (d < 1)
	{
		d *= 10;
		ex--;
	}
	if (ex > 9 || ex < -9)
		tmp1 = ft_strjoin(type == 'e' ? "e" : "E", ex < 0 ? "-" : "+");
	else
		tmp1 = ft_strjoin(type == 'e' ? "e" : "E", ex < 0 ? "-0" : "+0");
	tmp2 = ft_itoa(ex < 0 ? ex * -1 : ex);
	*expo = ft_strjoin(tmp1, tmp2);
	free(tmp1);
	free(tmp2);
}

long	get_prec_num_e(long double d, int prec)
{
	int	neg;
	int	i;

	neg = (d < 0 ? -1 : 1);
	d *= neg;
	while (d < 1)
		d *= 10;
	while (d >= 10)
		d /= 10;
	i = -1;
	while (++i < prec)
		d *= 10;
	d += 0.5;
	d *= neg;
	return ((long)d);
}

void	print_prec_e(t_pf_env *e, long double d, char type)
{
	ftoa_e(e, d, type, 0);
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
			e->ret += (e->flag.plus == 1 ? write(e->fd, "+", 1) :
			write(e->fd, " ", 1));
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
	}
	++e->i;
	free(e->out);
}
