/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa_prec_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 04:25:08 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/03 07:21:02 by msaliuta         ###   ########.fr       */
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
