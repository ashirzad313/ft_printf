/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:33:12 by ashirzad          #+#    #+#             */
/*   Updated: 2024/04/06 12:18:33 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*get;

	get = 0;
	while (*str)
	{
		if (*str == (char) c)
		{
			get = (char *)str;
		}
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (get);
}
