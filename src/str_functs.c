/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_functs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 04:25:20 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/08 13:14:06 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	str_for_print(t_pf_env *e, int n)
{
	if (n == 1)
	{
		n = ft_strlen(e->out);
		while (e->flag.width-- > n)
			if (e->flag.zero == 1)
				e->ret += write(e->fd, "0", 1);
			else
				e->ret += write(e->fd, " ", 1);
	}
	else
	{
		if (e->flag.prec < 0)
			n = 6;
		else
			n = e->flag.prec;
		while (e->flag.width-- > n)
			if (e->flag.zero == 1)
				e->ret += write(e->fd, "0", 1);
			else
				e->ret += write(e->fd, " ", 1);
		e->ret += write(e->fd, "(null)", n);
		++e->i;
	}
}

void	str_print(t_pf_env *e)
{
	char	*tmp;

	if (e->flag.prec >= 0 && e->flag.prec < (int)ft_strlen(e->out))
	{
		tmp = ft_strsub(e->out, 0, (e->flag.prec));
		free(e->out);
		e->out = tmp;
	}
	if (e->flag.minus)
	{
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
		str_for_print(e, 1);
	}
	else
	{
		str_for_print(e, 1);
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
	}
	++e->i;
	free(e->out);
}

void	init_str_arg(t_pf_env *e, char **tmp)
{
	if (e->tag.tag)
	{
		va_copy(e->ap[0], e->ap[1]);
		while (e->tag.pos >= 0)
		{
			*tmp = va_arg(e->ap[0], char *);
			e->tag.pos--;
		}
		return ;
	}
	*tmp = va_arg(e->ap[0], char *);
}

char	*ft_str_prec(char *s1, int dot, int end, int hash)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = ft_strnew(ft_strlen(s1) + 1);
	while (s1[i] != '\0')
	{
		tmp[j++] = s1[i];
		if ((i == dot - 1 && end > 0) || hash == 1)
		{
			tmp[j++] = '.';
			hash = 0;
		}
		if (i >= end)
		{
			tmp[j] = '\0';
			break ;
		}
		i++;
	}
	return (tmp);
}

void	prrint_wstr_1(t_pf_env *e, char c)
{
	e->ret += write(e->fd, &c, 1);
}
