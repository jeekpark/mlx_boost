/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boost_del_component_by_name.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:48:05 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/03 14:11:02 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mlx.h"
#include "../../includes/mlx_boost.h"
#include "../../includes/mlx_boost_list.h"
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

t_boost_err		boost_del_component_by_name(void *boost, char* comp_name)
{
	t_boost				*temp;
	t_boost_node		*node;

	if (boost == NULL || comp_name == NULL)
	{
		return (FALSE);
	}
	temp = (t_boost *)boost;
	node = _find_component(&temp->components, comp_name);
	if (node == NULL)
	{
		return (FALSE);
	}
	else
	{
		boost_list_del_one_node(&temp->components, node, boost_del_component);
		return (TRUE);
	}

}