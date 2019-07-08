/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prec_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 04:25:17 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/08 14:08:01 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_a_expo(double d, char type, char **expo)
{
	char	*tmp;
	char	pre[3];
	int		i;

	i = 0;
	pre[2] = '\0';
	d < 0 ? d *= -1 : 0;
	pre[1] = ((d >= 1 || d == 0) ? '+' : '-');
	pre[0] = type + 15;
	while ((d >= 2 || d < 1) && d != 0)
	{
		if (d < 1)
			d *= 2;
		else
			d /= 2;
		++i;
	}
	tmp = ft_itoa(i);
	*expo = ft_strjoin(pre, tmp);
	free(tmp);
}

void	hex_prec(t_pf_env *e, double d, char **frac, char type)
{
	unsigned long	cmp;
	long			num;
	int				len;
	int				cnt;
	int				i;

	len = (e->flag.prec < 0 ? 13 : e->flag.prec);
	*frac = ft_strnew(len);
	cmp = 0x0008000000000000;
	i = -1;
	num = *(long*)&d;
	while (++i < len)
	{
		cnt = 0;
		cnt += (num & cmp) == 0 ? 0 : 8;
		cmp >>= 1;
		cnt += (num & cmp) == 0 ? 0 : 4;
		cmp >>= 1;
		cnt += (num & cmp) == 0 ? 0 : 2;
		cmp >>= 1;
		cnt += (num & cmp) == 0 ? 0 : 1;
		cmp >>= 1;
		frac[0][i] = (cnt < 10 ? cnt + 48 : cnt + type - 10);
	}
}

void	print_prec_a_else(t_pf_env *e, char type)
{
	e->flag.width -= 2;
	prec_width_print(e);
	base_pre_print(e, type, 1);
	e->ret += write(e->fd, e->out, ft_strlen(e->out));
}
