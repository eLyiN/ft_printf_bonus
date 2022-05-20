/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:50:44 by aarribas          #+#    #+#             */
/*   Updated: 2022/05/20 07:30:01 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(t_print *tab)
{
	char	c;

	c = va_arg(tab->args, int);
	if (tab->wdt && !tab->dash)
		ft_right_cs(tab, 1);
	tab->tl += write(1, &c, 1);
	if (tab->wdt && tab->dash)
		ft_left_cs(tab, 1);
	return (1);
}

int	ft_print_string(t_print *tab)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	str = va_arg(tab->args, char *);
	if (tab->pnt == 1)
	{
		ft_prec_s(tab, str);
		return (1);
	}
	if (str)
		len = ft_strlen((char *)str);
	if (tab->wdt && !tab->dash && str != NULL)
		ft_right_cs(tab, len);
	if (str == NULL)
	{
		ft_special_cases(tab, str);
		return (1);
	}
	while (str[i] && str != NULL)
		write(1, &str[i++], 1);
	if (tab->wdt && tab->dash && str != NULL)
		ft_left_cs(tab, len);
	tab->tl += i;
	return (1);
}

void	ft_special_cases(t_print *tab, char *str)
{
	if (str == NULL && tab->pnt == 0)
	{
		if (tab->wdt && !tab->dash)
			ft_right_cs(tab, 6);
		write(1, "(null)", 6);
		if (tab->wdt && tab->dash)
			ft_left_cs(tab, 6);
		tab->tl += 6;
	}
	else if (str == NULL && tab->pnt == 1 && tab->prc >= 6)
	{
		if (tab->wdt && !tab->dash)
			ft_right_cs(tab, 6);
		write(1, "(null)", 6);
		if (tab->wdt && tab->dash)
			ft_left_cs(tab, 6);
		tab->tl += 6;
		tab->prc = 0;
		tab->pnt = 0;
	}
	else if ((str == NULL && tab->prc < 6))
		return ;
}