/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_width_functs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 04:25:14 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/08 10:03:07 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	base_width_print(t_pf_env *e, char type)
{
	int	i;
	int len;

	i = -1;
	len = ft_strlen(e->out);
	if (e->flag.hash && (e->out[0] != '\0' && e->out[0] != '0'))
		bpw_check(e, type);
	if (e->flag.prec >= 0)
	{
		while (e->flag.width > e->flag.prec + ++i && e->flag.width > len + i)
			e->ret += write(e->fd, " ", 1);
		while (e->flag.width > len + i++)
			e->ret += write(e->fd, "0", 1);
	}
	else
	{
		while (e->flag.width > len + ++i)
		if (e->flag.zero == 1)
			e->ret += write(e->fd, "0", 1);
		else
			e->ret += write(e->fd, " ", 1);
	}
}

void	bpw_check(t_pf_env *e, char type)
{
	if (type == 'o' || type == 'O')
		e->flag.width -= 1;
	else
		e->flag.width -= 0;
	if (type == 'x' || type == 'X')
		e->flag.width -= 2;
	else
		e->flag.width -= 0;
}

void	check_prec_base(t_pf_env *e, char type)
{
	char	*tmp;
	char	*res;
	int		len;
	int		i;

	len = (int)ft_strlen(e->out);
	if (e->flag.prec == 0 && e->out[0] == '0')
		e->out[0] = '\0';
	else if (e->flag.prec > len)
	{
		if ((type == 'o' || type == 'O') && e->flag.hash)
			e->flag.prec--;
		i = e->flag.prec - len;
		tmp = ft_strnew(i);
		while (--i >= 0)
			tmp[i] = '0';
		res = ft_strjoin(tmp, e->out);
		free(tmp);
		free(e->out);
		e->out = res;
	}
}

void	digit_width_print(t_pf_env *e)
{
	int i;
	int len;

	i = -1;
	if ((int)ft_strlen(e->out) > e->flag.prec)
		len = (int)ft_strlen(e->out);
	else
		len = e->flag.prec;
	if ((e->flag.plus + e->flag.sps + e->flag.neg) >= 1)
		e->flag.width--;
	if (e->flag.prec >= 0)
	{
		while (e->flag.width - ++i > len)
			e->ret += write(e->fd, " ", 1);
		i = -1;
		while ((int)ft_strlen(e->out) < len - ++i)
			e->ret += write(e->fd, "0", 1);
	}
	else
		while (e->flag.width - ++i > len)
			e->ret += (e->flag.zero == 1 ?
			write(e->fd, "0", 1) : write(e->fd, " ", 1));
}

void	prec_width_print(t_pf_env *e)
{
	int i;
	int len;

	i = -1;
	len = ft_strlen(e->out) + e->flag.plus + e->flag.sps;
	if (e->flag.prec >= 0)
	{
		while (e->flag.width - ++i > len)
			if (e->flag.zero)
				e->ret += write(e->fd, "0", 1);
			else
				e->ret += write(e->fd, " ", 1);
		i = -1;
		while ((int)ft_strlen(e->out) < len - ++i)
			e->ret += write(e->fd, "0", 1);
	}
	else
		while (e->flag.width - ++i > len)
			if (e->flag.zero == 1)
				e->ret += write(e->fd, "0", 1);
			else
				e->ret += write(e->fd, " ", 1);
}
