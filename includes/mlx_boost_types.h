/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_boost_types.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:56:15 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/01 14:15:51 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_BOOST_TYPES_H
# define MLX_BOOST_TYPES_H

# include <stddef.h>

# include "mlx_boost_list_types.h"

# define FALSE					0
# define TRUE					1

# define RDONLY					0
# define RDWR					1

# define MAX_WINDOW_WIDTH		3860
# define MIN_WINDOW_WIDTH		1
# define MAX_WINDOW_HEIGHT		2160
# define MIN_WINDOW_HEIGHT		1

# define MAX_COMPONENT_WIDTH	16384
# define MIN_COMPONENT_WIDTH	1
# define MAX_COMPONENT_HEIGHT	16384
# define MIN_COMPONENT_HEIGHT	1

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_MOTION_NOTIFY	6
# define X_EVENT_DESTROY		17
# define X_EVENT_MOUSE_PRESS	4
# define X_EVENT_MOUSE_RELEASE	5

typedef int				t_boost_color;
typedef int				t_boost_bool;
typedef t_boost_bool	t_boost_err;
typedef int				t_boost_mode;

typedef struct s_boost_pixel
{
	int					x;
	int					y;
}	t_boost_pixel;

typedef struct s_boost_component
{
	t_boost_mode		mode;
	char				*name;
	void				*mlx;
	void				*img;
	int					width;
	int					height;
	int					*mlx_data_addr;
	int					bpp;
	int					line_size;
	int					endian;
}	t_boost_component;

typedef struct s_boost
{
	void				*mlx;
	void				*win;
	t_boost_pixel		win_size;
	t_boost_list		components;
}	t_boost;







#endif