/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 10:19:04 by ashirzad          #+#    #+#             */
/*   Updated: 2024/04/16 11:00:05 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	execute_u(unsigned int n, t_obj *obj);
int	space_check_u(int s, int n, t_obj *obj);
int	zero_check_u(int s, int n, t_obj *obj);

int	execute_u(unsigned int n, t_obj *obj)
{
	int	i;
	int	count;
	int	s;

	i = 0;
	count = 0;
	s = sum_formula(obj);
	if (!s)
		return (ft_unsigned_nbr(n));
	count += ft_print(space_check_u(s, n, obj), ' ');
	count += ft_print(zero_check_u(s, n, obj), '0');
	if (!((s == 11 || s == 111 || s == 10 \
		|| s == 14 || s == 15 || s == 110) && n == 0))
		count += ft_unsigned_nbr(n);
	if (obj->dash)
		count += ft_print(obj->width - count, ' ');
	return (count);
}

int	space_check_u(int s, int n, t_obj *obj)
{
	int	s_n;
	int	len;

	len = get_digits_u(n);
	if (obj->dot && !obj->per && n == 0)
		len = 0;
	s_n = 0;
	if (s == 11 && n == 0)
		s_n = obj->width;
	else if (s == 15 || s == 11 || s == 1)
		s_n = (obj->width - len) - obj->space;
	else if (s == 31 || s == 27)
	{
		if (obj->per >= len)
			s_n = (obj->width - obj->per) - obj->space;
		else
			s_n = (obj->width - len) - obj->space;
	}
	return (s_n);
}

int	zero_check_u(int s, int n, t_obj *obj)
{
	int	z_n;

	z_n = 0;
	if (s == 5)
		z_n = (obj->width - get_digits_u(n)) - obj->space;
	else if (obj->per)
		z_n = obj->per - get_digits_u(n);
	return (z_n);
}
