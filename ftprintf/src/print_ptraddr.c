/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptraddr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 12:06:21 by msaliuta          #+#    #+#             */
/*   Updated: 2019/06/30 12:06:21 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ptraddr_prec(t_pf_env *e)
{
	char	*tmp;
	char	*res;
	int		len;
	int		i;

	i = -1;
	len = (int)ft_strlen(e->out);
	if (e->flag.prec > len)
	{
		tmp = ft_strnew(e->flag.prec - len);
		while (++i < e->flag.prec - len)
			tmp[i] = '0';
		res = ft_strjoin(tmp, e->out);
		free(e->out);
		free(tmp);
		e->out = res;
	}
	tmp = ft_strjoin("0x", e->out);
	free(e->out);
	e->out = tmp;
}

void	print_ptraddr_width(t_pf_env *e)
{
	int len;

	len = ft_strlen(e->out);
	while (e->flag.width-- > len)
		e->ret += write(e->fd, " ", 1);
}

void	print_ptraddr(t_pf_env *e, char type)
{
	if (e->flag.zero && e->flag.prec == -1)
		e->flag.prec = e->flag.width - 2;
	ptraddr_prec(e);
	if (type == 'p')
		ft_strlower(e->out);
	if (e->flag.minus)
	{
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
		print_ptraddr_width(e);
	}
	else
	{
		print_ptraddr_width(e);
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
	}
	++e->i;
	free(e->out);
}
