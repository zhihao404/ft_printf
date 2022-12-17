/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhihao <zhihao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:19:39 by zhihao            #+#    #+#             */
/*   Updated: 2022/12/17 16:24:44 by zhihao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_value(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	get_len(int n)
{
	int	len;

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

char	*ft_itoa(int n)
{
	char	*out;
	int		len;

	len = get_len(n);
	out = malloc((len + 1) * sizeof(char));
	if (!out)
		return (NULL);
	out[len] = '\0';
	len--;
	if (n < 0)
		out[0] = '-';
	if (n == 0)
		out[0] = '0';
	while (n != '\0')
	{
		out[len] = get_value(n % 10) + '0';
		len--;
		n = n / 10;
	}
	return (out);
}
