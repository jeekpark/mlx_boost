/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boost_set_pixel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 23:51:54 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/31 23:53:25 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mlx_boost_types.h"

t_boost_pixel	boost_set_pixel(int x, int y)
{
	t_boost_pixel	result;

	result.x = x;
	result.y = y;
	return (result);
}
