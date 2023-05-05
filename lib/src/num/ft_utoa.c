/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:14:08 by alvjimen          #+#    #+#             */
/*   Updated: 2022/09/22 17:35:02 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_uint_str(size_t n, size_t *pos, char *str)
{
	unsigned long int	nb;

	nb = n;
	if (nb > 9)
		ft_uint_str(nb / 10, pos, str);
	str[*pos] = nb % 10 + '0';
	pos[0]++;
}

static size_t	lenstr_of_uint(unsigned int n)
{
	long int	nbr;
	size_t		pos;

	nbr = n;
	pos = 1;
	while (nbr > 9)
	{
		nbr /= 10;
		pos++;
	}
	return (++pos);
}

char	*ft_utoa(unsigned int n)
{
	char	*str;
	size_t	len;
	size_t	nbr;

	nbr = 0;
	len = lenstr_of_uint(n);
	str = ft_calloc(sizeof(char), len);
	if (!str)
		return (NULL);
	ft_uint_str(n, &nbr, str);
	return (str);
}
