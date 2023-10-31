/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_del_one_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 22:09:18 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/31 23:16:19 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mlx_boost_list.h"

static void	_del_node(t_boost_node *node, void (*del)(void *))
{
	t_boost_node	*node1;
	t_boost_node	*node2;

	node1 = node->prev_node;
	node2 = node->next_node;
	del(node->content);
	free(node);
	node1->next_node = node2;
	node2->prev_node = node1;
}

static void	_del_head(t_boost_list *list, t_boost_node *node, void (*del)(void *))
{
	t_boost_node	*node_temp;

	node_temp = node->next_node;
	node_temp->prev_node = NULL;
	del(node->content);
	free(node);
	list->head = node_temp;
	list->cursor = node_temp;
}

static void	_del_tail(t_boost_list *list, t_boost_node *node, void (*del)(void *))
{
	t_boost_node	*node_temp;

	node_temp = node->prev_node;
	node_temp->next_node = NULL;
	del(node->content);
	free(node);
	list->tail = node_temp;
	list->cursor = list->head;
}

static void	_del_cursor(t_boost_list *list, t_boost_node *node, void (*del)(void *))
{
	_del_node(node, del);
	list->cursor = list->head;
}

t_boost_err	boost_list_del_one_node(t_boost_list *list, t_boost_node *node, void (*del)(void *))
{
	if (list == NULL || node == NULL)
		return (FALSE);
	if (node->next_node == NULL && node->prev_node == NULL)
	{
		del(node->content);
		free(node);
		list_init(list);
		return (TRUE);
	}
	if (list->head == node)
		_del_head(list, node, del);
	else if (list->tail == node)
		_del_tail(list, node, del);
	else if (list->cursor == node)
		_del_cursor(list, node, del);
	else
		_del_node(node, del);
	return (TRUE);
}