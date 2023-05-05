/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:23:44 by alvjimen          #+#    #+#             */
/*   Updated: 2022/06/27 19:28:09 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lens;
	size_t	lend;
	size_t	dif;

	lens = ft_strlen(src);
	lend = ft_strlen((const char *) dst);
	if (dstsize < lend)
		return (lens + dstsize);
	if (!dstsize)
		return (lens);
	dif = dstsize - lend;
	dst = dst + lend;
	while (*(src) && dif > 1)
	{
		*(dst) = *(src);
		src++;
		dst++;
		dif--;
	}
	*dst = '\0';
	return (lend + lens);
}
