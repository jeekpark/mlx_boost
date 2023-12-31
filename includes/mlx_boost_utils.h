/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_boost_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 23:44:05 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/03 14:01:56 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_BOOST_UTILS_H
# define MLX_BOOST_UTILS_H

# include "mlx_boost_types.h"

t_boost_pixel	boost_set_pixel(int x, int y);
char			*boost_strdup(const char *s1);
void			boost_del_component(void *content);

#endif