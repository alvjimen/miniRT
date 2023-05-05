/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_flags_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro </var/spool/mail/alvaro>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:33:03 by alvaro            #+#    #+#             */
/*   Updated: 2022/09/14 17:43:44 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "prt.h"

static void	ft_getflags(t_flags *flags, char **str)
{
	while (ft_is_flag(str) && !(*str[0] > '0' && *str[0] <= '9'))
	{
		if (*str[0] == '#' && !(flags->flags & B_HASTAG))
			flags->flags += B_HASTAG;
		else if (*str[0] == ' ' && !(flags->flags & B_SPACE))
			flags->flags += B_SPACE;
		else if (*str[0] == '+' && !(flags->flags & B_PLUS))
			flags->flags += B_PLUS;
		else if (*str[0] == '-' && !(flags->flags & B_MINUS))
			flags->flags += B_MINUS;
		else if (ft_fill_flags_zero(str, flags))
			flags->flags += B_ZERO;
		str[0]++;
	}
}

void	ft_fill_flags(t_flags *flags, char **str)
{
	ft_getflags(flags, str);
	ft_fix_flags(flags, *str);
	ft_add_to_str_flags(flags);
	if (*str[0] > '0' && *str[0] <= '9')
		flags->width = ft_atoi_pf(str, flags);
	if (*str[0] == '.' && !(flags->flags & B_DOT))
	{
		flags->flags += B_DOT;
		ft_memjoin_free_pf((void **)&flags->str, (void *)".",
			ft_strlen_null(flags->str), 1);
		str[0]++;
		if (*str[0] >= '0' && *str[0] <= '9')
			flags->accuracy = ft_atoi_pf(str, flags);
		else
			ft_memjoin_free_pf((void **)&flags->str, (void *)"0",
				ft_strlen_null(flags->str), 1);
	}
	ft_fix_flags(flags, *str);
}
