/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_ptraddr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 12:06:42 by msaliuta          #+#    #+#             */
/*   Updated: 2019/06/30 12:06:42 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	spec_ptraddr(t_pf_env *e, char type)
{
	long			tmp;
	unsigned long	addr;

	init_int_arg(e, &tmp);
	addr = (unsigned long)tmp;
	if (e->flag.prec == 0)
		e->out = ft_strdup("\0");
	else
		e->out = ft_ltoa_base(addr, 16);
	print_ptraddr(e, type);
}
