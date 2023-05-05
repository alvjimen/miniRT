/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_accuracy_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro </var/spool/mail/alvaro>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 10:43:51 by alvaro            #+#    #+#             */
/*   Updated: 2022/09/12 17:44:31 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "prt.h"

ssize_t	ft_accuracy(t_flags *flags)
{
	ssize_t			count;

	count = 0;
	while (count < flags->accuracy)
		count += write(1, "0", 1);
	flags->accuracy = 0;
	return (count);
}
