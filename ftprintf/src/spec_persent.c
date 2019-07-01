/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_persent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 12:06:41 by msaliuta          #+#    #+#             */
/*   Updated: 2019/06/30 12:06:41 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	spec_percent(t_pf_env *e)
{
	if (e->flag.minus)
	{
		e->ret += write(e->fd, "%", 1);
		while (e->flag.width-- > 1)
			e->ret += write(e->fd, " ", 1);
	}
	else
	{
		while (e->flag.width-- > 1)
			e->ret += (e->flag.zero ?
			write(e->fd, "0", 1) : write(e->fd, " ", 1));
		e->ret += write(e->fd, "%", 1);
	}
	++e->i;
}
