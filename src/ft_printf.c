/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhihao <zhihao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:42:03 by zhihao            #+#    #+#             */
/*   Updated: 2022/12/20 00:56:18 by zhihao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static char	*ft_strchr(const char *s, int c)
{
	unsigned char	*str;
	int				i;

	c = (unsigned char)c;
	str = (unsigned char *)s;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == '\0' && c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

static int	ft_formats(va_list args, const char *format, int i)
{
	if (format[i + 1] == 'c')
		return(ft_putchar(va_arg(args, int)));
	else if (format[i + 1] == 's')
		return(ft_printf_s_(va_arg(args, char *)));
	else if (format[i + 1] == 'p')
		return(ft_printf_p_(va_arg(args, void *), "0123456789abcdef"));
	else if (format[i + 1] == 'd' || format[i + 1] == 'i')
		return(ft_printf_d_i_(va_arg(args, int)));
	else if (format[i + 1] == 'u')
		return(ft_printf_u_(va_arg(args, unsigned int)));
	else if (format[i + 1] == 'x')
		return(ft_printf_x_X_(va_arg(args, int), "0123456789abcdef"));
	else if (format[i + 1] == 'X')
		return(ft_printf_x_X_(va_arg(args, int), "0123456789ABCDEF"));
	else if (format[i + 1] == '%')
		return(ft_print_percent());
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		i;
	
	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX%", str[i + 1]))
		{
			len += ft_formats(args, str, i);
			i++;
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
