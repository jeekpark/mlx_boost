/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boost_add_component.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 23:38:48 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/03 12:39:08 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mlx_boost.h"
#include "../../includes/mlx_boost_list.h"
#include "../../includes/mlx_boost_utils.h"
#include "../../includes/mlx.h"
#include <stdlib.h>

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

static t_boost_err	_init_component(void *mlx, t_boost_component *comp, t_boost_pixel comp_size, char *name)
{
	if (mlx == NULL || comp == NULL)
		return (FALSE);
	comp->img = mlx_new_image(mlx, comp_size.x, comp_size.y);
	if (comp->img == NULL)
		return (FALSE);
	comp->name = boost_strdup(name);
	if (comp->name == NULL)
	{
		mlx_destroy_image(mlx, comp->img);
		return (FALSE);
	}
	comp->mlx = mlx;
	comp->width = comp_size.x;
	comp->height = comp_size.y;
	comp->mlx_data_addr = (int *)mlx_get_data_addr(comp->img, &comp->bpp,
		&comp->line_size, &comp->endian);
	if (comp->mlx_data_addr == NULL)
	{
		mlx_destroy_image(mlx, comp->img);
		free(comp->name);
		return (FALSE);
	}
	return (TRUE);
}
#include <printf.h>
t_boost_err	boost_add_component(void *boost, t_boost_pixel comp_size, char *comp_name)
{
	t_boost				*temp;
	t_boost_component	*to_add;

	if (boost == NULL
		|| _valid_comp_size(comp_size) == FALSE
		|| comp_name == NULL)
		return (FALSE);
	temp = (t_boost *)boost;
	if (_find_component(&temp->components, comp_name))
		return (FALSE);
	to_add = (t_boost_component *)malloc(sizeof(t_boost_component));
	if (to_add == NULL)
		return (FALSE);
	if (_init_component(temp->mlx, to_add, comp_size, comp_name) == FALSE)
	{
		
		free(to_add);
		return (FALSE);
	}
	if (boost_list_push_back(to_add, &temp->components) == FALSE)
	{
		free(to_add->name);
		mlx_destroy_image(temp->mlx, to_add->img);
		return (FALSE);
	}
	return (TRUE);
}
