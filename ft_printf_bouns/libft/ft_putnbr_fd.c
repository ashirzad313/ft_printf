/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:28:27 by ashirzad          #+#    #+#             */
/*   Updated: 2024/04/16 10:18:18 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	char	str[12];
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (n == 0)
		return (write(fd, "0", 1));
	if (n == -2147483648)
		return (write(fd, "2147483648", 10));
	if (n < 0)
		n *= -1;
	while (n)
	{
		str[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (i)
		count += write(fd, &str[--i], 1);
	return (count);
}
