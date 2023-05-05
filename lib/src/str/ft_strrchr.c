/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 10:00:43 by alvjimen          #+#    #+#             */
/*   Updated: 2022/06/21 10:03:14 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	count;

	count = ft_strlen(s);
	while (((unsigned char *)s)[count] != (unsigned char)c && count)
		count--;
	if (((unsigned char *)s)[count] != (unsigned char)c)
		return (NULL);
	return ((char *)s + count);
}
