/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:35:54 by ashirzad          #+#    #+#             */
/*   Updated: 2024/04/16 10:54:20 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	execute_int(int n, t_obj *obj);
int	space_check_int(int s, int n, t_obj *obj);
int	zero_check_int(int s, int n, t_obj *obj);
int	plus_check_int(int n, t_obj *obj);
int	dash_check_int(t_obj *obj, int n);

int	execute_int(int n, t_obj *obj)
{
	int	i;
	int	count;
	int	s;

	s = sum_formula(obj);
	i = 0;
	count = 0;
	if (obj->space && (n >= 0))
		count += ft_putchar_fd(' ', 1);
	count += ft_print(space_check_int(s, n, obj), ' ');
	count += plus_check_int(n, obj);
	count += ft_print(zero_check_int(s, n, obj), '0');
	if (!((s == 11 || s == 111 || s == 10 \
		|| s == 14 || s == 15 || s == 110) && n == 0))
		count += ft_putnbr_fd(n, 1);
	count += ft_print(dash_check_char(obj, count), ' ');
	return (count);
}

int	space_check_int(int s, int n, t_obj *obj)
{
	int	s_n;
	int	len;

	s_n = 0;
	len = get_digits(n);
	if (obj->dot && !obj->per && n == 0)
		len = 0;
	if (s == 15 || s == 1 || s == 11)
		s_n = (obj->width - len);
	else if (s == 31 || s == 27)
	{
		if (obj->per >= len)
		{
			len = obj->per;
			if (n < 0)
				len += 1;
		}
		s_n = obj->width - len;
	}
	if (n >= 0)
		s_n = s_n - obj->space - obj->plus;
	return (s_n);
}

int	plus_check_int(int n, t_obj *obj)
{
	int	p_n;

	p_n = 0;
	if (obj->plus)
	{
		if (n >= 0)
			p_n += ft_putchar_fd('+', 1);
	}
	if (n < 0)
		p_n += ft_putchar_fd('-', 1);
	return (p_n);
}

int	zero_check_int(int s, int n, t_obj *obj)
{
	int	z_n;

	z_n = 0;
	if (s == 5)
	{
		if (n >= 0)
			z_n = (obj->width - get_digits(n)) - obj->space - obj->plus;
		else
			z_n = (obj->width - get_digits(n));
	}
	else if (obj->per)
	{
		if (n >= 0)
			z_n = obj->per - get_digits(n);
		else
			z_n = obj->per - (get_digits(n) - 1);
	}
	return (z_n);
}

int	dash_check_int(t_obj *obj, int n)
{
	int	d_n;

	d_n = 0;
	if (obj->dash)
		d_n = obj->width - n;
	return (d_n);
}
