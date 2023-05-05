/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:15:47 by alvjimen          #+#    #+#             */
/*   Updated: 2022/06/24 13:19:49 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strtrim_left(char const *s1, char const *set)
{
	size_t	count_s1;

	count_s1 = 0;
	while (ft_strchr(set, s1[count_s1]) && s1[count_s1])
		count_s1++;
	if (count_s1 == ft_strlen(s1))
		count_s1 = 1;
	return (count_s1);
}

static size_t	ft_strtrim_right(char const *s1, char const *set)
{
	size_t	count_s1;

	count_s1 = ft_strlen(s1);
	while (ft_strchr(set, s1[count_s1]) && count_s1)
		--count_s1;
	return (count_s1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = ft_strtrim_left(s1, set);
	end = ft_strtrim_right(s1, set);
	len = end - start;
	if (!len && start != end && !start && !end)
		str = ft_strdup("");
	str = ft_substr(s1, start, len + 1);
	return (str);
}
