/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleite-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:19:40 by fleite-j          #+#    #+#             */
/*   Updated: 2025/02/13 17:19:42 by fleite-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	format_specifier(va_list arg, const char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += print_chr(va_arg(arg, int));
	else if (format == 's')
		count += print_str(va_arg(arg, char *));
	else if (format == 'p')
		count += print_ptr(va_arg(arg, void *));
	else if (format == 'i' || format == 'd')
		count += print_int(va_arg(arg, int));
	else if (format == 'u')
		count += print_uns_int(va_arg(arg, unsigned int));
	else if (format == 'x' || format == 'X')
		count += print_hex(va_arg(arg, unsigned int), format);
	else if (format == '%')
		count += write(1, "%", 1);
	else
		count += write(1, &format, 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	int		i;
	va_list	arg;

	if (!str)
		return (-1);
	va_start(arg, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && (ft_islower(str[i + 1])
				|| str[i + 1] == '%' || str[i + 1] == 'X'))
		{
			count += format_specifier(arg, str[i + 1]);
			i++;
		}
		else
			count += write(1, &str[i], 1);
		i++;
	}
	va_end(arg);
	return (count);
}
