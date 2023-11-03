/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boost_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:18:11 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/03 16:33:26 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mlx_boost.h"
#include "../../includes/mlx_boost_list.h"
#include "../../includes/mlx_boost_utils.h"
#include "../../includes/mlx.h"
#include <stdlib.h>

t_boost_err	boost_destroy(void *boost)
{
	t_boost	*temp;

	if (boost == NULL)
	{
		return (FALSE);
	}
	temp = (t_boost *)boost;
	if (boost_list_del_all_node(&temp->components, boost_del_component) == FALSE)
	{
		return (FALSE);
	}
	mlx_destroy_window(temp->mlx, temp->win);
	free(boost);
	return (TRUE);
}
