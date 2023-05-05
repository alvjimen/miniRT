/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:08:58 by alvjimen          #+#    #+#             */
/*   Updated: 2022/06/27 19:58:51 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*str;
	size_t	pos;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	pos = -1;
	str = ft_calloc(sizeof(char), len + 1);
	if (!str || (size_t) ft_strmapi == (size_t) f)
		return (NULL);
	while (s[++pos])
		str[pos] = f(pos, s[pos]);
	return (str);
}
