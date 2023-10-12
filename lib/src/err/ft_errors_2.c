/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:27:57 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/02 20:23:13 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "err.h"

void	ft_check_fork(pid_t *child, size_t num_cmd)
{
	if (child[num_cmd] == -1)
	{
		perror("fork with zombies processes");
		exit (EXIT_FAILURE);
	}
}

void	ft_check_access(int access)
{
	if (access == -1)
	{
		perror ("ACCESS ");
		exit (EXIT_FAILURE);
	}
}
