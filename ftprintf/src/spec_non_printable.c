/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_non_printable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 12:06:41 by msaliuta          #+#    #+#             */
/*   Updated: 2019/06/30 12:06:41 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	spec_non_printable(t_pf_env *e)
{
	char	*tmp;
	int		i;

	init_str_arg(e, &tmp);
	i = -1;
	while (++i < e->flag.width)
	{
		if (tmp[i] >= 0 && tmp[i] <= 10)
			print_zero_to_ten(e, tmp[i]);
		else if (tmp[i] >= 11 && tmp[i] <= 20)
			print_ten_to_twenty(e, tmp[i]);
		else if (tmp[i] >= 21 && tmp[i] <= 31)
			print_twenty_to_thirty(e, tmp[i]);
		++e->ret;
	}
	++e->i;
}
