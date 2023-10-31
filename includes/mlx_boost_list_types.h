/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_boost_list_types.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 23:05:50 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/31 23:08:28 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_BOOST_LIST_TYPES_H
# define MLX_BOOST_LIST_TYPES_H

typedef struct s_boost_node
{
	void				*content;
	struct s_boost_node	*next_node;
	struct s_boost_node	*prev_node;
}	t_boost_node;


typedef	struct s_boost_list
{
	t_boost_node		*head;
	t_boost_node		*tail;
	t_boost_node		*cursor;
}	t_boost_list;

#endif