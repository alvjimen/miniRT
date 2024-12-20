/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:07:40 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/02 20:23:13 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "err.h"

void	ft_check_malloc(void *pointer)
{
	if (!pointer)
	{
		perror("Error on MALLOC");
		exit(EXIT_FAILURE);
	}
}

void	ft_check_open(int fd)
{
	if (fd == -1)
	{
		perror("Error on OPEN");
		exit(EXIT_FAILURE);
	}
}

/*return of pipe */
void	ft_check_pipe(int pipe)
{
	if (pipe == -1)
	{
		perror("Error on PIPE");
		exit (EXIT_FAILURE);
	}
}

void	ft_check_env(char *env)
{
	if (!env)
	{
		ft_putendl_fd("no enviroment var", 1);
		exit(EXIT_FAILURE);
	}
}

void	ft_check_dup(int i)
{
	if (i == -1)
	{
		perror("dup2");
		return ;
	}
}
