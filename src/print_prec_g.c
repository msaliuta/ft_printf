/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prec_g.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 04:25:18 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/08 10:46:06 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	delete_zero(char *tmp)
{
	int		i;

	i = ft_strlen(tmp);
	while (--i >= 0 && tmp[i] == '0')
		tmp[i] = '\0';
}

void	print_prec_g(t_pf_env *e, long double d, char type)
{
	check_form(e, d, type);
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
