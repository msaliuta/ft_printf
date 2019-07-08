/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prec_print_functs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 13:40:41 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/08 13:52:14 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_prec_a(t_pf_env *e, double d, char type)
{
	ftoa_a(e, d, type);
    if (d < 0)
        e->ret += write(1, "-", 1);
	if (e->flag.zero)
	{
		base_pre_print(e, type, 1);
		prec_width_print(e);
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
	}
	else if (e->flag.minus)
	{
		base_pre_print(e, type, 1);
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
		prec_width_print(e);
	}
	else
		print_prec_a_else(e, type);
	free(e->out);
	++e->i;
}
