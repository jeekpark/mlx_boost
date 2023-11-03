/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boost_draw_pixel_to_compnent.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:42:26 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/03 13:06:36 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mlx.h"
#include "../../includes/mlx_boost.h"

static t_boost_err	_strcmp_alt(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (TRUE);
		++s1;
		++s2;
	}
	return (FALSE);
}

static t_boost_component	*_find_component(t_boost_list *list, char *name)
{
	t_boost_component	*temp;

	if (list == NULL || name == NULL)
	{
		return (FALSE);
	}
	list->cursor = list->head;
	while (list->cursor)
	{
		temp = (t_boost_component *)list->cursor->content;
		if (_strcmp_alt(name, temp->name) == TRUE)
		{
			return (temp);
		}
		list->cursor = list->cursor->next_node;
	}
	return (NULL);
}

t_boost_err	_valid_pixel_range(t_boost_pixel pixel, t_boost_component *comp)
{
	if ((0 <= pixel.x && pixel.x < comp->width)
		&& (0 <= pixel.y && pixel.y < comp->height))
	{
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}

t_boost_err	boost_draw_pixel_to_component(void *boost, char *comp_name, t_boost_pixel pixel, t_boost_color color)
{
	t_boost				*temp;
	t_boost_component	*comp;

	temp = (t_boost *)boost;
	if (boost == NULL || comp_name == NULL)
	{
		return (FALSE);
	}
	comp = _find_component(&temp->components, comp_name);
	if (comp == NULL)
	{
		return (FALSE);
	}
	if (_valid_pixel_range(pixel, comp) == FALSE)
	{
		return (FALSE);
	}
	comp->mlx_data_addr[comp->line_size
		/ (comp->bpp / 8) * pixel.y + pixel.x] = color;
	return (TRUE);
}

