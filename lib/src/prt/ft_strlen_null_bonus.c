/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_null_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro </var/spool/mail/alvaro>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:34:21 by alvaro            #+#    #+#             */
/*   Updated: 2022/08/17 16:43:30 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "prt.h"

size_t	ft_strlen_null(char *str)
{
	char	*tmp;

	tmp = str;
	if (!str)
		return (0);
	while (*str)
		str++;
	return (str - tmp);
}
