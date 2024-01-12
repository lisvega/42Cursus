/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisriver <lisriver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:39:10 by lisriver          #+#    #+#             */
/*   Updated: 2023/12/29 17:59:19 by lisriver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_length_pointer(unsigned long long ptr);
void	ft_conver_pointer(unsigned long long ptr);

int	ft_print_pointer(unsigned long long ptr)
{
	int	size;

	size = 0;
	size += ft_print_string("0x");
	if (ptr == 0)
		size += ft_print_char('0');
	else
	{
		ft_conver_pointer(ptr);
		size += ft_length_pointer(ptr);
	}
	return (size);
}

int	ft_length_pointer(unsigned long long ptr)
{
	int	len;

	len = 0;
	while (ptr > 0)
	{
		len++;
		ptr /= 16;
	}
	return (len);
}

void	ft_conver_pointer(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		ft_conver_pointer(ptr / 16);
		ft_conver_pointer(ptr % 16);
	}
	else
	{
		if (ptr < 10)
			ft_print_char(ptr + '0');
		else
		{
			ft_print_char(ptr - 10 + 'a');
		}
	}
}
