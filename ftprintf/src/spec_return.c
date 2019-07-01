/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_return.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 12:06:43 by msaliuta          #+#    #+#             */
/*   Updated: 2019/06/30 12:06:43 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	spec_return(t_pf_env *e)
{
	int	*tmp;

	if (e->tag.tag)
	{
		va_copy(e->ap[0], e->ap[1]);
		while (--e->tag.pos >= 0)
			tmp = va_arg(e->ap[0], int *);
	}
	tmp = va_arg(e->ap[0], int *);
	*tmp = e->ret;
	++e->i;
}
