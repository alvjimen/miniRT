/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_is_digit_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 10:51:20 by alvaro            #+#    #+#             */
/*   Updated: 2023/10/02 20:23:13 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prt.h"

int	ft_flags_is_digit(t_flags *flags, char *str)
{
	return (*str == 'd' || *str == 'i' || *str == 'u'
		|| *str == 'x' || *str == 'X' || *str == 'p' || *str == 'o' || !flags);
}
