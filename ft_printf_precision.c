/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 00:13:20 by aarribas          #+#    #+#             */
/*   Updated: 2022/05/21 01:11:06 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prec_di(t_print *tab, char *str)
{
	int		prec;
	char	*temp;

	if (str == NULL)
		ft_special_cases(tab, str);
	prec = tab->prc;
	if (tab->wdt && !tab->dash)
		ft_right_cs(tab, tab->prc);
	if (ft_atoi(str) < 0)
	{
		temp = ft_strdup((const char *)str + 1);
		free(str);
		str = temp;
		tab->tl += write(1, "-", 1);
		tab->prc += 1;
	}
	while (prec > (int)ft_strlen(str))
	{
		tab->tl += write(1, "0", 1);
		prec--;
	}
	if (ft_atoi(str) != 0 || (ft_atoi(str) == 0 && tab->prc > 0))
	{
		ft_putstr_fd(str, 1);
		tab->tl += (int)ft_strlen(str);
	}
	if (tab->wdt && tab->dash && tab->wdt >= tab->prc)
		ft_left_cs(tab, tab->prc);
	free(str);
	return ;
}

void	ft_prec_u(t_print *tab, char *str)
{
	int	prec;

	if (str == NULL)
		ft_special_cases(tab, str);
	prec = tab->prc;
	if (tab->wdt && !tab->dash)
		ft_right_cs(tab, tab->prc);
	while (prec > (int)ft_strlen(str))
	{
		tab->tl += write(1, "0", 1);
		prec--;
	}
	if (ft_atoi(str) != 0 || (ft_atoi(str) == 0 && tab->prc > 0))
	{
		ft_putstr_fd(str, 1);
		tab->tl += (int)ft_strlen(str);
	}
	if (tab->wdt && tab->dash && tab->wdt >= tab->prc)
		ft_left_cs(tab, tab->prc);
	free(str);
	return ;
}

void	ft_prec_xX(t_print *tab, unsigned int hex, char format)
{
	int	prec;

	prec = tab->prc;
	if (tab->wdt && !tab->dash)
		ft_right_cs(tab, tab->prc);
	while (prec > ft_lenght_hex(tab, hex))
	{
		tab->tl += write(1, "0", 1);
		prec--;
	}
	if (hex != 0)
	{
		ft_format_hex(hex, format);
		tab->tl += ft_lenght_hex(tab, hex);
	}
	if (tab->wdt && tab->dash)
		ft_left_cs(tab, tab->prc);
	return ;
}

void	ft_prec_s(t_print *tab, char *str)
{
	int prec;
	int i;

	if (str == NULL)
	{
		ft_special_cases(tab, str);
		return ;
	}
	prec = tab->prc;
	if (tab->wdt && !tab->dash && tab->prc < (int)ft_strlen(str))
		ft_right_cs(tab, tab->prc);
	else
		ft_right_cs(tab, tab->wdt);
	i = 0;
	while (i < prec && str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	if (tab->wdt && tab->dash)
		ft_left_cs(tab, i);
	tab->tl += i;
	return ;
}