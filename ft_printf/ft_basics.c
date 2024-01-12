/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basics.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisriver <lisriver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:36:31 by lisriver          #+#    #+#             */
/*   Updated: 2023/12/29 17:05:50 by lisriver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...);

int	ft_print_char(int character)
{
	return (write(1, &character, sizeof(char)));
}

int	ft_print_string(char *str)
{
	int	size;

	size = 0;
	if (!str)
		str = "(null)";
	while (*str)
	{
		size += ft_print_char(*str);
		str++;
	}
	return (size);
}

int	ft_print_nbr(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		size += ft_print_char('0');
	if (n == -2147483648)
	{
		size += ft_print_string("-2147483648");
		return (size);
	}
	if (n < 0)
	{
		size += ft_print_char('-');
		n = -n;
	}
	if (n > 0)
		size += ft_print_unsigned((unsigned int)n);
	return (size);
}

int	ft_print_unsigned(unsigned int n)
{
	int	size;

	size = 0;
	if (n == 0)
		size += ft_print_char('0');
	else
	{
		if (n / 10 != 0)
			size += ft_print_unsigned(n / 10);
		ft_print_char((n % 10) + '0');
		size++;
	}
	return (size);
}
