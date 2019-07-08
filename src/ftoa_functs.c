/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa_functs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 10:43:23 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/08 12:15:39 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ftoa_a(t_pf_env *e, double d, char type)
{
	char	*frac;
	char	*ep;
	char	*tmp;

	d == 0 ? frac = ft_strdup("0") : hex_prec(e, d, &frac, type);
	d == 0 ? 0 : delete_zero(frac);
	get_a_expo(d, type, &ep);
	if (frac[0] == '\0')
		e->out = (d == 0 ? ft_strjoin("0", ep) : ft_strjoin("1", ep));
	else
	{
		tmp = (d == 0 ? ft_strdup(frac) : ft_strjoin("1.", frac));
		e->out = ft_strjoin(tmp, ep);
		free(tmp);
	}
	free(frac);
	free(ep);
	if (d < 0)
	{
		e->flag.plus = 0;
		e->flag.sps = 0;
		--e->flag.width;
	}
}

void	ftoa_e(t_pf_env *e, long double d, char type, int prec)
{
	char	*tmp;
	char	*nb;
	char	*expo;
	long	num;

	prec = (e->flag.prec >= 0 ? e->flag.prec : 6);
	if (d != 0)
	{
		num = get_prec_num_e(d, prec);
		nb = ft_ftoa(num);
		get_exponent(d, type, &expo);
	}
	else
	{
		expo = ft_strjoin(&type, "+00");
		num = 0;
		nb = ft_strdup("0000000");
	}
	tmp = (d < 0 ? ft_str_prec(nb, 2, prec + 1, e->flag.hash)
	: ft_str_prec(nb, 1, prec, e->flag.hash));
	e->out = ft_strjoin(tmp, expo);
	free(nb);
	free(tmp);
	free(expo);
}

void	ftoa_fg(t_pf_env *e, long double d, int end, long num)
{
	char	*tmp;
	char	*nb;
	int		prec;

	tmp = ft_ltoa((long)d);
	end -= ft_strlen(tmp) - 1;
	if (d == 0)
	{
		--e->flag.prec;
		--end;
	}
	prec = ft_strlen(tmp);
	num = get_prec_num_f(d, end);
	if (num == 0)
		nb = ft_strdup("0000000");
	else
		nb = ft_ftoa(num);
	if ((end <= prec || d == (long)d) && e->flag.hash == 0)
		e->out = ft_strdup(tmp);
	else
		e->out = ft_str_prec(nb, prec, end, 0);
	if (!e->flag.hash && d - (long)d != 0)
		delete_zero(e->out);
	free(tmp);
	free(nb);
}

void	ftoa_eg(t_pf_env *e, long double d, char type, int prec)
{
	char	*tmp;
	char	*nb;
	char	*expo;
	long	num;

	if (prec == 1)
		prec = 0;
	num = get_prec_num_e(d, prec);
	nb = ft_ftoa(num);
	get_exponent(d, type, &expo);
	if (d < 0)
		tmp = ft_str_prec(nb, 2, prec + 1, e->flag.hash);
	else
		tmp = ft_str_prec(nb, 1, prec, e->flag.hash);
	if (!e->flag.hash)
		delete_zero(tmp);
	e->out = ft_strjoin(tmp, expo);
	free(nb);
	free(tmp);
	free(expo);
}

void	ftoa_f(t_pf_env *e, long double d, long num)
{
	char	*tmp;
	char	*nb;
	int		prec;

	tmp = ft_ltoa((long)d);
	if (d == 0)
		--e->flag.prec;
	prec = ft_strlen(tmp);
	if (e->flag.prec >= 0)
		num = get_prec_num_f(d, e->flag.prec);
	else
		num = get_prec_num_f(d, 6);
	if (num == 0)
		nb = ft_strdup("0000000");
	else
		nb = ft_ftoa(num);
	if (e->flag.prec == 0 && e->flag.hash)
		e->out = ft_strjoin(tmp, ".");
	else if (e->flag.prec == 0 && !e->flag.hash)
		e->out = ft_strdup(tmp);
	else
		e->out = ft_str_prec(nb, prec, e->flag.prec >= 0 ?
		prec + e->flag.prec : prec + 6, e->flag.hash);
	free(nb);
	free(tmp);
}
