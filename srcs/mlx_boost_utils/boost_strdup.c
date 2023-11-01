/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boost_strdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:24:17 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/01 15:36:23 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mlx_boost.h"
#include <stdlib.h>

char	*boost_strdup(const char *s1)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	while (s1[i])
		i++;
	j = 0;
	res = (char *) malloc(sizeof(char) * i + 1);
	if (res == (void *) 0)
		return ((void *) 0);
	while (s1[j])
	{
		res[j] = s1[j];
		j++;
	}
	res[j] = '\0';
	return (res);
}
