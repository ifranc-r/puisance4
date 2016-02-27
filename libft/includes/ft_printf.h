/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmerlot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 13:50:00 by qmerlot           #+#    #+#             */
/*   Updated: 2016/02/10 18:39:36 by qmerlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <wchar.h>
# include "libft.h"

typedef struct	s_flags
{
	int			hash;
	int			zero;
	int			neg;
	int			space;
	int			plus;
	int			field;
	int			preci;
	int			h;
	int			hh;
	int			l;
	int			ll;
	int			j;
	int			z;
	int			disneg;
	int			modifok;
	int			dec;
	int			uns;
	int			sc;
	int			c;
	int			p;
	int			strlen;
	int			isnull;
}				t_flags;

int				ft_printf(const char *restrict format, ...);

int				ft_count_c(int n);
void			ft_putchar_c(int c);
void			ft_putstr_c(char *s);
void			ft_putstr_cc(char *s, int len);

char			*ft_itoa_ll(long long value, t_flags *flags);
char			*ft_itoa_u_base(unsigned long long value, int base, int upcase,
								t_flags *flags);
int				ft_get_base_b(char c);
int				ft_abs(int i);

const char		*ft_check_conversion(const char *format, va_list ap);

const char		*ft_check_flags(const char *format, t_flags *flags);
const char		*ft_check_field(const char *format, t_flags *flags);
const char		*ft_check_preci(const char *format, t_flags *flags);
const char		*ft_check_modif(const char *format, t_flags *flags);

void			ft_do_conversion(char c, t_flags *flags, va_list ap);
void			ft_conversion_s(char c, t_flags *flags, va_list ap);
void			ft_conversion_d(char c, t_flags *flags, va_list ap);
void			ft_conversion_b(char c, t_flags *flags, va_list ap);
void			ft_conversion_w(char c, t_flags *flags, va_list ap);

char			*ft_hexa(char *ptr, t_flags *flags, int diff, char c);
char			*ft_fdif(char *ptr, int diff, t_flags *flags);

void			ft_putcharw_c(unsigned int c);
void			ft_putstrw_c(wchar_t *s);
void			ft_putstrw_cc(wchar_t *s, t_flags *flags);
void			ft_putstrwlen_c(wchar_t *s, int len);
size_t			ft_strlenw(wchar_t *s);

#endif
