/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boost_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 23:28:25 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/31 23:59:05 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mlx_boost.h"
#include "../../includes/mlx_boost_utils.h"
#include "../../includes/mlx_boost_list.h"
#include "../../includes/mlx.h"

#include <stdlib.h>

static t_boost_err	_valid_window(int w, int h)
{
	if ((100 <= w && w <= 3860)
		&& (100 <= h && h <= 2160))
	{
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}

void	*boost_init(int window_width, int window_height, char *title)
{
	t_boost	*result;

	if (title == NULL || _valid_window(window_width, window_height) == FALSE)
		return (NULL);
	result = (t_boost *)malloc(sizeof(t_boost));
	if (result == NULL)
		return (NULL);
	result->mlx = mlx_init();
	if (result->mlx == NULL)
	{
		free(result);
		return (NULL);
	}
	result->win = mlx_new_window(result->mlx,
			window_width, window_height, title);
	if (result->win == NULL)
	{
		free(result);
		return (NULL);
	}
	result->win_size = boost_set_pixel(window_width, window_height);
	boost_list_init(&result->components);
	return (result);
}
