/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longd_functs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 04:25:11 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/07 20:40:57 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_long_double(t_pf_env *e, long double *tmp)
{
	if (e->tag.tag)
	{
		va_copy(e->ap[0], e->ap[1]);
		while (--e->tag.pos >= 0)
			*tmp = va_arg(e->ap[0], long double);
		return ;
	}
	*tmp = va_arg(e->ap[0], long double);
}

void	check_form(t_pf_env *e, long double d, char tnt)
{
	char	*nb;
	int		neg;

	if (d < 0)
		neg = -1;
	else
		neg = 1;
	d *= neg;
	if ((d + 0.5 > 1000000 || d < 0.0001) && e->flag.prec < 0 &&
		d != 0)
		return (ftoa_prec_eg(e, d * neg, tnt - 2, 5));
	else if (e->flag.prec < 0)
		return (ftoa_prec_fg(e, d * neg, 6));
	nb = ft_ltoa((long)d);
	if (((int)ft_strlen(nb) > e->flag.prec && e->flag.prec != 0) ||
		(e->flag.prec == 0 && d >= 10))
	{
		free(nb);
		return (ftoa_prec_eg(e, d * neg, tnt - 2, e->flag.prec - 1));
	}
	free(nb);
	ftoa_prec_fg(e, d * neg, e->flag.prec);
}

void	process_dgt_sign(t_pf_env *e)
{
	char *tmp;

	if (e->out[0] == '-')
	{
		tmp = ft_strdup(e->out + 1);
		free(e->out);
		e->out = tmp;
		e->flag.sps = 0;
		e->flag.plus = 0;
		e->flag.neg = 1;
	}
}

void	process_dgt_prec(t_pf_env *e)
{
	char	*tmp;
	char	*res;
	int		len;
	int		i;

	process_dgt_sign(e);
	len = (int)ft_strlen(e->out);
	if (e->flag.prec == 0 && e->out[0] == '0')
		e->out[0] = '\0';
	else if (e->flag.prec > len)
	{
		i = e->flag.prec - len;
		tmp = ft_strnew(i);
		while (i-- > 0)
			tmp[i] = '0';
		res = ft_strjoin(tmp, e->out);
		free(tmp);
		free(e->out);
		e->out = res;
	}
}
