/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_str_flags_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:15:19 by alvaro            #+#    #+#             */
/*   Updated: 2023/10/02 20:23:13 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prt.h"

void	ft_add_to_str_flags(t_flags *flags)
{
	if (flags->flags & B_HASTAG)
		ft_memjoin_free_pf((void **)&flags->str, "#",
			ft_strlen_null(flags->str), 1);
	if (flags->flags & B_SPACE)
		ft_memjoin_free_pf((void **)&flags->str, " ",
			ft_strlen_null(flags->str), 1);
	if (flags->flags & B_PLUS)
		ft_memjoin_free_pf((void **)&flags->str, "+",
			ft_strlen_null(flags->str), 1);
	if (flags->flags & B_MINUS)
		ft_memjoin_free_pf((void **)&flags->str, "-",
			ft_strlen_null(flags->str), 1);
	if (flags->flags & B_ZERO)
		ft_memjoin_free_pf((void **)&flags->str, "0",
			ft_strlen_null(flags->str), 1);
	if (flags->flags & B_DOT)
		ft_memjoin_free_pf((void **)&flags->str, ".",
			ft_strlen_null(flags->str), 1);
}
