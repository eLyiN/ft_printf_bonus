/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 08:47:24 by aarribas          #+#    #+#             */
/*   Updated: 2022/05/18 19:26:59 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

int	ft_ptr_len(uintptr_t num)
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

void	ft_put_ptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

int	ft_print_pointer(t_print *tab)
{
	int print_length;
	unsigned long long ptr;

	ptr = va_arg(tab->args, unsigned long long);
	print_length = 0;
	if (ptr == 0)
	{
		if (tab->wdt && !tab->dash)
			ft_right_cs(tab, 5);
		print_length += write(1, "(nil)", 5);
		if (tab->wdt && tab->dash)
			ft_left_cs(tab, 5);
		tab->tl += 5;
		return (1);
	}
	if (tab->wdt && !tab->dash)
		ft_right_cs(tab, ft_ptr_len(ptr) + 2);
	print_length += write(1, "0x", 2);
	ft_put_ptr(ptr);
	if (tab->wdt && tab->dash)
		ft_left_cs(tab, ft_ptr_len(ptr) + 2);
	print_length += ft_ptr_len(ptr);
	tab->tl += print_length;
	return (1);
}