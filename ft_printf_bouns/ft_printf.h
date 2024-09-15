/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 09:21:04 by ashirzad          #+#    #+#             */
/*   Updated: 2024/04/16 10:58:33 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <stddef.h>

typedef struct s_obj
{
	int	dash;
	int	plus;
	int	zero;
	int	dot;
	int	hash;
	int	space;
	int	width;
	int	per;
	int	type;
}	t_obj;

//main.c
int		ft_printf(const char *format, ...);

//ft_execute all formats
int		ft_execute(va_list args, t_obj *obj);

// create obj
void	create_obj(const char **format, t_obj *obj);
int		get_number(const char **format, t_obj *obj);

// execute_char
int		execute_char(char c, t_obj *obj);
int		space_check_char(int s, int n, t_obj *obj);
int		dash_check_char(t_obj *obj, int n);

//execute_hex
int		execute_hex(unsigned int n, t_obj *obj);
int		space_check_hex(int s, unsigned int n, t_obj *obj);
int		space_check_hex(int s, unsigned int n, t_obj *obj);
int		zero_check_hex(int s, unsigned int n, t_obj *obj);
int		hash_check_hex(unsigned int n, t_obj *obj);

//execute_int
int		execute_int(int n, t_obj *obj);
int		space_check_int(int s, int n, t_obj *obj);
int		zero_check_int(int s, int n, t_obj *obj);
int		plus_check_int(int n, t_obj *obj);
int		dash_check_int(t_obj *obj, int n);

//execute_p
int		execute_p(void *pointer, t_obj *obj);
int		space_check_p(int s, int n, t_obj *obj);
int		get_digits_p(void *ptr);

//execute_str
int		execute_s(char *str, t_obj *obj);
int		space_check_s(int s, int n, t_obj *obj);
int		dot_check_s(int s, char *str, t_obj *obj);

//execute_u
int		execute_u(unsigned int n, t_obj *obj);

//utils.c
int		sum_formula(t_obj *obj);
int		get_digits(int long long n);
int		ft_print(int n, int c);
int		ft_put_address(void *ptr);
int		hex_numbers(unsigned int n);

//hex.c
int		ft_print_hex(unsigned int nbr, char c);
int		ft_put_address(void *ptr);
int		convert_and_write_hex(char *str, unsigned long long nbr);
int		get_digits_u(unsigned int n);

//libft
int		ft_isalpha(int a);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_strlen(const char *str);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *str, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *str, int c);
void	*ft_memchr(void *str, int c, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strrchr(const char *str, int c);
void	*ft_memmove(void *dst, void *src, size_t len);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
int		ft_atoi(const char *str);
char	*ft_strdup(char *s1);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// part two
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_unsigned_nbr(unsigned int n);

#endif
