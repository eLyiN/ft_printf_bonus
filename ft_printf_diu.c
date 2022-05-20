/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_diu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:49:37 by aarribas          #+#    #+#             */
/*   Updated: 2022/05/21 01:18:02 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s_integer(t_print *tab) //d & i
{
	int nb;
	char *str;

	nb = va_arg(tab->args, int);
	str = ft_itoa(nb);
	if (tab->pnt == 1 && tab->prc >= (int)ft_strlen(str))
	{
		ft_prec_di(tab, str);
		return (1);
	}
	if (tab->is_zero == 1)
	{
		ft_flag_zero(tab, str);
		return (1);
	}

	if (tab->wdt && !tab->dash)
		ft_right_cs(tab, ft_strlen(str));
	ft_print_sign(tab, nb);
	if (!(nb == 0 && tab->prc == 0 && tab->pnt == 1))
	{
		ft_putstr_fd(str, 1);
		tab->tl += (int)ft_strlen(str);
	}
	if ((tab->wdt && tab->dash && !tab->pnt) || (tab->pnt == 1 && nb != 0))
		ft_left_cs(tab, ft_strlen(str));
	else if (tab->wdt && tab->dash && tab->pnt && nb == 0)
		ft_left_cs(tab, 0);
	free(str);
	return (1);
}

int	ft_print_u_integer(t_print *tab)
{
	unsigned int	nb;
	char			*str;

	nb = va_arg(tab->args, unsigned int);
	str = ft_uitoa(nb);
	if (tab->pnt == 1 && tab->prc >= (int)ft_strlen(str))
	{
		ft_prec_u(tab, str);
		return (1);
	}
	if (tab->wdt && !tab->dash)
		ft_right_cs(tab, ft_strlen(str));
	if (str == NULL)
	{
		tab->tl += write(1, "0", 1);
		return (1);
	}
	ft_print_sign(tab, nb);
	if (!(nb == 0 && tab->prc == 0 && tab->pnt == 1))
	{
		ft_putstr_fd(str, 1);
		tab->tl += (int)ft_strlen(str);
	}
	if ((tab->wdt && tab->dash && !tab->pnt) || (tab->pnt == 1 && nb != 0))
		ft_left_cs(tab, ft_strlen(str));
	else if (tab->wdt && tab->dash && tab->pnt && nb == 0)
		ft_left_cs(tab, 0);
	free(str);
	return (1);
}
