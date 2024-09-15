/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 10:03:47 by ashirzad          #+#    #+#             */
/*   Updated: 2024/04/16 09:39:01 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	execute_char(char c, t_obj *obj);
int	space_check_char(int s, int n, t_obj *obj);
int	dash_check_char(t_obj *obj, int n);

int	execute_char(char c, t_obj *obj)
{
	int	i;
	int	count;
	int	s;

	i = 0;
	count = 0;
	s = sum_formula(obj);
	count += ft_print(space_check_char(s, 1, obj), ' ');
	count += ft_putchar_fd(c, 1);
	count += ft_print(dash_check_char(obj, count), ' ');
	return (count);
}

int	space_check_char(int s, int n, t_obj *obj)
{
	int	s_n;

	s_n = 0;
	if (s == 1 || s == 11)
		s_n = obj->width - n;
	return (s_n);
}

int	dash_check_char(t_obj *obj, int n)
{
	int	d_n;

	d_n = 0;
	if (obj->dash)
		d_n = obj->width - n;
	return (d_n);
}
