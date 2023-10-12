/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_str_uniq_exclude_rule.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:07:30 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/02 20:23:13 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

int	ft_is_str_uniq_exclude_rule(char *str, int (*rule)(char, char))
{
	int	c_1;
	int	c_2;

	c_2 = 0;
	while (str[c_2])
	{
		c_1 = c_2 + 1;
		while (str[c_1])
		{
			if (rule && rule(str[c_1], str[c_2]))
				return (0);
			if (str[c_2] == str[c_1] && c_2 != c_1)
				return (0);
			c_1++;
		}
		c_2++;
	}
	return (1);
}
