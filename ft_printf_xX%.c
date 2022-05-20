/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xX%.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:50:14 by aarribas          #+#    #+#             */
/*   Updated: 2022/05/19 21:38:22 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lenght_hex(t_print *tab, unsigned int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb = nb / 16;
	}
	if (tab->hash == 1)
		len = len + 2;
	if (tab->hash == 1 && tab->sign == 1)
		len = len + 4;
	return (len);
}

void	ft_format_hex(unsigned int nb, char format)
{
	if (nb >= 16)
	{
		ft_format_hex(nb / 16, format);
		ft_format_hex(nb % 16, format);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd((nb + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((nb - 10 + 'a'), 1);
			if (format == 'X')
				ft_putchar_fd((nb - 10 + 'A'), 1);
		}
	}
}

int	ft_print_hex(t_print *tab, char format)
{
	unsigned int	nb;

	nb = va_arg(tab->args, unsigned int);
	if (tab->pnt == 1 && tab->prc >= ft_lenght_hex(tab, nb))
	{
		ft_prec_xX(tab, nb, format);
		return (1);
	}
	if (nb == 0)
	{
		if (tab->wdt && !tab->dash)
			ft_right_cs(tab, 1);
		tab->tl += write(1, "0", 1);
		if (tab->wdt && tab->dash)
			ft_left_cs(tab, 1);
		return (1);
	}
	else if (tab->wdt && !tab->dash)
		ft_right_cs(tab, ft_lenght_hex(tab, nb));
	ft_print_hash(tab, format);
	ft_format_hex(nb, format);
	tab->tl += ft_lenght_hex(tab, nb);
	if (tab->wdt && tab->dash)
		ft_left_cs(tab, ft_lenght_hex(tab, nb));
	return (1);
}

int	ft_print_procent(t_print *tab)
{
	tab->tl += write(1, "%", 1);
	return (1);
}
