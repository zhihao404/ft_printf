/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u_.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhihao <zhihao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:45:06 by zhihao            #+#    #+#             */
/*   Updated: 2022/12/17 17:14:05 by zhihao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_len(unsigned int n)
{
	unsigned int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != '\0')
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static char	*ft_utoa(unsigned int n)
{
	char			*str;
	unsigned int	len;

	len = get_len(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	if (n == 0)
		str[0] = '0';
	while (n != '\0')
	{
		str[len] = (n % 10) + '0';
		len--;
		n = n / 10;
	}
	return (str);
}

int	ft_printf_u_(unsigned int n)
{
	int		len;
	char	*str;

	str = ft_utoa(n);
	len = ft_printf_s_(str);
	free(str);
	return (len);
}
