/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:50:36 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/31 23:11:53 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mlx_boost_list.h"

static void	*_boost_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*b_save;

	i = 0;
	b_save = (unsigned char *) b;
	while (i < len)
		b_save[i++] = c;
	return (b);
}

t_boost_err	boost_list_init(t_boost_list *list)
{
	if (list == NULL)
	{
		return (FALSE);
	}
	_boost_memset(list, 0, sizeof(t_boost_list));
	return (TRUE);
}
