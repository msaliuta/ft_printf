/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 12:06:38 by msaliuta          #+#    #+#             */
/*   Updated: 2019/06/30 12:06:38 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	spec_char(t_pf_env *e, char type)
{
	char	*stmp;
	int		ctmp;

	e->flag.minus ? e->flag.zero = 0 : 0;
	if (type == 's')
	{
		init_str_arg(e, &stmp);
		if (stmp == NULL)
			return (print_null_str(e));
		e->out = ft_strdup((char*)stmp);
		print_str(e);
	}
	else if (type == 'c')
	{
		init_char_arg(e, &ctmp);
		print_char(e, ctmp);
	}
}
