/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_del_all_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 23:43:23 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/31 23:17:15 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mlx_boost_list.h"

t_boost_err	boost_list_del_all_node(t_boost_list *list, void (*del)(void *))
{
	list->cursor = list->head;
	while (list->cursor)
		boost_list_del_one_node(list, list->cursor, del);
	return (TRUE);
}
