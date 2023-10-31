/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 22:04:23 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/31 23:14:06 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mlx_boost_list.h"

static void	*_boost_calloc(size_t count, size_t size)
{
	char	*res;

	res = (char *) malloc(count * size);
	if (res == (void *) 0)
		return ((void *) 0);
	ft_bzero(res, count * size);
	return ((void *) res);
}

t_boost_err	boost_list_push_back(void *content, t_boost_list *list)
{
	t_boost_node	*node;

	if (list == NULL || content == NULL)
		return (FALSE);
	node = (t_boost_node *)_boost_calloc(sizeof(t_boost_node), 1);
	if (node == NULL)
		return (FALSE);
	node->content = content;
	node->next_node = NULL;
	node->prev_node = list->tail;
	if (node->prev_node != NULL)
		node->prev_node->next_node = node;
	if (list->head == NULL)
	{
		list->head = node;
		list->tail = node;
		list->cursor = node;
		return (TRUE);
	}
	list->tail = node;
	return (TRUE);
}
