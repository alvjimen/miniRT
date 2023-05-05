/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_flags_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro </var/spool/mail/alvaro>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:23:11 by alvaro            #+#    #+#             */
/*   Updated: 2022/08/16 18:47:24 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "prt.h"

void	ft_handle_flags(t_flags *flags, char **str)
{
	if (ft_is_flag(str) || *str[0] == '.')
		ft_fill_flags(flags, str);
}
