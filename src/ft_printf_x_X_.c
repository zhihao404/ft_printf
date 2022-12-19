/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x_X_.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhihao <zhihao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:45:11 by zhihao            #+#    #+#             */
/*   Updated: 2022/12/20 00:56:09 by zhihao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	cnt_digit(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static char	*change_base(unsigned int nbr, char *base)
{
	int		nbr_2;
	char	*hex;

	nbr_2 = cnt_digit(nbr);
	hex = (char *)malloc(sizeof(char) * (nbr_2 + 1));
	if (!hex)
		return (NULL);
	hex[nbr_2] = '\0';
	while (nbr_2 > 0)
	{
		hex[nbr_2 - 1] = base[nbr % 16];
		nbr = nbr / 16;
		nbr_2--;
	}
	return (hex);
}

int	ft_printf_x_X_(unsigned int n, char *base)
{
	int		len;
	char	*str;

	str = change_base(n, base);
	len = ft_printf_s_(str);
	free(str);
	return (len);
}