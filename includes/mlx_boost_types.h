/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_boost_types.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:56:15 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/31 23:05:10 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_BOOST_TYPES_H
# define MLX_BOOST_TYPES_H

# include <stddef.h>

# define FALSE	(0)
# define TRUE	(1)

typedef int				t_boost_color;
typedef int				t_boost_bool;
typedef t_boost_bool	t_boost_err;

typedef struct s_boost_pixel
{
	int					x;
	int					y;
}	t_boost_pixel;

typedef struct s_boost_line
{
	t_boost_pixel		first;
	t_boost_pixel		second;
}	t_boost_line;

typedef struct s_boost_rect
{
	t_boost_pixel		first;
	t_boost_pixel		second;
}	t_boost_rect;

struct s_boost
{
	void			*mlx;
	void			*win;
	t_boost_pixel	win_size;
	size_t			component_count;
}	t_boost;






#endif