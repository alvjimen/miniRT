/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin_free_pf_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacicio <dmacicio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 18:16:00 by alvaro            #+#    #+#             */
/*   Updated: 2023/10/02 20:23:13 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prt.h"

void	*ft_memjoin_free_pf(void **nsbuf, void *line, size_t n_chr,
ssize_t b_c)
{
	void	*tmp_mem;

	tmp_mem = ft_memjoin(*nsbuf, line, n_chr, b_c);
	free(*nsbuf);
	*nsbuf = NULL;
	*nsbuf = tmp_mem;
	return (tmp_mem);
}

void	*ft_memjoin(void const *s1, void const *s2, size_t l_s1, ssize_t l_s2)
{
	char	*mem;

	if ((!s1 && !s2) || (!l_s2 && !l_s1))
		return (NULL);
	mem = ft_calloc(1, l_s2 + l_s1 + 1);
	if (!mem)
		return (NULL);
	if (l_s1)
		ft_memmove(mem, s1, l_s1);
	if (l_s2)
		ft_memmove(mem + l_s1, s2, l_s2);
	return (mem);
}
