/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_pf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:51:45 by alvaro            #+#    #+#             */
/*   Updated: 2023/10/02 20:23:13 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prt.h"

int	ft_atoi_pf(char **str, t_flags *flags)
{
	int	n;
	int	n_bk;
	int	len_n;

	n = ft_atoi((const char *)str[0]);
	n_bk = n;
	len_n = 0;
	while (n_bk / 10)
	{
		len_n++;
		n_bk /= 10;
	}
	flags->str = ft_memjoin_free_pf((void **)&flags->str, (void *)*str,
			ft_strlen_null(flags->str), len_n + 1);
	while (*str[0] >= '0' && *str[0] <= '9')
		str[0]++;
	return (n);
}
