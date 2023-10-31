/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_boost.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:55:18 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/31 23:08:31 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_BOOST_H
# define MLX_BOOST_H

# include "mlx_boost_types.h"



void			*boost_init(t_boost_pixel win_size, char *title);

t_boost_err		boost_add_component(void *boost, t_boost_pixel comp_size, char *comp_ame);
t_boost_err		boost_add_component_from_xpm(void *boost, char* file_path, char *comp_name);
t_boost_err		boost_add_component_from_png(void *boost, char* file_path, char *comp_name);
t_boost_err		boost_del_component_by_name(void *boost, char* comp_name);

t_boost_err		boost_component_to_window(void *boost, char *comp_name, t_boost_pixel position);

t_boost_err		boost_draw_pixel_to_component(void *boost, char *comp_name, t_boost_pixel pixel, t_boost_color color);
t_boost_color	boost_pipet_color_from_component(void* boost, char *comp_name, t_boost_pixel pixel);

t_boost_err		boost_loop(void *boost);

t_boost_err		boost_destroy(void *boost);

#endif