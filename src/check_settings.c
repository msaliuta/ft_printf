/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 04:25:26 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/03 04:25:26 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_set(const char *restrict fmt, t_pf_env *e)
{
	int tmp;

	tmp = e->i;
	if (tmp == e->i)
		e->ret += write(e->fd, &fmt[e->i++], 1);
}
