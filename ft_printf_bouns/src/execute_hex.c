/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 10:28:22 by ashirzad          #+#    #+#             */
/*   Updated: 2024/04/16 10:53:55 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	execute_hex(unsigned int n, t_obj *obj);
int	space_check_hex(int s, unsigned int n, t_obj *obj);
int	space_check_hex(int s, unsigned int n, t_obj *obj);
int	zero_check_hex(int s, unsigned int n, t_obj *obj);
int	hash_check_hex(unsigned int n, t_obj *obj);

int	execute_hex(unsigned int n, t_obj *obj)
{
	int	count;
	int	s;

	count = 0;
	s = sum_formula(obj);
	count += ft_print(space_check_hex(s, n, obj), ' ');
	count += hash_check_hex(n, obj);
	count += ft_print(zero_check_hex(s, n, obj), '0');
	if ((s == 11 || s == 111 || s == 10 \
		|| s == 14 || s == 15 || s == 110) && n == 0)
		count += 0;
	else
		count += ft_print_hex(n, obj->type);
	if (obj->dash)
		count += ft_print(obj->width - count, ' ');
	return (count);
}

int	space_check_hex(int s, unsigned int n, t_obj *obj)
{
	int	s_n;
	int	len;

	s_n = 0;
	len = hex_numbers(n);
	if (obj->dot && !obj->per && n == 0)
		len = 0;
	if (n == 0)
		obj->hash = 0;
	if (s == 15 || s == 11 || s == 1)
		s_n = (obj->width - len) - obj->hash;
	else if (s == 31 || s == 27)
	{
		if (obj->per >= len)
			s_n = (obj->width - obj->per) - obj->hash;
		else
			s_n = (obj->width - len) - obj->hash;
	}
	return (s_n);
}

int	zero_check_hex(int s, unsigned int n, t_obj *obj)
{
	int	z_n;

	z_n = 0;
	if (s == 5)
		z_n = (obj->width - hex_numbers(n)) - obj->hash;
	else if (obj->per)
		z_n = obj->per - hex_numbers(n);
	return (z_n);
}

int	hash_check_hex(unsigned int n, t_obj *obj)
{
	int	h_n;

	h_n = 0;
	if (n == 0)
		return (0);
	if (obj->hash)
	{
		if (obj->type == 'x')
			h_n += ft_putstr_fd("0x", 1);
		else
			h_n += ft_putstr_fd("0X", 1);
	}
	return (h_n);
}
