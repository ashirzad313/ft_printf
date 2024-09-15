/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:15:38 by ashirzad          #+#    #+#             */
/*   Updated: 2024/04/16 11:01:09 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	n;

	n = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (*s)
	{
		n += write(fd, s, 1);
		s++;
	}
	return (n);
}
