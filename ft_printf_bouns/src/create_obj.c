/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:20:09 by ashirzad          #+#    #+#             */
/*   Updated: 2024/04/16 10:49:52 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	create_obj(const char **format, t_obj *obj);
int		get_number(const char **format, t_obj *obj);

void	create_obj(const char **format, t_obj *obj)
{
	ft_memset(obj, 0, sizeof(t_obj));
	while (*(*format))
	{
		if (*(*format) == '-')
			obj->dash = 1;
		else if (*(*format) == '+')
			obj->plus = 1;
		else if (*(*format) == '0')
			obj->zero = 1;
		else if (*(*format) == '#')
			obj->hash = 2;
		else if (*(*format) == ' ')
			obj->space = 1;
		else if (*(*format) >= '1' && *(*format) <= '9')
			obj->width = get_number(format, obj);
		if (*(*format) == '.')
			obj->per = get_number(format, obj);
		if (ft_isalpha(*(*format)) || *(*format) == '%')
		{
			obj->type = *(*format);
			return ;
		}
		(*format)++;
	}
}

int	get_number(const char **format, t_obj *obj)
{
	int	i;

	i = 0;
	if (*(*format) == '.')
	{
		obj->dot = 1;
		(*format)++;
	}
	while (*(*format) >= '0' && *(*format) <= '9')
	{
		i = (i * 10) + (*(*format) - 48);
		(*format)++;
	}
	return (i);
}
