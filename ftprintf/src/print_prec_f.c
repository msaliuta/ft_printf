/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prec_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 12:06:16 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/01 16:40:27 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ftoa_prec_f(t_pf_env *e, long double d)
{
	char	*tmp;
	char	*nb;
	long	num;
	int		prec;

	tmp = ft_ltoa((long)d);
	d == 0 ? --e->flag.prec : 0;
	prec = ft_strlen(tmp);
	num = get_prec_num_f(d, (e->flag.prec >= 0 ? e->flag.prec : 6));
	nb = (num == 0 ? ft_strdup("0000000") : ft_ftoa(num));
	if (e->flag.prec == 0)
		e->out = (e->flag.hash) ? ft_strjoin(tmp, ".") : ft_strdup(tmp);
	else
		e->out = ft_str_prec(nb, prec, e->flag.prec >= 0 ?
		prec + e->flag.prec : prec + 6, e->flag.hash);
	free(nb);
	free(tmp);
}

void	print_prec_f(t_pf_env *e, long double d)
{
	ftoa_prec_f(e, d);
	if (e->flag.minus)
	{
		if (d > 0 && (e->flag.plus || e->flag.sp))
			e->ret += (e->flag.plus == 1 ?
			write(e->fd, "+", 1) : write(e->fd, " ", 1));
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
		print_prec_width(e);
	}
	else
	{
		print_prec_width(e);
		if (d > 0 && (e->flag.plus || e->flag.sp))
			e->ret += (e->flag.plus == 1 ?
			write(e->fd, "+", 1) : write(e->fd, " ", 1));
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
	}
	++e->i;
	free(e->out);
}
