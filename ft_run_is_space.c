/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_is_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 08:45:16 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/02 16:59:17 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_run_is_space(char *str, size_t *pos)
{
	if (!str || !pos)
		return ;
	while (ft_is_space(str[*pos]))
		pos[0]++;
}

int	ft_run_atof(char *str, size_t *pos)
{
	if (ft_is_plus_or_minus(str[*pos], str[*pos]))
		pos[0]++;
	if (!ft_isdigit(str[*pos]))
		return (-1);
	while (str[*pos] == '.' || ft_isdigit(str[*pos]))
		pos[0]++;
	return (0);
}

int	ft_run_atoi(char *str, size_t *pos)
{
	if (ft_is_plus_or_minus(str[*pos], str[*pos]))
		pos[0]++;
	if (!ft_isdigit(str[*pos]))
		return (-1);
	while (ft_isdigit(str[*pos]))
		pos[0]++;
	return (0);
}
