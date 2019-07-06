/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 18:17:20 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/06 19:17:17 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../Libft/libft.h"
# include <wchar.h>
# include <limits.h>

# define INUM(i) (i >= '0' && i <= '9')
# define INUM1(i) (i >= '1' && i <= '9')
# define IPRSNT(i) (i == '%')
# define IINT(i) (i == 'd' || i == 'i')
# define IUINT(i) (i == 'u' || i == 'D' || i == 'U')
# define ICHR(i) (i == 'c' || i == 's')
# define ILCHR(i) (i == 'C' || i == 'S')
# define IPRC(i) (i == 'F' || i == 'A' || i == 'G'|| i == 'E')
# define ILPRC(i) (i == 'f' || i == 'a' || i == 'g'|| i == 'e')
# define IHEX(i) (i == 'b' || i == 'o' || i == 'x')
# define ILHEX(i) (i == 'B' || i == 'O' || i == 'X')
# define IN(i) (i == 'n')
# define I_FLAG " 0123456789Lhjltz#*+-."

typedef struct	s_pf_tag
{
	int			tag;
	int			pos;
}				t_pf_tag;

typedef struct	s_pf_flag
{
	int			sps;
	int			plus;
	int			neg;
	int			minus;
	int			hash;
	int			zero;
	int			prec;
	int			width;
}				t_pf_flag;

typedef enum	e_pf_mod
{
	pf_nomod = 0,
	pf_j,
	pf_z,
	pf_t,
	pf_h,
	pf_hh,
	pf_l,
	pf_ll,
	pf_L
}				t_pf_mod;

typedef	struct	s_pf_env
{
	va_list		ap[2];
	char		*out;
	int			fd;
	int			i;
	t_pf_tag	tag;
	t_pf_flag	flag;
	t_pf_mod	mod;
	int			ret;
}				t_pf_env;

int				ft_printf(const char *restrict fmt, ...);
void			start_fpf(const char *restrict fmt, t_pf_env *o);
void			parse_flags(const char *restrict fmt, t_pf_env *o);
void			init_env(t_pf_env *o);
void			init_flags(t_pf_flag *flag);
void			get_tags(const char *restrict fmt, t_pf_env *o);
void			get_prec(const char *restrict fmt, t_pf_env *o);
void			get_width(t_pf_env *o);
void			get_mods(const char *restrict fmt, t_pf_env *o);
void			get_specs(const char *restrict fmt, t_pf_env *o);
void			get_specs_01(const char *restrict fmt, t_pf_env *o);
void			init_char_arg(t_pf_env *o, int *tmp);
void			init_str_arg(t_pf_env *o, char **tmp);
void			init_int_arg(t_pf_env *o, long *tmp);
void			init_prec_arg(t_pf_env *o, double *tmp);
void			init_long_double(t_pf_env *o, long double *tmp);
void			init_wchar_arg(t_pf_env *o, wchar_t *tmp);
void			init_wstr_arg(t_pf_env *o, wchar_t **tmp);
void			spec_fd(t_pf_env *o);
void			spec_int(t_pf_env *o);
void			spec_unsint(t_pf_env *o, char type);
void			spec_char(t_pf_env *o, char type);
void			spec_wchar(t_pf_env *o, char type);
void			spec_precision(t_pf_env *o, char type);
void			spec_base(t_pf_env *o, char type);
void			spec_return(t_pf_env *o);
void			spec_ptraddr(t_pf_env *o, char type);
void			spec_non_printable(t_pf_env *o);
void			sp_percent(t_pf_env *o);
void			print_digit(t_pf_env *o);
void			print_digit_width(t_pf_env *o);
void			print_digit_sign(t_pf_env *o);
void			check_digit_sign(t_pf_env *o);
void			check_digit_prec(t_pf_env *o);
void			print_base(t_pf_env *o, char type, long val);
void			print_base_width(t_pf_env *o, char type);
void			print_base_pre(t_pf_env *o, char type, long val);
void			check_base_prec(t_pf_env *o, char type);
void			print_char(t_pf_env *o, char c);
void			print_null_char(t_pf_env *o);
void			print_char_width(t_pf_env *o);
void			print_str(t_pf_env *o);
void			print_null_str(t_pf_env *o);
void			print_str_width(t_pf_env *o);
void			print_wchar(t_pf_env *o, wchar_t wc);
void			print_wchar_minus(t_pf_env *o, wchar_t wc);
void			print_wstr(t_pf_env *o, wchar_t *wc);
void			print_wstr_minus(t_pf_env *o, wchar_t *wc, int len);
int				get_wstr_len(wchar_t *wc);
void			put_wstr(t_pf_env *o, wchar_t c);
void			put_wstr_c(t_pf_env *o, char c);
void			nan_inf(t_pf_env *o, char type, double var);
void			nan_inf_long(t_pf_env *o, char type, long double var);
void			print_prec_width(t_pf_env *o);
char			*ft_ftoa(long double d);
char			*ft_str_prec(char *s1, int dot, int end, int hash);
void			print_prec_a(t_pf_env *o, double d, char type);
void			print_prec_a_else(t_pf_env *o, double d, char type);
void			ftoa_prec_a(t_pf_env *o, double d, char type);
void			hex_prec(t_pf_env *o, double d, char **frac, char type);
void			get_a_expo(double d, char type, char **oxpo);
void			print_prec_e(t_pf_env *o, long double d, char type);
void			ftoa_prec_e(t_pf_env *o, long double d, char type);
long			get_prec_num_e(long double d, int prec);
void			get_exponent(long double d, char type, char **oxpo);
void			print_prec_f(t_pf_env *o, long double d);
void			ftoa_prec_f(t_pf_env *o, long double d);
long			get_prec_num_f(long double d, int prec);
void			print_prec_g(t_pf_env *o, long double d, char type);
void			check_form(t_pf_env *o, long double d, char type);
void			ftoa_prec_eg(t_pf_env *o, long double d, char type, int prec);
void			ftoa_prec_fg(t_pf_env *o, long double d, int end);
void			delete_zero(char *tmp);
void			print_ptraddr(t_pf_env *o, char type);
void			print_ptraddr_width(t_pf_env *o);
void			ptraddr_prec(t_pf_env *o);
void			print_invalid_spec(t_pf_env *o, char c);
void			print_invalid_width(t_pf_env *o);
void			print_non_printable(t_pf_env *o);
void			print_zero_to_ten(t_pf_env *o, char c);
void			print_ten_to_twenty(t_pf_env *o, char c);
void			print_twenty_to_thirty(t_pf_env *o, char c);
void			print_dice(t_pf_env *o);
void			check_set(const char *restrict fmt, t_pf_env *o);

#endif
