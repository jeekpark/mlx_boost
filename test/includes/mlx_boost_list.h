/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_boost_list.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:07:09 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/31 23:20:00 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_BOOST_LIST_H
# define MLX_BOOST_LIST_H

# include "mlx_boost_list_types.h"
# include "mlx_boost_types.h"

t_boost_err	boost_list_init(t_boost_list *list);
t_boost_err	boost_list_push_back(void *content, t_boost_list *list);
t_boost_err	boost_list_del_one_node(t_boost_list *list, t_boost_node *node, void (*del)(void *));
t_boost_err	boost_list_del_all_node(t_boost_list *list, void (*del)(void *));

#endif