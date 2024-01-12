/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisriver <lisriver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:46:46 by lisriver          #+#    #+#             */
/*   Updated: 2023/12/29 17:59:47 by lisriver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_length_hexadecimal(unsigned int num);

static void	ft_conver_dectohexa(unsigned int num, const char word);

int	ft_print_hexadecimal(unsigned int num, const char word)
{
	if (num == 0)
		return (ft_print_char('0'));
	else
		ft_conver_dectohexa(num, word);
	return (ft_length_hexadecimal(num));
}

static void	ft_conver_dectohexa(unsigned int num, const char word)
{
	if (num == 0)
		ft_print_char('0');
	else if (num >= 16)
	{
		ft_conver_dectohexa(num / 16, word);
		ft_conver_dectohexa(num % 16, word);
	}
	else
	{
		if (num < 10)
			ft_print_char(num + '0');
		else
		{
			if (word == 'x')
				ft_print_char(num - 10 + 'a');
			if (word == 'X')
				ft_print_char(num - 10 + 'A');
		}
	}
}

static int	ft_length_hexadecimal(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}
