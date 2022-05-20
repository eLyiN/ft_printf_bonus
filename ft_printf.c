/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:51:58 by aarribas          #+#    #+#             */
/*   Updated: 2022/05/20 07:50:53 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	*ft_initialise_tab(t_print *tab)
{
	tab->wdt = 0;
	tab->prc = 0;
	tab->zero = 0;
	tab->pnt = 0;
	tab->sign = 0;
	tab->tl = 0;
	tab->is_zero = 0;
	tab->dash = 0;
	tab->hash = 0;
	tab->sp = 0;
	tab->astk = 0;
	return (tab);
}

int	ft_printf(const char *format, ...)
{
	t_print	*tab;
	int		i;
	int		ret;

	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	tab = ft_initialise_tab(tab);
	va_start(tab->args, format);
	i = 0;
	ret = 0;
	while (format[i])
	{
		if (format[i] == '%')
			i = ft_control_formats(tab, format, i);
		else
			ret += write(1, &format[i], 1);
		i++;
	}
	va_end(tab->args);
	ret += tab->tl;
	free(tab);
	return (ret);
}

int	ft_control_formats(t_print *tab, const char *format, int pos)
{
	int	i;

	i = pos;
	i++;
	if (ft_strchr(SYMBOLS, format[i]))
		i = ft_set_flags(tab, format, i);
	i = ft_eval_format(tab, format, i);
	ft_sanitize_tab(tab);
	return (i);
}

int	ft_eval_format(t_print *tab, const char *format, int pos)
{
	if (format[pos] == 'c')
		ft_print_char(tab);
	else if (format[pos] == 's')
		ft_print_string(tab);
	else if (format[pos] == 'p')
		ft_print_pointer(tab);
	else if (format[pos] == 'd' || format[pos] == 'i')
		ft_print_s_integer(tab);
	else if (format[pos] == 'u')
		ft_print_u_integer(tab);
	else if (format[pos] == 'x' || format[pos] == 'X')
		ft_print_hex(tab, format[pos]);
	else if (format[pos] == '%')
		ft_print_procent(tab);
	return (pos);
}

int	ft_set_flags(t_print *tab, const char *format, int pos)
{
	if (format[pos] == '0')
	{
		tab->is_zero = 1;
		pos++;
	}
	while (!ft_strchr("cspdiuxX%", format[pos]))
	{
		if (format[pos] == '-')
			tab->dash = 1;
		if (format[pos] == '.')
			tab->pnt = 1;
		if (format[pos] == '#')
			tab->hash = 1;
		if (format[pos] == ' ')
			tab->sp = 1;
		if (format[pos] == '+')
			tab->sign = 1;
		if (format[pos] == '*')
			ft_asterisk(tab);
		if (ft_strchr("0123456789", format[pos]))
			process_wdt_p(tab, format, pos);
		pos++;
	}
	return (pos);
}
