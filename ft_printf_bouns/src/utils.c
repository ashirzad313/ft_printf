/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 10:24:01 by ashirzad          #+#    #+#             */
/*   Updated: 2024/04/16 11:00:40 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	get_digits(int long long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

int	get_digits_u(unsigned int n)
{
	char	str[12];
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		str[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (i > 0)
	{
		i--;
		count++;
	}
	return (count);
}

int	sum_formula(t_obj *obj)
{
	int	count;

	count = 0;
	if (obj->width)
		count += 1;
	if (obj->zero)
		count += 4;
	if (obj->dot)
		count += 10;
	if (obj->per)
		count += 16;
	if (obj->dash)
		count += 100;
	return (count);
}

int	ft_print(int n, int c)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		count += ft_putchar_fd(c, 1);
		n--;
	}
	return (count);
}

int	hex_numbers(unsigned int n)
{
	int	count;

	count = 1;
	while (n / 16)
	{
		n /= 16;
		count++;
	}
	return (count);
}
