/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:55:38 by ashirzad          #+#    #+#             */
/*   Updated: 2024/04/06 12:17:34 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			count;
	unsigned char	*d_str;
	unsigned char	*s_str;

	d_str = (unsigned char *)dst;
	s_str = (unsigned char *)src;
	count = 0;
	if (src == dst)
		return (NULL);
	while (count < n)
	{
		d_str[count] = s_str[count];
		count++;
	}
	return (d_str);
}
