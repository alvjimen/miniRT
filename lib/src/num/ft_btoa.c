/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:13:45 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/02 20:23:13 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "cmn.h"
#include "str.h"

static size_t	lenstr_of_base(unsigned long int nbr, size_t len)
{
	size_t	pos;

	pos = 1;
	while (nbr > len - 1)
	{
		nbr /= len;
		pos++;
	}
	return (++pos);
}

static void	ft_base(size_t n, char *base, size_t *pos, char *str)
{
	size_t	nb;
	size_t	len;

	len = ft_strlen(base);
	nb = n;
	if (nb > len - 1)
		ft_base(nb / len, base, pos, str);
	str[*pos] = base[nb % len];
	pos[0]++;
}

char	*ft_btoa(size_t n, char *base)
{
	char	*str;
	size_t	base_len;
	size_t	len;
	size_t	nbr;

	nbr = 0;
	if (!base)
		return (NULL);
	base_len = ft_strlen(base);
	len = lenstr_of_base(n, base_len);
	str = ft_calloc(sizeof(char), len);
	if (!str)
		return (NULL);
	ft_base(n, base, &nbr, str);
	return (str);
}
