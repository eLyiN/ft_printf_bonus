/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:45:58 by aarribas          #+#    #+#             */
/*   Updated: 2022/05/20 07:30:03 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unbrcount(unsigned int c)
{
	int	i;

	i = 0;
	if (c == 0)
		return (1);
	while (c > 0)
	{
		c = c / 10;
		i++;
	}
	return (i);
}

char	*ft_uitoa(unsigned int n)
{
	char	*fresh_str;
	int		i;

	i = ft_unbrcount(n);
	fresh_str = (char *)malloc(sizeof(char) * (i + 1));
	if (!fresh_str)
		return (NULL);
	if (n == 0)
	{
		fresh_str[0] = '0';
		fresh_str[1] = '\0';
		return (fresh_str);
	}
	fresh_str[i--] = '\0';
	while (n > 0)
	{
		fresh_str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (fresh_str);
}

void	process_wdt_p(t_print *tab, const char *format, int pos)
{
	int	nb;

	if (tab->pnt == 0)
	{
		nb = tab->wdt;
		nb = nb * 10 + (format[pos] - '0');
		tab->wdt = nb;
	}
	else if (tab->pnt == 1)
	{
		nb = tab->prc;
		nb = nb * 10 + (format[pos] - '0');
		tab->prc = nb;
	}
}

void	ft_sanitize_tab(t_print *tab)
{
	tab->wdt = 0;
	tab->prc = 0;
	tab->zero = 0;
	tab->pnt = 0;
	tab->sign = 0;
	tab->is_zero = 0;
	tab->dash = 0;
	tab->hash = 0;
	tab->sp = 0;
	tab->astk = 0;
}