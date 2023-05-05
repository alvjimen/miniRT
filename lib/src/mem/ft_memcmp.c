/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:29:41 by alvjimen          #+#    #+#             */
/*   Updated: 2022/06/27 19:47:47 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			count;
	int				dif;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	count = 0;
	dif = 0;
	while (count < n && !dif)
	{
		dif = str1[count] - str2[count];
		count++;
	}
	return (dif);
}
