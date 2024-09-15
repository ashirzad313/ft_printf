/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 11:12:28 by ashirzad          #+#    #+#             */
/*   Updated: 2024/04/16 11:16:52 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	execute_p(void *pointer, t_obj *obj);
int	space_check_p(int s, int n, t_obj *obj);
int	get_digits_p(void *ptr);

int	execute_p(void *pointer, t_obj *obj)
{
	int		count;
	int		len;
	int		s;

	count = 0;
	s = sum_formula(obj);
	len = get_digits_p(pointer) + 2;
	if (!s)
		return (ft_put_address(pointer));
	count += ft_print(space_check_p(s, len, obj), ' ');
	count += ft_put_address(pointer);
	if (obj->dash)
		count += ft_print(obj->width - count, ' ');
	return (count);
}

int	space_check_p(int s, int n, t_obj *obj)
{
	int	s_n;

	s_n = 0;
	if (s == 15 || s == 11 || s == 1)
		s_n = (obj->width - n);
	else if (s == 31 || s == 27)
	{
		if (obj->per >= n)
			s_n = (obj->width - obj->per);
		else
			s_n = (obj->width - n);
	}
	return (s_n);
}

int	get_digits_p(void *ptr)
{
	unsigned int long long	n;
	int						count;

	count = 1;
	n = (unsigned int long long )ptr;
	while (n / 16)
	{
		n /= 16;
		count++;
	}
	return (count);
}
