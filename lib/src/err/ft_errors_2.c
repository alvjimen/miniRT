/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:27:57 by alvjimen          #+#    #+#             */
/*   Updated: 2022/12/01 10:30:43 by alvjimen         ###   ########.fr       */
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
