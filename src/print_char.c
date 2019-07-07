/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 04:25:14 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/07 14:44:55 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char_width(t_pf_env *e)
{
	while (e->flag.width-- > 1)
	{
		if (e->flag.zero == 1)
			e->ret += write(e->fd, "0", 1);
		else
			e->ret += write(e->fd, " ", 1);
	}
}

void	spec_char(t_pf_env *e, char type)
{
	char	*stmp;
	int		ctmp;

	if (e->flag.minus)
		e->flag.zero = 0;
	if (type == 's')
	{
		init_str_arg(e, &stmp);
		if (stmp == NULL)
			return (print_null_str(e));
		else if (e->flag.prec)
			e->out = ft_strdup((char*)stmp);
		else
			e->out = ft_strdup("\0");
		print_str(e);
	}
	else if (type == 'c')
	{
		init_char_arg(e, &ctmp);
		print_char(e, ctmp);
	}
}

void	print_null_char(t_pf_env *e)
{
	while (e->flag.width-- > 1)
	{
		if (e->flag.zero == 1)
			e->ret += write(e->fd, "0", 1);
		else
			e->ret += write(e->fd, " ", 1);
	}
	++e->i;
}

void	print_char(t_pf_env *e, char c)
{
	if (e->flag.minus)
	{
		e->ret += write(e->fd, &c, 1);
		print_char_width(e);
	}
	else
	{
		print_char_width(e);
		e->ret += write(e->fd, &c, 1);
	}
	++e->i;
}
