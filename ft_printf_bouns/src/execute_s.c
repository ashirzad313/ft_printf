/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 11:33:09 by ashirzad          #+#    #+#             */
/*   Updated: 2024/04/16 11:09:56 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	execute_s(char *str, t_obj *obj);
int	space_check_s(int s, int n, t_obj *obj);
int	dot_check_s(int s, char *str, t_obj *obj);

int	execute_s(char *str, t_obj *obj)
{
	int	count;
	int	s;

	count = 0;
	s = sum_formula(obj);
	if (!s)
		return (ft_putstr_fd(str, 1));
	if (str == NULL)
		str = "(null)";
	count += ft_print(space_check_s(s, ft_strlen(str), obj), ' ');
	if (obj->dot)
		count += dot_check_s(s, str, obj);
	else
		count += ft_putstr_fd(str, 1);
	if (obj->dash)
		count += ft_print(obj->width - count, ' ');
	return (count);
}

int	space_check_s(int s, int n, t_obj *obj)
{
	int	s_n;

	s_n = 0;
	if (s == 1)
		s_n = (obj->width - n);
	else if (s == 27 || s == 11)
	{
		if (n == 0)
			s_n = (obj->width);
		else
		{
			if (obj->per < n)
				s_n = (obj->width - obj->per);
			else
				s_n = (obj->width - n);
		}
	}
	return (s_n);
}

int	dot_check_s(int s, char *str, t_obj *obj)
{
	int	s_n;
	int	i;

	s_n = 0;
	i = 0;
	if (s == 10)
		return (0);
	else if (obj->per)
	{
		while (*str && i < obj->per)
		{
			s_n += ft_putchar_fd(*str, 1);
			i++;
			str++;
		}
	}
	return (s_n);
}
