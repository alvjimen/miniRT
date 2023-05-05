/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:32:35 by alvjimen          #+#    #+#             */
/*   Updated: 2023/01/30 20:26:33 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include "cmn.h"

static size_t	lenstr_of_base(unsigned long int nbr, size_t len)
{
	size_t				pos;

	pos = 1;
	while (nbr > len - 1)
	{
		nbr /= len;
		pos++;
	}
	return (++pos);
}

static void	ft_pointer(size_t n, size_t len, size_t *pos, char *str)
{
	if (n > len - 1)
		ft_pointer(n / len, len, pos, str);
	str[*pos] = "0123456789ABCDEF"[n % len];
	pos[0]++;
}

char	*ft_ptoa(size_t n)
{
	char	*str;
	size_t	len;
	size_t	nbr;

	nbr = 0;
	len = lenstr_of_base(n, 16) + 2;
	str = ft_calloc(sizeof(char), len);
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = 'x';
	ft_pointer(n, 16, &nbr, str + 2);
	return (str);
}
