/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 00:12:24 by aarribas          #+#    #+#             */
/*   Updated: 2022/05/20 07:53:36 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_zero(t_print *tab, char *str)
{
	int		nb_zero;
	char	*temp;

	nb_zero = tab->wdt;
	if ((int)ft_strlen(str) > nb_zero)
		return ;
	else
		nb_zero -= (int)ft_strlen(str);
	tab->tl += nb_zero;
	if (ft_atoi(str) < 0)
	{
		temp = ft_strdup((const char *)str + 1);
		free(str);
		str = temp;
		tab->tl += write(1, "-", 1);
	}
	while (nb_zero != 0)
	{
		write(1, "0", 1);
		nb_zero -= 1;
	}
	ft_putstr_fd(str, 1);
	tab->tl += (int)ft_strlen(str);
	free(str);
	return ;
}

void	ft_print_sign(t_print *tab, int nb)
{
	if (tab->sign == 1 && nb > 0)
	{
		write(1, "+", 1);
		tab->tl += 1;
		tab->sign = 0;
	}
}

void	ft_print_hash(t_print *tab, char format)
{
	if (tab->hash == 1)
	{
		if (format == 'x')
			write(1, "0x", 2);
		else if (format == 'X')
			write(1, "0X", 2);
	}
	tab->hash = 0;
}