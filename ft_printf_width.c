/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:00:17 by aarribas          #+#    #+#             */
/*   Updated: 2022/05/17 16:08:17 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_right_cs(t_print *tab, int len)
{
	int	wdt_right;

	wdt_right = tab->wdt;
	if (len > wdt_right)
	{
		tab->wdt = 0;
		return ;
	}
	else
		wdt_right -= len;
	tab->tl += wdt_right;
	ft_flag_zero(tab, len);
	while (wdt_right != 0 && tab->is_zero == 0)
	{
		write(1, " ", 1);
		wdt_right -= 1;
	}
	tab->wdt = 0;
}

void	ft_left_cs(t_print *tab, int len)
{
	int	wdt_left;

	wdt_left = tab->wdt;
	if (len > wdt_left)
	{
		tab->wdt = 0;
		tab->dash = 0;
		return ;
	}
	else
		wdt_left -= len;
	tab->tl += wdt_left;
	while (wdt_left != 0 && tab->is_zero == 0)
	{
		write(1, " ", 1);
		wdt_left -= 1;
	}
	tab->wdt = 0;
	tab->dash = 0;
}

void	ft_asterisk(t_print *tab)
{
	int nb;
	nb = va_arg(tab->args, int);

	if (nb == 0)
		return ;
	else if (tab->pnt == 0)
	{
		if (nb > 0)
		{
			tab->wdt = nb;
		}
		else if (nb < 0)
		{
			tab->wdt = nb * -1;
			tab->dash = 1;
		}
	}
}