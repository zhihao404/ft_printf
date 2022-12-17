/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhihao <zhihao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:44:34 by zhihao            #+#    #+#             */
/*   Updated: 2022/12/17 18:37:00 by zhihao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *str, ...);
int	ft_printf_d_i_(int n);
int	ft_printf_p_(void *n, char *base);
int	ft_printf_s_(char *str);
int	ft_printf_u_(unsigned int n);
int	ft_printf_x_X_(unsigned int n, char *base);
int ft_print_percent(void);
char	*ft_itoa(int n);

#endif