/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:32:45 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/02 20:23:13 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prt.h"

static void	ft_conversion_char(char **str, t_flags *flags, va_list args,
	ssize_t *count)
{
	flags->str = ft_memjoin_free_pf((void **)&flags->str, (void *)*str,
			ft_strlen_null(flags->str), 1);
	if (*str[0] == '%')
		*count += write(1, str[0], 1);
	else if (*str[0] == 'c')
		*count += ft_putchar_pf((char) va_arg(args, int), flags);
	else if (*str[0] == 's')
		*count += ft_putstr_pf(va_arg(args, void *), flags);
	else if (*str[0] == 'p')
		*count += ft_putpointer_pf(va_arg(args, size_t), flags);
	else if (*str[0] == 'd' || *str[0] == 'i')
		*count += ft_putdigit(va_arg(args, int), flags);
	else if (*str[0] == 'u')
		*count += ft_putuint(va_arg(args, unsigned int), DEC, flags);
	else if (*str[0] == 'x')
		*count += ft_puthex_pf(va_arg(args, unsigned int), flags, HEX_L);
	else if (*str[0] == 'X')
		*count += ft_puthex_pf(va_arg(args, unsigned int), flags, HEX_U);
	else
		*count += ft_printf("%s", flags->str);
}

void	ft_conversion(char **str, va_list args, ssize_t *count)
{
	t_flags	*flags;

	flags = ft_calloc(1, sizeof(t_flags));
	if (!flags)
		return ;
	flags->str = ft_memjoin_free_pf((void **)&flags->str, (void *)*str,
			0, 1);
	str[0]++;
	ft_handle_flags(flags, str);
	ft_conversion_char(str, flags, args, count);
	ft_free_struct((void *)flags, ft_free_t_flags);
}
