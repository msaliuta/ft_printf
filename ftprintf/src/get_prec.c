/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 12:05:37 by msaliuta          #+#    #+#             */
/*   Updated: 2019/06/30 12:05:37 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_prec(const char *restrict fmt, t_pf_env *e)
{
	if (e->flag.prec >= 0)
	{
		++e->i;
		return ;
	}
	if (fmt[e->i] == '.' && fmt[e->i + 1] == '*')
	{
		e->flag.prec = va_arg(e->ap[0], int);
		e->i += 2;
	}
	else if (fmt[e->i] == '.')
	{
		++e->i;
		e->flag.prec = ft_atoi(fmt + e->i);
		while (FT_ISNUM(fmt[e->i]))
			++e->i;
	}
}
