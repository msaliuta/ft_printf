/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_functs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 04:25:14 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/08 10:33:13 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	char_for_ptint(t_pf_env *e, int n)
{
	if (n == 1)
	{
		while (e->flag.width-- > 1)
		{
			if (e->flag.zero == 1)
				e->ret += write(e->fd, "0", 1);
			else
				e->ret += write(e->fd, " ", 1);
		}
	}
	else
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
}

void	process_char(t_pf_env *e, char type)
{
	char	*stmp;
	int		ctmp;

	if (e->flag.minus)
		e->flag.zero = 0;
	if (type == 's')
	{
		init_str_arg(e, &stmp);
		if (stmp == NULL)
			return (str_for_print(e, 0));
		else if (e->flag.prec)
			e->out = ft_strdup((char*)stmp);
		else
			e->out = ft_strdup("\0");
		str_print(e);
	}
	else if (type == 'c')
	{
		init_char_arg(e, &ctmp);
		char_print(e, ctmp);
	}
}

void	init_char_arg(t_pf_env *e, int *tmp)
{
	if (e->tag.tag)
	{
		va_copy(e->ap[0], e->ap[1]);
		while (--e->tag.pos >= 0)
			*tmp = va_arg(e->ap[0], int);
		return ;
	}
	*tmp = va_arg(e->ap[0], int);
}

void	char_print(t_pf_env *e, char c)
{
	if (e->flag.minus)
	{
		e->ret += write(e->fd, &c, 1);
		char_for_ptint(e, 1);
	}
	else
	{
		char_for_ptint(e, 1);
		e->ret += write(e->fd, &c, 1);
	}
	++e->i;
}
