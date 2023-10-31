/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boost_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 00:16:34 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/01 00:31:55 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mlx_boost.h"
#include "../../includes/mlx.h"

t_boost_err	boost_loop(void *boost)
{
	t_boost	*temp;

	temp = (t_boost *)boost;
	mlx_loop(temp->mlx);
	return (FALSE);
}