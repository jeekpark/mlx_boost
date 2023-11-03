/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_component.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:59:48 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/03 14:05:47 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mlx.h"
#include "../../includes/mlx_boost.h"
#include "../../includes/mlx_boost.h"
#include <stdlib.h>

void	boost_del_component(void *content)
{
	t_boost_component	*comp;

	if (content == NULL)
		return ;
	comp = (t_boost_component *)content;
	free(comp->name);
	mlx_destroy_image(comp->mlx, comp->img);
}