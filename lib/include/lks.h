/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lks.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:51:26 by alvjimen          #+#    #+#             */
/*   Updated: 2023/01/31 13:01:14 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LKS_H
# define LKS_H
#include "num.h"
#include "out.h"

void	*debug_malloc(size_t size, const char *file, unsigned long line);
void	debug_free(void *p, const char *file, unsigned long line);
#endif
/*
#define malloc(s) debug_malloc(s, __FILE__, __LINE__)
#define free(p) debug_free(p, __FILE__, __LINE__)
*/
