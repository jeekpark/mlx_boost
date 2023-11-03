/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boost_component_to_window.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:48:55 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/03 12:41:43 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mlx.h"
#include "../../includes/mlx_boost.h"
#include "../../includes/mlx_boost_utils.h"


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

t_boost_err		boost_component_to_window(void *boost, char *comp_name, t_boost_pixel position)
{
	t_boost_component	*comp;
	t_boost				*boost_temp;

	if (boost == NULL || comp_name == NULL)
		return (FALSE);
	boost_temp = (t_boost *)boost;
	comp = _find_component(&boost_temp->components, comp_name);
	if (comp == NULL)
		return (FALSE);
	mlx_put_image_to_window(boost_temp->mlx, boost_temp->win, comp->img, position.x, position.y);
	return (TRUE);
}
