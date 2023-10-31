/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boost_add_component.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 01:57:41 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/01 02:31:25 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mlx_boost.h"
#include "../../includes/mlx_boost_list.h"

static int	_strcmp_alt(const char *s1, const char *s2)
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

static t_boost_node	*_find_component(t_boost_list *list, char *name)
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
			return (list->cursor);
		}
		list->cursor = list->cursor->next_node;
	}
	return (NULL);
}

static t_boost_err	_valid_comp_size(t_boost_pixel comp_size)
{
	if ((MIN_COMPONENT_WIDTH <= comp_size.x
			&& comp_size.x <= MAX_COMPONENT_WIDTH)
		&& (MIN_COMPONENT_HEIGHT <= comp_size.y
			&& comp_size.y <= MAX_COMPONENT_HEIGHT))
	{
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}

t_boost_err	boost_add_component(void *boost, t_boost_pixel comp_size, char *comp_name)
{
	t_boost	*temp;

	if (boost == NULL
		|| _valid_comp_size(comp_size) == FALSE
		|| comp_name == NULL)
		return (FALSE);
	if (_find_component(&temp->components, comp_name))
	{
		return (FALSE);
	}
}