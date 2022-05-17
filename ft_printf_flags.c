/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 00:12:24 by aarribas          #+#    #+#             */
/*   Updated: 2022/05/17 08:20:32 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_zero(t_print *tab, int len)
{
	int	nb_zero;

	if (tab->is_zero == 0)
		return ;
	nb_zero = tab->wdt;
	if (len > nb_zero)
	{
		tab->wdt = 0;
		return ;
	}
	else
		nb_zero -= len;
	tab->tl += nb_zero;
	while (nb_zero != 0)
	{
		write(1, "0", 1);
		nb_zero -= 1;
	}
	tab->wdt = 0;
	tab->is_zero = 0;
}

void	ft_print_sign(t_print *tab, int nb)
{
	if (tab->sign == 1 && nb > 0)
		write(1, "+", 1);
	tab->sign = 0;
}