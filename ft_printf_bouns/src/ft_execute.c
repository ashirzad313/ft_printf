/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:31:44 by ashirzad          #+#    #+#             */
/*   Updated: 2024/04/16 11:00:19 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_execute(va_list args, t_obj *obj)
{
	int	count;

	count = 0;
	if (obj->type == 'd' || obj->type == 'i')
		count += execute_int(va_arg(args, int), obj);
	else if (obj->type == 'c' || obj->type == '%')
	{
		if (obj->type == '%')
			count += execute_char('%', obj);
		else
			count += execute_char(va_arg(args, int), obj);
	}
	else if (obj->type == 'u')
		count += execute_u(va_arg(args, unsigned int), obj);
	else if (obj->type == 'x' || obj->type == 'X')
		count += execute_hex(va_arg(args, unsigned int), obj);
	else if (obj->type == 'p')
		count += execute_p(va_arg(args, void *), obj);
	else if (obj->type == 's')
		count += execute_s(va_arg(args, char *), obj);
	return (count);
}
